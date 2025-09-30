#include <stdio.h>

int main(void){
  int n, m;
  int arr[12] = {0, 1, 2, 4};
  scanf("%d", &n);
  for(int i=4; i<=12; i++){
    arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
  }
  while(n--){
    scanf("%d", &m);
    printf("%d\n", arr[m]);
  }
  return 0;
}