#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);

    int line[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &line[i]);
    }

    int stack[n];
    int top = -1;
    int current_num = 1;

    for (int i = 0; i < n; i++) {
        if (line[i] == current_num) {
            current_num++;
        } else {
            while (top >= 0 && stack[top] == current_num) {
                top--;
                current_num++;
            }
            stack[++top] = line[i];
        }
    }

    while (top >= 0 && stack[top] == current_num) {
        top--;
        current_num++;
    }

    if (top == -1) {
        printf("Nice\n");
    } else {
        printf("Sad\n");
    }

    return 0;
}