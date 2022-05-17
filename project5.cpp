// CPSC 240 Project 5
#include <iostream>

// Question 1 Vars and Init
short totalShirtNum = 0, medShirtNum = 0, blueShirtNum = 0,
      loopCount = 0;
int shirtArray[4][4] = {10, 20, 30, 40, 20, 10, 40,
                        30, 5, 15, 20, 25, 30, 25, 20, 15};

// Display counts of shirts
void displayCounts()
{
    std::cout << "a. Compute and display the total number of All shirts:  " << totalShirtNum << std::endl;
    std::cout << "b. Compute and display the total number of Medium shirts:  " << medShirtNum << std::endl;
    std::cout << "c. Compute and display the total number of Blue shirts:  " << blueShirtNum << std::endl;
}

// Question 2 Vars and Init
int i, j, a[5] = {9, 3, 22, 8, 1};

// Question 3 Vars and Init
short totalShirtNum3d = 0, medShirtNum3d = 0, shortSleeveShirtNum3d = 0, redShirtNum3d = 0, loopCount3d = 0;
int shirtArray3d[3][3][2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};

// Display counts of shirts 3d array
void displayCounts3d()
{
    std::cout << "a. Total number of All shirts: " << totalShirtNum3d << std::endl;
    std::cout << "b. Total number of Medium size shirts: " << medShirtNum3d << std::endl;
    std::cout << "c. Total number of Short Sleeve shirts: " << shortSleeveShirtNum3d << std::endl;
    std::cout << "d. Total number of Red shirts: " << redShirtNum3d << std::endl;
}

