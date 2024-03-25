// Alexandre Coninx
// ISIR CNRS/UPMC
// 22/03/2017

#include "vector.hpp"
#include <cmath> //sqrt
#include <cassert>
#include <random>

/*
 * Mutator
 * i: element index
 */
double& Vector::operator[](size_t i)
{
	assert(i<rows);
	return data[i];
}

/*
 * Accessor
 * i: element index
 */
const double& Vector::operator[](size_t i) const
{
	assert(i<rows);
	return data[i];
}

/*
 * Vector norm
 */
double Vector::norm() const
{
	double sum = 0.;
	for(int i = 0 ; i < rows ; i++)
		sum += data[i]*data[i];
	return sqrt(sum);
}

/*
 * Inner product of two vectors
 */
double Vector::inner(const Vector& v) const
{
	assert(rows == v.get_size()); // vectors must have same size
	double sum = 0.;
	for(int i = 0 ; i < rows ; i++)
		sum += data[i]*v[i];
	return sum;
}

/*
 * Vector product (in dim 3)
 */
Vector Vector::operator*(const Vector& v) const
{
	assert(rows == 3); // both vectors must be 3D
	assert(v.get_size() == 3); // both vectors must be 3D
	Vector out(3);
	out[0] = data[1]*v[2] - data[2]*v[1];
	out[1] = data[2]*v[0] - data[0]*v[2];
	out[2] = data[0]*v[1] - data[1]*v[0];
	return out;
}

/*
 * Outer product of two vectors
 */
Matrix Vector::outer(const Vector& v) const
{
	Matrix m(rows, v.get_size());
	for(int i = 0 ; i < rows ; i++)
	{
		for(int j = 0 ; j < v.get_size() ; j++)
		{
			m(i,j) = data[i] * v[j];
		}
	}
	return m;
}
/**** Statics ****/

/*
 * Random vector of a given size
 * Data is in [0;1]
 */
Vector Vector::randvec(size_t size)
{
	Vector v(size);
	for(int i = 0 ; i < size ; i++)
		v[i] =  (double)rand() / RAND_MAX;
	return v;
}

