#include "fraction.h"
#include <iostream>
#include <math.h>

Fraction::Fraction (int n, int d)
{
	numerator = n;
	denominator = d;
	simplify();
}

Fraction::Fraction (int n)
{
	numerator = n;
	denominator = 1;
	simplify();
}

Fraction::Fraction ()
{
	numerator = 0;
	denominator = 1;
	simplify();
}

Fraction::Fraction (const Fraction &src)
{
	numerator = src.numerator;
	denominator = src.denominator;
}

void Fraction::simplify ()
{
	if (numerator==0||denominator==0)
	{
		numerator = 0;
		denominator = 1;
	}
	if (denominator<0)
	{
		numerator *= -1;
		denominator *= -1;
	}
	int f = gcf(numerator,denominator);
	numerator = numerator/f;
	denominator = denominator/f;
}

Fraction Fraction::operator+ (const Fraction& frac)
{
    int lcd = lcm(denominator,frac.denominator);
    int q1 = lcd/denominator;
    int q2 = lcd/frac.denominator;
    return Fraction(numerator*q1+frac.numerator*q2,lcd);
}

Fraction Fraction::operator- (const Fraction& frac)
{
    int lcd = lcm(denominator,frac.denominator);
    int q1 = lcd/denominator;
    int q2 = lcd/frac.denominator;
    return Fraction(numerator*q1-frac.numerator*q2,lcd);
}

Fraction Fraction::operator* (const Fraction& frac)
{
    return Fraction(numerator*frac.numerator,denominator*frac.denominator);
}

Fraction Fraction::operator/ (const Fraction& frac)
{
    return Fraction(numerator*frac.denominator,denominator*frac.numerator);
}

bool Fraction::operator== (const Fraction& frac)
{
    return (numerator==frac.numerator&&denominator==frac.denominator);
}

std::ostream &operator<< (std::ostream &os, Fraction &fr)
{
	if (fr.numerator==0)
		os<<0;
	else
		os<<fr.numerator<<"/"<<fr.denominator;
	return os;
}

int Fraction::gcf (int a, int b)
{
	if (b==0)
		return abs(a);
	else
		return gcf(b,a%b);
}

int Fraction::lcm (int a, int b)
{
	int n = gcf(a,b);
	return a/n*b;
}
