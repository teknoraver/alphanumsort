#pragma once

#include <string>
#include <string_view>

bool alphanumsort(const std::string& a_, const std::string& b_) {
	std::string_view a {a_}, b {b_};

	while (a.length() && b.length()) {
		if (isdigit(a[0]) && isdigit(b[0])) {
			size_t next_off;
			unsigned long long numa = std::stoull(a.data(), &next_off, 10);
			unsigned long long numb = std::stoull(b.data(), nullptr, 10);

			if (numa != numb)
				return numa < numb;

			a.remove_prefix(next_off);
			b.remove_prefix(next_off);
		} else {
			if (a[0] != b[0])
				return a[0] < b[0];

			a.remove_prefix(1);
			b.remove_prefix(1);
		}
	}

	return b.length();
}
