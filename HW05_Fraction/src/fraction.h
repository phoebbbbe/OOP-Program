#ifndef FRACTION_H
#define FRACTION_H
#include <string>
#include <cmath>
#include "gcd.h"

class Fraction 
{
public:

  // default value is +0/1
  // i.e., _sign='+', _numerator=0, _denominator=1
  Fraction() 
  {
    _numerator = 0;
    _denominator = 1;
    _sign = '+';
  }

  // default value is an integer (denominator=1)
  // e.g., Fraction f(-3) has its _sign='-', _numerator=3, _denominator=1
  Fraction(int num) 
  {
    _numerator = abs(num);
    _denominator = 1;
    if (num >= 0)
      _sign = '+';
    else
      _sign = '-';
  }

  // hint: use gcd
  // throw exception when the denominator is 0
  Fraction(int numerator, int denominator) 
  {
    if(denominator == 0)
      throw std::string("divided by zero.");
    
    int reduct = gcd(numerator, denominator);
    _numerator = abs(numerator) / reduct;
    _denominator = abs(denominator) / reduct;
    
    if (not(numerator < 0 and denominator < 0) and not((numerator > 0 and denominator > 0)))
      _sign = '-';
    else
      _sign = '+';

    if(_numerator == 0)
    { 
      _denominator = 1;
      _sign = '+'
    }
  }

  // get the numerator of the fraction
  int numerator() const 
  {
    return _numerator;
  }

  // get the denominator of the fraction
  int denominator() const 
  {
    return _denominator;
  }

  // get positive or negative sign of the fraction
  char sign() const 
  {
    return _sign;
  }

  // display the fraction by string
  std::string toString() const 
  {
    std::string str;
    if (this->_sign == '+')
    {
      str = std::to_string(this->_numerator) + '/' + std::to_string(this->_denominator);
      if(this->_denominator == 1)
      {
        str =std::to_string(this->_numerator);
      }
    }
    else 
    {
      str = this->_sign + std::to_string(this->_numerator) + '/' + std::to_string(this->_denominator);
      if(this->_denominator == 1)
      {
        str =this->_sign + std::to_string(this->_numerator);
      }
    }
    return str;
  }

  Fraction plus(Fraction const &f1, Fraction const &f2) const
  {
    Fraction r = Fraction();
    if (f1._denominator == f2._denominator)
    {
      r._denominator = f1._denominator;
      r._numerator = f1._numerator - f2._numerator;
    }
    else
    {
      r._denominator = f1._denominator * f2._denominator;
      r._numerator = f1._numerator * f2._denominator - f2._numerator * f1._denominator;
    }
    return r;
  }

  Fraction add(Fraction const &f1, Fraction const &f2) const
  {
    Fraction r = Fraction();
    if (f1._denominator == f2._denominator)
    {
      r._denominator = f1._denominator;
      r._numerator = f1._numerator + f2._numerator;
    }
    else
    {
      r._denominator = f1._denominator * f2._denominator;
      r._numerator = f1._numerator * f2._denominator + f2._numerator * f1._denominator;
    }
    return r;
  }
  // addition of two Fractions
  Fraction operator + (Fraction const & f) const 
  {
    Fraction r = Fraction();
    if (this->_sign != f._sign)
    {
      if ((this->_numerator / this->_denominator) > (f._numerator / f._denominator))
      {
        r = plus(*this, f);
        r._sign = this->_sign;
      }
      else
      {
        r = plus(f, *this);
        r._sign = f._sign;
      }
    }
    else
    {
      r = add(*this, f);
      r._sign = this->_sign;
    }
    int reduct = gcd(r._numerator, r._denominator);
    r._numerator /= reduct;
    r._denominator /= reduct;
    return r;
  }

  // subtraction of two Fractions
  Fraction operator - (Fraction const & f) const 
  {
    Fraction r = Fraction();
    if (this->_sign == f._sign)
    {
      if ((this->_numerator / this->_denominator) > (f._numerator / f._denominator))
      {
        r = plus(*this, f);
        r._sign = this->_sign;
      }
      else
      {
        r = plus(f, *this);
        if(this->_sign == '+')
          r._sign = '-';
        else
          r._sign = '+';
      }
    }
    else
    {
      r = add(*this, f);
      r._sign = this->_sign;
    }

    if(r._numerator == 0)
    {
      r._sign = '+';
      r._denominator = 1;
    }
    else
    {
      int reduct = gcd(r._numerator, r._denominator);
      r._numerator /= reduct;
      r._denominator /= reduct;
    }
    return r;
  }

  // division of two Fractions
  Fraction operator / (Fraction const & f) const 
  {
    if(f._numerator == 0)
    {
      throw std::string("divided by zero.");
    }
    Fraction r = Fraction();
    r._numerator = this->_numerator * f._denominator;
    r._denominator = this->_denominator * f._numerator;
    if(this->_sign == f._sign)
      r._sign = '+';
    else
      r._sign = '-';

    if(r._numerator == 0)
    {
      r._sign = '+';
      r._denominator = 1;
    }
    else
    {
      int reduct = gcd(r._numerator, r._denominator);
      r._numerator /= reduct;
      r._denominator /= reduct;
    }
    return r;
  }

private:
  // both numerator and denominator should be positive
  int _numerator;
  int _denominator;
  char _sign;
};
#endif