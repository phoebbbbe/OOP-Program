#ifndef CAT_H
#define CAT_H
#include <string>

class Cat {
public:

  Cat(const std::string &name, const double &weight) 
  {
    _name = name;
    _weight = weight;
    _toyAmount = 0;
    _toyCollections = new std::string [_toyAmount];
  }

  ~Cat() 
  {
    delete [] _toyCollections;
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

  void addNewToy(const std::string &toyName) 
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
  }

  std::string getToy(const int &index) const
  {
    if (index >= _toyAmount)
    {
      throw std::string("undefined.");
    }
    return _toyCollections[index];
  }

private:
  std::string _name;
  double _weight;
  std::string * _toyCollections;
  int _toyAmount;

};

#endif
