#include "../incs/ScavTrap.hpp"

int main() {

    ScavTrap scav1("Ichigo");
    ScavTrap scav2("Bankai");
    ClapTrap clap1("Kenpachi");

    scav1.attack("FIRST");
    scav1.takeDamage(25);
    scav1.beRepaired(15);

    scav2.guardGate();
    scav2.attack("SECOND");
    scav2.takeDamage(50);
    scav2.beRepaired(30);

    clap1.attack("THIRD");
    clap1.takeDamage(10);
    clap1.beRepaired(10);
    
    for (int i = 0; i < 5; i++) {
        std::string enemyName = "lilmosey";
        enemyName += ('0' + (i + 1));
        scav2.attack(enemyName);  
    }

    for (int i = 0; i < 5; i++) {
        std::string nameEnemy = "lilmosey";
        nameEnemy += ('0' + (i + 1));
        clap1.attack(nameEnemy);  
    }

    std::cout << scav1.getName() << " has " << scav1.getHitPoints() << " hit points and " << scav1.getEnergyPoints() << " energy points." << std::endl;
    std::cout << scav2.getName() << " has " << scav2.getHitPoints() << " hit points and " << scav2.getEnergyPoints() << " energy points." << std::endl;
    std::cout << clap1.getName() << " has " << clap1.getHitPoints() << " hit points and " << clap1.getEnergyPoints() << " energy points." << std::endl;
    return 0;
}
