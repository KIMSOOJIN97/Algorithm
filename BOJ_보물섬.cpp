#include <iostream>
#include <queue>
#include <cstring>

#define MAX 51

using namespace std;

struct pos{
    int x,y;
};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool map[MAX][MAX]={0,};
int visited[MAX][MAX]={0,};
int N,M;

int BFS(int x,int y)
{
    memset(visited,0,sizeof(visited));
    
    queue <pos> q;
    q.push({x,y});
    visited[x][y]=1;
    int res =0;
    
    while(!q.empty()){
    
        int x= q.front().x;
        int y= q.front().y;
        
        if(res < visited[x][y]) res= visited[x][y];
        
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]!=0 || map[nx][ny] )  continue;
            
            q.push({nx,ny});
            visited[nx][ny]=visited[x][y]+1;
            
        }
    }
    
    return res;
}

int main(void){
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char ch;
            cin >> ch;
            if(ch == 'W')   map[i][j]=true;
        }
    }
    
    int ans =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==0){
                int res = BFS(i,j);
                if(res > ans )  ans = res;
            }
        }
    }
    cout << ans-1;
    return 0;
}

