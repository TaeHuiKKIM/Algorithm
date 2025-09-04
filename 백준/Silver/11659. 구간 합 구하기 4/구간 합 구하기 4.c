#include <stdio.h>

int main(void) {
  int n, m,
      arr[100001] =
          {
              0,
          },
      sum;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    arr[i] += arr[i - 1];
  }
  while (m--) {
    sum = 0;
    int i, j;
    scanf("%d %d", &i, &j);
    printf("%d\n", arr[j] - arr[i - 1]);
  }
}