// Project 4
#include <iostream>
#include <string>
#include <vector>

// question 1 vars and functions
short customers, drink_num, sandwich_num, sandwich_size, water = 1, soda = 2, ten_inch = 3, twelve_inch = 5, total_d, total_s, total, i = 0;
char drink_type;

// asks for the amount of customers
void askcustomers()
{
    short cu;
    std::cout << "enter the number of customers: ";
    std::cin >> cu;
    customers = cu;
}

// asks users for food types and amount
void readdata()
{
    std::cout << std::endl
              << " how many drinks? ";
    std::cin >> drink_num;
    std::cout << " what kind of drinks (s = soda, w = water)? ";
    std::cin >> drink_type;
    std::cout << " how many sandwiches? ";
    std::cin >> sandwich_num;
    std::cout << "what size of sandwich (10/12 inches)? ";
    std::cin >> sandwich_size;
    std::cout << std::endl;
}

// displays total bills for each customer
void showtotal()
{
    std::cout << "your total bill = " << total << std::endl;
}

// Question 2 Vars and Functions
int input = 0;
int numStudent = 0, totalSum = 0, userAvg = 0, total = 0;

void readScore()
{
    std::cout << "Enter your score (-1) to stop: ";
    std::cin >> input;
}

void displayAvg()
{
    std::cout << "\t Your average is " << userAvg << std::endl;
}

// question 3 vars and functions
std::string usersentence;
char currentChar = 'f';
short index = 0, sentenceLen = 0, counter = 0, UpperCaseCount = 0, LowerCaseCount = 0;

void readUserSentence()
{
    std::cout << "enter a sentence: ";
    std::getline(std::cin, usersentence);
    sentenceLen = (short)usersentence.length();
}

void getCurrentChar()
{
    currentChar = usersentence[index];
}

void displayCounts()
{
    std::cout << "no. of uppercase letters = " << UpperCaseCount << std::endl;
    std::cout << "no. of lowercase letters = " << LowerCaseCount << std::endl;
}

// question 4 vars and functions

short printernum, drivenum, ramsize;
void printdata()
{
    std::cout << "a.\t the number of printers connected to the computer: " << printernum << std::endl;
    std::cout << "b.\t the number of floppy drives: " << drivenum << std::endl;
    std::cout << "c.\t the size of the ram: " << ramsize << std::endl;
}

// Question 5 Vars and Frunctions
short registerData, workingCount = 0, defectiveCount = 0, i = 1, sprinkerOnCount = 0, defectiveSprinkler = 0, registerContent = 0x6A2F, loopCounter = 1;

void Base2()
{
    short x = 1 << 15, t;
    short n = registerData;
    std::cout << "AX = ";
    for (int i = 1; i <= 16; ++i)
    {
        t = n & x;
        if (t == 0)
        {
            std::cout << 0;
        }
        else
        {
            std::cout << 1;
        }
        if (i % 4 == 0)
        {
            std::cout << " ";
        }
        n = n << 1;
    }
}

void displayNumberOn()
{
    std::cout << "\n"
              << sprinkerOnCount << " sprinklers are ON" << std::endl;
}

void displaySprinklersFormat()
{
    std::cout << "Defective sprinklers: ";
}

