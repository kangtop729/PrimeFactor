#include <vector>
#include <iostream>
using std::vector;
using std::cout;
class PrimeFactors {
public:
	vector<int> of(int number) {
		vector<int> result = {};
		int divisor = 2;
		while(number != 1){
			if (number % divisor == 0) {
				result.push_back(divisor);
				number /= divisor;
			}
			else {
				divisor++;
			}
		}
		return result;
	}
};