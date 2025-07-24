#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100000
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty(){
    return(top == -1);
}

int is_full(){
    return(top == MAX_STACK_SIZE-1);
}

void push(element item){
    if(is_full()){
        return;
    }
    else stack[++top] = item;
}

element pop(){
    if(is_empty()){
        exit(1);
    }
    else return stack[top--];
}

int main(void){
    char result[200000] = {0, };
    int num, temp, add = 1, flag = 0;
    scanf("%d", &num);
    for(int i=0; i<num; i++){
      scanf("%d", &temp);
      if(temp>stack[top]){
        while(temp!=stack[top]){
          push(add++);
          result[flag++] = '+';
        }
        pop();
        result[flag++] = '-';
      }else if(temp==stack[top]){
        pop();
        result[flag++] = '-';
      }else{
        printf("NO");
        return 0;
      }
    }
    for(int i=0; i<flag; i++){
      printf("%c\n", result[i]);
    }
    return 0;
}