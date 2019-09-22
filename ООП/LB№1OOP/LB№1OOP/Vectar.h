#include<iostream>
#include<cmath>
#include<string>
#include<locale>
using namespace std;

int indefication = 0;
class Vectar
{
public:
	Vectar(const double x1 = 0, const double y1 = 0, const double z1 = 0, const double x2 = 0, const double y2 = 0, const double z2 = 0) {
		x = x2 - x1; 
		y = y2 - y1;
		z = z2 - z1;
		indefication += 1;//увеличение индефикатора 
		id = indefication;
		cout << "Конструктор вектора " << indefication << endl;
	};
	~Vectar() {
		cout << "Деструктор вектора " << indefication << endl;
	};
	//Gets========================================================
	double Get_LineX()const {
		return x;
	}
	double Get_LineY()const {
		return y;
	}
	double Get_LineZ()const {
		return z;
	}
    //Sets========================================================
	void Set_LineX(const double& x) {
		this->x = x;
	}
	void Set_LineY(const double& y) {
		this->y = y;
	}
	void Set_LineZ(const double& z) {
		this->z = z;
	}
	//============================================================
	double  Module_vector()const {//Модуль вектора
		return sqrt(x * x + y * y + z * z);
	}
	void Copy_vector(const Vectar& a) {
		this->x = a.x;
		this->y = a.y;
		this->z = a.z;
		//indefication += 1;//увеличениеИДЕНТИФИКА́ТОР
		this->id = id;
	}
	void Multiplication_cosnt(const double& num) {//умножение на константу
		x *= num;
		y *= num;
		z *= num;
	}//расчет модуля вектора sqrt(x^2+y^2+z^2)
	void Normal_vector() {//z = (a^2 + b^2 + c^2 …)^(1/2) Нормализация вектора   
		double z_n = Module_vector();
		x /= z_n;
		y /= z_n;
		z /= z_n;
	}
	//============================================================
private:
	double x;//координаты
	double y;//координаты
	double z;//координаты
	int id;//индификатор вектора
};

Vectar Plus(const Vectar& a, const Vectar& b) {
	Vectar c;
	c.Set_LineX(a.Get_LineX() + b.Get_LineX());
	c.Set_LineY(a.Get_LineY() + b.Get_LineY());
	c.Set_LineZ(a.Get_LineZ() + b.Get_LineZ());
	return c;
}//складываем векторы
Vectar Minus(const Vectar& a, const Vectar& b) {
	Vectar c;
	c.Set_LineX(a.Get_LineX() - b.Get_LineX());
	c.Set_LineY(a.Get_LineY() - b.Get_LineY());
	c.Set_LineZ(a.Get_LineZ() - b.Get_LineZ());
	return c;
}
Vectar Vector_proisvedenie(const Vectar& a, const Vectar& b) {
	Vectar c;
	c.Set_LineX(a.Get_LineX() * b.Get_LineZ() - a.Get_LineZ() * b.Get_LineY());
	c.Set_LineY(a.Get_LineZ() * b.Get_LineX() - a.Get_LineX() * b.Get_LineZ());
	c.Set_LineZ(a.Get_LineX() * b.Get_LineY() - a.Get_LineY() * b.Get_LineX());
	return c;
}
double Skalyr_proisvedenie(const Vectar& a, const Vectar& b) {
	double c;
	c = a.Get_LineX() * b.Get_LineX() + a.Get_LineY() * b.Get_LineY() + a.Get_LineZ() + b.Get_LineZ();//
	return c;
}
double* Cosinus_and_Sinus(const Vectar& a, const Vectar& b) {
	double* c = new double[2];
	c[0] = (Skalyr_proisvedenie(a, b)) / (a.Module_vector() * b.Module_vector());//нахождение cos
	c[1] = sqrt(1 - pow(c[0], 2.0));//sin
	return c;
}
double Predel(const Vectar& a, const Vectar& b) {
	double* n = new double[2];
	n = Cosinus_and_Sinus(a, b);//получаю sin и cos
	double c = atan2(n[1], n[0]);//нахождение арктангеса
	return c * 180 / 3.14;//перевод из радиан в градусы
}