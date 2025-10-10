#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	return(*(int*)b - *(int*)a);
}

int main(void){
	int num[11] = {-1,}, n, count=1;
	scanf("%d", &n);
	for(int i=0; i<11; i++){
		num[i] = n%10;
		if(n<10) break;
		n /= 10;
		count++;
	}
	qsort(num, count, sizeof(int), compare);

	for(int i=0; i<count; i++){
		printf("%d", num[i]);
	}


	return 0;
}
