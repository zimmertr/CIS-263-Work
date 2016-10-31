/*
 * RationalNumber.cpp
 * Author: Justin Good
 * Date: 09/15/2013
 */

#include "RationalNumber.h"

RationalNumber::RationalNumber()
    {
    numerator = 1;
    denominator = 1;
    }

RationalNumber::RationalNumber (int numer, int denom)
    {
    if (denom == 0)
	denom = 1;

    // Make the numerator "store" the sign
    if (denom < 0)
	{
	numer = numer * -1;
	denom = denom * -1;
	}

    numerator = numer;
    denominator = denom;
    RationalNumber::reduce();
    }

RationalNumber::RationalNumber(const RationalNumber& rn){
    numerator = rn.numerator;
    denominator = rn.denominator;
}

int RationalNumber::getNumerator() const
    {
    return numerator;
    }

int RationalNumber::getDenominator() const
    {
    return denominator;
    }

RationalNumber RationalNumber::reciprocal() const
    {
    return RationalNumber(denominator, numerator);
    }

RationalNumber RationalNumber::add(const RationalNumber& op2) const
    {
    int commonDenominator = denominator * op2.getDenominator();
    int numerator1 = numerator * op2.getDenominator();
    int numerator2 = op2.getNumerator() * denominator;
    int sum = numerator1 + numerator2;

    return RationalNumber (sum, commonDenominator);

    }

RationalNumber RationalNumber::subtract(const RationalNumber& op2) const
    {
    int commonDenominator = denominator * op2.getDenominator();
    int numerator1 = numerator * op2.getDenominator();
    int numerator2 = op2.getNumerator() * denominator;
    int difference = numerator1 - numerator2;

    return RationalNumber (difference, commonDenominator);
    }

RationalNumber RationalNumber::multiply(const RationalNumber& op2) const
    {
    int numer = numerator * op2.getNumerator();
    int denom = denominator * op2.getDenominator();
    return RationalNumber (numer, denom);
    }

RationalNumber RationalNumber::divide(const RationalNumber& op2) const
    {
    return RationalNumber::multiply(op2.RationalNumber::reciprocal());
    }

RationalNumber RationalNumber::operator+ (const RationalNumber& op2) const
    {
    return RationalNumber::add(op2);
    }
RationalNumber RationalNumber::operator- (const RationalNumber& op2) const
    {
    return RationalNumber::subtract(op2);
    }

RationalNumber RationalNumber::operator* (const RationalNumber& op2) const
					    {
    return RationalNumber::multiply(op2);
					    }

RationalNumber RationalNumber::operator/ (const RationalNumber& op2) const
					    {
    return RationalNumber::divide(op2);
					    }

bool RationalNumber::operator< (const RationalNumber& op2) const{
    float float1 = (float)numerator/(float)denominator;
    float float2 = (float)op2.getNumerator()/(float)op2.getDenominator();
    return (float1 < float2);
}

bool RationalNumber::operator> (const RationalNumber& op2) const{
    float float1 = (float)numerator/(float)denominator;
    float float2 = (float)op2.getNumerator()/(float)op2.getDenominator();
    return (float1 > float2);
}

bool RationalNumber::operator==(const RationalNumber& op2) const{
    return isLike(op2);
}

bool RationalNumber::isLike(const RationalNumber& op2) const
    {
    return ( numerator == op2.getNumerator() &&
	    denominator == op2.getDenominator() );
    }

void RationalNumber::reduce()
    {
    if (numerator != 0)
	{
	int common = RationalNumber::gcd(abs(numerator), denominator);
	numerator = numerator / common;
	denominator = denominator / common;
	}
    }

int RationalNumber::gcd (int num1, int num2)
    {
    while (num1 != num2)
	if (num1 > num2)
	    num1 = num1 - num2;
	else
	    num2 = num2 - num1;

    return num1;
    }

ostream& operator<< (ostream& os, const RationalNumber op2)
    {
    if (op2.getNumerator()== 0)
	os << "0";
    else
	if (op2.getDenominator() == 1)
	    os << op2.getNumerator() << "";
	else
	    os << op2.getNumerator() << "/" << op2.getDenominator();

    return os;
    };
