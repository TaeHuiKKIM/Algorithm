#include <stdio.h>

int main(void) {
  int result[41] = {
      0,
      1,
  };
  int num, n;
  for (int i = 2; i < 41; i++) {
    result[i] = result[i - 1] + result[i - 2];
  }
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    scanf("%d", &n);
    if (n == 0) {
      printf("1 0\n");
    } else {
      printf("%d %d\n", result[n - 1], result[n]);
    }
  }
  return 0;
}