#include <iostream>
#include <queue>

using namespace std;

int N, M ;
int map[20][20]={0,};
int visited[100]={0,};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int MAX = 0;
void DFS(int cnt , int x, int y)
{
    if(cnt == N*M){
        MAX = cnt;
        return ;
    }
    
    
    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny <0 || nx >= N || ny >= M)   continue;
        if(visited[map[nx][ny]]==1)    continue;
        visited[map[nx][ny]]=1;
        DFS(cnt+1 , nx,ny);
        visited[map[nx][ny]]=0;
    }
    if(cnt > MAX )  MAX = cnt;
}

int main(void)
{
    cin >> N >> M ;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char ch1;
            cin >> ch1;
            int num = ch1 - '0';
            map[i][j]=num;
        }

    }
    visited[map[0][0]]=1;

    DFS(1,0,0);
    cout << MAX ;
    return 0;
    
}

