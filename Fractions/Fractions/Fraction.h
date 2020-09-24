#pragma once
#include <iostream>
#include <memory>

class Fraction
{
public:
	Fraction();
	Fraction(long long nIn, long long dIn);
	//top half of fraction
	long long numerator;
	//bottom half of fraction
	long long denominator;
	bool positive;
	//sums called object with fractIn
	void SumWith(Fraction* fractIn);
	void operator+=(Fraction* fractIn);
	//minusses fractIn from called object
	void DiffWith(Fraction* fractIn);
	void operator-=(Fraction* fractIn);
	//timeses called object by fractIn
	void MultiplyBy(Fraction* fractIn);
	void operator*=(Fraction* fractIn);
	//divides called object by fractIn
	void DivideBy(Fraction* fractIn);
	void operator/=(Fraction* fractIn);
	//returns (fractIn + fractIn2)
	Fraction Sum(Fraction* fractIn, Fraction* fractIn2);
	Fraction operator+(Fraction* fractIn);
	//returns (fractIn - fractIn2)
	Fraction Difference(Fraction* fractIn, Fraction* fractIn2);
	Fraction operator-(Fraction* fractIn);
	//returns (fractIn * fractIn2)
	Fraction Multiply(Fraction* fractIn, Fraction* fractIn2);
	Fraction operator*(Fraction* fractIn);
	//returns (fractIn / fractIn2)
	Fraction Divide(Fraction* fractIn, Fraction* fractIn2);
	Fraction operator/(Fraction* fractIn);
	//returns true if the calling object is greater than the passed object
	bool GreaterThan(Fraction* fractIn);
	bool operator>(Fraction* fractIn);
	//returns true if the calling object is equal-to the passed object
	bool EqualTo(Fraction* fractIn);
	bool operator==(Fraction* fractIn);
	//simplifies fraction
	void Simplify();
	//decides if fraction is positive
	bool Positive();
	//returns fraction as a double
	double ReturnFraction();
	//prints fraction to console
	void PrintFraction();

};

