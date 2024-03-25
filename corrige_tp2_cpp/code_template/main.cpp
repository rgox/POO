// Alexandre Coninx
// ISIR CNRS/UPMC
// 22/03/2017

#include "matrix.hpp"
#include "vector.hpp"
#include <iostream>
#include <ctime>
#include <random>

int main(int argc, char* argv[])
{
	srand (time(NULL));
	// Matrice de doubles
	Matrix<double> m(3,4);
	Matrix<double> id = Matrix<double>::eye(4);
	m(1,1) = 23;
	m(0,0) = 17;
	std::cout << m << std::endl;
	std::cout << m*(id*5) << std::endl;

	// Matrice d'ints
	Matrix<int> mi(5,4);
	Matrix<int> idi = Matrix<int>::eye(4);
	mi(1,2) = 52;
	mi(0,1) = 23;
	std::cout << mi << std::endl;
	std::cout << (mi+1)*(idi*2) << std::endl;

	//Vector of ints
	Vector<int> v1(3);
	v1.fill(1);
	Vector<int> v2(3);
	v2.fill(2);
	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	std::cout << v1.dot(v2) << std::endl;
	v2[2] += 2;
	std::cout << v1.cross(v2) << std::endl;
	
	Matrix<int> mprod = Matrix<int>::eye(3) + 1;
	std::cout << mprod*v1 << std::endl;

}
