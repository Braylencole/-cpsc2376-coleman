#include "MixedFraction.h"

MixedFraction::MixedFraction(int whole, int n, int d) : Fraction(whole* d + n, d) {}
MixedFraction::MixedFraction(const Fraction& fraction) : Fraction(fraction) {}

std::ostream& operator<<(std::ostream& os, const MixedFraction& mf) 
{
    int whole = mf.getNumerator() / mf.getDenominator();
    int numerator = mf.getNumerator() % mf.getDenominator();
    if (numerator == 0) return os << whole;
    return os << whole << " " << numerator << "/" << mf.getDenominator();
}

MixedFraction::MixedFraction(int whole, int n, int d)
{
}

MixedFraction::MixedFraction(const Fraction& fraction)
{
}

std::ostream& operator<<(std::ostream& out, const MixedFraction& mixedFraction)
{
	
