#include <string.h>

#include "../netdissect.h"

/*
 * Copy src to string dest of size siz. At most siz-1 charcaters
 * will be copied. Always NULL terminates (unless siz == 0).
 * Returns strlen(src); if retval >= siz, trucation occured.
 */

size_t
strlcpy(char *dst, const char *src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;

	// Copy as many bytes as will fit
	if (n != 0 && --n != 0)
		do {
			if ((*d++ = *s++) == 0)
				break;
		} while (--n != 0);

	// Not enough room in dst, add NULL and traverse rest of src
	if (n == 0) {
		if (siz != 0)
			*d = '\0';
		while (*s++)
			;
	}

	return (s - src - 1); // Count doens't include NULL

}
