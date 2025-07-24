#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100002
typedef char element;
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
    int count = 0;
    char stick[100002];
    scanf("%s", stick);
    push('(');
    for(int i=1; i<strlen(stick); i++){
      if(stick[i]=='('){
        push('(');
      }else{
        if(stack[top]=='(' && stick[i-1]=='('){
          pop();
          for(int i=top; i>-1; i--) 
            if(stack[i]=='(') count++;
        }else{
          pop();
          count++;
        }
      }
    }
    printf("%d", count);
    return 0;
}