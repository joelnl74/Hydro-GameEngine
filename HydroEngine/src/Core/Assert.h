#pragma once

#ifdef HY_DEBUG
#define HY_ENABLE_ASSERTS
#endif

#ifdef HY_ENABLE_ASSERTS
#define HY_ASSERT_NO_MESSAGE(condition) { if(!(condition)) { HZ_ERROR("Assertion Failed"); __debugbreak(); } }
#define HY_ASSERT_MESSAGE(condition, ...) { if(!(condition)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

#define HY_ASSERT_RESOLVE(arg1, arg2, macro, ...) macro
#define HY_GET_ASSERT_MACRO(...) HZ_EXPAND_VARGS(HZ_ASSERT_RESOLVE(__VA_ARGS__, HZ_ASSERT_MESSAGE, HZ_ASSERT_NO_MESSAGE))

#define HY_ASSERT(...) HZ_EXPAND_VARGS( HZ_GET_ASSERT_MACRO(__VA_ARGS__)(__VA_ARGS__) )
#define HY_CORE_ASSERT(...) HZ_EXPAND_VARGS( HZ_GET_ASSERT_MACRO(__VA_ARGS__)(__VA_ARGS__) )
#else
#define HY_ASSERT(...)
#define HY_CORE_ASSERT(...)
#endif
