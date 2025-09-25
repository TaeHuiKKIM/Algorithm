#include <stdio.h>
#include <string.h>

int main(void) {
  int temp = 0, sum = 0, j = 0, answer;
  int result[50] = {0,};
  char str[51];
  scanf("%s", str);

  for(int i=0; i<=strlen(str); i++){
    if(str[i]=='-' || i==strlen(str)){
      sum+=temp;
      result[j++] = sum;
      sum = 0;
      temp = 0;
    }else if(str[i]=='+'){
      sum+=temp;
      temp = 0;
    }else{
      temp *= 10; //어짜피 0일때는 10을 곱해도 0이된다
      temp += str[i] - '0'; 
    }
  }
  answer = result[0];
  for(int i=1; i<=j; i++){
    answer -= result[i];
  }
  printf("%d", answer);
  
  return 0;
}