#include <stdio.h>

int heap[1000000] = {
    0,
};
int count = 0;

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int check(int *a){
  if(*a<0){
    return -1;
  }
  return 1;
}

int minus(int *a){
  return check(a) * (*a);
}

void push(int a) {
  int position = ++count;
  heap[count] = a;
  while (position != 1) {
    if (minus(&heap[position / 2]) > minus(&heap[position])) {
      swap(&heap[position / 2], &heap[position]);
    }
    else if (minus(&heap[position / 2]) == minus(&heap[position])) {
      if(check(&heap[position])==-1) 
        swap(&heap[position / 2], &heap[position]);
    }
    position /= 2;
  }
}

void pop() {
  if(count==0){
    printf("0\n");
    return;
  }
  printf("%d\n", heap[1]);
  heap[1] = heap[count--];
  int parent = 1;
  int child = 2;
  while (child <= count) {
    if (child < count && minus(&heap[child]) > minus(&heap[child + 1])) {
      child++;
    }else if(child < count && minus(&heap[child]) == minus(&heap[child + 1])){
      if(check(&heap[child+1])==-1)
        child++;
    }
    if(minus(&heap[parent]) == minus(&heap[child]) && check(&heap[parent])==-1)
      break;
    if (minus(&heap[parent]) < minus(&heap[child]))
      break;
    swap(&heap[parent], &heap[child]);
    parent = child;
    child = 2 * parent;
  }
}

int main(void) {
  int n, a;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &a);
    if (a == 0) {
      pop();
    } else {
      push(a);
    }
  }
}