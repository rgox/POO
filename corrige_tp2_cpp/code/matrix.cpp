// Alexandre Coninx
// ISIR CNRS/UPMC
// 22/03/2017

#include "matrix.hpp"
#include "vector.hpp"
#include <iostream>
#include <cassert>
#include <random>

/*
 * Basic constructor. Initial matrix is empty (0 everywhere)
 * r: number of rows
 * c: number of cols
 */
Matrix::Matrix(size_t r, size_t c) : rows(r), cols(c)
{
	data = new double[r*c];
	fill(0.);
}

/*
 * Square matrix constructor. Initial matrix is empty (0 everywhere)
 * size: number of rows and cols
 */
Matrix::Matrix(size_t size) : rows(size), cols(size)
{
	data = new double[size*size];
	fill(0.);
}


/*
 * Copy constructor
 * m: matrix to copy
 */
Matrix::Matrix(const Matrix& m)
{
	rows = m.get_rows();
	cols = m.get_cols();
	data = new double[rows*cols];
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
Matrix::~Matrix()
{
	delete[] data;
}

/*
 * Assignment operator.
 * m: matrix to copy data from
 */
Matrix& Matrix::operator=(const Matrix& m)
{
	size_t new_r = m.get_rows();
	size_t new_c = m.get_cols();
	if(new_r != rows || new_c != cols)
	{
		delete[] data;
		data = new double[new_r*new_c];
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
const double& Matrix::operator()(size_t i, size_t j) const
{
	assert(i<rows && j < cols); // check if we are in bounds
	return data[cols*i+j];
}

/*
 * Data mutator
 * i: row of cell to access
 * j: column of cell to access
 */
double& Matrix::operator()(size_t i, size_t j)
{
	assert(i<rows && j < cols); // check if we are in bounds
	return data[cols*i+j];
}

/*
 * Fill matrix with a number
 * d: data to fill the matrix with
 */
void Matrix::fill(double d)
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
bool Matrix::operator==(const Matrix& m) const {
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
bool Matrix::operator!=(const Matrix& m) const {
	return !(*this == m); // not equality
}


/*
 * Matrix sum
 */
Matrix Matrix::operator+(const Matrix& m) const
{
	assert(m.get_rows() == rows && m.get_cols() == cols); // matrices must have same size
	Matrix result(rows,cols);
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
Matrix Matrix::operator-(const Matrix& m) const
{
	assert(m.get_rows() == rows && m.get_cols() == cols); // matrices must have same size
	Matrix result(rows,cols);
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
 * Matrix product
 */
Matrix Matrix::operator*(const Matrix& m) const
{
	assert(cols == m.get_rows()); // inner dimensions must match
	Matrix result(rows,m.get_cols());
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
Vector Matrix::operator*(const Vector& v) const
{
	assert(cols == v.get_size()); // vector size must match cols
	Vector result(rows);
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
Matrix Matrix::operator+(double d) const
{
	Matrix result(rows,cols);
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
Matrix Matrix::operator-(double d) const
{
	Matrix result(rows,cols);
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
Matrix Matrix::operator*(double d) const
{
	Matrix result(rows,cols);
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
Matrix Matrix::transpose() const
{
	Matrix result(cols,rows);
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
double Matrix::trace() const
{
	assert(rows==cols); // Only square matrices have a trace
	double r = 0.;
	for(int i = 0; i < rows ; i++)
		r += (*this)(i,i);
	return r;
}

/*
 * Stream display operator
 */
std::ostream& operator<<(std::ostream& os, const Matrix& m)
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
Matrix Matrix::eye(size_t size)
{
	Matrix m(size);
	for(int i = 0; i < size ; i++)
		m(i,i) = 1.0;
	return m;
}

/*
 * Random matrix
 * Data is in [0;1]
 */
Matrix Matrix::randmat(size_t r, size_t c)
{
	Matrix m(r,c);
	for(int i = 0 ; i < r ; i++)
	{
		for(int j = 0 ; j < c ; j++)
		{
			m(i,j) = (double)rand() / RAND_MAX;
		}
	}
	return m;
}
/*
 * Random square matrix
 * Data is in [0;1]
 */
Matrix Matrix::randmat(size_t size)
{
	return Matrix::randmat(size,size);
}

