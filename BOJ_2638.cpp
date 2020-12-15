#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

struct pos{
    int x,y;
};

int map[MAX][MAX]={0,};
int N,M;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool BFS()
{
    bool flag= false;
    
    int visited[MAX][MAX]={0,};
    
    queue <pos> q;
    q.push({0,0});
    visited[0][0]=-1;
    
    while(!q.empty()){
        
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx<0 || ny < 0 || nx >= N || ny >= M)    continue;
            if(map[nx][ny] == 1){
                visited[nx][ny]++;
                continue;
            }
            if(visited[nx][ny]!=0)  continue;
            
            q.push({nx,ny});
            visited[nx][ny] = -1;
            
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j] >= 2){
                map[i][j] = 0;
                flag = true;
            }
        }
    }
    
    return flag;
}

int main(void)
{
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)    cin >> map[i][j];
    }
    
    int cnt =0;
    
    while(1){
        if(BFS()==false)    break;
        cnt++;
    }
    
    cout << cnt;
    return 0;
    
}

