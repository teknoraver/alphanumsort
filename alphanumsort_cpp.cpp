#include <string>
#include <string_view>
#include <iostream>
#include <vector>
#include <algorithm>

#define LT 1
#define GE 0

std::string_view num_alphas(const std::string_view& s)
{
	int i;
	std::string_view sv { s };
	for (i = 0; s[i]; i++)
		if (std::isdigit(s[i]))
			break;

	sv.remove_suffix(sv.length() - i);

	return sv;
}

bool alphanumsort(const std::string& a_, const std::string& b_) {
	std::string_view a {a_}, b {b_};

	while (a.length() && b.length()) {
		if (std::isdigit(a[0]) != std::isdigit(b[0]))
			return a[0] < b[0];

		if (std::isdigit(a[0])) {
			size_t next_off;
			long long numa = std::stoll(a.data(), &next_off, 10);
			long long numb = std::stoll(b.data(), nullptr, 10);

			if (numa != numb)
				return numa < numb;

			a.remove_prefix(next_off);
			b.remove_prefix(next_off);
		} else {
			std::string_view alphaa = num_alphas(a);
			std::string_view alphab = num_alphas(b);

			if (alphaa != alphab)
				return alphaa < alphab;

			a.remove_prefix(alphaa.length());
			b.remove_prefix(alphaa.length());
		}
	}

	return a.length() == 0 && b.length() > 0;
}

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
