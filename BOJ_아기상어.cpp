#include <iostream>
#include <queue>

#define MAX 20
using namespace std;

struct INFO{
    int x,y,size;
    
};
struct pos{
    int x,y;
};
int total=0;

int N,M;
int map[MAX][MAX]={0,};

INFO shark;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


bool BFS()
{
    int visited[MAX][MAX]={0,};
    int tx,ty;
    
    int len = 1e9;
    
    queue <pos> q;
    q.push({shark.x , shark.y});
    
    while(!q.empty()){
        int x= q.front().x;
        int y= q.front().y;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx <0 || ny < 0 || nx >= N || ny >= N)   continue;
            if(visited[nx][ny] != 0)    continue;
            if(map[nx][ny] > shark.size)    continue;
            
            visited[nx][ny] = visited[x][y]+1;
            q.push({nx,ny});
            
            if(map[nx][ny] != 0 && map[nx][ny] < shark.size){
                if(len > visited[nx][ny]){
                    tx = nx;
                    ty = ny;
                    len = visited[nx][ny];
                }
                else if(len == visited[nx][ny]){
                    if(nx <tx){
                        tx = nx;
                        ty = ny;
                    }
                    else if(nx == tx){
                        if(ny < ty){
                            tx = nx;
                            ty = ny;
                        }
                    }
                }
            }
        }
    }
    if(len ==1e9) return false;
    map[tx][ty]=0;
    shark.x = tx;
    shark.y = ty;
    total+= len;
    return true;
}

int main(void)
{
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&map[i][j]);
            if (map[i][j]==9){
                INFO info = {i,j,2};
                shark = info;
                map[i][j]=0;
            }
        }
    }
    int cnt =0;
    while(1)
    {
        if(BFS()){
            cnt++;
            if(cnt == shark.size){
                shark.size++;
                cnt=0;
            }
        }
        else break;
    }
    printf("%d",total);
    
    return 0;
    
}

