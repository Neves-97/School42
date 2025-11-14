#include "../incs/FragTrap.hpp"

int main() {

    FragTrap fragname1("Davido");
    FragTrap fragname2("Lucy");

    fragname1.attack("aimlesstool");
    fragname1.takeDamage(40);
    fragname1.beRepaired(20);
    fragname1.highFivesGuys();

    fragname2.attack("balancelessstool");
    fragname2.takeDamage(70);
    fragname2.beRepaired(50);
    fragname2.highFivesGuys();


    fragname2.takeDamage(50);
    fragname2.beRepaired(100);

    std::cout << fragname1.getName() << " has " << fragname1.getHitPoints() << " hit points and " << fragname1.getEnergyPoints() << " energy points." << std::endl;
    std::cout << fragname2.getName() << " has " << fragname2.getHitPoints() << " hit points and " << fragname2.getEnergyPoints() << " energy points." << std::endl;

    return 0;
}
