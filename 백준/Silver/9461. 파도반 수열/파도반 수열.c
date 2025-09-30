#include <stdio.h>

int main(void){
  int n, m;
  long long int arr[101] = {0, 1, 1, 1, 2, 2};
  scanf("%d", &n);
  for(int i=6; i<=101; i++){
    arr[i] = arr[i-1] + arr[i-5];
  }
  while(n--){
    scanf("%d", &m);
    printf("%lld\n", arr[m]);
  }
  return 0;
}