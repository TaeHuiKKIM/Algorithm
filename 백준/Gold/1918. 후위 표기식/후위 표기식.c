#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct{
  element data[MAX_STACK_SIZE];
  int top; 
}StackType;

void init_stack(StackType *s){
  s->top = -1;
}

int is_empty(StackType *s){
  return(s->top == -1);
}

int is_full(StackType *s){
  return(s->top == MAX_STACK_SIZE-1);
}

void push(StackType *s, element item){
  if(is_full(s)){
    return;
  }
  s->data[++(s->top)] = item;
}

element pop(StackType *s){
  if(is_empty(s)){
    return 0;
  }
  return s->data[(s->top)--];
}

int priority(char c){
  if(c == '(' || c==')')
    return 0; //'()'은 연산에 참가 안하고 따로 처리하므로 후순위로 둠
  else if(c == '+' || c == '-') 
    return 1;
  else if(c == '*' || c == '/')
    return 2;
}

int main(void){
  char input[100] = {0,};
  scanf("%s", input);
  StackType s;
  char temp;
  init_stack(&s);
  for(int i=0; i<strlen(input); i++){
    int ch = input[i];
    switch(ch){
      case '+': case '-' : case '*' : case '/':
        while(!is_empty(&s) && priority(s.data[s.top])>=priority(ch)){
          printf("%c", pop(&s));
        }
        push(&s, ch);
        break;

      case '(':
        push(&s, ch);
        break;

      case ')':
        temp = pop(&s);
        while(temp !='('){
          printf("%c", temp);
          temp = pop(&s);
        }
        break;

      default : //피연산자인 경우
        printf("%c", ch);
        break;
    }
  }
  while(!is_empty(&s)){
    printf("%c", pop(&s));
  }
}