#include <iostream>
#include <queue>
#define MAX 51

using namespace std;

struct pos{
    int x,y,cnt;
};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool map[MAX][MAX]={0,};
int visited[MAX][MAX]={0,};
int N;

int BFS()
{
    int res = MAX*MAX;
    queue <pos> q;
    q.push({0,0,1});
    visited[0][0]=1;
    
    while(!q.empty()){
        int x= q.front().x;
        int y= q.front().y;
        int cnt = q.front().cnt;
        visited[0][0]=1;
        q.pop();
        if(x==N-1 && y==N-1){
            if(res > cnt)   res = cnt;
            continue;
        }
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx<0 || ny < 0 || nx >= N || ny >= N  )    continue;
            int tmp=cnt;
            if(map[nx][ny]==0) tmp+=1;
            if(visited[nx][ny]!=0  && tmp >= visited[nx][ny])   continue;
            
            visited[nx][ny] =  tmp;
            q.push({nx,ny,tmp});
            
        }
    }
    return res-1;
    
}
int main(void)
{
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%1d",&map[i][j]);
        }
    }
    cout << BFS();
    return 0;
}

~
