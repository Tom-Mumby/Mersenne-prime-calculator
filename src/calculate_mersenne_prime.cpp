/*Calculates Mersenne primes, numbers of the form 2^n-1, where n is an integer which for certain values will
produce prime numbers. The first such examples of n are 2, 3, 5, 7, 13, 17, 19 and 31. The largest prime yet found
is of this form with n=82,589,933. This code is designed to calculate this number and print it to the screen or
save it to a file as well as any other Mersenne prime the user desires.

Code works by first setting a target value for the index n, we then choose a base to work in. A larger base than 10
decreases the time for the code to run. Here we choose 10^9. Using logarithms, then calculate the number of digits
in the answer and initialise an array with that many digits. We then times the number in this array by a multiplier
chosen to be large to increase effiency here, 2^25. We then finish the calculation by multiplying by two the nesserery
number of times to reach the desired index. Then finally we subtract 1 and print to screen or save the number as a 
file.*/

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <math.h>
#include "print_arrays.h"
using namespace std;

// sets the power of two to calculate i.e 2^targetIndex
const int targetIndex = 110503; //82589933;
// sets base to do the calculation in (doesn't have to be 10^n)
const int base = pow(10,9);
//sets power of two to multiply by
const int multiplierIndex = 25;
const int multiplier = pow(2, multiplierIndex);

long double digitsPerIndex = 1 / log2 (base);  // digits per additional 1 in index
const double digitsPerMultiplier = digitsPerIndex * multiplierIndex;  // digits per additional mulitplier

// total number of digits in answer
const int totalDigits = ceil(targetIndex * digitsPerIndex);
//sets the number of times to multiply it by multiplier
const int multiplierTimes = targetIndex / multiplierIndex;
//sets the number of times to muliply it by 2
const int mulitplyByTwoTimes = targetIndex % multiplierIndex;
// main array to hold the result of the calculation
int* resultArray = new int[totalDigits];


void multiply_by_number(int numTimes, int multiplier, bool truncateCalculation) {
    // number of digits in number currently
    int numDigitsNow = totalDigits;
    // used to hold the result of the multiplication
    unsigned long long int multiplicationResult;
    // holds the remainder when the multiplication result is divided by the base
    int remainder;
    // holds the number to carry to the next iteration to add to the next digit
    int carry;
    // stores the number for use in the next iteration
    int carryFromLastIteration = 0;
    int i = 0;
    while (i < numTimes){

        if (truncateCalculation){  //terminate calculation after last current digit
            numDigitsNow = ceil(i * digitsPerMultiplier) + 1;  // set number of digits currently in array
        }

        for (int j = 0; j < numDigitsNow; j++) {  // loop over digits in array

            multiplicationResult = (long long) multiplier * resultArray[j];  // perform multiplication and cast to long long

            carry = multiplicationResult / base;  // next digit along
            remainder = (multiplicationResult % base) + carryFromLastIteration;  // current element value and add any digits from previous iteration
    
            if (remainder < base ){  // if the value fits in the base
                        resultArray[j] = remainder;  // set current element
                    }else{  // if value overruns
                        resultArray[j] = (remainder % base);  // set current element as remainder
                        carry++;  // increase value of next iteration by one
                    }
            
            carryFromLastIteration = carry;  // set the amount to increase the value in the next iteration by

            }
        i++;
    }
}

int main()
{   
    //starts timer
    auto start = std::chrono::high_resolution_clock::now();

    //sets array values to 0
    for(int i=0; i < totalDigits; i++){
        resultArray[i] = 0;
    }

    // sets first number in array to 1
    resultArray[0] = 1;
    cout << "Number of array elements: " << totalDigits << endl;
    cout << "Number of digits: " << ceil(targetIndex * log10 (2)) << endl;

    // multiplies array a set number of times by power of two multiplier
    multiply_by_number(multiplierTimes, multiplier, true);
    // multiplies array by two a set number of times to find 2^n
    multiply_by_number(mulitplyByTwoTimes, 2, false);
    // takes one off answer
    resultArray[0]--;

    print("Finished calculation");
    // outputs the time taken
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

    // will take some time to print long numbers to screen
    //print_array_backwards_to_screen(resultArray,totalDigits,base);
    write_array_to_file(resultArray, totalDigits, base);

    // deletes array
    delete[] resultArray;

    std::cout << "\nElapsed time: " << elapsed.count() << " s\n";
	return 0;
}
