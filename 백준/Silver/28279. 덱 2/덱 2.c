#include <stdio.h>
#include <string.h>
#define MAX 2000001
int queue[MAX], front = 0, rear = 0;

int empty() { return front == rear; }

void push(int a) {
  queue[rear] = a;
  rear = (rear + 1) % MAX;
}

void pushFront(int a) {
  front = (front - 1 + MAX) % MAX;
  queue[front] = a;
}

int popFront() {
  if (empty())
    return -1;
  int temp = queue[front];
  front = (front + 1) % MAX;
  return temp;
}

int pop() {
  if (empty())
    return -1;
  rear = (rear - 1 + MAX) % MAX;
  return queue[rear];
}

int size() {
  return (rear - front + MAX)%MAX;
}

int main() {
  int a, n, move;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &move);
    switch (move) {
    case 1:
      scanf("%d", &a);
      pushFront(a);
      break;
    case 2:
      scanf("%d", &a);
      push(a);
      break;
    case 3:
      printf("%d\n", popFront());
      break;
    case 4:
      printf("%d\n", pop());
      break;
    case 5:
      printf("%d\n", size());
      break;
    case 6:
      printf("%d\n", empty());
      break;
    case 7:
      if (empty())
        printf("-1\n");
      else
        printf("%d\n", queue[front]);
      break;
    case 8:
      if (empty())
        printf("-1\n");
      else
        printf("%d\n", queue[(rear-1+MAX)%MAX]);
      break;
    }
  }
  return 0;
}