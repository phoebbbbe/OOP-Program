#ifndef DOG_H
#define DOG_H

#include <stdexcept>
#include <string>

#include "pet.h"


class Dog : public Pet {
public:

  /*  add and modify your code from assignment 8  */

  static int amount() {
    return _amount;
  }

private:
  static int _amount;

};

int Dog::_amount = 0;


#endif /* end of include guard: DOG_H */
