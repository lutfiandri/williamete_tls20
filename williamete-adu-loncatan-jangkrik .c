#include <stdbool.h>
#include <stdio.h>

void myLoop(int x1, int x2, int *v1, int *v2, bool *success) {
    while (x1 <= x2) {
        x1 += *v1;
        x2 += *v2;
        if (x1 == x2) {
            *success = true;
            break;
        }
    }
}

int main() {
    int x1, x2, v1, v2;
    scanf("%d%d%d%d", &x1, &v1, &x2, &v2);
    bool success = false;

    if (x1 == x2)
        success = true;
    else if (x1 < x2 && v1 != v2)
        myLoop(x1, x2, &v1, &v2, &success);
    else if (x2 > x1 && v1 != v2)
        myLoop(x2, x1, &v1, &v2, &success);

    if (success)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}