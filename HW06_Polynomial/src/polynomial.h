#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <algorithm>
#include <string>
#include "term.h"

class Polynomial {
public:

  Polynomial () {}
  Polynomial(std::vector<Term> terms, int degree) 
  {
    for(int i = 0; i <= degree; i++)
    {
      Term tmp;
      int target = -1;
      for(int j = 0; j < terms.size(); j++)
      {
        if(terms[j].exponent() == i)
        {
          if(target == -1)
            target = j;
          else
            throw std::string("duplicate term.");
        }
      }
      if(target == -1)
        tmp = Term(0.0 , i);
      else
        tmp = Term(terms[target].coefficient(), i);
      _terms.push_back(tmp);
    }
    _degree = degree;
  }

  // get a term by exponent
  // If the term does not exist, return the term (0, exponent)
  Term term(int exponent) const 
  {
    Term tmp;
    int target = -1;
    for(int j = 0; j < this->_terms.size(); j++)
    {
      if(this->_terms[j].exponent() == exponent)
      {
        if(target == -1)
          target = j;
      }
    }
    if(target == -1)
      tmp = Term(0.0 , exponent);
    else
      tmp = Term(this->_terms[target].coefficient(), exponent);
    return tmp;
  }

  // get the degree
  int degree() const 
  {
    return _degree;
  }

  // add two polynomials
  Polynomial operator+ (const Polynomial & q) const 
  {
    Polynomial pmp = Polynomial();
    if(this->degree() > q.degree())
      pmp._degree  = this->degree();
    else
      pmp._degree = q.degree();
    for(int i = 0; i <= pmp._degree; i++)
      pmp._terms.push_back(this->term(i) + q.term(i));
    while(pmp.term(pmp._degree).isZero() and pmp._degree != 0)
    {
      pmp._degree --;
    }
    return pmp;
  }

  // multiply by a term
  Polynomial operator* (Term t) const 
  {
    Polynomial pmp = Polynomial();
    pmp._degree = this->degree() + t.exponent();
    for(int i = 0; i <= pmp._degree; i++)
      pmp._terms.push_back(this->term(i) * t);
    return pmp;
  }

  // multiply by another Polynomial
  Polynomial operator* (const Polynomial & q) const 
  {
    Polynomial pmp = Polynomial();
    pmp._degree  = this->degree() + q.degree();
    for(int i = this->degree(); i >=0; i--)
    {
      Polynomial pp = Polynomial();
      for(int j = 0; j <= q.degree(); j++)
        pp._terms.push_back(this->term(i) * q.term(j));
      pmp = pmp + pp;
    }
    return pmp;
  }

private:
  std::vector<Term> _terms;
  int _degree;

};

#endif
