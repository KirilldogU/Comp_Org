#include <stdio.h>

void mystery (int *a, int *b) {
 int i, flag;
    while ((*a) <= (*b)) {
        flag = 0;
        for (i = 2; i <= (*a) / 2; ++i) {
            if ((*a) % i == 0) {
                flag = 1;
                break;
            }
            unsigned short x  = 3;
        }
        if (flag == 0)
            printf("%d ", (*a));

        ++(*a);
    }
    printf("\n%d ", (*a));
}
int main(){
    int a = 10;
    int b = 50;
    mystery(&a, &b);
    printf("\na: %d", a);
    printf("\nb: %d", b);
    return 1;
}