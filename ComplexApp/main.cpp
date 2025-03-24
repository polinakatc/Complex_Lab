#include<iostream>
#include"..\ComplexLib\Complex.h"
using namespace std;


int main()
{
	TComplex<int> N, M;
	cout << "enter 1 complex number: " << "\n";
	cin >> M;
	cout << "enter 2 complex number: " << "\n";
	cin >> N;
	M + N;
	std::cout << M + N <<"\n";
	std::cout << M - N << "\n";
	std::cout << M * N << "\n";
	std::cout << M / N << "\n";

}
