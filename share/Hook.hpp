#pragma once

#include "Error.hpp"

#include <bit>
#include <optional>
#include <vector>

namespace mebius {

#ifdef MEBIUS_EXPORT
#define MEBIUSAPI __declspec(dllexport)
#else
#define MEBIUSAPI __declspec(dllimport)
#endif

	using code_t = uint8_t;

	class HookData {
	public:
		virtual ~HookData() = default;
		virtual const std::vector<const void*>& GetHeadHooks() const noexcept = 0;
		virtual const std::vector<const void*>& GetTailHooks() const noexcept = 0;
		virtual const code_t* GetTrampolineCode() const noexcept = 0;
	};

	MEBIUSAPI const HookData& _GetHookData(uint32_t address);
	MEBIUSAPI const HookData* _GetHookDataNullable(uint32_t address) noexcept;
	MEBIUSAPI void _SetHookOnHead(uint32_t hookTarget, const void* hookFunction, const void* internalHookFunction) noexcept;
	MEBIUSAPI void _SetHookOnTail(uint32_t hookTarget, const void* hookFunction, const void* internalHookFunction) noexcept;

	namespace internal {};
	namespace {
		namespace internal {
			using pvfv_t = void(*)(void);
			template <typename T>
			using ptfv_t = T(*)(void);
			template <typename... Args>
			using pvfa_t = void(*)(Args...);
			template <typename T, typename... Args>
			using ptfa_t = T(*)(Args...);
			template <typename T>
			using ptft_t = T(*)(T);
			template <typename T, typename... Args>
			using ptfta_t = T(*)(T, Args...);


			void hook_vfv(pvfv_t hookedFunction, int32_t returnAddress) {
				try {
					uint32_t address = std::bit_cast<uint32_t>(hookedFunction);
					auto& hook = _GetHookData(address);

					for (auto&& f : hook.GetHeadHooks()) {
						auto head = std::bit_cast<pvfv_t>(f);
						head();
					}

					auto trampoline = std::bit_cast<pvfv_t>(hook.GetTrampolineCode());
					trampoline();

					for (auto&& f : hook.GetTailHooks()) {
						auto tail = std::bit_cast<pvfv_t>(f);
						tail();
					}
				}
				catch (const MebiusError& e) {
					ShowErrorDialog(e.what());
				}

				__asm {
					leave
					mov ecx, returnAddress
					mov dword ptr[esp], ecx
					ret 4
				};
			}

			template <typename T>
			void hook_tfv(ptfv_t<T> hookedFunction, int32_t returnAddress) {
				T result;
				try {
					int32_t address = std::bit_cast<int32_t>(hookedFunction);
					auto& hook = _GetHookData(address);

					for (auto&& f : hook.GetHeadHooks()) {
						auto head = std::bit_cast<pvfv_t>(f);
						head();
					}

					auto trampoline = std::bit_cast<ptfv_t<T>>(hook.GetTrampolineCode());
					result = trampoline();

					for (auto&& f : hook.GetTailHooks()) {
						auto tail = std::bit_cast<ptft_t<T>>(f);
						result = tail(result);
					}
				}
				catch (const MebiusError& e) {
					ShowErrorDialog(e.what());
				}

				__asm {
					leave
					mov eax, returnAddress
					mov dword ptr[esp], eax
					mov eax, result
					ret 4
				};
			}

			template <typename... Args>
			void hook_vfa(pvfa_t<Args...> hookedFunction, int32_t returnAddress, Args... args) {
				try {
					int32_t address = std::bit_cast<int32_t>(hookedFunction);
					auto& hook = _GetHookData(address);

					for (auto&& f : hook.GetHeadHooks()) {
						auto head = std::bit_cast<pvfa_t<Args...>>(f);
						head(args...);
					}

					auto trampoline = std::bit_cast<pvfa_t<Args...>>(hook.GetTrampolineCode());
					trampoline(args...);

					for (auto&& f : hook.GetTailHooks()) {
						auto tail = std::bit_cast<pvfa_t<Args...>>(f);
						tail(args...);
					}
				}
				catch (const MebiusError& e) {
					ShowErrorDialog(e.what());
				}

				__asm {
					leave
					mov ecx, returnAddress
					mov dword ptr[esp], ecx
					ret 4
				};
			}

