#include <stdio.h>
#include <stdlib.h>

// khai bao cau truc stack
typedef struct {
    int *data;
    int top;
    int maxSize;
} Stack;

// khoi tao stack
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

// them phan tu vao stack
void push(Stack *s, int value) {
    if (s->top == s->maxSize - 1) {
        fprintf(stderr, "Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

// ham in thong tin stack
void printStack(Stack s) {
    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i <= s.top; i++) {
        printf("%d", s.data[i]);
        if (i < s.top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", s.top);
    printf("    cap: %d\n", s.maxSize);
    printf("}\n");
}

// ham in toan bo phan tu theo LIFO
void viewStack(Stack s) {
    if (s.top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements in LIFO order:\n");
    for (int i = s.top; i >= 0; i--) {
        printf("%d\n", s.data[i]);
    }
}

int main(void) {
    Stack myStack = createStack(5);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 40);
    push(&myStack, 50);

    // in thong tin stack
    printStack(myStack);

    // xem toan bo phan tu
    viewStack(myStack);

    // giai phong bo nho
    free(myStack.data);
    return 0;
}
