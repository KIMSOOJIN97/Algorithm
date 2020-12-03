#include <iostream>
#include <queue>
#include <vector>

#define MAX 51

using namespace std;

struct pos{
    int x,y;
};

pos S,D; // 고슴도치, 비버

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int visited[MAX][MAX]={0,};
int map[MAX][MAX]={0,};
int R,C;


vector <pos> water;

void move()
{
    int size = water.size();
    
    for(int i=0;i<size;i++)
    {
        int x= water[i].x;
        int y= water[i].y;
        
        for(int j=0;j<4;j++){
            int nx=x+dx[j];
            int ny=y+dy[j];
            
            if(nx < 0 || ny<0 || nx >= R || ny >= C || map[nx][ny] != 0) continue;
            else if( nx == D.x && ny == D.y)  continue;

            map[nx][ny]=1;
            water.push_back({nx,ny});
            
        }
    }
}

void BFS()
{
    queue <pos> q;
    q.push({S.x,S.y});
    int cnt =-1;
    
    while(!q.empty()){

        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        if(cnt != visited[x][y]){
            move();
            cnt= visited[x][y];
         }
        if( x == D.x && y == D.y)  return;
            
        
        for(int i=0;i<4;i++){
            
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx < 0 || ny<0 || nx >= R || ny >= C || visited[nx][ny] != 0) continue;
            else if(map[nx][ny] != 0)   continue;
            
            q.push({nx,ny});
            visited[nx][ny] = visited[x][y]+1;
            
        }
    }

}

int main(void)
{
    cin >> R >> C;
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            char ch1;
            cin >> ch1;
            
            if(ch1 == '.')  map[i][j]=0;
            else if(ch1 == '*'){
                map[i][j]=1; //물
                water.push_back({i,j});
            }
            else if (ch1 == 'X')    map[i][j]=-1; // 돌
            else if(ch1 == 'S') S={i,j};
            else if(ch1 == 'D') D={i,j};
            
        }
    }
    
    BFS();
    if(visited[D.x][D.y] == 0)    cout<<"KAKTUS";
    else cout << visited[D.x][D.y];
    
    return 0;
    
}

