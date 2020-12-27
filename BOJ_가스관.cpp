#include <iostream>
#include <queue>
#define MAX 26
using namespace std;

struct pos{
    int x,y;
};

int N,M;
int map[MAX][MAX]={0,};
int visited[MAX][MAX]={0,};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


pos start,END;

void solve(int x,int y)
{
    int v[4]={0,};
    
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny]==0)  continue;
        
        if(i==0 && (map[nx][ny] == 1 || map[nx][ny] == 4 ||map[nx][ny] == 5||map[nx][ny] == 7))    v[0]=1;
        else if(i==1 && (map[nx][ny] == 3 || map[nx][ny] == 4 ||map[nx][ny] == 6||map[nx][ny] == 7))    v[1]=1;
        else if(i==2 && (map[nx][ny] == 2 || map[nx][ny] == 3 ||map[nx][ny] == 5||map[nx][ny] == 7))    v[2]=1;
        else if(i==3 && (map[nx][ny] == 1 || map[nx][ny] == 2 ||map[nx][ny] == 6||map[nx][ny] == 7))    v[3]=1;


    }
    cout<<x+1 << " " << y+1 << " ";
    
    if(v[0] && v[1] && v[2] && v[3] )   cout << "+";
    else if(v[0]==0 && v[1] && v[2]==0 && v[3] )   cout << "-";
    else if(v[0] && v[1]==0 && v[2] && v[3]==0 )   cout << "|";
    else if(v[0]==0 && v[1] && v[2] && v[3]==0 )   cout << "1";
    else if(v[0] && v[1] && v[2]==0 && v[3]==0 )   cout << "2";
    else if(v[0] && v[1]==0 && v[2]==0 && v[3] )   cout << "3";
    else if(v[0]==0 && v[1]==0 && v[2] && v[3] )   cout << "4";
    
    return ;
}

void BFS()
{
    queue <pos> q;
    q.push({start.x,start.y});
    
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        
        visited[x][y] = 1;
        
        q.pop();
        
        int nx, ny;
        
        if(map[x][y] == 1){
            
            for(int i=1;i<3;i++){
                nx = x+dx[i];
                ny = y+dy[i];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] == 1)  continue;
                
                if(map[nx][ny] == 0){
                    solve(nx,ny);
                    return;
                }
                visited[nx][ny] = 1;
                q.push({nx,ny});
                
            }
        }
        else if(map[x][y] == 2){
            
            for(int i=0;i<2;i++){
                nx = x+dx[i];
                ny = y+dy[i];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] == 1)  continue;
                
                if(map[nx][ny] == 0){
                    solve(nx,ny);
                    return;
                }
                visited[nx][ny] = 1;
                q.push({nx,ny});
                
            }
        }
        else if(map[x][y] == 3){
            
            for(int i=0;i<4;i+=3){
                nx = x+dx[i];
                ny = y+dy[i];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] == 1)  continue;
                
                if(map[nx][ny] == 0){
                    solve(nx,ny);
                    return;
                }
                visited[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
        else if(map[x][y] == 4){
            
            for(int i=2;i<4;i++){
                nx = x+dx[i];
                ny = y+dy[i];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] == 1)  continue;
                
                if(map[nx][ny] == 0){
                    solve(nx,ny);
                    return;
                }
                visited[nx][ny] = 1;
                q.push({nx,ny});
                
            }
        }
        else if(map[x][y] == 5){
            
            for(int i=0;i<3;i+=2){
                nx = x+dx[i];
                ny = y+dy[i];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] == 1)  continue;
                
                if(map[nx][ny] == 0){
                    solve(nx,ny);
                    return;
                }
                visited[nx][ny] = 1;
                q.push({nx,ny});
                
            }
        }
        else if(map[x][y] == 6){
            
            for(int i=1;i<4;i+=2){
                nx = x+dx[i];
                ny = y+dy[i];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] == 1)  continue;
                
                if(map[nx][ny] == 0){
                    solve(nx,ny);
                    return;
                }
                visited[nx][ny] = 1;
                q.push({nx,ny});
                
            }
        }
        
        else if(map[x][y] == 7){
            
            for(int i=0;i<4;i++){
                nx = x+dx[i];
                ny = y+dy[i];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] == 1)  continue;
                
                if(map[nx][ny] == 0){
                    solve(nx,ny);
                    return;
                }
                visited[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
        else if(map[x][y] == 8){
            
            for(int i=0;i<4;i++){
                nx = x+dx[i];
                ny = y+dy[i];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] == 1)  continue;
                visited[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
    
}

int main(void)
{
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char ch;
            cin >>ch;
            
            if(ch == '.')   map[i][j]=0;
            else if(ch == '|')   map[i][j]=5;
            else if(ch == '-')   map[i][j]=6;
            else if(ch == '+')   map[i][j]=7;
            else if(ch == '1')   map[i][j]=1;
            else if(ch == '2')   map[i][j]=2;
            else if(ch == '3')   map[i][j]=3;
            else if(ch == '4')   map[i][j]=4;
                      
            else if(ch == 'M'){
                      start={i,j};
                      map[i][j] = 8;
            }
            else if(ch == 'Z'){
                      END={i,j};
                      map[i][j] = 9;
            }
        }
    }
    
    BFS();
    return 0;
}
