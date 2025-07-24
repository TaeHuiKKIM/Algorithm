#include <stdio.h>
#include <string.h>

int recursion(const char *s, int l, int r, int *count) {
  (*count)++;
  if (l >= r)
    return 1;
  else if (s[l] != s[r])
    return 0;
  else
    return recursion(s, l + 1, r - 1, count);
}

int isPalindrome(const char *s, int *count) {
  return recursion(s, 0, strlen(s) - 1, count);
}

int main() {
  int num, count, temp;
  char s[1002];
  scanf("%d", &num);
  while (num--) {
    count = 0;
    scanf("%s", s);
    temp = isPalindrome(s, &count);
    printf("%d %d\n", temp, count);
  }
  return 0;
}