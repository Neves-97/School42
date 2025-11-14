#include "../incs/Point.hpp"

// int main() {
//     Point a(0, 0);
//     Point b(0, 5);
//     Point c(5, 0);
//     Point point1(1, 1);
//     Point point2(5, 5);

//     std::cout << "Point inside triangle: " << bsp(a, b, c, point1) << std::endl;
//     std::cout << "Point outside triangle: " << bsp(a, b, c, point2) << std::endl;

//     return 0;
// }

int main() {
	{
		Point a(0.0f, 0.0f);
		Point b(10.0f, 0.0f);
		Point c(5.0f, 10.0f);
		Point test(5.0f, 10.0f);
		std::cout << bsp(a, b, c, test) << std::endl;
	}

	{
		Point a(0.0f, -10.0f);
		Point b(-10.0f, 3.0f);
		Point c(4.0f, 10.0f);
		Point test(0.0f, 0.0f);
		std::cout << bsp(a, b, c, test) << std::endl;
	}

	return 0;
}
