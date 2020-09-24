#include "Fraction.h"

int main() {
	Fraction half(1, 2);
	Fraction quarter(1, 4);
	Fraction negHalf(-1, 2);
	Fraction negQuarter(-1, 4);

	Fraction tempFract(1, 1);

	std::cout << "--------------------------------------------" << "\nReturn Functions" << std::endl;
	std::cout << std::endl << std::endl << "1/2 + 1/4 \t=\t";
	tempFract = tempFract.Sum(&half, &quarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 +  -1/4 \t=\t";
	tempFract = tempFract.Sum(&half, &negQuarter);
	tempFract.PrintFraction();
	
	std::cout << std::endl << std::endl << "1/2 - 1/4 \t=\t";
	tempFract = tempFract.Difference(&half, &quarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 -  -1/4 \t=\t";
	tempFract = tempFract.Difference(&half, &negQuarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "-1/2 - 1/4 \t=\t";
	tempFract = tempFract.Difference(&negHalf, &quarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "-1/2 -  -1/4 \t=\t";
	tempFract = tempFract.Difference(&negHalf, &negQuarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 * 1/4 \t=\t";
	tempFract = tempFract.Multiply(&half, &quarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "-1/2 /  -1/4 \t=\t";
	tempFract = tempFract.Divide(&negHalf, &negQuarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 / 1/4 \t=\t";
	tempFract = tempFract.Divide(&half, &quarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 * -1/4 \t=\t";
	tempFract = tempFract.Multiply(&half, &negQuarter);
	tempFract.PrintFraction();

	std::cout << "\n\n\n--------------------------------------------" << "\nVoid Functions" << std::endl;

	std::cout << std::endl << std::endl << "1/2 + 1/4 \t=\t";
	tempFract = Fraction(1, 2);
	tempFract.SumWith(&quarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 +  -1/4 \t=\t";
	tempFract = Fraction(1, 2);
	tempFract.SumWith(&negQuarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 - 1/4 \t=\t";
	tempFract = Fraction(1, 2);
	tempFract.DiffWith(&quarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 -  -1/4 \t=\t";
	tempFract = Fraction(1, 2);
	tempFract.DiffWith(&negQuarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "-1/2 - 1/4 \t=\t";
	tempFract = Fraction(-1, 2);
	tempFract.DiffWith(&quarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "-1/2 -  -1/4 \t=\t";
	tempFract = Fraction(-1, 2);
	tempFract.DiffWith(&negQuarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 * 1/4 \t=\t";
	tempFract = Fraction(1, 2);
	tempFract.MultiplyBy(&quarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "-1/2 /  -1/4 \t=\t";
	tempFract = Fraction(-1, 2);
	tempFract.DivideBy(&negQuarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 / 1/4 \t=\t";
	tempFract = Fraction(1, 2);
	tempFract.DivideBy(&quarter);
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 * -1/4 \t=\t";
	tempFract = Fraction(1, 2);
	tempFract.MultiplyBy(&negQuarter);
	tempFract.PrintFraction();

	std::cout << "\n\n\n--------------------------------------------" << "\nComparisons" << std::endl;

	std::cout << std::endl << std::endl << "is 1/2 > -1/4 \t=\t" << half.GreaterThan(&negQuarter);

	std::cout << std::endl << std::endl << "is -1/2 > -1/4 \t=\t" << negHalf.GreaterThan(&negQuarter);

	std::cout << std::endl << std::endl << "is -1/2 > 1/4 \t=\t" << negHalf.GreaterThan(&quarter);

	std::cout << std::endl << std::endl << "is -1/2 == 1/4 \t=\t" << negHalf.EqualTo(&quarter);

	std::cout << std::endl << std::endl << "is -1/2 == -1/2\t=\t" << negHalf.EqualTo(&negHalf);

	std::cout << "\n\n\n============================================" << "\nOperator Overloads" << std::endl;

	std::cout << "\n\n\n--------------------------------------------" << "\nVoid Funcs" << std::endl;
	std::cout << std::endl << std::endl << "1/2 + 1/4 \t=\t";
	tempFract = Fraction(1, 2);
	tempFract += &quarter;
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 - 1/4 \t=\t";
	tempFract = Fraction(1, 2);
	tempFract -= &quarter;
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 * 1/4 \t=\t";
	tempFract = Fraction(1, 2);
	tempFract *= &quarter;
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 / 1/4 \t=\t";
	tempFract = Fraction(1, 2);
	tempFract /= &quarter;
	tempFract.PrintFraction();

	std::cout << "\n\n\n--------------------------------------------" << "\nReturn Funcs" << std::endl;

	std::cout << std::endl << std::endl << "1/2 + 1/4 \t=\t";
	tempFract = half + &quarter;
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 - 1/4 \t=\t";
	tempFract = half - &quarter;
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 * 1/4 \t=\t";
	tempFract = half * &quarter;
	tempFract.PrintFraction();

	std::cout << std::endl << std::endl << "1/2 / 1/4 \t=\t";
	tempFract = half / &quarter;
	tempFract.PrintFraction();

	std::cout << "\n\n\n--------------------------------------------" << "\nComparisons" << std::endl;

	std::cout << std::endl << std::endl << "is 1/2 > -1/4 \t=\t" << (half > &negQuarter);

	std::cout << std::endl << std::endl << "is -1/2 > -1/4 \t=\t" << (negHalf > &negQuarter);

	std::cout << std::endl << std::endl << "is -1/2 > 1/4 \t=\t" << (negHalf > &quarter);

	std::cout << std::endl << std::endl << "is -1/2 == 1/4 \t=\t" << (negHalf == &quarter);

	std::cout << std::endl << std::endl << "is -1/2 == -1/2 \t=\t" << (negHalf == &negHalf);

	
}