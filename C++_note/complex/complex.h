// complex.h
#include <iostream>
using namespace std;

class Complex
{
  private:
	double rpart, ipart;	 // ʵ�����鲿
	double abs(void) const;  // ����ģ
	double norm(void) const; // ����ģ��ƽ��

  public:
	Complex(void) { rpart = .0, ipart = .0; }

	Complex(const Complex &c) // Ԥ���忽�����캯�����ɺ��ԣ�
	{
		rpart = c.rpart, ipart = c.ipart;
	}

	Complex(const double &r, const double &i) { rpart = r, ipart = i; }

	Complex(const double &r) { rpart = r, ipart = .0; }

	Complex &operator=(const Complex &c) // Ԥ���帳ֵ���㣨�ɺ��ԣ�
	{
		rpart = c.rpart, ipart = c.ipart;
		return *this;
	}

	Complex operator-(void);
	friend Complex operator+(const Complex &, const Complex &);
	friend Complex operator-(const Complex &, const Complex &);
	friend Complex operator*(const Complex &, const Complex &);
	friend Complex operator/(const Complex &, const Complex &);
	Complex operator+=(const Complex &);
	Complex operator-=(const Complex &);
	friend int operator==(const Complex &, const Complex &);
	friend int operator<(const Complex &, const Complex &);
	friend int operator>(const Complex &, const Complex &);
	friend istream &operator>>(istream &, Complex &);
	friend ostream &operator<<(ostream &, Complex &);
};