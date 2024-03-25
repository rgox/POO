#ifndef MATRIX_HPP
#define MATRIX_HPP
// Alexandre Coninx
// ISIR CNRS/UPMC
// 22/03/2017

#include <cstddef> // size_t
#include <ostream>
#include <cassert>
#include <random>

template<typename T>
class Vector; // forward declaration


// Template version
template<typename T>
class Matrix
{
public:
	//Constructors
	Matrix(size_t r, size_t c);
	Matrix(size_t size);
	Matrix(const Matrix<T>& m);
	//Destructor
	~Matrix();
	//Attribution
	Matrix<T>& operator=(const Matrix<T>& m);
	//Access
	const T& operator()(size_t i, size_t j) const;
	T& operator()(size_t i, size_t j);
	inline size_t get_rows() const {return rows;}
	inline size_t get_cols() const {return cols;}
	//Equality
	bool operator==(const Matrix<T>& m) const;
	bool operator!=(const Matrix<T>& m) const;
	//Maths
	Matrix<T> operator+(const Matrix<T>& m) const;
	Matrix<T> operator-(const Matrix<T>& m) const;
	Matrix<T> operator*(const Matrix<T>& m) const;
	Matrix<T> operator+(T d) const;
	Matrix<T> operator-(T d) const;
	Matrix<T> operator*(T d) const;
	Matrix<T> transpose() const;
	T trace() const;
	//Matrix-vector product
	Vector<T> operator*(const Vector<T>& v) const;
	// utility
	void fill(T d);
	// Statics
	static Matrix<T> eye(size_t size);
	static Matrix<T> randmat(size_t r, size_t c);
	static Matrix<T> randmat(size_t size);
protected:
	size_t rows;
	size_t cols;
	T* data;
};

template<typename T>
std::ostream& operator<<(std::ostream&, const Matrix<T>& m);


/*
 * Basic constructor. Initial matrix is empty (0 everywhere)
 * r: number of rows
 * c: number of cols
 */
template<typename T>
Matrix<T>::Matrix(size_t r, size_t c) : rows(r), cols(c)
{
	data = new T[r*c];
	fill(static_cast<T>(0));
}

/*
 * Square matrix constructor. Initial matrix is empty (0 everywhere)
 * size: number of rows and cols
 */
template<typename T>
Matrix<T>::Matrix(size_t size) : rows(size), cols(size)
{
	data = new T[size*size];
	fill(static_cast<T>(0));
}


/*
 * Copy constructor
 * m: matrix to copy
 */
template<typename T>
Matrix<T>::Matrix(const Matrix<T>& m)
{
	rows = m.get_rows();
	cols = m.get_cols();
	data = new T[rows*cols];
	for(int i = 0; i < rows ; i++)
	{
		for(int j = 0; j < cols ; j++)
		{
			(*this)(i,j) = m(i,j);
		}
	}
}

/*
 * Destructor
 */
template<typename T>
Matrix<T>::~Matrix()
{
	delete[] data;
}

/*
 * Assignment operator.
 * m: matrix to copy data from
 */
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& m)
{
	size_t new_r = m.get_rows();
	size_t new_c = m.get_cols();
	if(new_r != rows || new_c != cols)
	{
		delete[] data;
		data = new T[new_r*new_c];
	}
	rows = new_r;
	cols = new_c;
	for(int i = 0; i < rows ; i++)
	{
		for(int j = 0; j < cols ; j++)
		{
			(*this)(i,j) = m(i,j);
		}
	}
	return (*this);
}

/*
 * Data accessor.
 * i: row of cell to access
 * j: column of cell to access
 */
template<typename T>
const T& Matrix<T>::operator()(size_t i, size_t j) const
{
	assert(i<rows && j < cols); // check if we are in bounds
	return data[cols*i+j];
}

/*
 * Data mutator
 * i: row of cell to access
 * j: column of cell to access
 */
template<typename T>
T& Matrix<T>::operator()(size_t i, size_t j)
{
	assert(i<rows && j < cols); // check if we are in bounds
	return data[cols*i+j];
}

/*
 * Fill matrix with a number
 * d: data to fill the matrix with
 */
template<typename T>
void Matrix<T>::fill(T d)
{
	for(int i = 0; i < rows ; i++)
	{
		for(int j = 0; j < cols ; j++)
		{
			(*this)(i,j) = d;
		}
	}
}

/*
 * Equality test
 */
template<typename T>
bool Matrix<T>::operator==(const Matrix<T>& m) const {
	if(m.get_rows() != rows || m.get_cols() != cols){
		return false; // if matrices have different size they can't be equal
	} else { // if any cell differ, matrices are not equal
		for(int i = 0; i < rows ; i++)
		{
			for(int j = 0; j < cols ; j++)
			{
				if((*this)(i,j) != m(i,j))
					return false;
			}
		}
	}
	return true;
}

/*
 * Inequality test
 */
