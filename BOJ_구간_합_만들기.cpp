#include <iostream>
#define MAX 1025


int map[MAX][MAX]={0,};
long long int DP[MAX][MAX]={0,};

int N,M;


int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%d",&map[i][j]);
            DP[i][j] = DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1] + map[i][j];
        }
    }
    
    DP[1][1]=map[1][1];
     
    for(int i=0;i<M;i++)    {
        
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        std::cout << DP[x2][y2]-DP[x2][y1-1]-DP[x1-1][y2] + DP[x1-1][y1-1] << "\n";
    }
    
    return 0;
    
}

