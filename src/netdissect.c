#include <string.h>
#include "netdissect.h"

int
nd_init(char *errbuf, size_t errbuf_size)
{
	/*
	 * Clears the error buffer, and uses it so we don't get
	 * "unused argument" warnings at compile time.
	 */

	strlcpy(errbuf, "", errbuf_size);
	return 0;
}

void
nd_cleanup(void)
{
#ifdef USE_LIBSMI
	/*
	 * This appears, in libsmi 0.4.8, to do nothing if smiInit()
	 * wasn't done or failed, so we call it unconditionally
	 */

	smiExit();
#endif
}
