#include <stdio.h>

// func returns summation for argument n
int summation(int n){
    int retVal = 0;
    short summationRound = 0; // variable tracks i
    short adds = 0;
    // outer loop subtracts -10
    do{
        adds = 0; 
        // loop adds 7, i times
        while (adds < summationRound)
        {
            retVal += 7;    //adds 7 to sum
            adds++;
        }
        // subtracts 10 from sum
        retVal += -10;
        summationRound++; // increments summation round (i)
    }while (summationRound <= n); // repeat until summation round = n
    return retVal;    // return sum
}

int main(void){
    short n = 10;   //maximum n value
    short curN = 0;
    int retVal;
    // loop runs through all summations up to maximum n value
    do{
        printf("%2d  %x :", curN, curN);    // prints n
        retVal = summation(curN);
        printf("%6d   %08x\n", retVal, retVal); // prints sum
        curN++;
    }while (curN <= n); // until curN reaches maximum n
}