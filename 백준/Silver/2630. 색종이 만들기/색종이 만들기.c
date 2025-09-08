#include <stdio.h>

int paper[128][128], zero, one;

int search(int x, int y, int n){
    int count = 0;
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(paper[i][j]==1) count++; 
        }
    }
    if(count == n * n) one++;
    else if(count == 0) zero++;
    else{
        search(x, y, n/2);
        search(x, y+n/2, n/2);
        search(x+n/2, y, n/2);
        search(x+n/2, y+n/2, n/2);
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &paper[i][j]);
        }
    }
    search(0, 0, n);
    printf("%d\n%d", zero, one);
}