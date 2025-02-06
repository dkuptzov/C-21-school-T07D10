#include <stdio.h>
#include <stdlib.h>

int test(int *x);

int main() {
    int y = 10;
    int *x = &y;
    printf("%d", y);
    test(x);
    printf("%d", y);
}

int test(int *x)
{
    *x = 5;
    printf("%d", *x);
}
