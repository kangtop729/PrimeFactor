#include <vector>
#include <iostream>
using std::vector;
using std::cout;
class PrimeFactors {
public:
	vector<int> of(int i) {
		vector<int> result = {};
		for (int n = 2; n <= i/2 + 1; n++) {
			if (i % n == 0) {
				result.push_back(n);
			}
		}
		return result;
	}
};