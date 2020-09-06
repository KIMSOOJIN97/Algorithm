#include <stdio.h>

int main(void)
{
    int num[1000001];
    int N,B,C;
    
    long long res=0;
    
    scanf("%d",&N);

    for(int i=0;i<N;i++)    scanf("%d",&num[i]);
    scanf("%d %d",&B,&C);
    
    for(int i=0;i<N;i++){
        num[i] -= B;
        res++;
        if(num[i]<=0)   continue;
        res += num[i]/C + (num[i] % C != 0);
    }
    
    
    printf("%lld", res);
    return 0;

}

