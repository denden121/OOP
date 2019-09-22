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
	Matrix() {//����������� �� ��������� �������� ������
		n = 3;
		m = 3;
		mat = new double* [n];
		for (int i = 0; i < n; i++) {//���������� ������� ������
			mat[i] = new double[m];
			for (int j = 0; j < m; j++)
			{
				mat[i][j] = 0;
			}
		}
		ide();
		cout << "����������� ������� " << idefication << endl;
	}
	Matrix(int n, double* a) {//���������� ��� ���������� �������
		this->n = n;
		m = n;
		mat = new double* [n];
		for (int i = 0; i < n; i++) {//���������� ������� ����������� ���������� 
			mat[i] = new double[m];
			for (int j = 0; j < m; j++)
			{
				mat[i][j] = a[i + j];
			}
		}
		ide();
		cout << "����������� ������� " << idefication << endl;
	}
	Matrix(const int n, const int m, double* a) { //����������� ��� �������������  �������
		this->n = n;
		this->m = m;
		mat = new double* [n];
		for (int i = 0; i < n; i++) {//���������� ������� 
			mat[i] = new double[m];
			for (int j = 0; j < m; j++)
			{
				mat[i][j] = a[i + j];
			}
		}
		ide();
		cout << "����������� ������� " << idefication << endl;
	}
	Matrix(const Matrix& a) {//����������� ������� 
		mat = a.mat;
		n = a.n;
		m = a.m;
		ide();
		cout << "����������� ������� " << idefication << endl;
	}
	~Matrix() {
		for (int i = 0; i < n; i++)
		{
			delete[] mat[i];
		}
		delete mat;
		cout << "���������� ������� " << id << endl;
	}
	void ide() {
		idefication += 1;//���������� ������������ 
		id = idefication;
	}
	//Check======================================================
	bool Is_Multiplication(const Matrix& a, const Matrix& b)const {//������� �������� ����������� ������������ 
		if (a.m == b.n && b.m == a.n) {
			return true;
		}
		return false;
	}
	bool Is_Amount(const Matrix& a, const Matrix& b)const {//������� �������� ����������� ��������
		if (a.m == b.m && b.n == a.n) {
			return true;
		}
		return false;
	}
	//===========================================================
	double Min()const {//���������� ��������
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
	double Max()const {// ��������� ��������
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
	//����������=================================================
	double* operator[](const int index) {//���������� ������ �������� ��������� ��������� �� ������
		temp = index;//��������� ���������� ��� ��������� ������ �������
		return mat[index];
	}
	double* operator[](const short int index)const {//���������� ������ ������ ���  ���������� ��������� ��������
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
	void operator*(const int& b) {//��������� �� ���������
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
ostream& operator<<(ostream& stream,const  Matrix& a) {// ���������� ������
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