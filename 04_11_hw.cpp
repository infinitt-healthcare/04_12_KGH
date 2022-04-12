#include <iostream>
#include <vector>
using namespace std;

class Calc {
public:
	virtual double calc(const int a, const int b) const = 0;
};

class Divide : public Calc {
public:
	virtual double calc(const int a, const int b) const override {
		if (b == 0) {
			cout << "0���� �������� �����ϴ�." << endl;
			return 0;
		}
		return (double)a / b;
	}
};

class Calculator {
private:
	Calc* pCalc = new Divide();
public:
	void input();
	double calc(const int a, const int b);
};

void Calculator::input() {
	int a, b;
	while (1) {
		cout << "�Է� : ";
		cin >> a >> b;
		if (!cin) {
			cout << "���ڸ� �Է��� �� �ֽ��ϴ�." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		cout << calc(a, b) << endl;
	}
}

double Calculator::calc(const int a, const int b) {
	return pCalc->calc(a, b);
}

int main()
{
	Calculator calculator;

	calculator.input();

	return 0;
}