#include <stdio.h>

int main(void) {
  int coin[10] = {
      0,
  };
  int n, k, index, count = 0;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &coin[i]);
  }
  for (int i=n-1; i >= 0; i--) {
    while (k - coin[i] >= 0) {
      k = k - coin[i];
      count++;
    }
  }
  printf("%d", count);
}