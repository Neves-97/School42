#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
    public:
        Brain();
        Brain(const Brain & src);
        Brain & operator=(const Brain & src);
        ~Brain();
        void setIdea(int index, const std::string & idea);
        std::string getIdea(int index) const;

    private:
        static const int nb_ideas = 100;
        std::string ideas[nb_ideas];
};

#endif
