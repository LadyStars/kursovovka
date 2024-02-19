#include <UnitTest++/UnitTest++.h>
#include "Counter.h"
#include <iostream>
#include <string>

using namespace std;


SUITE(meanTest)
{
	TEST(Default) {
		std::vector<int16_t> arr ={10, 20 ,30};
		CHECK_EQUAL(60,*( Counter().summ(arr)));
	}
	TEST(Negative) {
		std::vector<int16_t> arr ={-90, -80 ,-70};
		CHECK_EQUAL(-240,*( Counter().summ(arr)));
	}
	TEST(MaximumPositive) {
		std::vector<int16_t> arr ={32767, 32767 ,32767};
		CHECK_EQUAL(32765,*( Counter().summ(arr)));
	}
	TEST(MaximumNegative) {
		std::vector<int16_t> arr ={-32768, -32768, -32768};
		CHECK_EQUAL(-32768,*( Counter().summ(arr)));
	}
	TEST(Zero) {
		std::vector<int16_t> arr ={0, 0, 0, 0};
		CHECK_EQUAL(0,*( Counter().summ(arr)));
	}
	TEST(Owerflow) {
			std::vector<int16_t> arr ={};
		CHECK_THROW(Counter().summ(arr),server_error);
	}
}


int main()
{
	return UnitTest::RunAllTests();
}
