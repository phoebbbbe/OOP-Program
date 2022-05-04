#ifndef VECTOR_SPACE_H
#define VECTOR_SPACE_H
#include <cmath>

double *add(double u[], int dim_u, double v[], int dim_v)
{
    if(dim_u <= 0 || dim_v <= 0)
    {
        throw std::string("undefined.");
    }
    double *w = new double[dim_u];
    if(dim_u == dim_v)
    {
        for(int i = 0; i < dim_u; i++)
        {
            w[i] = u[i] + v[i];
        }
    }
    else
    {
        delete [] w;
        throw std::string("undefined.");
    }
    return w;
}

double *scale(double u[], int dim, double n)
{
    if(dim <= 0)
    {
        throw std::string("undefined.");
    }
    double *w = new double[dim];
    for(int i = 0; i < dim; i ++)
    {
        w[i] = u[i] * n;
    }
    return w;
}

#endif