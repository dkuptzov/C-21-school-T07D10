#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

int input(int *a, int *n);
int sort(int *a, int n);
int output(int *a, int n);

int main() {
    int n;
    if (!scanf("%d", &n)) {
        return 1;
    }
    int *arr = (int*) malloc(n * sizeof(int));
    // ввод данных и проверка на корректность
    int error = input(arr, &n);
    if (error == 1) {
        printf("n/a");
        return 0;
    }
    sort(arr, n);
    output(arr, n);
    free((int*)arr);
    return 0;
}

// функция ввода данных в массив
int input(int *a, int *n) {
    for (int i = 0; i < *n; i++)
    {
        if (!scanf("%d", &a[i])) {
            return 1;
        }
    }
    return 0;
}

int sort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return 0;
}

int output(int *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", a[i]);
    }
    printf("%d", a[n - 1]);
    return 0;
}
