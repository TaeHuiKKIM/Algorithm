#include <stdio.h>

int count = 0; // 전역변수 초기화
int r, c;

int search(int x, int y, int n) { 
    if (n == 1) {
        if (x == r && y == c) {
            return 1; // 찾았을 때 1 반환
        }
    } else {
        int half = n / 2;

        // 1사분면
        if (r < x + half && c < y + half) {
            return search(x, y, half);
        } else {
            count += half * half;
        }

        // 2사분면
        if (r < x + half && c >= y + half) {
            return search(x, y + half, half);
        } else {
            count += half * half;
        }

        // 3사분면
        if (r >= x + half && c < y + half) {
            return search(x + half, y, half);
        } else {
            count += half * half;
        }

        // 4사분면
        if (r >= x + half && c >= y + half) {
            return search(x + half, y + half, half);
        } else {
            count += half * half;
        }

        return 0; // 여기 도달하면 안되지만 컴파일 경고 방지
    }
}

int main() {
    int n;
    scanf("%d %d %d", &n, &r, &c);

    int size = 1 << n; // 2^n 계산

    search(0, 0, size); // 좌표 0, 0 부터 탐색

    printf("%d\n", count);
    return 0;
}