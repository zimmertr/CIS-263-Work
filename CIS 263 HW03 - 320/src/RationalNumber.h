/*
 * RationalNumber.h
 * Author: Justin Good
 * Date: 09/15/2013
 */

#ifndef RATIONALNUMBER_H_
#define RATIONALNUMBER_H_
#include <iostream>
#include <cstdlib>

using namespace std;

class RationalNumber{
	friend ostream& operator<< (ostream& os, const RationalNumber);

public:
	RationalNumber();
	RationalNumber(int numer, int denom);
	RationalNumber (const RationalNumber&);

	int getNumerator() const;
	int getDenominator() const;

	RationalNumber reciprocal() const;
	RationalNumber add(const RationalNumber& op2) const;
	RationalNumber subtract(const RationalNumber& op2) const;
	RationalNumber multiply(const RationalNumber& op2) const;
	RationalNumber divide(const RationalNumber& op2) const;
	RationalNumber operator+ (const RationalNumber& op2) const;
	RationalNumber operator- (const RationalNumber& op2) const;
	RationalNumber operator* (const RationalNumber& op2) const;
	RationalNumber operator/ (const RationalNumber& op2) const;
	bool operator< (const RationalNumber& op2) const;
	bool operator> (const RationalNumber& op2) const;
	bool isLike(const RationalNumber& op2) const;
	bool operator==(const RationalNumber& op2) const;

private:
	int numerator, denominator;
	void reduce();
	int gcd (int num1, int num2);
};

#endif /* RATIONALNUMBER_H_ */
