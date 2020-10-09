#include <stdio.h>
#define MAX 1000001


int MIN(int a, int b)
{
    if(a>b )    return b;
    else    return a;
}

int main(void)
{
    int N;
    int DP[MAX]={0,};
    
    scanf("%d",&N);
    
    for(int i=2;i<=N;i++)
    {
        DP[i] = DP[i-1]+1;
        if(i%2 == 0)    DP[i] = MIN(DP[i], DP[i/2]+1);
        if(i%3 == 0)    DP[i] = MIN(DP[i], DP[i/3]+1);
    }
    printf("%d",DP[N]);
    return 0;
    
}

