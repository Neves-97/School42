
#include "../incs/Form.hpp"

void	test(std::string test_type, std::string name, int grade, std::string form) {
	if (test_type == "b_range")
		std::cout << "Creating " << name << " with a grade of " << grade << ":\t";
	else if (test_type == "increment")
		std::cout << "Incrementing " << name << " (prev_grade = " << grade << "):\t";
	else if (test_type == "decrement")
		std::cout << "Decrementing " << name << " (prev_grade = " << grade << "):\t";
	else if (test_type == "signing")
		std::cout << name << " signing " << form << " with grade " << grade << ":\t"; 
}

int	main() {
	std::string name;
	std::string form_name;
	int			grade;
	int			sign_grade;
	int			exec_grade;

	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "           TESTING GRADE RANGES             " << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	{
		try {
			name = "Bill";
			grade = 10;
			test("b_range", name, grade, "(nil)");
			Bureaucrat bill(name, grade);
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}

		try {
			name = "Alex";
			grade = 150;
			test("b_range", name, grade, "(nil)");
			Bureaucrat alex(name, grade);
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;;
		}

		try {
			name = "John";
			grade = -10;
			test("b_range", name, grade, "(nil)");
			Bureaucrat john(name, grade);
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}

		try {
			name = "Carl";
			grade = 151;
			test("b_range", name, grade, "(nil)");
			Bureaucrat carl(name, grade);
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}

		try {
			name = "Valid";
			test("b_range", name, 10, "(nil)");
			Form form(name, 10, 20);
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}

		try {
			name = "Invalid";
			test("b_range", name, -10, "(nil)");
			Form form(name, -10, 20);
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}

		try {
			name = "Invalid";
			test("b_range", name, 200, "(nil)");
			Form form(name, 10, 200);
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}
	}

	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "          TESTING INCREMENTATION            " << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	{
		try {
			name = "Kate";
			grade = 10;
			test("increment", name, grade, "(nil)");
			Bureaucrat bill(name, grade);
			bill.incrementGrade();
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}

		try {
			name = "Jack";
			grade = 1;
			test("increment", name, grade, "(nil)");
			Bureaucrat jack(name, grade);
			jack.incrementGrade();
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}
	}

	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "          TESTING DECREMENTATION            " << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	{
		try {
			name = "Anna";
			grade = 10;
			test("decrement", name, grade, "(nil)");
			Bureaucrat bill(name, grade);
			bill.decrementGrade();
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}

		try {
			name = "Buck";
			grade = 150;
			test("decrement", name, grade, "(nil)");
			Bureaucrat jack(name, grade);
			jack.decrementGrade();
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}
	}

	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "            TESTING SIGNING             " << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	{
		{
			name = "Liam";
			grade = 10;
			form_name = "NJ-3592";
			sign_grade = 11;
			exec_grade = 1;
			test("signing", name, grade, form_name);
			Bureaucrat burr(name, grade);
			Form form(form_name, sign_grade, exec_grade);
			burr.signForm(form);
		}

		{
			name = "Noah";
			grade = 10;
			form_name = "GD-412";
			sign_grade = 5;
			exec_grade = 1;
			test("signing", name, grade, form_name);
			Bureaucrat burr(name, grade);
			Form form(form_name, sign_grade, exec_grade);
			burr.signForm(form);
		}
	}
	std::cout << std::endl;
	return 0;
}