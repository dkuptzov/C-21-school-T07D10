#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int number_of_matrix_view();
int input_in_matrix(int *arr);
int input_size(int *size);
int input(int *a, int cols, int rows);
void output(int *a, int cols, int rows);
void max(int *a, int cols, int rows);
void min(int *a, int cols, int rows);

int main()
{
    int error = 0;
    int arr[2] = {0, 0};
    int matrix_view = number_of_matrix_view();
    if (matrix_view == 1)
    {
        for (int i = 0; i < 2; i++) {
            if (!scanf("%d", &arr[i]) || (arr[i] <= 0) || (arr[i] > 100)) {
                error = -1;
            }
            if (arr[0] == 0 || arr[1] == 0)
            {
                error = -1;
            }
        }
        int matrix[arr[0] * arr[1]];
        error = input(matrix, arr[0], arr[1]);
        if (error != -1)
        {
            output(matrix, arr[0], arr[1]);
            max(matrix, arr[0], arr[1]);
            min(matrix, arr[0], arr[1]);
        }
    }
    else if (matrix_view == 2)
    {
        error = input_in_matrix(arr);
        int *matrix = (int*)malloc(arr[0] * arr[1] * sizeof(int));
        error = input(matrix, arr[0], arr[1]);
        if (error != -1)
        {
            output(matrix, arr[0], arr[1]);
            max(matrix, arr[0], arr[1]);
            min(matrix, arr[0], arr[1]);
        }
    }
    else if (matrix_view == 3)
    {
        error = input_in_matrix(arr);
        int *matrix = calloc(arr[0] * arr[1], sizeof(int));
        error = input(matrix, arr[0], arr[1]);
        if (error != -1)
        {
            output(matrix, arr[0], arr[1]);
            max(matrix, arr[0], arr[1]);
            min(matrix, arr[0], arr[1]);
        }
    }
    else if (matrix_view == 4)
    {
        error = input_in_matrix(arr);
        int *matrix_first = (int*)malloc(sizeof(int));
        int *matrix = realloc(matrix_first, arr[0] * arr[1] * sizeof(int));
        error = input(matrix, arr[0], arr[1]);
        if (error != -1)
        {
            output(matrix, arr[0], arr[1]);
            max(matrix, arr[0], arr[1]);
            min(matrix, arr[0], arr[1]);
        }
    }
    if (error == -1)
    {
        printf("n/a");
    }
    return 0;
}

int number_of_matrix_view()
{
    int view = 0;
    if (!scanf("%d", &view) || (view <= 0) || (view > 4)) {
        view = -1;
    }
    return view;
}

int input_in_matrix(int *a)
{
    int error = 0;
    for (int i = 0; i < 2; i++) {
        if (!scanf("%d", &a[i])) {
            error = -1;
        }
    }
    if (a[0] == 0 || a[1] == 0)
    {
        error = -1;
    }
    return error;
}

int input(int *a, int cols, int rows)
{
    int error = 0;
    for (int i = 0; i < cols * rows; i++)
    {
        if (!scanf("%d", &a[i]))
        {
            error = -1;
        }
    }
    return error;
}

void output(int *a, int cols, int rows)
{
    int count = 0;
    for (int i = 0; i < (cols * rows); i++)
    {
        if (count == rows - 1)
        {
            printf("%d", a[i]);
            printf("\n");
            count = 0;
        }
        else
        {
            printf("%d ", a[i]);
            count++;
        }
    }
}

void max(int *a, int cols, int rows)
{
    int count = 0;
    int maximum_in_string = a[0];
    for (int i = 0; i < cols * rows; i++)
    {
        if (count < rows)
        {
            if (a[i] > maximum_in_string)
            {
                maximum_in_string = a[i];
            }
            count++;
        }
        else
        {
            printf("%d ", maximum_in_string);
            maximum_in_string = a[i];
            count = 1;
        }
    }
    printf("%d", maximum_in_string);
    printf("\n");
}

void min(int *a, int cols, int rows)
{
    int min[cols], count = 0;
    for (int i = 0; i < cols; i++)
    {
        min[i] = a[i];
    }
    for (int j = cols; j < cols * rows; j++)
    {
        if (count < cols)
        {
            if (a[j] < min[count])
            {
                min[count] = a[j];
            }
            count++;
        }
        else
        {
            count = 0;
            if (a[j] < min[count])
            {
                min[count] = a[j];
            }
        }
    }
    for (int k = 0; k < cols - 1; k++)
    {
        printf("%d ", min[k]);
    }
    printf("%d", min[cols - 1]);
    free((int *)a);
}
