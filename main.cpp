#include <concepts>
#include <stdint.h>
#include "src/core/math/trig.hpp"
template <std::integral T>
T calcSomething(T input)
{
	return (input + input) * input * input * input;
}
int main()
{
	l2d_cpp::Triangle t1;
	int k = 10;
	uint16_t kk = 7;
	float f = 2.3f;
	calcSomething<int>(k);
	calcSomething<uint16_t>(kk);

	return 1;
}