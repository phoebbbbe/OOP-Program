#ifndef TOY_H
#define TOY_H
#include <string>
class Toy
{
public:
    Toy ()
    {
        _name = std::string("default_name");
    }
    Toy(const std::string &name)
    {
        _name = name;
    }
    std::string getName() const
    {
        return _name;
    }
    Toy & operator=(const Toy &other)
    {
        this->_name = other._name;
        return *this;
    }

private:
    std::string _name;
};

#endif