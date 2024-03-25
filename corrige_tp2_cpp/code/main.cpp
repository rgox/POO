// Alexandre Coninx
// ISIR CNRS/UPMC
// 22/03/2017

#include "matrix.hpp"
#include "vector.hpp"
#include <iostream>
#include <ctime>

int main(int argc, char* argv[])
{
	srand (time(NULL));
	Matrix m(3,4);
	Matrix m2 = Matrix::randmat(4);
	Matrix mr = Matrix::randmat(4);
	Matrix id = Matrix::eye(4);
	m(1,1) = 23;
	double x = m(0,0);
	std::cout << m << std::endl;
	std::cout << m*(id*5) << std::endl;
	Matrix m3 = (m+1)*3 - 5;
	std::cout << m3 << std::endl;
	std::cout << m2 << std::endl;
	std::cout << m2.transpose() << std::endl;
	std::cout << m2.trace() << std::endl;
	std::cout << m3*m2 - m << std::endl;
	std::cout << ((m2 + id) == (id + m2)) << std::endl;
	std::cout << ((m2*mr) != (mr*m2)) << std::endl;
	//double y = m(0,42);
	
	Vector v(4);
	std::cout << v << std::endl;
	Matrix mz(4);
	std::cout << mz << std::endl;
	std::cout << v << std::endl;
	
	Vector v1 = Vector::randvec(4);
	Vector v2 = Vector::randvec(4);
	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	std::cout << v1+v2 << std::endl;
	std::cout << v1.outer(v2) << std::endl;
	std::cout << v1.inner(v2) << std::endl;
	std::cout << v1.dot(v2) << std::endl;
	// Vector product
	Vector v3 = Vector::randvec(3);
	Vector v4 = Vector::randvec(3);
	Vector v34 = v3*v4;
	std::cout << v3 << std::endl;
	std::cout << v4 << std::endl;
	std::cout << v34 << std::endl;
	// Matrix-vector product
	Vector v5 = mr*v1;
	std::cout << v5 << std::endl;
	std::cout << v5.norm() << std::endl;
}
