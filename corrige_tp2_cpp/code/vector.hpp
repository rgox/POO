#ifndef VECTOR_HPP
#define VECTOR_HPP
// Alexandre Coninx
// ISIR CNRS/UPMC
// 22/03/2017

#include "matrix.hpp"

class Vector: public Matrix
{
public:
	Vector(size_t size): Matrix(size,1) {} // A vector is a matrix with 1 column
	double& operator[](size_t i);
	const double& operator[](size_t i) const;
	Vector operator*(const Vector& v) const;
	double norm() const;
	double inner(const Vector& v) const;
	inline double dot(const Vector& v) const {return inner(v);} // dot (scalar) product == inner product
	Matrix outer(const Vector& v) const;
	inline size_t get_size() const {return rows;} // vector size == number of rows
	//static
	static Vector randvec(size_t size);
};


#endif // VECTOR_HPP

