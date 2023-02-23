# Mersenne-prime-calculator
Calculates Mersenne primes, numbers of the form 2^n-1, where n is an integer which for certain values will produce prime numbers. The first such examples of are n = 2, 3, 5, 7, 13, 17, 19 and 31. The largest prime yet found is of this form when n = 82,589,933. This code is designed to calculate this prime number as well as any other Mersenne prime the user desires.

## Composition
The code works by first setting a target value for the index n, we then choose a base to work in. A larger base than 10 decreases the time for the code to run. Here we choose 10^9. Using logarithms, the code then calculates the number of digits in the answer and initialises an array with that many digits. We then times the number in this array by a multiplier, chosen to be large to increase efficiency, here 2^25. We then finish the calculation by multiplying by two the necessary number of times to reach the desired index. Then we subtract 1 and print to screen or save the found number as a text file.

## Finding number of digits in the prime to calculate
An important part of the code is finding the number of digits in the prime to be calculated. There is a pdf included in the files which describes how this bit of maths works.

## Largest known prime
Also included is a file containing the result of the calculation for the largest prime currently known. The sum for this is 2^82,589,933 a number which contains nearly 25 million digits!
