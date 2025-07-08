#include <stdio.h>
#include <stdlib.h>

// Define stack structure
typedef struct {
    int *data;
    int top;
    int maxSize;
} Stack;

// Create a new stack
Stack createStack(int maxSize) {
    Stack s;
    s.data = (int *)malloc(maxSize * sizeof(int));
    if (s.data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    s.top = -1;
    s.maxSize = maxSize;
    return s;
}

// Push element to stack
void push(Stack *s, int value) {
    if (s->top == s->maxSize - 1) {
        fprintf(stderr, "Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

// Print array
void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

// Reverse array using stack
void reverseArray(int arr[], int n) {
    Stack s = createStack(n);
    for (int i = 0; i < n; i++) {
        push(&s, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = s.data[s.top--];
    }
    free(s.data);
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        fprintf(stderr, "Invalid array size\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array: ");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("Reversed array: ");
    printArray(arr, n);

    free(arr);
    return 0;
}
