#include <iostream>
#include <queue>

#define MAX 301

using namespace std;

int N;
int map[MAX][MAX]={0,};

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

struct pos{
    int x,y;
};

int BFS()
{
    
    int visited[MAX][MAX]={0,};
    
    queue <pos> q;
    
    int cnt=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            
            if(map[i][j]==9){
                visited[i][j]=1;
                continue;
            }
            if(map[i][j]==-1 && visited[i][j]==0 )   {
                q.push({i,j});
                cnt++;
            }
            
            while(!q.empty()){
                
                int x = q.front().x;
                int y = q.front().y;
                
                q.pop();
                visited[x][y]=cnt;
                
                for(int k=0;k<8;k++){
                    
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    
                    if(nx < 0 || ny <0 || nx >= N || ny >= N )   continue;
                    if(map[nx][ny] == -1 && visited[nx][ny]==0) q.push({nx,ny});
                    visited[nx][ny]=cnt;

                }
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
         
            if(visited[i][j]==0)    cnt++;
        }
    }
    return cnt;
    
}
int main(void)
{
    int T;
    scanf("%d",&T);
    
    for(int k=0;k<T;k++){
        scanf("%d",&N);
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                char ch;
                cin >> ch;
                if(ch == '.')   map[i][j]=-1;
                else if(ch=='*')    map[i][j]=9;
            }
        }
        

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                
                if(map[i][j]==9){
                    
                    for(int k=0;k<8;k++){
                        
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        
                        if(nx < 0 || ny <0 || nx >= N || ny >= N || map[nx][ny]==9)   continue;
                        if(map[nx][ny]==-1) map[nx][ny]=1;
                        else    map[nx][ny]++;
                        
                    }
                }
            }
        }
        
        int res = BFS();
        

        printf("#%d %d\n",k+1,res);
    }
    return 0;
}

