#include <stdio.h>

// create an array and fill it with first 20 multiples of 3
// add up all of the odd values in the array


void main ()

{
   int arr[20];

   int i;
   int sum;
   int mult3;


   // fill array with multiples of 3
   i = 0;
   mult3 = 0;

   do {

      arr[i] = mult3;
      mult3 += 3;
      i++;

   } while (i < 20);

   // add up only odd values in array
   i = 0;
   sum = 0;

   do {

      if (arr[i] & 1)

         sum += arr[i];

      i++;

   } while (i < 20);

   printf ("sum: %d\n", sum);
}

