#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
	public:
		Fraction (int,int);
		Fraction (int);
		Fraction ();
		Fraction (const Fraction &src);
		Fraction operator+ (const Fraction &frac);
		Fraction operator- (const Fraction &frac);
		Fraction operator* (const Fraction &frac);
		Fraction operator/ (const Fraction &frac);
        bool operator== (const Fraction &frac);
        friend std::ostream &operator<<(std::ostream &os, Fraction &fr);
	protected:
		int numerator;
		int denominator;
		void simplify (void);
		int gcf (int,int);
		int lcm (int,int);
};

#endif