int main()
{
    // QUESTION 1
    _asm {
        // Move shirt array into esi
		lea esi, [shirtArray];
        // Move totalShirtNum into ax
		mov ax, totalShirtNum;

        // For Loop
	forLoop:
            // For loop condition compare
		cmp loopCount, 16;
        // Break out of for loop
		Jnl continuePartTwo;

        // Add current esi element into eax register
		add eax, [esi];
        // Increase loop counter
		inc loopCount;
        // Move array up one element
		add esi, 4;
        // Jump to start of For loop
		Jmp forLoop;

        // Part two of Question 1 
	continuePartTwo:
            // Move ax into totalShirtNum
		mov totalShirtNum, ax;
        // Move shirtArray into esi
		lea esi, [shirtArray];
        // Move redShirtNum into ax
		mov ax, medShirtNum;
        // Step through array and update ax register
		add esi, 4;
		add ax, [esi];
		add esi, 16;
		add ax, [esi];
		add esi, 16;
		add ax, [esi];
		add esi, 16;
		add ax, [esi];
        // Continue to part three
		Jmp continuePartThree;

        // Part three of Question 1 
	continuePartThree:
            // Move ax into redShirtNum
		mov medShirtNum, ax;
        // Move shirtArray into esi
		lea esi, [shirtArray];
        // Move blueShirtNum into ax;
		mov ax, blueShirtNum;
        // Step through array increasing ax 
		add esi, 32;
		add ax, [esi];
		add esi, 4;
		add ax, [esi];
		add esi, 4;
		add ax, [esi];
		add esi, 4;
		add ax, [esi];
        // Update blueShirtNum with ax
		mov blueShirtNum, ax;
        // Jump to done
		Jmp done;

        // Done
	done:
		call displayCounts;
    }

    // QUESTION 2

    // Print out current array content
    std::cout << "Original array a: 9, 3, 22, 8, 1" << std::endl;

    _asm {
        // Move 0 into i
		mov i, 0;
        // For loop
	forloop:
            // For loop condition
		cmp i, 4;
        // Break out of four loop
		jnl done;
        // Update j with 0 value
		mov j, 0;
        // Increase i (loop counter)
		inc i;
        // Move array into esi
		lea esi, [a];
        // Jump to inner loop
		Jmp forloop2;

        // for loop 2 (inner loop)
	forloop2:
            // Inner loop condition
		cmp j, 4;
        // Break to outter for loop
		jnl forloop;
        // Move esi element into eax
		mov eax, [esi];
        // Move esi + 1 element into ebx
		mov ebx, [esi + 4];
        // Compare eax and ebx
		cmp eax, ebx;
        // If ebx is greater than eax jump to swap_nodes
		jg swap_nodes;
        // Else increase esi index
		add esi, 4;
        // Increase j (inner loop counter)
		inc j;
        // Jump to inner loop
		jmp forloop2;

        // Swap nodes
	swap_nodes:
            // Move esi element into eax
		mov eax, [esi];
        // Move eax into ebx
		mov ebx, eax;
        // Swap eax and esi + 4 element
		xchg eax, [esi + 4];
        // Move eax into esi
		mov[esi], eax;
        // Increase inner loop counter 
		inc j;
        // Update esi current element
		add esi, 4;
        // Jump back to fourLoop2
		jmp forloop2;

        // Done
	done:
    }
    // Question 2 display current content

    std::cout << "Sorted array a: ";

    for (int y = 0; y < 5; y++)
    {
        std::cout << a[y] << "  ";
    }

    // QUESTION 3
    _asm {
        // Move shirtArray3d into esi
		lea esi, [shirtArray3d];
        // Move totalShirtNum3d into ax
		mov ax, totalShirtNum3d;

        // For loop
	forLoop:
            // For loop condition
		cmp loopCount3d, 18;
        // For loop break
		Jnl continuePartTwo3d;

        // Add eax with shirtArray3d element
		add eax, [esi];
        // Increae loop counter
		inc loopCount3d;
        // Increase array element 
		add esi, 4;
        // Jump back to for loop
		Jmp forLoop;

        // Part two question 3 
	continuePartTwo3d:
            // Move ax into totalShirtNum3d
		mov totalShirtNum3d, ax;
        // Move shirtArray3d into esi
		lea esi, [shirtArray3d];
        // Move redShirtNum3d into ax
		mov ax, medShirtNum3d;
        // Step through array increasing ax register
		add esi, 4;
		add ax, [esi];
		add esi, 12;
		add ax, [esi];
		add esi, 12;
		add ax, [esi];
		add esi, 12;
		add ax, [esi];
		add esi, 12;
		add ax, [esi];
		add esi, 12;
		add ax, [esi];
        // Update redShirtNum3d with ax value
		mov medShirtNum3d, ax;
        // Jump to part three 
		Jmp continePartThree3d;

        // Part three question 3
	continePartThree3d:
            // Move shirtArray3d into esi register
		lea esi, [shirtArray3d];
        // Move shortSleeveShirtNum3d into ax
		mov ax, shortSleeveShirtNum3d;
        // Update loop counter
		mov loopCount3d, 0;

        // For loop 2 
	forLoop2:
            // For loop condition
		cmp loopCount3d, 9;
        // Jump to part four
		Jnl continuePartFour3d;

        // Increase ax with esi element
		add ax, [esi];
        // Increase loop counter
		inc loopCount3d;
        // Increase array index
		add esi, 4;
        // Jump back to for loop 2
		Jmp forLoop2;

        // Part four Question 3 
	continuePartFour3d:
            // Update shortSleeveShirtNum3d with ax register
		mov shortSleeveShirtNum3d, ax;
        // Move shirtArray3d into esi
		lea esi, [shirtArray3d];
        // Move redShirtNum into ax
		mov ax, redShirtNum3d;
        // Step through array increasing ax 
		add ax, [esi];
		add esi, 4;
		add ax, [esi];
		add esi, 4;
		add ax, [esi];
		add esi, 28;
		add ax, [esi];
		add esi, 4;
		add ax, [esi];
		add esi, 4;
		add ax, [esi];
        // Move ax value into redShirtNum3d
		mov redShirtNum3d, ax;
        // Done
        // displayCounts3d()
		call displayCounts3d;
    }
    return 0;
}