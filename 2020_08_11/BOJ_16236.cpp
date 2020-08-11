#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 20


// 물고기 M마리와 아기 상어 1마리 ( 처음 크기 2)
//자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다
// 자신의 크기보다 작은 물고기만 먹을 수 있다. 따라서, 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.

struct Shark{
    int x,y,size;
};

int dx[4] = { -1,0,1,0};
int dy[4] = {0,-1,0,1};
int fx,fy;

int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];

Shark shark;

void BFS()
{
    int dist = 401;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            visited[i][j] = -1;
    }
    
    queue <pair<int , int >> q;
    q.push(make_pair(shark.x,shark.y));
    
    visited[shark.x][shark.y] =0;
    
    while(!q.empty()){
        
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx <0 || ny < 0 || nx >= N || ny >= N)   continue;
            if( map[nx][ny] > shark.size || visited[nx][ny] != -1)   continue;
            
            q.push(make_pair(nx, ny));
            visited[nx][ny] = visited[x][y] + 1;
            
            if(map[nx][ny] > 0 && map[nx][ny] < shark.size){
                if(dist > visited[nx][ny] ) {
                    fx = nx;
                    fy = ny;
                    dist = visited[nx][ny];
                }
                else if (dist == visited[nx][ny]){
                    if(nx < fx){
                        fx = nx;
                        fy = ny;
                    }
                    else if(nx == fx){
                        if(ny < fy){
                            fx = nx;
                            fy = ny;
                        }
                    }
                }
            }
            
        }
    }
    
}
int main(void)
{

    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            
            if ( map[i][j] == 9){
                shark.x = i;
                shark.y = j;
                shark.size = 2;
                map[i][j] = 0 ;
                
            }
        }
    }
    
    int eat_num=0;
    int tm=0;
    queue <pair<int,int>> q; // 상어가 갈 수 있는 위치
    vector <pair<int,int>> fish; // 상어가 먹을 수 있는 물고기들
    
    while(1){
        
        fx =MAX;
        fy =MAX;
        
        BFS();
        
        if(fx != MAX && fy != MAX){
            map[fx][fy]=0;
            eat_num++;
            tm += visited[fx][fy];
            shark.x = fx;
            shark.y = fy;
            
            if(eat_num == shark.size){
                shark.size++;
                eat_num=0;
            }
        }
        else break;
        
    }
    cout << tm;
    
    return 0;
    
}

