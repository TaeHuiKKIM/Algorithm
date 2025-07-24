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

void push(int a) {
  int position = ++count;
  heap[count] = a;
  while (position != 1) {
    if (heap[position / 2] < heap[position]) {
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
    if (child < count && heap[child] < heap[child + 1]) {
      child++;
    }
    if (heap[parent] >= heap[child])
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