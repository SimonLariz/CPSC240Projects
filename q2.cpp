#include <iostream>
#include <iomanip>

// Question 1

// question 1 vars and functions
std::string customerName;
float foodNum = 0, drinkNum = 0, taxRate = 1.10;
float pizzaPrice = 3.25, sandwichPrice = 2.10, sodaPrice = 1.25, juicePrice = 1.75, beerPrice = 1.85, customerTotal = 55;
char foodSelection, drinkSelection;

void readInformation()
{
    // Customer Name
    std::cout << "What is your name: ";
    std::cin >> customerName;

    // Customer Food
    std::cout << "What kind of food in uppercase (P = pizza, S = sandwich): ";
    std::cin >> foodSelection;
    std::cout << "\tHow many? ";
    std::cin >> foodNum;

    // Customer Drink
    std::cout << "What would you like to drink in uppercase (S = soda, J = juice, B = beer): ";
    std::cin >> drinkSelection;
    std::cout << "\tHow many? ";
    std::cin >> drinkNum;
    std::cout << "foodSelection: " << foodSelection << " foodNum: " << foodNum << " drinkSelection: " << drinkSelection << " drinkNum: " << drinkNum << "\n";
}

void displayFinal()
{
    std::cout << customerName << " your total bill including 10% is $" << std::fixed << std::setprecision(2) << customerTotal << "\n";
}

int main()
{
    _asm {
		call readInformation;

		cmp foodSelection, 'P';
		Je pizza;
		cmp foodSelection, 'S';
		Je sandwich;

	pizza:
		fld pizzaPrice;
		fld foodNum;
		fmul;
		fstp customerTotal;

		cmp drinkSelection, 'S';
		Je soda;
		cmp drinkSelection, 'J';
		Je juice;
		cmp drinkSelection, 'B';
		Je beer;

	sandwich:
		fld sandwichPrice;
		fld foodNum;
		fmul;
		fstp customerTotal;

		cmp drinkSelection, 'S';
		Je soda;
		cmp drinkSelection, 'J';
		Je juice;
		cmp drinkSelection, 'B';
		Je beer;

	soda:
		fld customerTotal;
		fld sodaPrice;
		fld drinkNum;
		fmul;
		fadd;
		fld taxRate;
		fmul;
		fstp customerTotal;
		Jmp done;

	juice:
		fld customerTotal;
		fld juicePrice;
		fld drinkNum;
		fmul;
		fadd;
		fld taxRate;
		fmul;
		fstp customerTotal;
		Jmp done;

	beer:
		fld customerTotal;
		fld beerPrice;
		fld drinkNum;
		fmul;
		fadd;
		fld taxRate;
		fmul;
		fstp customerTotal;
		Jmp done;

	done:
		call displayFinal;
    }
}
