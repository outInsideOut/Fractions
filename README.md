# Fraction.h - A C++ .lib (static library)

## Contents
* [Description](#description)
* [Integration With Visual Studio Projects](#integration-with-visual-studio-projects)
* [Usage](#usage)
* [Structure](#structure)
* [Version Control](#version-control)
* [Conclusion](#Conclusion)

## Description

This is a c++ static library for Visual Studio which contains 1 class: Fraction.

Fractions are a pair of <i>long long</i> variables which represent the <i>numerator</i> and <i>denominator</i> of the Fraction object and a boolean variable which represents the positivity of the fraction.

The Fraction class comes with simple arithmetic functions, and overloaded operators as one would expect, this allows: Addition, Subtraction, Multiplication & Division with other Fraction objects or integers. If an arithmetic or comparitive operation is performed between a fraction object and an integer then the integer is first converted into a fraction.

This Class also includes a Exception class, currently used to catch denominators equal to 0, to avoid divide by 0 errors, this will cause the program to report the error to the console and exit with code 0;

## Integration with Visual Studio (VS) C++ projects


1. Download the package "Fraction" and take note of it's location
2. open the visual studio app you wish to use this library with
3. right-click on the top level of solution explorer -> add -> existing project -> the Fractions project you downloaded
	- (The Fractions project should now be in your solution explorer)
4. right-click on the references tab for your project in VS solution explorer
	- Tick the box next to the "Fraction" to include a reference to the library
5. right-click on your project in the solution explorer tab -> properties
	- on the left hand side click on c/c++ -> general
	- on the drop down menu for "Additional Include Directories" select "edit"
	- click the new folder button and then the "..." button to browse for the "Fractions" project you downloaded
6. In the code file you wish to use this library within, type *#include "Fraction.h"*

The library should now be included within your VS C++ project, allowing you to initialise and use objects Fraction class.

## Usage

All the following examples can be found in the FractionsWorkspace.cpp file in this repo.

#### Example 1
This example shows the construction of a fraction object to represent 0.5:

    Fraction half(1, 2);

#### Example 2
This example shows the use of the arithmetic Fraction-return-type functions on Fraction objects

Code:
```cpp
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
```
Result:

<a data-flickr-embed="true" href="https://www.flickr.com/photos/190027932@N07/50378544742/in/dateposted-public/" title="return type Funcs"><img src="https://live.staticflickr.com/65535/50378544742_492fa23283_o.png" width="1004" height="440" alt="return type Funcs"></a>

The same result can be acheived usuing the overloaded operators (+, -, *, /).

Code:
```cpp
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
```
### Example 3

This example shows the use of the void type arithmetic functions of the Fraction class. These functions modify the the value of the calling object using the arithmetic operation and the passed value.

Code: 
```cpp
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
```
Result:

<a data-flickr-embed="true" href="https://www.flickr.com/photos/190027932@N07/50378544737/in/dateposted-public/" title="void type funcs"><img src="https://live.staticflickr.com/65535/50378544737_1fae07b9ec_o.png" width="1006" height="456" alt="void type funcs"></a>

Once again, the same can be achieved using overloaded operators (+=, -=, *=, /=).

Code:
```cpp
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
```
### Example 4

This example shows the use of the comparitive functions of the Fractions class.

Code:
```cpp
    std::cout << std::endl << std::endl << "is 1/2 > -1/4 \t=\t" << half.GreaterThan(&negQuarter);

	std::cout << std::endl << std::endl << "is -1/2 > -1/4 \t=\t" << negHalf.GreaterThan(&negQuarter);

	std::cout << std::endl << std::endl << "is -1/2 > 1/4 \t=\t" << negHalf.GreaterThan(&quarter);

	std::cout << std::endl << std::endl << "is -1/2 == 1/4 \t=\t" << negHalf.EqualTo(&quarter);

	std::cout << std::endl << std::endl << "is -1/2 == -1/2\t=\t" << negHalf.EqualTo(&negHalf);
```
Result:

<a data-flickr-embed="true" href="https://www.flickr.com/photos/190027932@N07/50378544747/in/dateposted-public/" title="comparisons"><img src="https://live.staticflickr.com/65535/50378544747_963b2b7958_o.png" width="1007" height="296" alt="comparisons"></a>

The same result can be achieved using the overloaded comparitive  operators (>, ==).

Code:
```cpp
    std::cout << "\n\n\n--------------------------------------------" << "\nComparisons" << std::endl;

	std::cout << std::endl << std::endl << "is 1/2 > -1/4 \t=\t" << (half > &negQuarter);

	std::cout << std::endl << std::endl << "is -1/2 > -1/4 \t=\t" << (negHalf > &negQuarter);

	std::cout << std::endl << std::endl << "is -1/2 > 1/4 \t=\t" << (negHalf > &quarter);

	std::cout << std::endl << std::endl << "is -1/2 == 1/4 \t=\t" << (negHalf == &quarter);

	std::cout << std::endl << std::endl << "is -1/2 == -1/2 \t=\t" << (negHalf == &negHalf);
```
## Structure

As of yet, this library only consists of the one class, Fraction.

### Arithmetic Functions
The arithmetic functions that return a Fraction type variable are the following:
```cpp
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
```
These functions take pointers to two Fraction objects as parameters and return a Fraction with the result of the arithmetic operation on the two Fractions pointed to by the parameters.
As you can see from the following psuedo-code example, these will also work with the overloaded operators:
```cpp
    Fraction result, parameter1(), parameter2();

    result = parameter1 + parameter2;
```

The void-type arithmetic functions are the following:

```cpp 
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
```
These functions take a single Pointer-to-Fraction type argument and modify the calling abject by that value. As you can see by the following psuedo-code these functions can also be called by the overloaded operators:

```cpp
    Fraction result(), parameter1();

    result += parameter1;
```
The comparitive fuinctions are the follwing:

```cpp
    //returns true if the calling object is greater than the passed object
	bool GreaterThan(Fraction* fractIn);
	bool operator>(Fraction* fractIn);
	//returns true if the calling object is equal-to the passed object
	bool EqualTo(Fraction* fractIn);
	bool operator==(Fraction* fractIn);
```
These functions return boolian values depending on if the query is true or false. They take a single pointer-to-Fraction type argument and compare the calling object to that Fraction object.

As you can see from the following psuedo-code these can also be called using the overloaded operators

```cpp
    Fraction calling(1, 2), Parameter(2, 1);

    if (calling > parameter || calling == parameter) {
        //do something
    }
```
## Version Control

### v1.1.0
Arithmetic and comparitive operations, and operator overloading, with integers included.
### v1.0.2
Exception handling and try-catch statements for denominator==0.
### v1.0.1 
Initial commit, arithmetic operations fully tested and operation with other Fraction objects. 

## Conclusion

If you have any questions or suggestions regarding this repo, please feel free to make a pull request or email at fionnoconnor.dev@gmail.com.

Thank you.