#include <iostream>
#define MAX 31

using namespace std;
//map[x][y]< == > (x,y), (x,y+1)
int map[MAX][MAX]={0,};
int N,M,H;
int MIN = 4;

bool solve()
{
    for(int i=1;i<=N;i++){
        int x =1;
        int y =i;
        
        while(x <= H ){
            
            if(map[x][y] == 1)  y++;
            else if(map[x][y-1]==1) y--;
            x++;
        }
        if( i != y) return false;
    }
    return true;
}

void DFS( int cnt, int num)
{
    if(MIN!= 4) return;
    if(num == cnt) {
        if(solve()){
            MIN= cnt;
        }
        return ;
    }
    
    for(int j=1; j < N; j++){
        for(int i = 1; i <= H; i++) {
            if(map[i][j] || map[i][j + 1] || map[i][j - 1]) continue;
            map[i][j] = 1;
            DFS(cnt+1,num);
            map[i][j] = 0;
            while(!map[i][j - 1] && !map[i][j + 1]) i++;
        }
    }
}

int main(void)
{
    scanf("%d %d %d",&N,&M,&H);
    for(int i=0;i<M;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        map[x][y]=1;
        
    }
    
    for(int i = 0; i < 4; i++) {
        DFS(0,i);
        if(MIN!= 4) {
            printf("%d",MIN);
            break;
        }
    }
    if(MIN==4)printf("-1");
    return 0;
}

