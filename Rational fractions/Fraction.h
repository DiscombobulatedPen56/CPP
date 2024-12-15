#pragma once
#include <iostream>

class Fraction {
private:
	int denom;
	int num;
	int gcd(int denom, int num);
	void reduce();
public:
	Fraction(int denom, int num);
	Fraction();
	Fraction operator+(const Fraction& a);
	Fraction operator-(const Fraction& a);
	Fraction operator*(const Fraction& a);
	Fraction operator/(const Fraction& a);
	bool operator==(const Fraction& a);
	friend std::ostream& operator<<(std::ostream& stream, const Fraction& a);
	friend std::istream& operator>>(std::istream& stream, Fraction& a);
};
