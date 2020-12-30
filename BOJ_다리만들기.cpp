#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

struct pos{
    int x,y;
};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int map[MAX][MAX]={0,};
int N;
int cnt=0;
int answer=MAX*MAX;

int BFS(int idx)
{
    int visited[MAX][MAX]={0,};
    queue <pos> q;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]==idx){
                q.push({i,j});
                visited[i][j]=1;
            }
        }
    }
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            
            if(nx<0 || ny <0 || nx >= N || ny >= N || visited[nx][ny]!=0 )  continue;
            if(map[nx][ny] !=0 &&  map[nx][ny] != idx)  return visited[x][y]+1;
            
            visited[nx][ny]=visited[x][y]+1;
            q.push({nx,ny});
        }
    }
    return 0;
}

int main(void)
{
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }
    
    queue <pos> q;
    int visited[MAX][MAX]={0,};
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j]==0 && map[i][j]==1){
                cnt++;
                map[i][j]=cnt;
                visited[i][j]=1;
                q.push({i,j});
            }
            
            while(!q.empty()){
                int x = q.front().x;
                int y = q.front().y;
                q.pop();
                for(int k=0;k<4;k++){
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    
                    if(nx<0 || ny <0 || nx >= N || ny >= N || visited[nx][ny])  continue;
                    if(map[nx][ny] == 0 )  continue;
                    
                    visited[nx][ny]=1;
                    map[nx][ny] = cnt;
                    q.push({nx,ny});
                }
            }
        }
    }
    
    for(int i=1;i<cnt;i++)  {
        int res =BFS(i);
        if(res!=0 && res < answer)  answer =res;
    }
    cout << answer-2;
    return 0;
}

