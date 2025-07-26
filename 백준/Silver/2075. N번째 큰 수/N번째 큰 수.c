#include <stdio.h>

int heap[1500*1500+1] = {
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

int pop() {
  if (count == 0) {
    return 0;
  }
  int temp = heap[1];
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
  return temp;
}

int main(void) {
  int n, a, result;
  scanf("%d", &n);
  for (int i = 0; i < n * n; i++) {
    scanf("%d", &a);
    push(a);
  }
  while (n--) {
    result = pop();
  }
  printf("%d", result);
}
