#include <stdio.h>
#define MAX 200001

int visited[MAX] = { 0, };
int k, count = 0;

typedef struct {
	int queue[MAX];
	int front, rear;
} QueueType;

void queue_init(QueueType *q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
	return (q->front == q->rear);
}

void enqueue(QueueType *q, int item) {
	q->rear = (q->rear + 1) % MAX;
	q->queue[q->rear] = item;
}

int dequeue(QueueType *q) {
	q->front = (q->front + 1) % MAX;
	return q->queue[q->front];
}

int bfs(int n) {
	if (n == k) return 0;
	int w, size;
	QueueType q;
	queue_init(&q);
	visited[n] = 1;
	enqueue(&q, n);
	while (1) {
		count++;
		size = q.rear - q.front;
		for (int i = 0; i < size; i++) {
			w = dequeue(&q);
			if (w - 1 == k || w + 1 == k || w * 2 == k)
				return count;
			if (visited[w - 1] == 0 && w - 1 >= 0) {
				visited[w - 1] = 1;
				enqueue(&q, w - 1);
			}
			if (visited[w + 1] == 0 && w + 1 <= 100000) {
				visited[w + 1] = 1;
				enqueue(&q, w + 1);
			}
			if (visited[w * 2] == 0 && w * 2 <= 100000) {
				visited[w * 2] = 1;
				enqueue(&q, w * 2);
			}

		}
	}
	return -1;
}

int main(void) {
	int n;
	scanf("%d %d", &n, &k);
	printf("%d", bfs(n));
}
