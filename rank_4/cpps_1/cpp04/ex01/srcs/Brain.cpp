#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &src) {
    std::cout << "Brain copy constructor called" << std::endl;
    
    int i = 0;
    while (i < nb_ideas) {
        this->ideas[i] = src.ideas[i];  // Deep copy each idea from the source
        i++;
    }
}


Brain & Brain::operator=(const Brain & src)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &src)
    {
        int i = 0;
        while (i < nb_ideas)
        {
            this->ideas[i] = src.ideas[i];
            i++;
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string & idea)
{
    if (index >= 0 && index < nb_ideas)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < nb_ideas)
        return ideas[index];
    return "";
}
