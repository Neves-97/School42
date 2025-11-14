#include "../incs/easyfind.hpp"

int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7};
	int target;
	{
		std::vector<int> vec1(array, array + (sizeof(array) / sizeof(*array)));
		try
		{
			target = 3;
			std::vector<int>::iterator it = easyfind(vec1, target);
			std::cout << "target found-> " << *it << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << "-> " << target << std::endl;
		}
		try
		{
			target = -1;
			std::vector<int>::iterator it = easyfind(vec1, target);
			std::cout << "target found-> " << *it << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << "-> " << target << std::endl;
		}
		try
		{
			target = 8;
			std::vector<int>::iterator it = easyfind(vec1, target);
			std::cout << "target found-> " << *it << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << "-> " << target << std::endl;
		}
		try
		{
			target = 7;
			std::vector<int>::iterator it = easyfind(vec1, target);
			std::cout << "target found-> " << *it << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << "-> " << target << std::endl;
		}
		
	}
}