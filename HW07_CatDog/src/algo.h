#ifndef ALGO_H
#define ALGO_H
#include <vector>
#include "pet.h"

namespace pet_comp {
  bool largerWeight(Pet *a , Pet *b) {
    if (a->weight() < b->weight()){
      return true;
    } else {
      return false;
    }
  }
  bool longerName(Pet *a , Pet *b) {
    if (a->name().size() < b->name().size()) {
      return true;
    } else {
      return false;
    }
  }
}

template<typename ForwardIterator, typename Compare>
ForwardIterator maxPet(ForwardIterator first, ForwardIterator last, Compare comp) {
  ForwardIterator largest = first;
  while (first != last) {
    if (comp(*largest, *first)) {
      largest = first;
    }
    ++first;
  }
  return largest;
}


#endif /* end of include guard: ALGO_H */
