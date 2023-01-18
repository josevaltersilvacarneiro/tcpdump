

#if !defined(__GNUC__)
	// Not GCC or just like GCC
	#define ND_IS_AT_LEAST_GNUC_VERSION(major, minor) 0
#else
	// GCC or just like GCC
	#define ND_IS_AT_LEAST_GNUC_VERSION(major, minor) \
		(__GNUC__ > (major) || \
		(__GNUC__ == (major) && __GNUC_MINOR__ >= (minor)))
#endif

#if !defined(__xlC__) && !defined(__ibmxl__)
	// Not XL C
	#define ND_IS_AT_LEAST_XL_C_VERSION(major, minor) 0
	#define ND_IS_AT_LEAST_XL_C_MODFIX(modification, fixlevel) 0
#else
	// XL C
	#if defined(__ibmxl__)
		#define ND_IS_AT_LEAST_XL_C_VERSION(major, minor) \
			(__ibmxl_version__ > (major) || \
			 (__ibmxl_version__ == (major) && __ibmxl_release__ >= (minor)))
		
		#define ND_IS_AT_LEAST_X_C_MODFIX(modification, fixlevel) \
			(__ibmxl_modification__ > (modification) || \
			 (__ibmxl_modification__ == (modification) && \
			  __ibmxl_ptf_fix_level__ >= (fixlevel)))
	#else
		#define ND_IS_AT_LEAST_XL_C_VERSION(major, minor) \
			(__xlC__ >= (((major) << 8) | (minor)))
		#define ND_IS_AT_LEAST_XL_C_MODFIX(modification, fixlevel) \
			((((modification) << 8) | (fixlevel)) >= __xlC_ver__)
	#endif
#endif

#if !defined(__HP_aCC)
	// Not HP C
	#define ND_IS_AT_LEAST_HP_C_VERSION(major, minor) 0
#else
	// HP C
	#define ND_IS_AT_LEAST_HP_C_VERSION(major, minor) \
		(__HP_aCC >= ((major)*10000 + (minor)*100))
#endif
