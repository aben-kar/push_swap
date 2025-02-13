#include <stdio.h>
#include <stdlib.h>

// Swap the first two elements of stack a
void sa(int *stack_a, int size_a) {
    if (size_a >= 2) {
        int temp = stack_a[0];
        stack_a[0] = stack_a[1];
        stack_a[1] = temp;
    }
}

// Swap the first two elements of stack b
void sb(int *stack_b, int size_b) {
    if (size_b >= 2) {
        int temp = stack_b[0];
        stack_b[0] = stack_b[1];
        stack_b[1] = temp;
    }
}

// Perform sa and sb at the same time
void ss(int *stack_a, int size_a, int *stack_b, int size_b) {
    sa(stack_a, size_a);
    sb(stack_b, size_b);
}

// Push the first element of stack b to stack a
void pa(int *stack_a, int *size_a, int *stack_b, int *size_b) {
    if (*size_b > 0) {
        // Shift stack a to make space for the new element
        for (int i = *size_a; i > 0; i--) {
            stack_a[i] = stack_a[i - 1];
        }
        // Move the first element of stack b to stack a
        stack_a[0] = stack_b[0];
        (*size_a)++;
        // Shift stack b to remove the first element
        for (int i = 0; i < *size_b - 1; i++) {
            stack_b[i] = stack_b[i + 1];
        }
        (*size_b)--;
    }
}

// Push the first element of stack a to stack b
void pb(int *stack_a, int *size_a, int *stack_b, int *size_b) {
    if (*size_a > 0) {
        // Shift stack b to make space for the new element
        for (int i = *size_b; i > 0; i--) {
            stack_b[i] = stack_b[i - 1];
        }
        // Move the first element of stack a to stack b
        stack_b[0] = stack_a[0];
        (*size_b)++;
        // Shift stack a to remove the first element
        for (int i = 0; i < *size_a - 1; i++) {
            stack_a[i] = stack_a[i + 1];
        }
        (*size_a)--;
    }
}

// Rotate stack a (shift up by 1)
void ra(int *stack_a, int size_a) {
    if (size_a > 1) {
        int first = stack_a[0];
        for (int i = 0; i < size_a - 1; i++) {
            stack_a[i] = stack_a[i + 1];
        }
        stack_a[size_a - 1] = first;
    }
}

// Rotate stack b (shift up by 1)
void rb(int *stack_b, int size_b) {
    if (size_b > 1) {
        int first = stack_b[0];
        for (int i = 0; i < size_b - 1; i++) {
            stack_b[i] = stack_b[i + 1];
        }
        stack_b[size_b - 1] = first;
    }
}

// Perform ra and rb at the same time
void rr(int *stack_a, int size_a, int *stack_b, int size_b) {
    ra(stack_a, size_a);
    rb(stack_b, size_b);
}

// Reverse rotate stack a (shift down by 1)
void rra(int *stack_a, int size_a) {
    if (size_a > 1) {
        int last = stack_a[size_a - 1];
        for (int i = size_a - 1; i > 0; i--) {
            stack_a[i] = stack_a[i - 1];
        }
        stack_a[0] = last;
    }
}

// Reverse rotate stack b (shift down by 1)
void rrb(int *stack_b, int size_b) {
    if (size_b > 1) {
        int last = stack_b[size_b - 1];
        for (int i = size_b - 1; i > 0; i--) {
            stack_b[i] = stack_b[i - 1];
        }
        stack_b[0] = last;
    }
}

// Perform rra and rrb at the same time
void rrr(int *stack_a, int size_a, int *stack_b, int size_b) {
    rra(stack_a, size_a);
    rrb(stack_b, size_b);
}

// Helper function to print a stack
void print_stack(int *stack, int size, const char *name) {
    printf("%s: ", name);
    for (int i = 0; i < size; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    // Example stacks
    int stack_a[] = {1, 2, 3, 4};
    int stack_b[] = {5, 6, 7};
    int size_a = sizeof(stack_a) / sizeof(stack_a[0]);
    int size_b = sizeof(stack_b) / sizeof(stack_b[0]);

    // Print initial stacks
    print_stack(stack_a, size_a, "Stack A");
    print_stack(stack_b, size_b, "Stack B");

    // Perform operations
    sa(stack_a, size_a);
    sb(stack_b, size_b);
    printf("\nAfter sa and sb:\n");
    print_stack(stack_a, size_a, "Stack A");
    print_stack(stack_b, size_b, "Stack B");

    ss(stack_a, size_a, stack_b, size_b);
    printf("\nAfter ss:\n");
    print_stack(stack_a, size_a, "Stack A");
    print_stack(stack_b, size_b, "Stack B");

    pa(stack_a, &size_a, stack_b, &size_b);
    printf("\nAfter pa:\n");
    print_stack(stack_a, size_a, "Stack A");
    print_stack(stack_b, size_b, "Stack B");

    pb(stack_a, &size_a, stack_b, &size_b);
    printf("\nAfter pb:\n");
    print_stack(stack_a, size_a, "Stack A");
    print_stack(stack_b, size_b, "Stack B");

    ra(stack_a, size_a);
    rb(stack_b, size_b);
    printf("\nAfter ra and rb:\n");
    print_stack(stack_a, size_a, "Stack A");
    print_stack(stack_b, size_b, "Stack B");

    rra(stack_a, size_a);
    rrb(stack_b, size_b);
    printf("\nAfter rra and rrb:\n");
    print_stack(stack_a, size_a, "Stack A");
    print_stack(stack_b, size_b, "Stack B");

    return 0;
}