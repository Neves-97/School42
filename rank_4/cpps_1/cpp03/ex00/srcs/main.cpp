#include "../incs/ClapTrap.hpp"

int main() {
    ClapTrap first("Ichigo");
    ClapTrap second("Bankai");

    first.attack("");
    first.takeDamage(7);
    first.beRepaired(5);
    first.attack("Ulquiorra");

    second.attack("Grimjow");
    second.takeDamage(10);
    second.beRepaired(6);
    second.takeDamage(5);

    std::cout << first.getName() << " has " << first.getHitPoints() << " hit points and " << first.getEnergyPoints() << " energy points." << std::endl;
    std::cout << second.getName() << " has " << second.getHitPoints() << " hit points and " << second.getEnergyPoints() << " energy points." << std::endl;

    return 0;
}

















// std::cout << "\e[1;31mRed Text\033[0m" << std::endl;       // Red
// std::cout << "\e[1;32mGreen Text\033[0m" << std::endl;     // Green
// std::cout << "\e[1;33mYellow Text\033[0m" << std::endl;    // Yellow
// std::cout << "\e[1;34mBlue Text\033[0m" << std::endl;      // Blue
// std::cout << "\e[1;36mCyan Text\033[0m" << std::endl;      // Cyan
// std::cout << "\e[1;37mWhite Text\033[0m" << std::endl;     // White
// std::cout << "\e[0;30mBlack Text\033[0m" << std::endl;     // Black
// std::cout << "\e[0;31mDark Red Text\033[0m" << std::endl;  // Dark Red
// std::cout << "\e[0;32mDark Green Text\033[0m" << std::endl;// Dark Green
// std::cout << "\e[0;33mBrown Text\033[0m" << std::endl;     // Brown
// std::cout << "\e[0;34mDark Blue Text\033[0m" << std::endl; // Dark Blue
// std::cout << "\e[0;35mMagenta Text\033[0m" << std::endl;   // Magenta
// std::cout << "\e[0;36mLight Cyan Text\033[0m" << std::endl;// Light Cyan
// std::cout << "\e[0;37mGray Text\033[0m" << std::endl;      // Gray
// std::cout << "\e[1;90mBright Black Text\033[0m" << std::endl; // Bright Black
// std::cout << "\e[1;91mBright Red Text\033[0m" << std::endl;   // Bright Red
// std::cout << "\e[1;92mBright Green Text\033[0m" << std::endl; // Bright Green
// std::cout << "\e[1;93mBright Yellow Text\033[0m" << std::endl;// Bright Yellow
// std::cout << "\e[1;94mBright Blue Text\033[0m" << std::endl;  // Bright Blue
// std::cout << "\e[1;95mBright Magenta Text\033[0m" << std::endl;// Bright Magenta
// std::cout << "\e[1;96mBright Cyan Text\033[0m" << std::endl;  // Bright Cyan
