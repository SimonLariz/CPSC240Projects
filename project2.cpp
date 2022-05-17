#include <iostream>
#include <iomanip>

int main()
{
	// QUESTION 1
	// Declare and init vars
	short drinkNum, sandwichNum, drinkPrice = 2, sandwichPrice = 4, amountTotal;
	// Menu Formatting
	std::cout << std::setw(14) << std::setfill('-') << ""
			  << "MENU" << std::setw(14) << "" << std::endl;
	std::cout << std::setw(30) << std::left << "Drinks" << std::right << "$2" << std::endl;
	std::cout << std::setw(30) << std::left << "Sandwiches" << std::right << "$4" << std::endl;
	// Take user input
	std::cout << "\t How many drinks?: ";
	std::cin >> drinkNum;
	std::cout << "\t How many sandwiches?: ";
	std::cin >> sandwichNum;
	// Assembly
	_asm
	{
		// Move drinkNum into register ax
		mov ax, drinkNum;
		// Multiply ax by drinkPrice
		imul drinkPrice;
		// Move result into amountTotal
		mov amountTotal, ax;
		// Move sandwichNum into register ax
		mov ax, sandwichNum;
		// Multiply by sandwichPrice
		imul sandwichPrice;
		// Add ax register + amount total 
		add ax, amountTotal;
		// Move ax register to update amountTotal
		mov amountTotal, ax;
	}
	// Display final total amount
	std::cout << "\t\t Your total bill $" << amountTotal << std::endl
			  << std::endl;

	// QUESTION 2
	// Declare and init vars
	int a, b, c, h, permTriangle, areaTriangle, two = 2;
	int lengths, width, permRectangle, areaRectangle;
	// Printing
	std::cout << "       /|\\                _______________      " << std::endl;
	std::cout << "      / | \\               |             |      " << std::endl;
	std::cout << "  a  / h|  \\ b     width  |             |      " << std::endl;
	std::cout << "    /   |   \\             |             |      " << std::endl;
	std::cout << "   /____c____\\            |____length___|      " << std::endl
			  << std::endl;
	// User input
	std::cout << "Enter the values of a, b, c, and h for the triangle: ";
	std::cin >> a >> b >> c >> h;
	std::cout << "Enter the length and width of the rectangle: ";
	std::cin >> lengths >> width;
	// Assembly
	_asm
	{
		// calculate area of triangle
		//  b*h\2
		mov eax, c;
		imul h;
		idiv two;
		mov areaTriangle, eax;
		// calculate perimeter of triangle
		mov eax, a;
		add eax, b;
		add eax, c;
		mov permTriangle, eax;
		// calculate area of rectangle
		// area = width*length
		mov eax, lengths;
		imul width;
		mov areaRectangle, eax;
		// calculate perimeter of rectangle
		// 2*width+2*length
		mov ebx, width;
		add ebx, width;
		mov eax, lengths;
		add eax, lengths;
		add eax, ebx;
		mov permRectangle, eax;
	}
	// Printing
	std::cout << "\tTriangle" << std::endl;
	std::cout << "\t\tArea..............." << areaTriangle << std::endl;
	std::cout << "\t\tPerimeter.........." << permTriangle << std::endl;
	std::cout << "\tRectangle" << std::endl;
	std::cout << "\t\tArea..............." << areaRectangle << std::endl;
	std::cout << "\t\tPerimeter.........." << permRectangle << std::endl
			  << std::endl;

	// QUESTION 3
	// Declare and init vars
	short fahrenheitTemp, x = 5, y = 32, z = 9, celsiusTemp;
	std::cout << "Enter a temperature in Fahrenheit: ";
	// Take userInput
	std::cin >> fahrenheitTemp;
	// Assembly
	_asm
	{
		// Move fahrenheitTemp into register ax
		mov ax, fahrenheitTemp;
		// Subtract ax by -32 (formula)
		sub ax, y;
		// Multiply ax by 5 (formula)
		imul x;
		// Divide ax by 9 (formula)
		idiv z;
		// Move result in register ax to celsiusTemp
		mov celsiusTemp, ax;
	}
	// Display final result
	std::cout << fahrenheitTemp << "F is " << celsiusTemp << "C" << std::endl
			  << std::endl;

	// QUESTION 4
	// Declare and init vars
	int userInput, onesPlace, tensPlace, hundredsPlace, HUNDRED = 100, TEN = 10, runningSum = 0;
	// Take user input
	std::cout << "Enter a 3 digit int number: ";
	std::cin >> userInput;
	_asm
	{
		// Move user input to eax register
		mov eax, userInput;
		// Convert double word to quad word before division
		cdq;
		// Divide by 100
		idiv HUNDRED;
		// Set hundredsPlace to result
		mov hundredsPlace, eax;
		// Update eax to remainder 
		mov eax, edx;
		// Convert double word to quad word before division
		cdq;
		// Divide by 10
		idiv TEN;
		// Set tensPlace to result
		mov tensPlace, eax;
		// Set onesPlace to remainder
		mov onesPlace, edx;
		// Sum up digits
		mov eax, runningSum;
		add eax, hundredsPlace;
		add eax, tensPlace;
		add eax, onesPlace;
		// Update runningSum to sum of all digits stored in register eax
		mov runningSum, eax;
	}
	std::cout << "\tThe total of digits in " << userInput << " is " << runningSum << std::endl;
}