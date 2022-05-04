#ifndef DOT_H
#define DOT_H

#include <string>

// use array to represent the vector in mathematics
// e.g., let double u[2] = {1, 2}, v[2] = {3, 4},
//       then dot(u, 2, v, 2) = 11

double dot(double *u, int dim_u, double *v, int dim_v) {

  // shouldn't have different dimensions and negative dimension
  if (dim_u != dim_v || dim_u < 0 || dim_v < 0) 
  {
    throw std::string("undefined.");
  }

  // compute the inner product of two vectors
  double result = 0;
  // for (...) { ... }
  for(int i = 0; i < dim_u; i++)
  {
    result += u[i]*v[i];
  }

  return result;
} // end of dot

#endif // end of include guard: DOT_H
