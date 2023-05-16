#include <iostream>
#include <vector>
#include <algorithm>

#include "alphanumsort_cpp.h"

#define LT 1
#define GE 0

struct {
	const char *a;
	bool res;
	const char *b;
} tests[] {
	{ "1", LT, "2" },
	{ "", LT, "a" },
	{ "1", GE, "" },
	{ "a", LT, "d" },
	{ "e", GE, "d" },
	{ "Hi", LT, "Hi All" },
	{ "1", LT, "4" },
	{ "5", LT, "12" },
	{ "U2", GE, "U" },
	{ "100", GE, "99" },
	{ "floor", LT, "floor1" },
	{ "floor1", LT, "floor2" },
	{ "floor3", LT, "floor10" },
	{ "floor10b", GE, "floor10a" },
	{ "floor10b", GE, "floor10" },
	{ "Win95", LT, "Win98" },
	{ "Win98", LT, "Win2000" },
	{ "Win2000", LT, "WinXP" },
	{ "WinXP", GE, "Win7" },
	{ "Win95", GE, "Win10" },
	{ "floor10b", GE, "floor10" },
	{ "", GE, "" },
	{ "11", GE, "11" },
	{ "zz", GE, "zz" },
	{ "a1", GE, "a1" },
	{ "1a", GE, "1a" },
	{ "2way", GE, "2way" },
};

void test()
{
	for (int i = 0; i < sizeof(tests) / sizeof(*tests); i++) {
		int res = alphanumsort(tests[i].a, tests[i].b);

		if (res != tests[i].res)
			printf("FAIL: cmp(%s, %s): expected %d, got %d\n",
				tests[i].a, tests[i].b, tests[i].res, res);
	}
}


int main(int argc, char *argv[])
{
	test();
	std::vector<std::string> strings(argv + 1, argv + argc);

	std::sort(strings.begin(), strings.end(), alphanumsort);

	for (const auto&s : strings)
		std::cout << s << std::endl;

	return 0;
}
