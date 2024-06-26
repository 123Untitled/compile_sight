#ifndef CS_CONFIG_HEADER
#define CS_CONFIG_HEADER

// requirements
#define ___cs_requirements 1

// check if __has_builtin is available
#ifndef ___cs_has_builtin
#	ifndef __has_builtin
#		define ___cs_has_builtin(_) 0
#	else
#		define ___cs_has_builtin(_) __has_builtin(_)
#	endif
#endif // __has_builtin

// check cplusplus version
#if __cplusplus < 202002L
#	error "c++20 standard is required."
#	undef ___cs_requirements
#	define ___cs_requirements 0
#endif // ___cs_cxx_version

// check if __is_trivially_copyable is available
#if not __has_builtin(__is_trivially_copyable)
#	error "compiler does not support __is_trivially_copyable"
#	undef ___cs_requirements
#	define ___cs_requirements 0
#endif

// check if __is_trivially_destructible is available
#if not __has_builtin(__is_trivially_destructible)
#	error "compiler does not support __is_trivially_destructible"
#	undef ___cs_requirements
#	define ___cs_requirements 0
#endif


#define ___cs_not_copyable(_) \
	_(const _&) = delete; \
	auto operator=(const _&) -> _& = delete

#define ___cs_not_moveable(_) \
	_(_&&) = delete; \
	auto operator=(_&&) -> _& = delete

#define ___cs_not_instantiable(_) \
	_(void) = delete; \
	~_(void) = delete; \
	___cs_not_copyable(_); \
	___cs_not_moveable(_)


#endif // CS_CONFIG_HEADER
