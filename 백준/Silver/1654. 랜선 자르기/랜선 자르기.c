#include <stdio.h>

int main(void) {
  long long arr[10000];
  int n, k;
  long long left, mid, right, sum, max_len=0, max = 0;

  scanf("%d %d", &k, &n);
  for (int i = 0; i < k; i++) {
    scanf("%lld", &arr[i]);
    if (max < arr[i])
      max = arr[i];
  }

  left = 1;
  right = max;
  while (left<=right){
    mid = (left+right)/2;
    sum = 0;
    for (int i = 0; i < k; i++) {
      sum += arr[i] / mid;
    }
    if(sum>=n && max_len<mid)
      max_len = mid;
    if(sum<n)    
      right = mid-1;
    else  
      left = mid+1;
  }
  printf("%lld", max_len);
}