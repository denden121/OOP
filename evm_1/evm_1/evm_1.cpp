// evm_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Steack
{
public:
	bool IsEmpty() {
		if (n == -1) {
			return true;
		}
		return false;
	}
	bool IsEmptych() {
		if (n1 == -1) {
			return true;
		}
		return false;
	}
	int Pop() {
		if (n== -1) {
			cout << "errorn";
		}
		else {
			int y = a[n];
			n -= 1;
			return y;
		}
	}
	char Popch() {
		if (n1==-1) {
			cout << "errorn1";
		}
		else {
			char y = b[n1];
			n1 -= 1;
			return y;
		}
	}
	int Top() {
		return a[n];
	}
	int Topch() {
		return b[n1];
	}
	void Push(int tmp) {
		if (n>9) {
			cout << "error\n";
		}
		else {
			n += 1;
			a[n] = tmp;
		}
	}
	void Pushch(char tmp) {
		if (n1>9) {
			cout << "error\n";
		}
		else {
			n1 += 1;
			b[n1] = tmp;
		}
	}
	int Max(int a, int b) {
		if (a >= b) {
			return a;
		}
		return b;
	}
	int Min(int a, int b) {
		if (a <= b) {
			return a;
		}
		return b;
	}
private:
	int a[10];
	char b[10];
	int n = -1;
	int n1 = -1;
};

int main()
{
	ifstream F;
	string str;
	Steack num;


	F.open("1.txt");
	getline(F, str);
	int i = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'M' || str[i] == 'm') {
			num.Pushch(str[i]);
		}
		if (str[i] > 47 && str[i] < 58) {
			int tempnum = int(str[i]) - 48;
			num.Push(tempnum);
		}
		if (str[i] == ')') {
			if (num.Popch() == 'M') {
				num.Push(num.Max(num.Pop(), num.Pop()));
			}
			else{
				num.Push(num.Min(num.Pop(), num.Pop()));
			}
		}
	}
	cout << num.Pop()<<endl;
	
}


/*for (int i = 0; i < str.length(); i++) {
	if (str[i] == 'M' || str[i] == 'm') {
		num.Pushch(str[i]);
	}
	if (str[i] > 47 && str[i] < 58) {
		while (str[i] > 47 && str[i] < 58) {
			int tempstr = 0;
			//int tempnum = 0;
			tempstr = tempstr * 10 + int(str[i]);
			i += 1;
			if (i == str.length() - 1) {
				break;
			}
		}
	}
}*/	