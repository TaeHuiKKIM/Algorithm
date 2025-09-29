#include <stdio.h>

int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char arr[601][601] = {
    0,
};
int visit[601][601] = {
    0,
};
int count = 0;

void dfs(int x, int y) {
  visit[x][y] = 1;
  for (int k = 0; k < 4; k++) {
    int x_ = x + dx[k];
    int y_ = y + dy[k];
    if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < m && arr[x_][y_] != 'X' && visit[x_][y_] == 0) {
      if (arr[x_][y_] == 'P') {
        count++;
      }
      dfs(x_, y_);
    }
  }
}

int main(void) {
  int i, j;
  int flag = 0;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%s", arr[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (arr[i][j] == 'I') {
        dfs(i, j);
        flag = 1;
        break;
      }
    }
    if (flag == 1)
      break;
  }
  if (count == 0) {
    printf("TT");
  } else {
    printf("%d", count);
  }
  return 0;
}