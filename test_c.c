#include <stdio.h>
#include <unistd.h>

#include "alphanumsort_c.h"

#define LT (-1)
#define EQ 0
#define GT 1

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
