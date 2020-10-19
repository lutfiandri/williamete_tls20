#include <stdio.h>
#define MAX_HEIGHT 41

int main() {
    int n, length, width, height;
    scanf("%d", &n);

    int top = -1;
    int stack[n];

    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &length, &width, &height);
        if (height < MAX_HEIGHT) {
            top++;
            stack[top] = length * width * height;
        }
    }

    for (int i = 0; i <= top; i++) {
        printf("%d\n", stack[i]);
    }

    return 0;
}