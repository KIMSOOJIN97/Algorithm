#include <iostream>
#include <queue>

#define MAX 1001

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int N,M;
int map[MAX][MAX]={0,};
int visited[MAX][MAX][2]={0,};

struct pos{
    int x,y;
    bool crash;
};

int BFS()
{
    queue <pos> q;
    q.push({1,1,false});
    visited[1][1][0] =1;
    
    while(!q.empty()){
        
        int x = q.front().x;
        int y = q.front().y;
        bool check = q.front().crash;

        if(x == N && y == M)    return visited[x][y][check];
        
        q.pop();
        
        for(int i=0;i<4;i++){
            
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx<1 || ny <1 || nx >  N || ny > M )  continue;
            if(map[nx][ny] == 1 && check)  continue;
            
            bool flag = false;
            if(map[nx][ny]==1)  flag = true;
            else    flag = check;
            
            if(visited[nx][ny][flag]!=0)    continue;
            
            q.push({nx,ny,flag});
            visited[nx][ny][flag]=visited[x][y][check]+1;
            
        }
    }
    return -1;
}

int main(void)
{
    scanf("%d %d",&N,&M);
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%1d",&map[i][j]);
        }
    }
    
    cout << BFS();
}

