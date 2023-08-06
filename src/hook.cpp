#include "_Hook.hpp"
#include "_Alloc.hpp"
#include "Error.hpp"

#include <Windows.h>
#include <Zydis/Zydis.h>
#include <format>


using namespace mebius;

static inline code_t* make_trampoline_code(uint32_t address) noexcept;
static inline size_t calc_assembly_length(uint32_t address) noexcept;
static inline std::pair<bool, HookDataImpl&> add_hook_data(uint32_t address) noexcept;
static inline void write_call_opcode(uint32_t address, const void* func);
static inline void write_jmp_opcode(uint32_t address, const void* func) noexcept;


MEBIUSAPI const HookData& mebius::_GetHookData(uint32_t address)
{
	decltype(_HOOK_LIST)::iterator it = _HOOK_LIST.find(address);
	if (it == _HOOK_LIST.end()) {
		throw MebiusError(std::vformat("Mebius has not hook on address 0x{:08X}.", std::make_format_args(address)));
	}
	else {
		return it->second;
	}
}

MEBIUSAPI const HookData* mebius::_GetHookDataNullable(uint32_t address) noexcept
{
	decltype(_HOOK_LIST)::iterator it = _HOOK_LIST.find(address);
	if (it == _HOOK_LIST.end()) {
		return nullptr;
	}
	else {
		return &(it->second);
	}
}

MEBIUSAPI void mebius::_SetHookOnHead(uint32_t hookTarget, const void* hookFunction, const void* internalHookFunction) noexcept
{
	auto [unhooked, hook] = add_hook_data(hookTarget);
	hook.AppendHeadHook(hookFunction);
	if (unhooked) {
		try {
			write_call_opcode(hookTarget, internalHookFunction);
		}
		catch (const MebiusError& e) {
			ShowErrorDialog(e.what());
		}
	}
}

MEBIUSAPI void mebius::_SetHookOnTail(uint32_t hookTarget, const void* hookFunction, const void* internalHookFunction) noexcept
{
	auto [unhooked, hook] = add_hook_data(hookTarget);
	hook.AppendTailHook(hookFunction);
	if (unhooked) {
		try {
			write_call_opcode(hookTarget, internalHookFunction);
		}
		catch (const MebiusError& e) {
			ShowErrorDialog(e.what());
		}
	}
}


HookDataImpl::HookDataImpl(uint32_t address) noexcept {
	_trampoline_code = make_trampoline_code(address);
}

HookDataImpl::~HookDataImpl() noexcept {
	if (_trampoline_code != nullptr) {
		alloc::CodeAllocator::GetInstance().DeAllocate(_trampoline_code);
		_trampoline_code = nullptr;
	}
}


static inline code_t* make_trampoline_code(uint32_t address) noexcept {
	size_t length = 0;
	do {
		length += calc_assembly_length(address + length);
	} while (length < 5);

	auto mem = alloc::CodeAllocator::GetInstance().Allocate(length + 5);
	std::memcpy(mem, std::bit_cast<void*>(address), length);
	write_jmp_opcode(std::bit_cast<uint32_t>(mem) + length, std::bit_cast<void*>(address + length));
	return mem;
}

static inline size_t calc_assembly_length(uint32_t address) noexcept {
	ZydisDisassembledInstruction inst;
	if (ZYAN_SUCCESS(ZydisDisassembleIntel(ZYDIS_MACHINE_MODE_LONG_COMPAT_32, 0, std::bit_cast<void*>(address), 0x7fffffff, &inst))) {
		return inst.info.length;
	}
	return 0;
}

static inline std::pair<bool, HookDataImpl&> add_hook_data(uint32_t address) noexcept
{
	decltype(_HOOK_LIST)::iterator it = _HOOK_LIST.find(address);
	if (it == _HOOK_LIST.end()) {
		decltype(_HOOK_LIST)::iterator item = std::get<0>(_HOOK_LIST.emplace(address, address));
		return { true, item->second };
	}
	else {
		return { false, it->second };
	}
}

static inline void write_call_opcode(uint32_t address, const void* func) {
	auto ptr = std::bit_cast<code_t*>(address);
	DWORD oldProtect;
	if (VirtualProtect(ptr, 5, PAGE_EXECUTE_READWRITE, &oldProtect) == 0) {
		throw MebiusError(std::vformat("Can't change the page protect of 0x{:08X}.", std::make_format_args(address)));
	}
	ptr[0] = _OPCODE_REL_CALL;
	auto callee = std::bit_cast<uint32_t*>(address + 1);
	callee[0] = std::bit_cast<uint32_t>(func) - (address + 5);
	VirtualProtect(ptr, 5, oldProtect, &oldProtect);
}

static inline void write_jmp_opcode(uint32_t address, const void* func) noexcept {
	auto ptr = std::bit_cast<code_t*>(address);
	ptr[0] = _OPCODE_REL_JMP;
	auto callee = std::bit_cast<uint32_t*>(address + 1);
	callee[0] = std::bit_cast<uint32_t>(func) - (address + 5);
}
