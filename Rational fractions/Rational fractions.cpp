#include "Fraction.h"
#include <cmath>
#include <iostream>

Fraction::Fraction(int num, int denom) : num(num), denom(denom)
{
    reduce();
}

Fraction::Fraction() : num(0), denom(0) {

}

Fraction Fraction::operator+(const Fraction& a) {
    return Fraction(this->num*a.denom+this->denom*a.num, this->denom*a.denom);
}

Fraction Fraction::operator-(const Fraction& a) {
    return Fraction(this->num * a.denom-this->denom * a.num, this->denom*a.denom);
}

Fraction Fraction::operator*(const Fraction& a) {
    return Fraction(this->num * a.num, this->denom * a.denom);
}

Fraction Fraction::operator/(const Fraction& a) {
    return Fraction(this->denom * a.num, this->num * a.denom);
}

std::ostream& operator<<(std::ostream& stream, const Fraction& a) {
    return stream << "(" << a.num << "/" << a.denom << ")";
}

std::istream& operator>>(std::istream& stream, Fraction& a) {
    stream >> a.num >> a.denom;
    return stream;
}

bool Fraction::operator==(const Fraction& a) {
    if (this->num == a.num) {
        return true;
    }
    else{
        return false;
    }
}

int Fraction::gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::reduce() {
    int g = gcd(this->denom, this->num);
    this->denom = this->denom / g;
    this->num = this->num / g;
}

int main()
{
    Fraction a;
    Fraction b;
    std::cin >> a >> b;
    std::cout << a + b;
}