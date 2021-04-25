#include <iostream>
#include <vector>
#include <queue>
#define MAX 8

using namespace std;

struct pos{
    int x,y;
};

int N,M;
int map[MAX][MAX]={0,};
int res =0;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

vector <pos> blank;
queue <pos> virus;



void BFS()
{
    int visited[MAX][MAX]={0,};
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)    visited[i][j]= map[i][j];
    }

    queue <pos> q = virus;
    
    while(!q.empty())
    {
        int x= q.front().x;
        int y= q.front().y;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || ny < 0 || nx >=N || ny >= M || visited[nx][ny] != 0 )    continue;
            
            visited[nx][ny] = -1;
            q.push({nx,ny});
        }
    }
    
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j]== 0)   cnt++;
        }
    }
    if(cnt > res)   res = cnt;
    return ;
}

void DFS(int cnt,int idx)
{
    if(cnt == 3)
    {
        BFS();
        return ;
    }
    
    for(int i=idx ; i<blank.size();i++)
    {
        pos tmp = blank[i];
        map[tmp.x][tmp.y]=1;
        DFS(cnt+1,i+1);
        map[tmp.x][tmp.y]=0;
    }
}
int main(void)
{
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
        {
            cin >>map[i][j];
            if(map[i][j]==0)    blank.push_back({i,j});
            else if(map[i][j]==2)   virus.push({i,j});
        }
    }
    DFS(0,0);
    cout << res;
    return 0;
}

