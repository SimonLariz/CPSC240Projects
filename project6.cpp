#include <iostream>
#include <iomanip>

// Question 1 Vars and Functions
float a = 0, b = 0, c = 0, h = 0, permTriangle = 0, areaTriangle = 0, two = 2,
      recLength = 0, recWidth = 0, permRectangle = 0, areaRectangle = 0;

// Display shapes and read user input
void displayShape()
{
    std::cout << "       /|\\                _______________      " << std::endl;
    std::cout << "      / | \\               |             |      " << std::endl;
    std::cout << "  a  / h|  \\ b     width  |             |      " << std::endl;
    std::cout << "    /   |   \\             |             |      " << std::endl;
    std::cout << "   /____c____\\            |____length___|      " << std::endl;
    std::cout << std::endl;

    std::cout << "Enter the values of a, b, c, and h for the triangle: ";
    std::cin >> a >> b >> c >> h;
    std::cout << "Enter the length and width of the rectangle: ";
    std::cin >> recLength >> recWidth;
}

// Display shape results
void displayMeasure()
{
    std::cout << "     Traingle" << std::endl;
    std::cout << "            Area..............." << std::fixed << std::setprecision(2) << areaTriangle << std::endl;
    std::cout << "            Perimeter.........." << std::fixed << std::setprecision(2) << permTriangle << std::endl;

    std::cout << "     Rectangle" << std::endl;
    std::cout << "            Area..............." << std::fixed << std::setprecision(2) << areaRectangle << std::endl;
    std::cout << "            Perimeter.........." << std::fixed << std::setprecision(2) << permRectangle << std::endl;
}

// Question 2 Vars and Functions
float a, b, c, four = 4, two = 2, negOne = -1, ansX1, ansX2;

// Read User Input
void readUserInput()
{
    std::cout << "To see the two real roots of aX^2+ bX + c=0, enter the a,b, and c values: ";
    std::cin >> a >> b >> c;
}

// Display results for X1 and X2
void printResults()
{
    std::cout << std::fixed << std::setprecision(2) << "\t X1: " << ansX1 << "\t X2: " << ansX2 << std::endl;
}

int main()
{
    // Question 1
    _asm
    {
        call displayShape;

        // calculate triangle area: (h*c)/2

        fld c; // st[0] = c
        fld h; // st[0] = h   st[1] = c
        fmul; // st[0] = c*h
        fld two; // st[0] = 2   st[1] = c*h 
        fdiv; // st[0] = (c*h) / 2
        fstp areaTriangle;

        // calculate traingle perimeter: a + b + c

        fld a; // st[0] = a
        fld b; // st[0] = b   st[1] = a
        fadd; // st[0] = a+b
        fld c; // st[0] = c   st[1] = a+b
        fadd; // st[0] = a+b+c
        fstp permTriangle;

        // calculate rectangle area: w*l

        fld recLength; // st[0] = recLength
        fld recWidth; // st[0] = recWidth   st[1] = recLength
        fmul;
        fstp areaRectangle;

        // calculate rectangle perimeter: 2(l+w)

        fld recLength; // st[0] = recLength
        fld recWidth; // st[0] = recWidth   st[1] = recLength
        fadd; // st[0] = recLength+recWidth 
        fld two; // st[0] = 2   st[1] = recLength+recWidth
        fmul; // st[0] = 2(recLength+recWidth)
        fstp permRectangle;

        call displayMeasure;

    }

    // Question 2
    _asm
    {
        call readUserInput;
        // Calculation for X1
    compX1:
        // a * c
        fld a;
        fld c;
        fmul;
        // -4(ac)
        fld four;
        fmul;
        fld negOne;
        fmul;
        // b^2
        fld b;
        fld b;
        fmul;
        // b^2 - (4ac)
        fadd;
        // sqrt(b^2 - (4ac))
        fsqrt;
        //-b
        fld b;
        fld negOne;
        fmul;
        // -b + sqrt(b^2 - (4ac))
        fadd;
        // 2a
        fld two;
        fld a;
        fmul;
        // -b + sqrt(b^2 - (4ac)) / 2a
        fdiv;
        fstp ansX1;
        Jmp compX2;
    compX2:
        // a * c
        fld a;
        fld c;
        fmul;
        // -4(ac)
        fld four;
        fmul;
        fld negOne;
        fmul;
        // b^2
        fld b;
        fld b;
        fmul;
        // b^2 - (4ac)
        fadd;
        // sqrt(b^2 - (4ac))
        fsqrt;
        //-b
        fld b;
        fld negOne;
        fmul;
        // -b + sqrt(b^2 - (4ac))
        fsub;
        // 2a
        fld two;
        fld a;
        fmul;
        // -b + sqrt(b^2 - (4ac)) / 2a
        fdiv;
        fstp ansX2;
        Jmp done;
    done:
        call printResults;
    }
    return 0;
}