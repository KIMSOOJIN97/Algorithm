#include <iostream>
#include <vector>
#include <queue>

#define MAX 8

using namespace std;

struct pos{
    int x,y;
};

int N,M;
int map[MAX][MAX];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int MAX_AREA = 0;

vector <pos> virus;
int BFS()
{
    queue <pos> q;
    
    int visited[MAX][MAX];
    int x,y;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            visited[i][j] = map[i][j];
    }
    
    for(int i=0;i<virus.size();i++){

        q.push({virus[i].x,virus[i].y});
        
        while(!q.empty()){
            x = q.front().x;
            y = q.front().y;
            q.pop();
            
            for(int k=0;k<4;k++){
                
                int nx = x+dx[k];
                int ny = y+dy[k];
                
                if(nx < 0 || ny <0 || nx >= N || ny >= M )   continue;
                if( visited[nx][ny] != 0)   continue;
                q.push({nx,ny});
                visited[nx][ny] = -1;
            }
        }
    }
    
    int cnt =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j]==0)    cnt++;
        }
    }
    
    return cnt;
    
}
void DFS(int cnt)
{
    if(cnt == 3){
        
        int cnt = BFS();
        if( MAX_AREA < cnt) MAX_AREA = cnt;
        return ;
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==0)
            {
                map[i][j]=1;
                DFS(cnt+1);
                map[i][j]=0;
            }
        }
    }
}


int main(void)
{
    
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            
            if(map[i][j] == 2)  virus.push_back({i,j});
        }
    }
    
    DFS(0);
    
    cout << MAX_AREA;
    
    return 0;
}

