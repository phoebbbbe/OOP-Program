#ifndef CAT_H
#define CAT_H

#include <stdexcept>
#include <string>

#include "pet.h"


class Cat : public Pet {
public:

  /*  add and modify your code from assignment 8  */

  static int amount() {
    return _amount;
  }

private:
  static int _amount;

};

int Cat::_amount = 0;


#endif /* end of include guard: CAT_H */
