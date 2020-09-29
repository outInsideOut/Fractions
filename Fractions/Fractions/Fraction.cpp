#include "Fraction.h"

Fraction::Fraction() {
	numerator = 1;
	denominator = 1;
	positive = true;
}

Fraction::Fraction(long long nIn, long long dIn) {
	try {
		if (dIn == 0) { throw FractionException("Denominator == 0; Divide by Zero error"); }
		numerator = nIn;
		denominator = dIn;
	}
	catch (FractionException& e) {
		std::cout << e.ReturnMessage();

		exit(0);
	}
	Positive();
	Simplify();
}

void Fraction::SumWith(Fraction* fractIn) {
	//XOR one fraction negative
	if ((fractIn->positive == true || positive == true) && !((fractIn->positive == true && positive == true))) {
		if (positive == true) {
			numerator = ((fractIn->denominator * numerator) - (denominator * fractIn->numerator));
			denominator = (denominator * fractIn->denominator);
		}
		else {
			numerator = ((denominator * fractIn->numerator) - (fractIn->denominator * numerator));
			denominator = (denominator * fractIn->denominator);
		}
	}
	//if both positive
	else if (positive == true && fractIn->positive == true) {
		numerator = ((denominator * fractIn->numerator) + (fractIn->denominator * numerator));
		denominator = (denominator * fractIn->denominator);
	}
	//if both negative
	else {
		numerator = -1 * ((denominator * fractIn->numerator) + (fractIn->denominator * numerator));
		denominator = (denominator * fractIn->denominator);
	}
	Simplify();
	Positive();
}
void Fraction::SumWith(int valIn) {
	numerator += (valIn * denominator);
}
void Fraction::operator+=(Fraction* fractIn) {
	SumWith(fractIn);
}
void Fraction::operator+=(int valIn) {
	SumWith(valIn);
}

void Fraction::DiffWith(Fraction* fractIn) {
	//XOR one fraction negative
	if ((positive == true || fractIn->positive == true) && !((positive == true && fractIn->positive == true))) {
		if (positive == true) {
			numerator = ((fractIn->denominator * numerator) + (denominator * fractIn->numerator));
			denominator = (denominator * fractIn->denominator);
		}
		else {
			numerator = -1 * ((fractIn->denominator * numerator) + (denominator * fractIn->numerator));
			denominator = (denominator * fractIn->denominator);
		}
	}
	//if both positive
	else if (positive == true && fractIn->positive == true) {
		numerator = ((fractIn->denominator * numerator) - (denominator * fractIn->numerator));
		denominator = (denominator * fractIn->denominator);
	}
	//if both negative
	else {
		numerator = ((denominator * fractIn->numerator) - (fractIn->denominator * numerator));
		denominator = (denominator * fractIn->denominator);
	}
	Positive();
	Simplify();
}
void Fraction::DiffWith(int valIn) {
	Fraction tempFract(valIn, 1);
	DiffWith(&tempFract);
}
void Fraction::operator-=(Fraction* fractIn) {
	DiffWith(fractIn);
}
void Fraction::operator-=(int valIn) {
	DiffWith(valIn);
}

void Fraction::MultiplyBy(Fraction* fractIn) {
	numerator *= fractIn->numerator;
	denominator *= fractIn->denominator;


	//XOR one fraction negative
	if ((positive == true || fractIn->positive == true) && !((positive == true && fractIn->positive == true))) {
		numerator *= -1;
	}
	Positive();
	Simplify();
}
void Fraction::MultiplyBy(int valIn) {
	Fraction tempFract(valIn, 1);
	MultiplyBy(&tempFract);
}
void Fraction::operator*=(Fraction* fractIn) {
	MultiplyBy(fractIn);
}
void Fraction::operator*=(int valIn) {
	MultiplyBy(valIn);
}

void Fraction::DivideBy(Fraction* fractIn) {
	numerator *= fractIn->denominator;
	denominator *= fractIn->numerator;

	//XOR one fraction negative
	if ((positive == true || fractIn->positive == true) && !((positive == true && fractIn->positive == true))) {
		numerator *= -1;
	}
	Positive();
	Simplify();
}
void Fraction::DivideBy(int valIn) {
	Fraction tempFract(valIn, 1);
	MultiplyBy(&tempFract);
}
void Fraction::operator/=(Fraction* fractIn) {
	DivideBy(fractIn);
}
void Fraction::operator/=(int valIn) {
	DivideBy(valIn);
}

