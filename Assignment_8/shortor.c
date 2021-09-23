// Assignment 8 for Computer Organization (CSCI 304)
// By Kirill Usubyan. Due 5/7/21
//shortor.c file
#include <stdio.h>

//returns the negation of num
int neg (int num){
    // creates copy
    int numCopy = num;
    // negates through subtracting num twice from the copy
    numCopy = numCopy - num;
    numCopy = numCopy - num;
    return numCopy;
}

//computes and returns the product of x and y by recursively adding x to itself y times (this
//function should only be called for positive x and y, and with x > y, when possible)
int rmult (int x, int y){
    // checks for condition
    if (x > 0 && y > 0){
        // base case
        if(y == 1){
            // return x
            return x;
        // recursive case
        }else{
            // return x + result of recursive call with y-1
            return x + rmult(x, y-1);
        }
    }else{
        printf("Invalid multiplication");
        return 0;
    }
}

//returns the square of num
//negate num, if necessary; use rmult to help
int square (int num){
    // negate num if necessary
    if(num < 0){
        num = neg(num);
    }
    // rmult calculates square
    return rmult(num, num);
}

//computes and returns the factorial value of n through recursion
int rfact (int n){
    int result;
    int prevVal;
    // base case
    if (n <= 1){
        // result is 1 in base case
        result = 1;
    // recursive case
    }else{
        // recursive call for n-1
        prevVal = rfact(n-1);
        // multiply result of recursive call * n
        result = rmult(prevVal, n);
    }
    // return result
    return result;
}

int main(void){
    // input
    int input[4] = {4, -9, 13};
    short index = 0;
    int num = input[index];
    int negNum;
    int squareNum;
    int num2;
    int numFact;
    int status;
    while (num != '\0')
    {
        // print num in dec and hex
        printf("%13d    %#010x\n", num, num);
        // get negation of num and print result
        negNum = neg(num);
        printf("%13d    %#010x\n", negNum, negNum);
        // get square of num and print result
        squareNum = square(num);
        printf("%13d    %#010x\n", squareNum, squareNum);
        // set num2 to absolute value of num
        num2 = num;
        if(num < 0){
            num2 = negNum;
        }
        // get factorial for absolute val of num
        numFact = rfact(num2);
        printf("%13d    %#010x\n", numFact, numFact);
        // set status to 0
        status = 0;
        //if num is odd, set the lsb of status by adding an appropriate number
        // bitwise test for odd
        if((num & 1) > 0){
            // add 2^0 to status
            status += 1;
        }        
        // if num is negative, set the next lsb of status by adding
        if(num < 0){
            // add 2^1 to status
            status += 2;
        }
        // if square of num > 100, set the next lsb of status by adding
        if(squareNum > 100){
            // add 2^2 to status
            status += 4;
        }
        // set a 1 in the 2^4 column so that 0 status can be shown
        status += 16;
        // print status in hex
        printf("                 %#010x\n", status);
        // print hex row of 1’s to separate from next num
        printf("                 0x11111111\n");
        // increment to next value in array
        index += 1;
        num = input[index];
    }
    return 0;
}
