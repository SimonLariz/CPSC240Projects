#include <iostream>
#include <iomanip>

// Question 2
char calcGradeChar, compGradeChar, historyGradeChar, englishGradeChar, input;
float calcValue, compValue, historyValue, englishValue;
float calcUnits = 5.0, compUnits = 4.0, historyUnits = 3.0, englishUnits = 3.0, totalUnits;
float GPAValue = 0.0;

void getUserGrades()
{
    std::cout << "Enter your grades in Calculus 1, Computer Programing, History, and English: ";
    std::cin >> calcGradeChar >> compGradeChar >> historyGradeChar >> englishGradeChar;
}

void computeGradeValues()
{
    // Calc grade
    if (calcGradeChar == 'A')
    {
        calcValue = 4.0;
    }
    else if (calcGradeChar == 'B')
    {
        calcValue = 3.0;
    }
    else if (calcGradeChar == 'C')
    {
        calcValue = 2.0;
    }
    else if (calcGradeChar == 'D')
    {
        calcValue = 1.0;
    }
    else
    {
        calcValue = 0.0;
    }
    // Comp grade
    if (compGradeChar == 'A')
    {
        compValue = 4.0;
    }
    else if (calcGradeChar == 'B')
    {
        compValue = 3.0;
    }
    else if (compGradeChar == 'C')
    {
        compValue = 2.0;
    }
    else if (compGradeChar == 'D')
    {
        compValue = 1.0;
    }
    else
    {
        compValue = 0.0;
    }
    // History grade
    if (historyGradeChar == 'A')
    {
        historyValue = 4.0;
    }
    else if (historyGradeChar == 'B')
    {
        historyValue = 3.0;
    }
    else if (historyGradeChar == 'C')
    {
        historyValue = 2.0;
    }
    else if (historyGradeChar == 'D')
    {
        historyValue = 1.0;
    }
    else
    {
        historyValue = 0.0;
    }
    // English grade
    if (englishGradeChar == 'A')
    {
        englishValue = 4.0;
    }
    else if (englishGradeChar == 'B')
    {
        englishValue = 3.0;
    }
    else if (englishGradeChar == 'C')
    {
        englishValue = 2.0;
    }
    else if (englishGradeChar == 'D')
    {
        englishValue = 1.0;
    }
    else
    {
        englishValue = 0.0;
    }
    totalUnits = (calcUnits + compUnits + historyUnits + englishUnits);
}

// Display GPA and ask user to contine
void displayGPA()
{
    std::cout << "Your GPA is: " << std::fixed << std::setprecision(2) << GPAValue << "\n";
    std::cout << "CONTINUE? (Y/N in uppercase): ";
    std::cin >> input;
}

int main()
{
    std::cout << "QUESTION 2\n";
    _asm {
        // While Loop
    whileLoop:
            // Get grades and compute grade values
			call getUserGrades;
            call computeGradeValues;

        // Float computation
            fld calcValue;
            fld calcUnits;
            fmul;
            fld compValue;
            fld compUnits;
            fmul;
            fadd;
            fld historyValue;
            fld historyUnits;
            fmul;
            fadd;
            fld englishValue;
            fld englishUnits;
            fmul;
            fadd;
            fld totalUnits;
            fdiv;
            fstp GPAValue;

        // Display GPA
            call displayGPA;

        // Check if user wants to continue
			cmp input, 'Y';
			JE whileLoop;

		jmp done;
		done:
    }
}
