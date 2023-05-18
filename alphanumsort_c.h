#pragma once

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static inline
int alphanumsort(const void *aptr, const void *bptr)
{
	const char *a = *(char **)aptr;
	const char *b = *(char **)bptr;

	while (*a && *b) {
		if (isdigit(*a) && isdigit(*b)) {
			unsigned long numa = strtoul(a, (char **)&a, 10);
			unsigned long numb = strtoul(b, (char **)&b, 10);

			if (numa != numb)
				return numa - numb;
		} else {
			if (*a != *b)
				return *a - *b;
			a++;
			b++;
		}

	}

	return *a - *b;
}
