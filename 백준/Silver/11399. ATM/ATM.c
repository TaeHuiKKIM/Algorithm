#include <stdio.h>
#include <stdlib.h>

int compare(const int* a, const int* b) {
  return(*a - *b);
}

int main(void){
  int num, sum=0, result=0;
  int arr[1000];
  scanf("%d", &num);
  for(int i=0; i<num; i++){
    scanf("%d", &arr[i]);
  }
  qsort(arr, num, sizeof(int), compare);
  
  for(int i=0; i<num; i++){
    sum+=arr[i];
    result += sum;
  }
  printf("%d", result);
  return 0;
}