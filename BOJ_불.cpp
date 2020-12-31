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

queue <pos> fq;

void BFS()
{
    queue <pos> q;
    
    q.push(start);
    visited[start.x][start.y]=1;
    
    while(!q.empty()){
        
        int _size = q.size();
        int fsize = fq.size();
        
        while(fsize--){
            int x = fq.front().x;
            int y = fq.front().y;
            
            fq.pop();
            
            for(int i=0;i<4;i++){
                
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx<0 || ny<0 || nx>=w || ny >= h || map[nx][ny]!= 0 || visited[nx][ny] != 0)  continue;

                map[nx][ny]=1;
                visited[nx][ny]=-1;
                fq.push({nx,ny});
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
                
                if(map[nx][ny]!= 0 || visited[nx][ny]!=0)  continue;

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

        while(!fq.empty())  fq.pop();
        
        cin >> h >> w;
        res=0;
        
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                
                char ch;
                cin >> ch;
                
                if( ch == '@')  start={i,j};
                else if( ch == '*') {
                    map[i][j]=1;
                    visited[i][j]=-1;
                    fq.push({i,j});
                }
                else if( ch == '#') map[i][j]=1;
                
            }
        }
        
        BFS();
        
        if(res==0)  cout << "IMPOSSIBLE";
        else    cout << res;
        
        cout << "\n";
    }
    
    return 0;
}

