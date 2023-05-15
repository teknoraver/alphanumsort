#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#define LT (-1)
#define EQ 0
#define GT 1

static int num_alphas(const char *s)
{
	int i;
	for (i = 0; s[i]; i++)
		if (isdigit(s[i]))
			break;
	return i;
}

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

struct {
	const char *a;
	int res;
	const char *b;
} tests[] = {
	{ "1", LT, "2" },
	{ "", LT, "a" },
	{ "1", GT, "" },
	{ "a", LT, "d" },
	{ "e", GT, "d" },
	{ "Hi", LT, "Hi All" },
	{ "1", LT, "4" },
	{ "5", LT, "12" },
	{ "U2", GT, "U" },
	{ "100", GT, "99" },
	{ "floor", LT, "floor1" },
	{ "floor1", LT, "floor2" },
	{ "floor3", LT, "floor10" },
	{ "floor10b", GT, "floor10a" },
	{ "floor10b", GT, "floor10" },
	{ "Win95", LT, "Win98" },
	{ "Win98", LT, "Win2000" },
	{ "Win2000", LT, "WinXP" },
	{ "WinXP", GT, "Win7" },
	{ "Win95", GT, "Win10" },
	{ "floor10b", GT, "floor10" },
	{ "", EQ, "" },
	{ "11", EQ, "11" },
	{ "zz", EQ, "zz" },
	{ "a1", EQ, "a1" },
	{ "1a", EQ, "1a" },
	{ "2way", EQ, "2way" },
};

void test(void)
{
	int i;
	for (i = 0; i < sizeof(tests) / sizeof(*tests); i++) {
		int res = alphanumsort(&tests[i].a, &tests[i].b);
		if (res < 0)
			res = LT;
		else if (res > 0)
			res = GT;

		if (res != tests[i].res)
			printf("FAIL: cmp(%s, %s): expected %d, got %d\n",
				tests[i].a, tests[i].b, tests[i].res, res);
	}
}




int main(int argc, char *argv[])
{
	test();

	qsort(argv + 1, argc - 1, sizeof(*argv), alphanumsort);

	while(*(++argv))
		puts(*argv);
			
	return 0;
}
