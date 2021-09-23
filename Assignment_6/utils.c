#include "utils.h"
#include <string.h>

// method uppercases the lowercase letters in argument char[] 
void upper (char str []){
    // iterates through []
    short index;
    for (index=0; index<strlen(str); index++){
        // checks for lowercase char
        if('a' <= str[index] && 'z' >= str[index]){
            //converts to uppercase using ascii vals
            str[index] = str[index] - 32;
        }
    }
}