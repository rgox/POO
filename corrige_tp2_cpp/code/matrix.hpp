#ifndef MATRIX_HPP
#define MATRIX_HPP
// Alexandre Coninx
// ISIR CNRS/UPMC
// 22/03/2017

#include <cstddef> // size_t
#include <ostream>

class Vector; // forward declaration


// Double-only version for now
class Matrix
{
public:
	//Constructors
	Matrix(size_t r, size_t c);
	Matrix(size_t size);
	Matrix(const Matrix& m);
	//Destructor
	~Matrix();
	//Attribution
	Matrix& operator=(const Matrix& m);
	//Access
	const double& operator()(size_t i, size_t j) const;
	double& operator()(size_t i, size_t j);
	inline size_t get_rows() const {return rows;}
	inline size_t get_cols() const {return cols;}
	//Equality
	bool operator==(const Matrix& m) const;
	bool operator!=(const Matrix& m) const;
	//Maths
	Matrix operator+(const Matrix& m) const;
	Matrix operator-(const Matrix& m) const;
	Matrix operator*(const Matrix& m) const;
	Matrix operator+(double d) const;
	Matrix operator-(double d) const;
	Matrix operator*(double d) const;
	Matrix transpose() const;
	double trace() const;
	//Matrix-vector product
	Vector operator*(const Vector& v) const;
	// utility
	void fill(double d);
	// Statics
	static Matrix eye(size_t size);
	static Matrix randmat(size_t r, size_t c);
	static Matrix randmat(size_t size);
protected:
	size_t rows;
	size_t cols;
	double* data;
};

std::ostream& operator<<(std::ostream&, const Matrix& m);

#endif // MATRIX_HPP

