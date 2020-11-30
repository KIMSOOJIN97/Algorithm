#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

int visited[MAX][MAX]={0,};
int map[MAX][MAX]={0,};
int N,M;

int dx[4]= {-1,1,0,0};
int dy[4] = {0,0,1,-1};

struct pos{
    int x,y;
};

int BFS()
{
    queue <pos> q;
    
    q.push({0,0});
    visited[0][0]=1;
    
    while(!q.empty()){
        
        int x= q.front().x;
        int y= q.front().y;
        if(x==N-1 && y==M-1)    break;
        q.pop();
        
        for(int i=0;i<4;i++){
            
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx <0 || ny<0 || nx >= N || ny >= M || map[nx][ny]==0)    continue;
            if(visited[nx][ny]!= 0 )   continue;
            
            visited[nx][ny] = visited[x][y]+1;
            q.push({nx,ny});
        }
    }
    
    return visited[N-1][M-1];
}

int main(void)
{
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%1d",&map[i][j]);
        }
    }
    
    cout << BFS();
    
    return 0;
    
}

