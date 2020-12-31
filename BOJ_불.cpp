#include <iostream>
#include <string>
#include <queue>

#define MAX 1001

using namespace std;

struct pos{
    int x,y;
};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

pos start;
int visited[MAX][MAX]={0,};
bool tmp[MAX][MAX]={0,};
int map[MAX][MAX]={0,};
int w,h;
int res=0;


void BFS()
{
    queue <pos> q;
    q.push(start);
    visited[start.x][start.y]=1;
    
    while(!q.empty()){
        
        int _size = q.size();
        
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                if(map[i][j] == 1){
                    for(int k=0;k<4;k++){
                        
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        
                        if(nx<0 || ny<0 || nx>=w || ny >= h || map[nx][ny]!= 0)  continue;
                        tmp[nx][ny] = true;
                    }
                }
            }
        }
        
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                if(tmp[i][j])    map[i][j]=1;
            }
        }

        while(_size--){
        
            int x = q.front().x;
            int y = q.front().y;
            
            q.pop();
            
            for(int i=0;i<4;i++){
                
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx<0 || ny<0 || nx>=w || ny >= h){
                    res = visited[x][y];
                    return;
                }
                
                if(map[nx][ny]!= 0 || visited[nx][ny])  continue;

                visited[nx][ny]=visited[x][y]+1;
                q.push({nx,ny});
                            
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
        memset(tmp, false, sizeof(tmp));
        memset(visited, false, sizeof(visited));
        memset(map, false, sizeof(map));

        cin >> h >> w;
        res=0;
        
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                
                char ch;
                cin >> ch;
                
                if( ch == '@')  start={i,j};
                else if( ch == '#') map[i][j]=-1;
                else if( ch == '*') map[i][j]=1;
                
            }
        }
        
        BFS();
        
        if(res==0)  cout << "IMPOSSIBLE";
        else    cout << res;
        
        cout << "\n";
    }
    
    return 0;
}

