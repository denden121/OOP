#include<iostream>
#include<cmath>
#include<string>
#include<locale>
#include<iomanip>
using namespace std;

int idefication = 0;
class Matrix
{
public:
	Matrix() {//конструктор по умолчанию заполняю нулями
		n = 3;
		m = 3;
		mat = new double* [n];
		for (int i = 0; i < n; i++) {//заполнения массива нулями
			mat[i] = new double[m];
			for (int j = 0; j < m; j++)
			{
				mat[i][j] = 0;
			}
		}
		ide();
		cout << "Конструктор вектора " << idefication << endl;
	}
	Matrix(int n, double* a) {//коструктор для квадратной матрицы
		this->n = n;
		m = n;
		mat = new double* [n];
		for (int i = 0; i < n; i++) {//заполнения массива переданными значениями 
			mat[i] = new double[m];
			for (int j = 0; j < m; j++)
			{
				mat[i][j] = a[i + j];
			}
		}
		ide();
		cout << "Конструктор вектора " << idefication << endl;
	}
	Matrix(const int n, const int m, double* a) { //конструктор для прямоугольной  матрицы
		this->n = n;
		this->m = m;
		mat = new double* [n];
		for (int i = 0; i < n; i++) {//заполнения массива 
			mat[i] = new double[m];
			for (int j = 0; j < m; j++)
			{
				mat[i][j] = a[i + j];
			}
		}
		ide();
		cout << "Конструктор вектора " << idefication << endl;
	}
	Matrix(const Matrix& a) {//копирование вектора 
		mat = a.mat;
		n = a.n;
		m = a.m;
		ide();
		cout << "Конструктор вектора " << idefication << endl;
	}
	~Matrix() {
		for (int i = 0; i < n; i++)
		{
			delete[] mat[i];
		}
		delete mat;
		cout << "Деструктор вектора " << id << endl;
	}
	void ide() {
		idefication += 1;//увеличение индефикатора 
		id = idefication;
	}
	//Check======================================================
	bool Is_Multiplication(const Matrix& a, const Matrix& b)const {//функция проверки возможности перемножения 
		if (a.m == b.n && b.m == a.n) {
			return true;
		}
		return false;
	}
	bool Is_Amount(const Matrix& a, const Matrix& b)const {//функция проверки возможности сложения
		if (a.m == b.m && b.n == a.n) {
			return true;
		}
		return false;
	}
	//===========================================================
	double Min()const {//нахождения минимума
		try
		{
			if (n == 0 && m == 0) {
				
			}
		}
		catch (const std::exception&)
		{

		}
		double min = mat[0][0];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				if (min > mat[i][j]) {
					min = mat[i][j];
				}
			}
		}
		return min;
	}
	double Max()const {// нажодения минимума
		double max = mat[0][0];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				if (max > mat[i][j]) {
					max = mat[i][j];
				}
			}
		}
		return max;
	}
	//Gets=======================================================
	double** Get_mat() const {
		return mat;
	}
	int Get_m() const {
		return m;
	}
	int Get_n() const {
		return n;
	}
	//Перегрузки=================================================
	double* operator[](const int index) {//перегрузка первой скобочки возвращие указатель на строку
		temp = index;//временная переменная для запоминая строки матрицы
		return mat[index];
	}
	double* operator[](const short int index)const {//перегрузка второй скобки для  нахождения конечного значения
		return &mat[temp][index];
	}
	void operator=(const Matrix& b) {
		n = b.n;
		m = b.m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				this->mat[i][j] = b.mat[i][j];
			}
		}
		id = b.id;
	}
	void operator+=(const Matrix& b) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mat[i][j] += b.mat[i][j];
			}
		}
	}
	void operator-=(const Matrix& b) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mat[i][j] -= b.mat[i][j];
			}
		}
	}
	void operator*=(const Matrix& b) {
		//if (this->IsMulAccepted(mtr)) {
		//const int temp_n = b.n;
		//const int temp_m = this->m;
		//double a[temp_m][temp_n];
		//*this = a;

	}
	void operator*(const int& b) {//умножение на константу
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++) {
				mat[i][j] *= b;
			}
		}
	}
private:
	int temp;
	double** mat;
	int n;
	int m;
	int id;
};
Matrix& operator+(const Matrix& a, const Matrix& b) {
	Matrix c(a);
	c += b;
	return c;
}
Matrix& operator-(const Matrix& a, const Matrix& b) {
	Matrix c(a);
	c -= b;
	return c;
}
Matrix& operator*(const Matrix& a, const Matrix& b) {
	Matrix c(a);
	c *= b;
	return c;
}
ostream& operator<<(ostream& stream,const  Matrix& a) {// перегрузка вывода
	for (int i = 0; i < a.Get_n(); i++)
	{
		stream << "|";
		for (int j = 0; j < a.Get_m(); j++) {
			stream << setw(5) << a.Get_mat()[i][j]<<"|";
		}
		stream <<"|"<< endl;
	}
	return stream;
}