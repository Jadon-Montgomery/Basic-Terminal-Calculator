
#include <iostream>
#include <iomanip>
#include <locale>
#include <cmath>
#include <string>

using std::endl, std::string, std::cout, std::cin;

// Custom facet for thousands separator
struct OverriddenNumpunct : std::numpunct<char> {
	char do_thousands_sep() const override { return ','; }
	std::string do_grouping() const override { return "\03"; }
};

void result(double* calculatedValue) {
	//Creating overridden locale so we can use "thousands separator"
	std::locale myLocale(std::cout.getloc(), new OverriddenNumpunct);
	//setting locale
	std::cout.imbue(myLocale);
	std::cout << "\nEquals ";
	std::cout << std::setprecision(9) << *calculatedValue << endl;

	return;
}
 
void calculate(int* operatorNum, double* calculatedValue, double* inputtedValue, double* inputtedValue2) {

	switch (*operatorNum)
	{

	case 1:
		*calculatedValue += *inputtedValue2;
		break;

	case 2:
		*calculatedValue -= *inputtedValue2;
		break;

	case 3:
		*calculatedValue *= *inputtedValue2;
		break;

	case 4:

		*calculatedValue /= *inputtedValue2;
		break;

	case 5:
		result(calculatedValue);
		break;

	default:
		break; 
	}


}

void identifyOperator(int* sizeofArray, string* selectedOperator, string operatorTypes [], int* operatorNum) {

	for (int i = 0; i < *sizeofArray; i++)
	{
		if (*selectedOperator == operatorTypes[i]) {
			*operatorNum = i + 1;
		}
	}
}

int main()
{
	//Operator tracking
	string operatorTypes[6]{ "+", "-", "*", "/", "=" };
	int operatorTypesSize{ sizeof(operatorTypes) / sizeof(operatorTypes[0]) };
	//"Out of range" default number
	int operatorNum{10};
	string selectedOperator;

	double inputtedValue{0}, inputtedValue2{ 0 }, calculatedValue{0};

	cout << "Enter a number to start \n";
	cin >> inputtedValue;

	calculatedValue += inputtedValue;

	cout << "Enter Operation: ";
	cin >> selectedOperator;

	//Find inputted operator and give it to operatorNum as an int so we can identify it
	identifyOperator(&operatorTypesSize, &selectedOperator, operatorTypes, &operatorNum);

	cout << "\nEnter a second number ";
	cin >> inputtedValue2;

	//if not "out of range"
	if (operatorNum != 10) {
		calculate(&operatorNum, &calculatedValue, &inputtedValue, &inputtedValue2);
	}
	 
	selectedOperator = "=";

	//Find inputted operator and give it to operatorNum as an int so we can identify it
	identifyOperator(&operatorTypesSize, &selectedOperator, operatorTypes, &operatorNum);
	calculate(&operatorNum, &calculatedValue, &inputtedValue, &inputtedValue2);



	return 0;

}