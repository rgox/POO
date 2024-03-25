#ifndef VECTOR_HPP
#define VECTOR_HPP
// Alexandre Coninx
// ISIR CNRS/UPMC
// 22/03/2017

#include "matrix.hpp"

template<typename T>
class Vector: public Matrix<T>
{
public:
	Vector(size_t size): Matrix<T>(size,1) {} // A vector is a matrix with 1 column
	T& operator[](size_t i);
	const T& operator[](size_t i) const;
	double norm() const;
	T inner(const Vector<T>& v) const;
	inline T dot(const Vector<T>& v) const {return inner(v);} // dot (scalar) product == inner product
	Matrix<T> outer(const Vector<T>& v) const;
	Vector<T> cross(const Vector<T>& v) const;
	inline size_t get_size() const {return this->rows;} // vector size == number of rows
	//static
	static Vector<T> randvec(size_t size);
};



/*
 * Mutator
 * i: element index
 */

template<typename T>
T& Vector<T>::operator[](size_t i)
{
	assert(i<this->rows);
	return this->data[i];
}

/*
 * Accessor
 * i: element index
 */
template<typename T>
const T& Vector<T>::operator[](size_t i) const
{
	assert(i<this->rows);
	return this->data[i];
}

/*
 * Vector norm
 */

template<typename T>
double Vector<T>::norm() const
{
	T sum = 0.;
	for(int i = 0 ; i < this->rows ; i++)
		sum += this->data[i]*this->data[i];
	return sqrt(sum);
}

/*
 * Inner product of two vectors
 */

template<typename T>
T Vector<T>::inner(const Vector<T>& v) const
{
	assert(this->rows == v.get_size()); // vectors must have same size
	T sum = 0.;
	for(int i = 0 ; i < this->rows ; i++)
		sum += this->data[i]*v[i];
	return sum;
}

/*
 * Outer product of two vectors
 */

template<typename T>
Matrix<T> Vector<T>::outer(const Vector<T>& v) const
{
	Matrix<T> m(this->rows, v.get_size());
	for(int i = 0 ; i < this->rows ; i++)
	{
		for(int j = 0 ; j < v.get_size() ; j++)
		{
			m(i,j) = this->data[i] * v[j];
		}
	}
	return m;
}

/*
 * Cross product of two dim 3 vectors
 */

template<typename T>
Vector<T> Vector<T>::cross(const Vector<T>& v) const
{
	assert(this->rows == 3 && v.get_size() == 3);
	Vector<T> out(3);
	out[0] = this->data[1]*v[2] - this->data[2]*v[1];
	out[1] = this->data[2]*v[0] - this->data[0]*v[2];
	out[2] = this->data[0]*v[1] - this->data[1]*v[0];
	return out;
}


/**** Statics ****/

/*
 * Random vector of a given size
 * Data is in [0;1]
 */

template<typename T>
Vector<T> Vector<T>::randvec(size_t size)
{
	Vector<T> v(size);
	for(int i = 0 ; i < size ; i++)
		v[i] =  static_cast<T>((double)rand() / RAND_MAX);
	return v;
}



#endif // VECTOR_HPP