Fraction Fraction::Sum(Fraction* fractIn, Fraction* fractIn2) {
	std::unique_ptr<Fraction> tempFract(new Fraction());
	//XOR one fraction negative
	if ((fractIn->positive == true || fractIn2->positive == true) && !((fractIn->positive == true && fractIn2->positive == true))) {
		if (fractIn->positive == true) {
			tempFract->numerator = ((fractIn2->denominator * fractIn->numerator) - (fractIn->denominator * fractIn2->numerator));
			tempFract->denominator = (fractIn->denominator * fractIn2->denominator);
		}
		else {
			tempFract->numerator = ((fractIn->denominator * fractIn2->numerator) - (fractIn2->denominator * fractIn->numerator));
			tempFract->denominator = (fractIn->denominator * fractIn2->denominator);
		}
	}
	//if both positive
	else if (fractIn->positive == true && fractIn2->positive == true) {
		tempFract->numerator = ((fractIn->denominator * fractIn2->numerator) + (fractIn2->denominator * fractIn->numerator));
		tempFract->denominator = (fractIn->denominator * fractIn2->denominator);
	}
	//if both negative
	else {
		tempFract->numerator = -1 * ((fractIn->denominator * fractIn2->numerator) + (fractIn2->denominator * fractIn->numerator));
		tempFract->denominator = (fractIn->denominator * fractIn2->denominator);
	}
	tempFract->Positive();
	tempFract->Simplify();
	return *tempFract;
}
Fraction Fraction::Sum(Fraction* fractIn, int valIn) {
	Fraction tempFract(valIn, 1);
	return Sum(fractIn, &tempFract);
}
Fraction Fraction::operator+(Fraction* fractIn) {
	return Sum(this, fractIn);
}
Fraction Fraction::operator+(int valIn) {
	return Sum(this, valIn);
}

Fraction Fraction::Difference(Fraction* fractIn, Fraction* fractIn2) {
	std::unique_ptr<Fraction> tempFract(new Fraction());

	//XOR one fraction negative
	if ((fractIn->positive == true || fractIn2->positive == true) && !((fractIn->positive == true && fractIn2->positive == true))) {
		if (fractIn->positive == true) {
			tempFract->numerator = ((fractIn2->denominator * fractIn->numerator) + (fractIn->denominator * fractIn2->numerator));
			tempFract->denominator = (fractIn->denominator * fractIn2->denominator);
		}
		else {
			tempFract->numerator = -1 * ((fractIn2->denominator * fractIn->numerator) + (fractIn->denominator * fractIn2->numerator));
			tempFract->denominator = (fractIn->denominator * fractIn2->denominator);
		}
	}
	//if both positive
	else if (fractIn->positive == true && fractIn2->positive == true) {
		tempFract->numerator = ((fractIn2->denominator * fractIn->numerator) - (fractIn->denominator * fractIn2->numerator));
		tempFract->denominator = (fractIn->denominator * fractIn2->denominator);
	}
	//if both negative
	else {
		tempFract->numerator = ((fractIn->denominator * fractIn2->numerator) - (fractIn2->denominator * fractIn->numerator));
		tempFract->denominator = (fractIn->denominator * fractIn2->denominator);
	}
	tempFract->Positive();
	tempFract->Simplify();
	return *tempFract;
}
Fraction Fraction::Difference(Fraction* fractIn, int valIn) {
	Fraction tempFract(valIn, 1);
	return Difference(fractIn, &tempFract);
}
Fraction Fraction::operator-(int valIn) {
	return Difference(this, valIn);
}
Fraction Fraction::operator-(Fraction* fractIn) {
	return Difference(this, fractIn);
}

Fraction Fraction::Multiply(Fraction* fractIn, Fraction* fractIn2) {
	Fraction tempFract(
		(fractIn->numerator * fractIn2->numerator),
		(fractIn->denominator * fractIn2->denominator)
	);
	//XOR one fraction negative
	if ((fractIn->positive == true || fractIn2->positive == true) && !((fractIn->positive == true && fractIn2->positive == true))) {
		tempFract.numerator *= -1;
	}
	tempFract.Positive();
	tempFract.Simplify();
	return tempFract;
}
Fraction Fraction::Multiply(Fraction* fractIn, int valIn) {
	Fraction tempFract(valIn, 1);
	return Multiply(fractIn, &tempFract);
}
Fraction Fraction::operator*(Fraction* fractIn) {
	return Multiply(this, fractIn);
}
Fraction Fraction::operator*(int valIn) {
	return Multiply(this, valIn);
}

