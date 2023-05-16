#pragma once

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

static inline
int num_alphas(const char *s)
{
	int i;
	for (i = 0; s[i]; i++)
		if (isdigit(s[i]))
			break;
	return i;
}

static inline
int alphanumsort(const void *aptr, const void *bptr)
{
	char * const *_a = aptr;
	char * const *_b = bptr;

	const char *a = *_a;
	const char *b = *_b;

	int pos = 0;
	int len = min(strlen(a), strlen(b));

	while (pos < len) {
		if (isdigit(a[pos]) != isdigit(b[pos]))
			return a[pos] - b[pos];

		if (isdigit(a[pos])) {
			char *end;
			long numa = strtol(a + pos, &end, 10);
			long numb = strtol(b + pos, NULL, 10);

			if (numa != numb)
				return numa - numb;

			pos = end - a;
		} else {
			int lena = num_alphas(a + pos);
			int lenb = num_alphas(b + pos);

			int alphacmp = strncmp(a + pos, b + pos, min(lena, lenb));
			if (alphacmp)
				return alphacmp;
			if (lena != lenb)
				return lena - lenb;

			pos += lena;
		}

	}

	return a[pos] - b[pos];
}
