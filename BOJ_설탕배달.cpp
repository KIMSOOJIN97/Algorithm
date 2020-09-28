#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d",&N);
    
    int cnt =0;
    
    while(N>0){
        if(N%5==0){
            N-=5;
            cnt++;
        }
        else if(N%3==0){
            N-=3;
            cnt++;
        }
        else if(N>5){
            N-=5;
            cnt++;
        }
        else    break;
    }
    if(N!=0)    printf("-1");
    else    printf("%d",cnt);
    
    return 0;
}

