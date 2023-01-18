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
