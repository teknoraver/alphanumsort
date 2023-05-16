#pragma once

#include <string>
#include <string_view>

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
