#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 51

using namespace std;

struct pos{
    int x,y;
};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int N,M;
bool visited[MAX][MAX]={0,};
bool map[MAX][MAX]={0,};
bool b[MAX][MAX]={0,};

void black()
{
    queue <pos> q;
    b[0][0]=true;
    q.push({0,0});
    visited[0][0]=true;
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx<0||ny<0||nx>=N||ny>=M||visited[nx][ny])   continue;
            if(b[x][y]==false) b[nx][ny] = true;
            q.push({nx,ny});
            visited[nx][ny]=true;
        }
    }
}


int solve(int x,int y)
{
    int b_cnt=0;
    int w_cnt=0;
    
    for(int i=x;i<x+8;i++){
        for(int j=y;j<y+8;j++){
            if(map[i][j] != b[i][j])    b_cnt++;
        }
    }
    for(int i=x;i<x+8;i++){
        for(int j=y;j<y+8;j++){
            if(map[i][j] == b[i][j])    w_cnt++;
        }
    }
    return min(b_cnt,w_cnt);
}
int main(void)
{
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char ch;
            cin >> ch;
            if(ch=='B')    map[i][j]=true;
        }
    }
    
    int ans = MAX*MAX;
    black();
    
    for(int i=0;i<=N-8;i++){
        for(int j=0;j<=M-8;j++){
            ans = min(ans,solve(i,j));
        }
    }
    cout << ans;
    return 0;
}

