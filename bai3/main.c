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

// ham them vao phan tu stack
void push(Stack *s, int value) {
    if (s->top >= s->maxSize - 1) {
        fprintf(stderr, "Stack overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

// ham lay phan tu o dinh stack
int pop(Stack *s) {
    if (s->top == -1) {
        printf("No element in stack\n");
        return -1;
    }
    return s->data[s->top--];
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

int main(void) {
    Stack myStack = createStack(5);

    // them 5 phan tu vao stack
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 40);
    push(&myStack, 50);

    // in thong tin stack ban dau
    printStack(myStack);

    // thuc hien pop tung phan tu
    while (1) {
        int popped = pop(&myStack);
        if (popped == -1) {
            break;
        }
        printf("\n%d\n", popped);
        printStack(myStack);
    }

    // giai phong bo nho sau khi ket thuc
    free(myStack.data);
    return 0;
}
