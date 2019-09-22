#include<iostream>
//#include"Vectar.h"
#include"Matrix.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	double m[9] = {1,1,1,1,1,1,1,1,1};
	Matrix a(3 ,m);
	Matrix b;
	a = b;
	return 0;
}