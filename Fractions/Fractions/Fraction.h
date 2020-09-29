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
	void SumWith(int valIn);
	void operator+=(Fraction* fractIn);
	void operator+=(int valIn);
	//minusses fractIn from called object
	void DiffWith(Fraction* fractIn);
	void DiffWith(int valIn);
	void operator-=(Fraction* fractIn);
	void operator-=(int valIn);

	//timeses called object by fractIn
	void MultiplyBy(Fraction* fractIn);
	void MultiplyBy(int valIn);
	void operator*=(Fraction* fractIn);
	void operator*=(int valIn);

	//divides called object by fractIn
	void DivideBy(Fraction* fractIn);
	void DivideBy(int valIn);
	void operator/=(Fraction* fractIn);
	void operator/=(int valIn);

	//returns (fractIn + fractIn2)
	Fraction Sum(Fraction* fractIn, Fraction* fractIn2);
	Fraction Sum(Fraction* fractIn, int valIn);
	Fraction operator+(Fraction* fractIn);
	Fraction operator+(int valIn);

	//returns (fractIn - fractIn2)
	Fraction Difference(Fraction* fractIn, Fraction* fractIn2);
	Fraction Difference(Fraction* fractIn, int valIn);
	Fraction operator-(Fraction* fractIn);
	Fraction operator-(int valIn);

	//returns (fractIn * fractIn2)
	Fraction Multiply(Fraction* fractIn, Fraction* fractIn2);
	Fraction Multiply(Fraction* fractIn, int valIn);
	Fraction operator*(Fraction* fractIn);
	Fraction operator*(int valIn);

	//returns (fractIn / fractIn2)
	Fraction Divide(Fraction* fractIn, Fraction* fractIn2);
	Fraction Divide(Fraction* fractIn, int valIn);
	Fraction operator/(Fraction* fractIn);
	Fraction operator/(int valIn);

	//returns true if the calling object is greater than the passed object
	bool GreaterThan(Fraction* fractIn);
	bool operator>(Fraction* fractIn);

	//returns true if calling object is less than the passed object
	bool LessThan(Fraction* fractIn);
	bool operator<(Fraction* fractIn);

	//returns true if the calling object is equal-to the passed object
	bool EqualTo(Fraction* fractIn);
	bool operator==(Fraction* fractIn);

	//returns true if the calling object is less than or equal to the passed object
	bool LessThanOrEqualTo(Fraction* fractIn);
	bool operator<=(Fraction* fractIn);

	//returns true if the calling object is more than or equal to the passed object
	bool GreaterThanOrEqualTo(Fraction* fractIn);
	bool operator>=(Fraction* fractIn);

	//simplifies fraction
	void Simplify();
	//decides if fraction is positive
	bool Positive();
	//returns fraction as a double
	double ReturnFraction();
	//prints fraction to console
	void PrintFraction();

};

//small exception class for the fractions library
//seemed unnessecary to include string lib so just used speedy C-Strings
class FractionException {
public:
	FractionException(const char* msgIn) {
		//+1 to lengths to account for null char
		msg = new char[strlen(msgIn) + 1];
		//cpy parameter into msg var
		memcpy(msg, msgIn, strlen(msgIn) + 1);
		//find size of cStrings to concat
		size = strlen(type) + strlen(msg);
		//allocate memory for concatonated message
		tempStr = new char[size + 1];
	};
	const char* ReturnMessage() {
		//copy type var into beginning of tempStr
		memcpy(tempStr, type, strlen(type) + 1);
		//append tempStr with msg
		strcat_s(tempStr, size + 1, msg);
		//return
		return tempStr;
	};
	~FractionException() {
		//clean up dynamic char[]s
		delete tempStr;
		delete msg;
	}
private:
	//will hold size of the concatonated cString message
	int size;
	//const cString applicable to all Exceptions
	const char* type = "Fatal Fraction error occured - ";
	//holds passed parameter message from constructor
	char* msg;
	//holds concatonated message to be returned in ReturnMessage()
	char* tempStr;
};