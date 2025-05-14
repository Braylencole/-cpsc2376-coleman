#include "Fraction.h"

Fraction::Fraction(int n, int d) : num(n), den(d) 
{
    if (den == 0) throw std::invalid_argument("The denominator can't be zero");
    simplify();
}

void Fraction::simplify() 
{
    int a = num, b = den;
    while (b != 0) { int temp = b; b = a % b; a = temp; 
    }
    int gcd = a;
    num /= gcd;
    den /= gcd;
    if (den < 0) { num = -num; den = -den; 
    }
}

void Fraction::simplify()
{
}

Fraction::Fraction()
{
}

Fraction::Fraction(int n, int d)
{
}

int Fraction::getNumerator() const
{
	return 0;
}

int Fraction::getDenominator() const
{
	return 0;
}

void Fraction::setNumerator(int n)
{
}

void Fraction::setDenominator(int d)
{
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs)
{
	return Fraction();
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs)
{
	return Fraction();
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs)
{
	return Fraction();
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs)
{
	return Fraction();
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
	
}

