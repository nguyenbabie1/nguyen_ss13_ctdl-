#include <stdio.h>
#include <stdlib.h>
// dinh nghia cau truc stack
typedef struct Stack {
    int *data;      // con tro toi mang chua du lieu
    int top;       // chi so cua phan tu tren cung
    int maxSize;  // dung luong toi da cua stack
} Stack;
// ham khoi tao stack

Stack createStack(int maxSize) {
    Stack s;
    s.data = (int *)malloc(maxSize * sizeof(int)); // cap phat bo nho cho stack
    if (s.data == NULL) {
        printf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    s.top = -1; // khoi tao stack rong
    s.maxSize = maxSize; // gan dung luong toi da
    return s;
} 
// ham in thong tin stack
void printStack(Stack s) {
    if (s.top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("cac phan tu trong stack la: ");
    for (int i = 0; i <= s.top; i++) {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}
int main(void) {
    Stack myStack = createStack(5);
    // thu gan thu cong vai gia tri
    myStack.data[++myStack.top] = 10;
    myStack.data[++myStack.top] = 20;
    myStack.data[++myStack.top] = 30;

    printStack(myStack);
    // giai phong bo nho
    free(myStack.data);

    return 0;
}