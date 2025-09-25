#include <stdio.h>
#define min(a, b) (a < b ? a : b)

int arr[1000001] = {0,0,1,1, };

int main(void) {
  int x, i=4;
  scanf("%d", &x);
  if(x<4){
    printf("%d", arr[x]);
    return 0;
  }
  while(i<=x){
    arr[i] = arr[i-1]+1;
    if(i%3==0) arr[i] = min(arr[i], arr[i/3]+1);
    if(i%2==0) arr[i] = min(arr[i], arr[i/2]+1);
    i++;
  }
  printf("%d", arr[x]);
  return 0;
}