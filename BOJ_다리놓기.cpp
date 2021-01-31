#include <iostream>
#define MAX 31

using namespace std;

int main(void)
{
    int T;
    scanf("%d",&T);
    
    for(int i=0;i<T;i++)
    {
        int DP[MAX][MAX]={0,};
        int N,M;
        scanf("%d %d",&N,&M);
        for(int j=1;j<=M;j++)   DP[1][j]=j;
        for(int j=2;j<=N;j++){
            for(int k=j;k<=M;k++){
                for(int l=k;l>=j;l--){
                    DP[j][k]+=DP[j-1][l-1];x
                }
            }
        }
        printf("%d\n",DP[N][M]);
    }
    return 0;
}

