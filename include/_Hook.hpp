#pragma once

#include "Hook.hpp"
#include <unordered_map>

namespace mebius {
	using code_t = uint8_t;

	constexpr static inline size_t _MEM_CODE_SIZE = 0x1000;
	constexpr static inline code_t _OPCODE_REL_CALL = 0xE8;
	constexpr static inline code_t _OPCODE_REL_JMP = 0xE9;

#pragma section(".mebius", read, write, execute)
	__declspec(allocate(".mebius")) static inline code_t _MEBIUS_RWX_MEM_POOL[_MEM_CODE_SIZE];
	
	class HookDataImpl : public HookData{
	public:
		explicit HookDataImpl(uint32_t address) noexcept;
		~HookDataImpl() noexcept override;
		HookDataImpl(HookDataImpl&& hookData) noexcept = default;

		inline const std::vector<const void*>& GetHeadHooks() const noexcept override {
			return _head_hooks;
		}
		inline const std::vector<const void*>& GetTailHooks() const noexcept override {
			return _tail_hooks;
		}
		inline const code_t* GetTrampolineCode() const noexcept override {
			return _trampoline_code;
		}
		inline void AppendHeadHook(const void* func) noexcept {
			_head_hooks.push_back(func);
		}
		inline void AppendTailHook(const void* func) noexcept {
			_tail_hooks.push_back(func);
		}

	private:
		std::vector<const void*> _head_hooks;
		std::vector<const void*> _tail_hooks;
		const code_t* _trampoline_code;
	};

	static inline std::unordered_map<uint32_t, HookDataImpl> _HOOK_LIST{};
}
