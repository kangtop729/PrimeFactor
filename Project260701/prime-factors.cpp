#pragma once
#include <vector>

class PrimeFactors {
public:
	static std::vector<int> of(int n) {
		std::vector<int> factors;

		for (; n % 2 == 0; n /= 2)
			factors.push_back(2);

		for (int d = 3; (long long)d * d <= n; d += 2)
			for (; n % d == 0; n /= d)
				factors.push_back(d);

		if (n > 1)
			factors.push_back(n);

		return factors;
	}
};