Fraction Fraction::Divide(Fraction* fractIn, Fraction* fractIn2) {
	Fraction tempFract(
		(fractIn->numerator * fractIn2->denominator),
		(fractIn->denominator * fractIn2->numerator)
	);
	//XOR one fraction negative
	if ((fractIn->positive == true || fractIn2->positive == true) && !((fractIn->positive == true && fractIn2->positive == true))) {
		tempFract.numerator *= -1;
	}
	tempFract.Positive();
	tempFract.Simplify();
	return tempFract;
}
Fraction Fraction::Divide(Fraction* fractIn, int valIn) {
	Fraction tempFract(valIn, 1);
	return Divide(fractIn, &tempFract);
}
Fraction Fraction::operator/(Fraction* fractIn) {
	return Divide(this, fractIn);
}
Fraction Fraction::operator/(int valIn) {
	return Divide(this, valIn);
}

bool Fraction::GreaterThan(Fraction* fractIn) {
	if ((fractIn->positive == true || positive == true) && !(fractIn->positive == true && positive == true)) {
		if (fractIn->positive == true) {
			return false;
		}
		else { return true; }
	}
	else if (numerator * fractIn->denominator > fractIn->numerator * denominator) {
		return true;
	}
	else { return false; }
}
bool Fraction::operator>(Fraction* fractIn) {
	return GreaterThan(fractIn);
}

bool Fraction::LessThan(Fraction* fractIn) {
	return fractIn->GreaterThan(this);
}
bool Fraction::operator<(Fraction* fractIn) {
	return this->LessThan(fractIn);
}

bool Fraction::EqualTo(Fraction* fractIn) {
	if ((fractIn->positive == true || positive == true) && !(fractIn->positive == true && positive == true)) {
		return false;
	}
	if (numerator * fractIn->denominator == fractIn->numerator * denominator) {
		return true;
	}
	else {
		return false;
	}
}
bool Fraction::operator==(Fraction* fractIn) {
	return EqualTo(fractIn);
}

bool Fraction::LessThanOrEqualTo(Fraction* fractIn) {
	if (this->LessThan(fractIn) || this->EqualTo(fractIn)) {
		return true;
	}
	else { return false; }
}
bool Fraction::operator<=(Fraction* fractIn) {
	return LessThanOrEqualTo(fractIn);
}

bool Fraction::GreaterThanOrEqualTo(Fraction* fractIn) {
	if (this->GreaterThan(fractIn) || this->EqualTo(fractIn)) {
		return true;
	}
	else { return false; }
}
bool Fraction::operator>=(Fraction* fractIn) {
	return GreaterThanOrEqualTo(fractIn);
}


bool Fraction::Positive() {

	try {
		if (denominator == 0) { throw FractionException("Denominator == 0; Divide by Zero error"); }
	}
	catch (FractionException& e) {
		std::cout << e.ReturnMessage();
		exit(0);
	}
	//XOR one half of fraction < 0
	if ((denominator < 0 || numerator < 0) && !((denominator < 0 && numerator < 0))) {
		positive = false;
		denominator = abs(denominator);
		numerator = abs(numerator);
		return false;
	}
	positive = true;
	denominator = abs(denominator);
	numerator = abs(numerator);
	return true;

}

void Fraction::Simplify() {
	long long i;
	//only need to check LCF up-to the smallest half of the fraction
	(std::abs(numerator) > std::abs(denominator) ? i = std::abs(denominator) : i = std::abs(numerator));
	//if either denom or numerator are odd, LCF cannot be even, so jump even numbers
	if (numerator % 2 != 0 || denominator % 2 != 0) {
		for (long long j = 3; j <= i; j += 2) {
			if (numerator % j == 0 && denominator % j == 0) {
				numerator /= j;
				denominator /= j;
				Simplify();
				return;
			}
		}
	}
	//if both denom and numerator are even, check all numbers up to smallest half
	else {
		for (long long j = 2; j <= i; j++) {
			if (numerator % j == 0 && denominator % j == 0) {
				numerator /= j;
				denominator /= j;
				Simplify();
				return;
			}
		}
	}
}

double Fraction::ReturnFraction() {
	return (double(numerator) / double(denominator));
}

void Fraction::PrintFraction() {
	if (positive == false) {
		std::cout << "-";
	}
	std::cout << "(" << numerator << "\\" << denominator << ")";
}