void displaySprinklers()
{
    std::cout << defectiveSprinkler << " ";
}
int main()
{
    // QUESTION 1
    // Print menu
    std::cout << "--------------7-11 Convenient Store---------------" << std::endl;
    std::cout << std::endl
              << "Drinks" << std::endl;
    std::cout << "Soda (S)....................$2" << std::endl;
    std::cout << "Water (W)...................$1" << std::endl;
    std::cout << std::endl
              << "Sandwiches" << std::endl;
    std::cout << "10 inches...................$3" << std::endl;
    std::cout << "12 inches...................$5" << std::endl;
    std::cout << std::endl;

    _asm {
        // calls askCustomers for input
			call askCustomers;
        // bx = customers
			mov bx, customers;
        // i = 1
			mov i, 1;
        // for loop beginning
		forloop:
            // compare i with customers
			cmp i, bx;
        // if i !<= to customers, then jump to done
			jnle done;
        // calls readData for input
			call readData;

        // Compares drink_type with S for soda
			cmp drink_type, 'S';
        // Jump to Soda calculation
			Je Soda;
        // Compares drink_type with s for soda
			cmp drink_type, 's';
        // Jump to Soda calculation
			Je Soda;

        // Compares drink_type with W for soda
			cmp drink_type, 'W';
        // Jump to Water calculation
			Je Water;
        // Compares drink_type with w for soda
			cmp drink_type, 'w';
        // Jump to Water calculation
			Je Water;

        // Soda calculation
		Soda:
            // ax = soda
			mov ax, soda;
        // ax * drink_num, multiplies soda with drink_num
			imul drink_num;
        // total = ax, moves total to the product
			mov total_d, ax;
        // after calculation, jump to Sandwich selection
			Jmp Sandwich;

        // Water calculation
		Water:
            // ax = water
			mov ax, water;
        // ax * drink_num, multiplies water with drink_num
			imul drink_num;
        // total = ax, moves total to the product
			mov total_d, ax;
        // after calculation, jump to Sandwich selection
			Jmp Sandwich;

        // Sandwich selection
		Sandwich:
            // comapres user input between sanwich and size ten
			cmp sandwich_size, '10';
        // jump to size Ten calculation
			Je Ten;
        // compares user input between sandwich and size twelve
			cmp sandwich_size, '12';
        // jump to size Twelve calculation
			Je Twelve;

        // Ten calculation
		Ten:
            // ax = ten_inch, so ax = 3
			mov ax, ten_inch;
        // multiplies sandwich amount by 3
			imul sandwich_num;
        // total = ax, moves total to the product
			mov total_s, ax;
        // jump to Total calculation
			Jmp Total;

        // Twelve calculation
		Twelve:
            // ax = twelve_inch, so ax = 5
			mov ax, twelve_inch;
        // multiplies sandiwhc amount by 5
			imul sandwich_num;
        // total = ax, moves total to the product 
			mov total_s, ax;
        // jump to Total calculation 
			Jmp Total;

        // Total calculation
		Total:
            // ax = total_D, so ax = total drink bill
			mov ax, total_d;
        // add ax with total sandwich bill
			add ax, total_s;
        // total = ax, so moves the overall sum of the bill to total
			mov total, ax;
        // calls the function to display the customer total
			call showTotal;

        // increment i for for loop
			inc i;
        // jumps to the for loop 
			Jmp forloop;
		done:
    }

    // QUESTION 2
    std::cout << "QUESTION 2\n";
    _asm {
        // While Loop
		whileLoop:
            // readScore()
			call readScore;
        // Move user input into eax register
			mov eax, input
            // Compare input with -1 
			cmp input, -1;
        // If input == -1 compute average
			JE computeAvg;

        // Else
        // Add user score to total
			add eax, totalSum;
        // Mov eax into totalSum
			mov totalSum, eax;
        // Increase numStudent
			inc numStudent;
        // Jump back to while loop
			jmp whileLoop;

        // Compute average
		computeAvg:
            // Move totalSum into eax register
			mov eax, totalSum;
        // Convert into quad for division
			cdq;
        // Divide by numStudent
			idiv numStudent;
        // mov eax into userAvg
			mov userAvg, eax;
        // displayAvg()
			call displayAvg;
        // Done
			jmp done;

		done:
    }

    // QUESTION 3
    _asm
    {
        // Read user sentence
        call readUserSentence;

        // For loop
    forLoop:
        // Move index into ax register
        mov ax, index;
        // Compare ax with sentence length
        cmp ax, sentenceLen;
        // If not within loop jump to displayFunc
        Jnl displayFunc;

        // getCurrentChar()
        call getCurrentChar;
        // Move currentChar into ecx register
        movzx ecx, currentChar;
        // Compare with ascii values according
        cmp currentChar, 65;
        Jl notChar;
        cmp currentChar, 90;
        Jle upperChar;
        cmp currentChar, 97;
        Jl notChar;
        cmp currentChar, 122;
        Jle lowerChar;

        // currentChar is not a letter
    notChar:
        // Update index
        mov ax, index;
        inc ax;
        mov index, ax;
        // Jump to for loop
        jmp forLoop;

        // currentChar is Uppercase
    upperChar:
        // Update index
        mov ax, index;
        inc ax;
        mov index, ax;
        // Update upperCaseCount
        mov bx, UpperCaseCount;
        inc bx;
        mov UpperCaseCount, bx;
        // Jump to for loop
        jmp forLoop;

        // currentChart is Lowercase
    lowerChar:
        // Update index
        mov ax, index;
        inc ax;
        mov index, ax;
        // Update LowerCaseCount
        mov bx, LowerCaseCount;
        inc bx;
        mov LowerCaseCount, bx;
        // Jump to for loop
        jmp forLoop;

        // displayCounts()
    displayFunc:
        call displayCounts;
    }

    // question 4
    _asm {

        // printer
		printer:
            // move register content into register
			mov bx, 1100111010011100b;
        // shift right 13 bits to leave 15 and 16th bits
			shr bx, 14;
        // compare register with printer values and jump to according condition
        // printer == 00b
			cmp bx, 00b;
			je printer0;
        // printer == 01b
			cmp bx, 01b;
			je printer1;
        // printer == 10b
			cmp bx, 10b;
			je printer2;
        // printer == 11b
			cmp bx, 11b;
			je printer3;

        // update printernum accordingly and jump to floppy
		printer0:
			mov printernum, 00b;
			jmp floppy;
		printer1:
			mov printernum, 01b;
			jmp floppy;
		printer2:
			mov printernum, 10b;
			jmp floppy;
		printer3:
			mov printernum, 11b;
			jmp floppy;

        // floppy
		floppy:
            // move register content into register
			mov bx, 1100111010011100b;
        // shift right 6 bits to remove bits 1-6
			shr bx, 6;
        // shift left 14 to remove bits 9 - 16
			shl bx, 14;
        // shift right to clear and reset bit 7 and 8 in the 1 and 2 position 
			shr bx, 14;

        // compare register with floppy values and jump to according condition
        // floppy = 00b
			cmp bx, 00b;
			je floppy0;
        // floppy = 01b
			cmp bx, 01b;
			je floppy1;
        // floppy = 10b
			cmp bx, 10b;
			je floppy2;
        // floppy = 11b
			cmp bx, 11b;
			je floppy3;

        // update drivenum accordingly and jump to ram
		floppy0:
			mov drivenum, 1;
			jmp ram;
		floppy1:
			mov drivenum, 2;
			jmp ram;
		floppy2:
			mov drivenum, 3;
			jmp ram;
		floppy3:
			mov drivenum, 4;
			jmp ram;

        // ram
		ram:
            // move register content into register
			mov bx, 1100111010011100b;
        // shift to the right to remove bits 1 -2
			shr bx, 2;
        // shift to the left to remove remaining bits
			shl bx, 14;
        // shift right to reset bit positioning
			shr bx, 14;

        // compare register with ram values and jump to according condition
        // ram = 00b
			cmp bx, 00b;
			je ram0;
        // ram = 01b
			cmp bx, 01b;
			je ram1;
        // ram = 10b
			cmp bx, 10b;
			je ram2;
        // ram = 11b
			cmp bx, 11b;
			je ram3;

        // update ramsize accordingly and jump to done 
		ram0:
			mov ramsize, 16;
			jmp done;
		ram1:
			mov ramsize, 32;
			jmp done;
		ram2:
			mov ramsize, 48;
			jmp done;
		ram3:
			mov ramsize, 64;
			jmp done;

		done:
            // print out information
			call printdata;
    }

    // QUESTION 5
    _asm
    {
        // Move registerContent into ax register
        mov ax, registerContent;
        // Move ax into registerData
        mov registerData, ax;
        // Base2()
        call Base2;

        // Update ax register
        mov ax, registerData;
        // Move 0000000000000001 into bx for bitwise operations
        mov bx, 0000000000000001b;

        // For Loop
    forLoop:
        // Update ax register with registerData
        mov ax, registerData;
        // AND operation
        and ax, bx;
        // Compare result with 0
        cmp ax, 0;
        // If not 0 then there is a sprinkler there
        Jg incSprinkerCounter;
        // Jump to continueLoop
        Jmp contineLoop;

        // contineLoop
    contineLoop:
        // Compare loopCounter
        cmp loopCounter, 17;
        // If loopCounter is <= 17 Jump to shiftLeft
        Jle shiftLeft;
        // Else jump endForLoop
        Jmp endForLoop;

        // IncreaseSprinklerCounter
    incSprinkerCounter:
        // Increase sprinkerOnCount
        inc sprinkerOnCount;
        // Jump to shiftLeft
        Jmp shiftLeft;

        // shiftLeft Operation
    shiftLeft:
        // Increase loopCounter
        inc loopCounter;
        // Shift bx left 1
        shl bx, 1;
        // Jump forLoop
        Jmp forLoop;

        // endForLoop
    endForLoop:
        // displayNumberOn()
        call displayNumberOn;
        // displaySprinklersFormat
        call displaySprinklersFormat;
        // Move registerContent into ax
        mov ax, registerContent;
        // Move ax into registerData
        mov registerData, ax;
        // Move 0000000000000001 into bx
        mov bx, 0000000000000001b;

        // forLoop2
    forLoop2:
        // Compare i with 17 (loop condition)
        cmp i, 17;
        // If i == 17 jump to done
        Je done;
        // Move registerData into ax
        mov ax, registerData;
        // AND operation
        and ax, bx;
        // Compare AND result with 0
        cmp ax, 0;
        // If result == 0 sprinkler is defective
        Je defectiveSprinklers;
        // Shift bx register left 1
        shl bx, 1;
        // Increase i
        inc i;
        // Jump forLoop2
        Jmp forLoop2;

        // defectiveSprinklers
    defectiveSprinklers:
        // Move i into cx register
        mov cx, i;
        // Move cx into defectiveSprinkler (sprinklerNumber or Position)
        mov defectiveSprinkler, cx;
        // displaySprinklers
        call displaySprinklers;
        // Shift bx register left 1
        shl bx, 1;
        // Increase i
        inc i;
        // Jump forLoop2
        Jmp forLoop2;

        // Done
    done:
    }
    return 0;
}