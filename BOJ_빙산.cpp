#include <iostream>
#include <queue>

#define MAX 300

using namespace std;

int N,M;
int map[MAX][MAX];

struct pos{
    int x,y;
};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int BFS()
{
    int visited[MAX][MAX]={0,};
    int cnt =0;
    
    queue <pos> q;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] !=0 && visited[i][j] ==0){
                q.push({i,j});
                cnt++;
            }
                while(!q.empty())
                {
                    int x= q.front().x;
                    int y= q.front().y;
                    q.pop();
                    visited[x][y] = cnt;
                    
                    for(int k=0;k<4;k++)
                    {
                        int nx = x+ dx[k];
                        int ny = y+ dy[k];
                        
                        if( nx <0 || ny < 0 || nx >= N || ny >=M || map[nx][ny]==0 || visited[nx][ny]!=0 )   continue;

                        visited[nx][ny] = cnt;
                        q.push({nx,ny});
                        
                    }
                }
            }
        }
    
    
    if(cnt >= 2)    return 1;
    else if(cnt ==0)    return  -1;
    else    return 0;
    
}
void solve()
{
    int tmp[MAX][MAX]={0,};
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int cnt =0;
            
            if(map[i][j] ==0)   continue;
            for(int k=0;k<4;k++)
            {
                int nx = i +dx[k];
                int ny = j +dy[k];
                
                if( nx <0 || ny < 0 || nx >= N || ny >=M || map[nx][ny]!=0)   continue;
                cnt++;
            }
            
            tmp[i][j] = map[i][j]-cnt;
            if(tmp[i][j] < 0)   tmp[i][j]=0;
        }
    }
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)    map[i][j] = tmp[i][j];
    
}
int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)    scanf("%d",&map[i][j]);
    }
    
    int year=0;
    
    while(1)
    {
        int res = BFS();
        if(res == 1)   break;
        else if( res == -1) {
            printf("0");
            return 0;
        }
        solve();
        year++;
    }
    printf("%d",year);
    return 0;
}

