#include "compiler-tests.h"

#if __has_attribute(noreturn) \
	|| ND_IS_AT_LEAST_GNUC_VERSION(2,5) \
	|| ND_IS_AT_LEAST_XL_C_VERSION(10,1) \
	|| ND_IS_AT_LEAST_HP_C_VERSION(6,10)

	#define NORETURN __attribute((noreturn))

	#if (defined(__GNUC__) && ((__GNUC__ * 100 + __GNUC_MINOR__) < 401))
		#define NORETURN_FUNCPTR
	#else
		#define NORETURN_FUNCPTR __attribute((noreturn))
	#endif
#else
	#define NORETURN
	#define NORETURN_FUNCPTR
#endif

#if __has_attribute(__format__) \
	|| ND_IS_AT_LEAST_GNUC_VERSION(2,3) \
	|| ND_IS_AT_LEAST_XL_C_VERSION(10,1) \
	|| ND_IS_AT_LEAST_HP_C_VERSION(60,10)
/*
 *
 */
	#define PRINTFLIKE(x,y) __attribute__((__format__(__printf__,x,y)))

/*
 *
 */

	#if (ND_IS_AT_LEAST_GNUC_VERSION(4,1) \
			&& !ND_IS_AT_LEAST_XL_C_VERSION(10,1)) \
			 || (ND_IS_AT_LEAST_XL_C_VERSION(16,1) \
				&& (ND_IS_AT_LEAST_XL_C_MODFIX(1,8) && defined(__linux__)) \
				 || (ND_IS_AT_LEAST_XL_C_MODFIX(0,5) && defined(_AIX)))
		#define PRINTFLIKE_FUNCPTR(x,y) __attribute__((__format__(__printf__, x, y)))
	#endif
#endif

#if !defined(PRINTFLIKE)
#define PRINTFLIKE(x, y)
#endif

#if !defined(PRINTFLIKE_FUNCPTR)
#define PRINTFLIKE_FUNCPTR(x, y)
#endif

#ifdef _MSC_VER
	#include <sal.h>
	#define FORMAT_STRING(p) _Printf_format_string_ p
#else
	#define FORMAT_STRING(p) p
#endif
