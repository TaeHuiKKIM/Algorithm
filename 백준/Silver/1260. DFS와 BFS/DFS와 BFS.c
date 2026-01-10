#include <stdio.h>

int Graph[1001][1001] = {
	0,
};
int DFSvisited[1001] = {
	0,
};
int BFSvisited[1001] = {
	0,
};
int queue[1001];

void DFS(int v, int n)
{
	DFSvisited[v] = 1;
	printf("%d ", v);
	for (int i = 1; i <= n; i++)
	{
		if (DFSvisited[i] == 0 && Graph[v][i] == 1)
		{
			DFS(i, n);
		}
	}
}

void BFS(int v, int n)
{
	int front = 0, rear = 0, pop;

	printf("%d ", v);
	queue[rear++] = v;
	BFSvisited[v] = 1;

	while (front < rear)
	{
		pop = queue[front++];
		for (int i = 1; i <= n; i++)
		{
			if (BFSvisited[i] == 0 && Graph[pop][i] == 1)
			{
				printf("%d ", i);
				queue[rear++] = i;
				BFSvisited[i] = 1;
			}
		}
	}
}
int main(void)
{

	int n, m, start;
	int x, y;

	scanf("%d %d %d", &n, &m, &start);

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		Graph[x][y] = 1;
		Graph[y][x] = 1;
	}

	DFS(start, n);
	printf("\n");
	BFS(start, n);

	return 0;
}