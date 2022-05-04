#ifndef CAT_H
#define CAT_H
#include <string>
#include <vector>
#include "toy.h"

class Cat {
public:
  
  Cat()
  {
  }
  Cat(const std::string &name, const double &weight) 
  {
    if (name == std::string(""))
    {
      throw std::string("undefined.");
    }
    if ( weight < 10 or weight > 50)
    {
      throw std::string("undefined.");
    }
    _name = name;
    _weight = weight;
    _toyAmount = 0;
    _toyCollections = std::vector<Toy>(_toyAmount);
  }
  // copy constructor
  Cat(Cat const &other)
  {
    _name = other._name;
    _weight = other._weight;
    _toyAmount = other._toyAmount;
    _toyCollections = std::vector<Toy>(_toyAmount);
    for(int i = 0; i < _toyAmount; i ++)
    {
      _toyCollections.at(i) = other._toyCollections.at(i);
    }

  }

  Cat & operator= (Cat const &other)
  {
    if(this != &other)
    {
      this->_name = other._name;
      this->_weight = other._weight;
      this->_toyAmount = other._toyAmount;
      this->_toyCollections = std::vector<Toy>(this->_toyAmount);
      for( int i = 0; i < this->_toyAmount; i++)
      {
        this->_toyCollections.at(i) = other._toyCollections.at(i);
      }
    }
    return *this;
  }

  std::string getName() const
  {
    return  _name;
  }

  double getWeight() const
  {
    return _weight;
  }

  int getAmount() const
  {
    return _toyAmount;
  }

 /*  void addNewToy(const std::string &toyName) 
  {
    _toyAmount = _toyAmount + 1;
    std::string *toys = new std::string [_toyAmount];
    for(int i = 0; i < _toyAmount-1; i++)
    {
      toys[i] = _toyCollections[i];
    }
    toys[_toyAmount-1] = toyName;
    delete [] _toyCollections;
    _toyCollections = toys;
    toys = nullptr;
  } */

  void addNewToy(Toy const &toyName)
  {
    _toyAmount = _toyAmount + 1;
    std::vector<Toy> toys = std::vector<Toy>(_toyAmount);
    for(int i = 0; i < _toyAmount-1; i++)
    {
      toys.at(i) = _toyCollections.at(i);
    }
    toys.at(_toyAmount-1) = toyName;
  
    _toyCollections = toys;
    toys = std::vector<Toy>();
  }

  /* std::string getToy(int index) const
  {
    if (index >= _toyAmount)
    {
      throw std::string("undefined.");
    }
    return _toyCollections[index];
  } */

  Toy getToy(int index) const
  {
    if(index < 0 or index >= _toyAmount)
    {
      throw std::string("undefined.");
    }
    return _toyCollections.at(index);
  }

  bool isHeavierThan(Cat const &other) const
  {
    if (this->_weight > other._weight)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

private:
  std::string _name;
  double _weight;
  //std::string * _toyCollections;
  std::vector<Toy> _toyCollections;
  int _toyAmount;

};

#endif
