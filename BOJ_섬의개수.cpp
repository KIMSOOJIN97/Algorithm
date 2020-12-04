#include <iostream>
#include <queue>
#define MAX 51

using namespace std;

struct pos{
    int x,y;
};

int N,M;
int map[MAX][MAX]={0,};

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

void BFS()
{
    queue <pos> q;
    int cnt =1;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            
            if(map[i][j]==1){
                cnt++;
                map[i][j] = cnt;
                q.push({i,j});
            }
            
            while(!q.empty()){
                int x = q.front().x;
                int y = q.front().y;
                q.pop();
                
                for(int k=0;k<8;k++){
                    
                    int nx= x+dx[k];
                    int ny= y+dy[k];
                    
                    if(nx<0||ny<0||nx>=N||ny>=M||map[nx][ny]!=1)  continue;
                    map[nx][ny]= cnt;
                    q.push({nx,ny});
                    
                }
            }
        }
    }
    
    printf("%d\n",cnt-1);
}

int main(void)
{
    
    while(1){
        scanf("%d %d",&M, &N);
        
        if(!N && !M)    break;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)    scanf("%d",&map[i][j]);
        }
        
        BFS();
    }
    
    return 0;
    
}

