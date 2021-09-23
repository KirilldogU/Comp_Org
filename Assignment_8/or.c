//returns the bitwise complement of num
int comp (int num){
    return ~num;
}
//returns the negation of num
int neg (int num){
    return -1*(num);
}
//returns the bitwise or of x and y (i.e., x | y)
//use DeMorgan’s Law to compute or: ~(~x & ~y)
int or (int x, int y){
    return ~(~x & ~y);
}
//computes and returns the product of x and y by recursively adding x to itself y times (this
//function should only be called for positive x and y, and with x > y, when possible)
int rmult (int x, int y){
    if (x > 0 && y > 0){
        if(y == 1){
            return x;
        }else{
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
    return rmult(num, num);
}

//computes and returns the factorial value of n through recursion
int rfact (int n){
    
}

int rshift (int x, int pos){

}

void setbit (int *x, int bit){

}

int main(void){

}
