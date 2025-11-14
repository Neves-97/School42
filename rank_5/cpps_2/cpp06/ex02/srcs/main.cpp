#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *gererate(void)
{
    srand(time(NULL));
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Type is B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Type is C" << std::endl;
}

void	identify(Base& p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Type is A" << std::endl;
	}
	catch(const std::exception& e) {
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Type is B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Type is C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}

int main()
{
	srand(time(NULL));
	Base *base = gererate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}

// You're passing the address of a pointer (Base**) instead of the pointer itself (Base*).
// In your main() function, base is already a pointer:
// Base *base = gererate();



// dynamic casting