#include <iostream>
#include <queue>
#include <vector>

#define MAX 101

using namespace std;

int N,M;
int map[MAX][MAX]={0,};

struct pos{
    int x,y;
};
int cnt=0;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool BFS()
{
    int visited[MAX][MAX]={0,};
    
    queue<pos> q;
    visited[0][0]=1;
    q.push({0,0});
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        for(int i=0;i<4;i++){
            
            int nx= x+dx[i];
            int ny= y+dy[i];
            
            if(nx< 0 || ny <0 || nx >=N || ny >= M || visited[nx][ny] == 1 || map[nx][ny]==1) continue;
            q.push({nx,ny});
            visited[nx][ny] = 1;
            
        }
    }
    int num=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==0 && visited[i][j]==0)
                map[i][j]=-1;
            else if (map[i][j]==1)  num++;
        }
    }
    
    if(num==0)  return true;
    else return false;
}

void solve()
{
    cnt =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==1){
                for(int k=0;k<4;k++)
                {
                    int nx= i+dx[k];
                    int ny= j+dy[k];
                    if(map[nx][ny] == 0){
                        cnt++;
                        map[i][j]=-1;
                        break;
                    }
                }
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==-1)   map[i][j]=0;
        }
    }
}
int main(void)
{
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)    cin >> map[i][j];
    }
    
    int step =0;
    
    while(1){
        if(BFS())   break;
        solve();
        step++;
    }
    
    cout << step <<"\n" << cnt;
    
    return 0;
}

