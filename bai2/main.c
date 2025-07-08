#include <stdio.h>
#include <stdlib.h>

// khai bao cau truc stack
typedef struct {
    int *data;
    int top;
    int maxSize;
} Stack;
// Ham khoi tao stack
Stack createStack(int maxSize){
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
// Ham tham vao stack push
void push(Stack *s, int value) {
    if (s->top == s->maxSize - 1) {
        fprintf("Stack overflow\n",value);
        return;
    }
    s->data[++(s->top)] = value;
}
   // ham in thong tin stack
void printStack(Stack s){
    printf("Stack contents: \n ");
     printf("elements: ");
    for (int i = 0; i <= s.top; i++) {
        printf("%d ", s.data[i]);
        if (i < s.top) {
            printf("-> ");
        }
    printf("\n");
    printf("Top index: %d\n", s.top);
    printf("Max size: %d\n", s.maxSize);
    printf("}\n");
}
int main(void) {
    int value;
    Stack myStack = createStack(5); // Tạo stack với kích thước tối đa là 5

printf("Nhap cac phan tu:\n");
for (int i = 0; i < 5; i++) {
    printf("> ");
    scanf("%d", &value);
    push(&myStack, value);
    return 0;
    printStack(myStack);
    // Giaiphongbo nho
    free(myStack.data);
    return 0;

}