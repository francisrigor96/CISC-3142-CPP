#include <iostream>
#include <math.h>

using namespace std;

struct Calculator {
	// Inputs
	double x,y;
	
	// Enumeration of calculator operations
	enum Operation {add, subtract, multiply, divide, power, squareRoot};
	
	// Calculator operations
	double calcOperation(double x,double y, int operation) {
		switch(operation) {
			case add:
				return x + y;
				break;
			case subtract:
				return x - y;
				break;
			case multiply:
				return x * y;
				break;
			case divide:
				return x / y;
				break;
			case power:
				return pow(x,y);
				break;
			case squareRoot:
				cout << "x = " << x << " y = " << y << endl;
				cout << "Choose either " << x << " or " << y << " to evaluate the square root: ";
				int input;
				cin >> input;
				if (input == x) return sqrt(x); 
				else if (input == y) return sqrt(y); 
				else return 0;
				break;
		}
	}

};

int main() {
	double input1, input2;
	cout << "Enter 2 numbers: ";
	cin >> input1 >> input2;
	Calculator calc = {input1, input2};
	
	int opChoice;
	cout << "Enter an operation from the following choices: 1-add, 2-subtract, 3-multiply, 4-divide, 5-power, 6-sqrt: ";
	cin >> opChoice;
	
	switch(opChoice) {
		case 1:
			cout << calc.calcOperation(input1,input2,calc.add);
			break;
		case 2:
			cout << calc.calcOperation(input1,input2,calc.subtract);
			break;
		case 3:
			cout << calc.calcOperation(input1,input2,calc.multiply);
			break;
		case 4:
			cout << calc.calcOperation(input1,input2,calc.divide);
			break;
		case 5:
			cout << calc.calcOperation(input1,input2,calc.power);
			break;
		case 6:
			cout << calc.calcOperation(input1, input2, calc.squareRoot);
			break;
		default:
			cout << "Not a valid operation";
			break;
	}
	
	return 0;
}
