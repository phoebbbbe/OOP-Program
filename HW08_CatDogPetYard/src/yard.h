#ifndef YARD_H
#define YARD_H

#include <vector>

#include "pet.h"


class Yard {
public:
  Yard() = default;


  template<typename Condition>
  std::vector<Pet *> getPetWithCondition(Condition cond) {
    std::vector<Pet *> pets_in_cond;
    for (Pet * pet : _pets) {
      if (cond(pet)) {
        pets_in_cond.push_back(pet);
      }
    }
    return pets_in_cond;
  }

private:
  std::vector<Pet *> _pets;

};


#endif /* end of include guard: YARD_H */
