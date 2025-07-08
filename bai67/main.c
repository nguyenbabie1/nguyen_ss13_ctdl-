#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    char *data;
    int top;
    int maxSize;
} CharStack;
// khoi tao stack
CharStack createCharStack(int maxSize) {
    CharStack s;
    s.data = (char *)malloc(maxSize * sizeof(char));
    if (s.data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    s.top = -1;
    s.maxSize = maxSize;
    return s;
}
// push ky tu vao stack
void pushChar(CharStack *s, char value) {
    if (s->top >= s->maxSize - 1) {
        fprintf(stderr, "Stack overflow\n");
        return;
    }

    s->data[++s->top] = value;
}
// pop ky tu khoi stack
char popChar(CharStack *s) {
    if (s->top == -1) {
        return 0; // Return null character if stack is empty
    }
    return s->data[s->top--];
}
// Ham kiem tra chuoi doi xung
bool isPalindrome(char str[]) {
    int len = strlen(str);
    CharStack s = createCharStack(len);

    // Day tat ca ky tu vao stack
    for (int i = 0; i < len; i++) {
        pushChar(&s, str[i]);
    }

    // So sanh voi tung ky tu trong chuoi ban dau
    for (int i = 0; i < len; i++) {
        char c = popChar(&s);
        if (str[i] != c) {
            free(s.data);
            return false;
        }
    }

    free(s.data);
    return true;
}
int main(void) {
    char input[MAX];

    printf("Nhap chuoi: ");
    fgets(input, MAX, stdin);

    // Xoa ky tu xuong dong '\n' neu co
    size_t len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // In ket qua
    if (isPalindrome(input)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}