			template <typename T, typename... Args>
			void hook_tfa(ptfa_t<T, Args...> hookedFunction, int32_t returnAddress, Args... args) {
				T result;
				try {
					int32_t address = std::bit_cast<int32_t>(hookedFunction);
					auto& hook = _GetHookData(address);

					for (auto&& f : hook.GetHeadHooks()) {
						auto head = std::bit_cast<pvfa_t<Args...>>(f);
						head(args...);
					}

					auto trampoline = std::bit_cast<ptfa_t<T, Args...>>(hook.GetTrampolineCode());
					T result = trampoline(args...);

					for (auto&& f : hook.GetTailHooks()) {
						auto tail = std::bit_cast<ptfta_t<T, Args...>>(f);
						result = tail(result, args...);
					}
				}
				catch (const MebiusError& e) {
					ShowErrorDialog(e.what());
				}

				__asm {
					leave
					mov eax, returnAddress
					mov dword ptr[esp], eax
					mov eax, result
					ret 4
				};
			}
		}

		void HookOnHead(internal::pvfv_t caller, const internal::pvfv_t callee) noexcept {
			_SetHookOnHead(std::bit_cast<uint32_t>(caller), std::bit_cast<const void*>(callee), std::bit_cast<const void*>(&internal::hook_vfv));
		}

		template <typename T>
		void HookOnHead(internal::ptfv_t<T> caller, const internal::pvfv_t callee) noexcept {
			_SetHookOnHead(std::bit_cast<uint32_t>(caller), std::bit_cast<const void*>(callee), std::bit_cast<const void*>(&internal::hook_tfv<T>));
		}

		template <typename... Args>
		void HookOnHead(internal::pvfa_t<Args...> caller, const internal::pvfa_t<Args...> callee) noexcept {
			_SetHookOnHead(std::bit_cast<uint32_t>(caller), std::bit_cast<const void*>(callee), std::bit_cast<const void*>(&internal::hook_vfa<Args...>));
		}

		template <typename T, typename... Args>
		void HookOnHead(internal::ptfa_t<T, Args...> caller, const internal::pvfa_t<Args...> callee) noexcept {
			_SetHookOnHead(std::bit_cast<uint32_t>(caller), std::bit_cast<const void*>(callee), std::bit_cast<const void*>(&internal::hook_tfa<T, Args...>));
		}

		void HookOnTail(internal::pvfv_t caller, const internal::pvfv_t callee) noexcept {
			_SetHookOnTail(std::bit_cast<uint32_t>(caller), std::bit_cast<const void*>(callee), std::bit_cast<const void*>(&internal::hook_vfv));
		}

		template <typename T>
		void HookOnTail(internal::ptfv_t<T> caller, const internal::ptft_t<T> callee) noexcept {
			_SetHookOnTail(std::bit_cast<uint32_t>(caller), std::bit_cast<const void*>(callee), std::bit_cast<const void*>(&internal::hook_tfv<T>));
		}

		template <typename... Args>
		void HookOnTail(internal::pvfa_t<Args...> caller, const internal::pvfa_t<Args...> callee) noexcept {
			_SetHookOnTail(std::bit_cast<uint32_t>(caller), std::bit_cast<const void*>(callee), std::bit_cast<const void*>(&internal::hook_vfa<Args...>));
		}

		template <typename T, typename... Args>
		void HookOnTail(internal::ptfa_t<T, Args...> caller, const internal::ptfta_t<T, Args...> callee) noexcept {
			_SetHookOnTail(std::bit_cast<uint32_t>(caller), std::bit_cast<const void*>(callee), std::bit_cast<const void*>(&internal::hook_tfa<T, Args...>));
		}
	}
}