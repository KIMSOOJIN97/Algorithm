#include <iostream>
#include <queue>

#define MAX 17

using namespace std;

struct pos{
    int x,y,dir;
};

int map[MAX][MAX]={0,};
int N;

int dx[3] = {0,1,1};
int dy[3] = {1,1,0};

void BFS()
{
    int cnt =0;

    queue <pos> q;
    
    q.push({0,1,0});
    
    while(!q.empty())
    {
        int x= q.front().x;
        int y= q.front().y;
        int dir = q.front().dir;
        if( x== N-1 && y == N-1)    cnt++;
        q.pop();
        
        for(int i=0;i<3;i++){
            
            if(dir ==0 && i==2) continue;
            else if(dir == 2 && i ==0)  continue;
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N ) continue;
            if(map[nx][ny] == 1)    continue;
            if(i==1 && (map[nx][ny-1] !=0 || map[nx-1][ny]!=0)) continue;
            
            q.push({nx,ny,i});
        }
    }
    printf("%d",cnt);
    return ;
}

int main(void)
{
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&map[i][j]);
        }
    }
    
    BFS();
    return 0;
}

