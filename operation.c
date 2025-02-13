#include <stdio.h>

void sa(int *stack_a, int size)
{
    int tmp;

    if (size >= 2)
    {
        tmp = stack_a[0];
        stack_a[0] = stack_a[1];
        stack_a[1] = tmp;
    }
}
void sb(int *stack_b, int size)
{
    int tmp;
    if (size >= 2)
    {
        tmp = stack_b[0];
        stack_b[0] = stack_b[1];
        stack_b[1] = tmp;
    }
}
void ss(int *stack_a, int size_a, int *stack_b, int size_b)
{
    sa(stack_a, size_a);
    sa(stack_b, size_b);
}

void push_a(int *stack_a, int *size_a, int *stack_b, int *size_b) {
    if (*size_b == 0)
        return;

    int i = *size_a;
    while (i > 0) {
        stack_a[i] = stack_a[i - 1];
        i--;
    }

    stack_a[0] = stack_b[0];
    (*size_a)++;

    i = 0;
    while (i < *size_b - 1) {
        stack_b[i] = stack_b[i + 1];
        i++;
    }
    (*size_b)--;
}

