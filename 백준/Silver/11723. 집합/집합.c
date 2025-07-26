#include <stdio.h>
#include <string.h>
int s[21] = {
    0,
};

void addA(int a) { s[a] = 1; }

void removeA(int a) { s[a] = 0; }

int checkA(int a) { return s[a]; }

void toggleA(int a) {
  if (s[a] == 0)
    s[a] = 1;
  else
    s[a] = 0;
}

void allA() {
  for (int i = 1; i < 21; i++) {
    s[i] = 1;
  }
}

void emptyA() {
  for (int i = 1; i < 21; i++) {
    s[i] = 0;
  }
}

int main(void) {
  int n, a;
  char action[10];
  scanf("%d", &n);
  while (n--) {
    scanf("%s", action);
    if (!strcmp(action, "add")) {
      scanf("%d", &a);
      addA(a);
    } else if (!strcmp(action, "remove")) {
      scanf("%d", &a);
      removeA(a);
    } else if (!strcmp(action, "check")) {
      scanf("%d", &a);
      printf("%d\n", checkA(a));
    } else if (!strcmp(action, "toggle")) {
      scanf("%d", &a);
      toggleA(a);
    } else if (!strcmp(action, "all")) {
      allA();
    }else if (!strcmp(action, "empty")) {
      emptyA();
    }
  }
  return 0;
}