template<typename T>
bool Matrix<T>::operator!=(const Matrix<T>& m) const {
	return !(*this == m); // not equality
}


/*
 * Matrix sum
 */
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m) const
{
	assert(m.get_rows() == rows && m.get_cols() == cols); // matrices must have same size
	Matrix<T> result(rows,cols);
	for(int i = 0; i < rows ; i++)
	{
		for(int j = 0; j < cols ; j++)
		{
			result(i,j) = (*this)(i,j) + m(i,j);
		}
	}
	return result;
}

/*
 * Matrix difference
 */
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& m) const
{
	assert(m.get_rows() == rows && m.get_cols() == cols); // matrices must have same size
	Matrix<T> result(rows,cols);
	for(int i = 0; i < rows ; i++)
	{
		for(int j = 0; j < cols ; j++)
		{
			result(i,j) = (*this)(i,j) - m(i,j);
		}
	}
	return result;
}
/*
 * Matrix product
 */
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& m) const
{
	assert(cols == m.get_rows()); // inner dimensions must match
	Matrix<T> result(rows,m.get_cols());
	for(int i = 0; i < rows ; i++)
	{
		for(int j = 0; j < m.get_cols() ; j++)
		{
			result(i,j) = 0.;
			for(int k = 0; k < cols ; k++)
				result(i,j) += (*this)(i,k)*m(k,j);
		}
	}
	return result;
}

/*
 * Matrix-vector product, returns a vector.
 */
template<typename T>
Vector<T> Matrix<T>::operator*(const Vector<T>& v) const
{
	assert(cols == v.get_size()); // vector size must match cols
	Vector<T> result(rows);
	for(int i = 0; i < rows ; i++)
	{
		for(int k = 0; k < cols ; k++)
			result[i] += (*this)(i,k)*v[k];
	}
	return result;
}

/*
 * Addition of a scalar.
 */
template<typename T>
Matrix<T> Matrix<T>::operator+(T d) const
{
	Matrix<T> result(rows,cols);
	for(int i = 0; i < rows ; i++)
	{
		for(int j = 0; j < cols ; j++)
		{
			result(i,j) = (*this)(i,j) + d;
		}
	}
	return result;
}

/*
 * Substraction of a scalar.
 */
template<typename T>
Matrix<T> Matrix<T>::operator-(T d) const
{
	Matrix<T> result(rows,cols);
	for(int i = 0; i < rows ; i++)
	{
		for(int j = 0; j < cols ; j++)
		{
			result(i,j) = (*this)(i,j) - d;
		}
	}
	return result;
}

/*
 * Product with a scalar.
 */
template<typename T>
Matrix<T> Matrix<T>::operator*(T d) const
{
	Matrix<T> result(rows,cols);
	for(int i = 0; i < rows ; i++)
	{
		for(int j = 0; j < cols ; j++)
		{
			result(i,j) = (*this)(i,j) * d;
		}
	}
	return result;
}

/*
 * Returns a transposed version of the matrix
 */
template<typename T>
Matrix<T> Matrix<T>::transpose() const
{
	Matrix<T> result(cols,rows);
	for(int i = 0; i < rows ; i++)
	{
		for(int j = 0; j < cols ; j++)
		{
			result(j,i) = (*this)(i,j);
		}
	}
	return result;
}

/*
 * Trace of a square matrix
 */
template<typename T>
T Matrix<T>::trace() const
{
	assert(rows==cols); // Only square matrices have a trace
	T r = 0;
	for(int i = 0; i < rows ; i++)
		r += (*this)(i,i);
	return r;
}

/*
 * Stream display operator (out of class)
 */
template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& m)
{
	for(int i = 0; i < m.get_rows() ; i++)
	{
		os<<"[";
		for(int j = 0; j < m.get_cols() ; j++)
		{
			os << m(i,j);
			if(j < m.get_cols()-1)
				os <<", ";
		}
		os<<"]" << std::endl;;
	}
	return os;
}

/**** Static members ****/

/*
 * Identity matrix
 */
template<typename T>
Matrix<T> Matrix<T>::eye(size_t size)
{
	Matrix m(size);
	for(int i = 0; i < size ; i++)
		m(i,i) = static_cast<T>(1);
	return m;
}

/*
 * Random matrix
 * Data is in [0;1]
 */
template<typename T>
Matrix<T> Matrix<T>::randmat(size_t r, size_t c)
{
	Matrix m(r,c);
	for(int i = 0 ; i < r ; i++)
	{
		for(int j = 0 ; j < c ; j++)
		{
			m(i,j) = static_cast<T>((double)rand() / RAND_MAX);
		}
	}
	return m;
}
/*
 * Random square matrix
 * Data is in [0;1]
 */
template<typename T>
Matrix<T> Matrix<T>::randmat(size_t size)
{
	return Matrix<T>::randmat(size,size);
}





#endif // MATRIX_HPP

