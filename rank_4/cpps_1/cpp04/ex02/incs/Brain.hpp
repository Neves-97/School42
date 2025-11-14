#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
    public:
        Brain();                            // Default constructor
        Brain(const Brain & src);           // Copy constructor
        ~Brain();                           // Destructor

        Brain & operator=(const Brain & src); // Assignment operator

        void setIdea(int index, const std::string & idea);
        std::string getIdea(int index) const;

    private:
        static const int nb_ideas = 100;
        std::string ideas[nb_ideas];
};

#endif
