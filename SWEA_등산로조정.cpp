#include <iostream>
#include <queue>

#define MAX 8
using namespace std;

int N,K;
int map[MAX][MAX]={0,};

int dx[4] ={-1,0,1,0};
int dy[4] ={0,1,0,-1};

int MAX_len = 0;
int start=0;

struct pos{
    int x,y;
};


void BFS()
{
    queue <pos> q;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            
            int visited[MAX][MAX]={0,};

            if(map[i][j]==start){
                q.push({i,j});
                visited[i][j]=1;
            }
            
            while(!q.empty()){
                
                int x = q.front().x;
                int y = q.front().y;


                if(visited[x][y] > MAX_len) MAX_len = visited[x][y];

                q.pop();
                
                for(int k=0;k<4;k++){
                    
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    
                    if(nx<0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]==1 )    continue;
                    if(map[nx][ny] >= map[x][y]) continue;
                    
                    q.push({nx,ny});
                    visited[nx][ny]= visited[x][y]+1;
                }
            }
        }
    }
}


int main(void)
{
    int T;
    cin >> T;
    for(int k=0;k<T;k++)
    {
        cin >> N >> K;
        MAX_len = 0;
        start =0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >>  map[i][j];
                if( map[i][j] > start)  start = map[i][j];
            }
        }
                
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int l=0;l<=K;l++){
                    int tmp = map[i][j];
                    map[i][j] -= l;
                    if(map[i][j] < 0)   map[i][j] =0;
                    BFS();
                    map[i][j]=tmp;
                }
            }
        }
        
        cout <<"#" << k+1 << " " << MAX_len <<"\n";
    }
    return 0;
    
}

