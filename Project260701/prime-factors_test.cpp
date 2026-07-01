#include "gmock/gmock.h"
#include "prime-factors.cpp"

using namespace testing;
using std::vector;

struct PrimeParam {
	int         input;
	vector<int> expected;
};

class PrimeFixture : public TestWithParam<PrimeParam> {};

TEST_P(PrimeFixture, Of) {
	EXPECT_EQ(GetParam().expected, PrimeFactors::of(GetParam().input));
}

INSTANTIATE_TEST_SUITE_P(PrimeFactorsTests, PrimeFixture, Values(
	PrimeParam{ 1,          vector<int>{}                                                         },
	PrimeParam{ 2,          vector<int>{2}                                                        },
	PrimeParam{ 3,          vector<int>{3}                                                        },
	PrimeParam{ 4,          vector<int>{2,2}                                                      },
	PrimeParam{ 6,          vector<int>{2,3}                                                      },
	PrimeParam{ 9,          vector<int>{3,3}                                                      },
	PrimeParam{ 12,         vector<int>{2,2,3}                                                    },
	// 큰 수 (10억 이상)
	PrimeParam{ 1000000000, vector<int>{2,2,2,2,2,2,2,2,2, 5,5,5,5,5,5,5,5,5}                   }, // 2^9  x 5^9
	PrimeParam{ 1073741824, vector<int>{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2} }, // 2^30
	PrimeParam{ 1500000000, vector<int>{2,2,2,2,2,2,2,2, 3, 5,5,5,5,5,5,5,5,5}                  }, // 2^8  x 3 x 5^9
	PrimeParam{ 2000000000, vector<int>{2,2,2,2,2,2,2,2,2,2, 5,5,5,5,5,5,5,5,5}                 }, // 2^10 x 5^9
	PrimeParam{ 2147483647, vector<int>{2147483647}                                               }  // Mersenne 소수 (2^31 - 1)
));
