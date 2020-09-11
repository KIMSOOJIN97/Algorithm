#include <iostream>
#define MAX 51

using namespace std;

int map[MAX][MAX]={0,};
int N,M;
int x,y,dir;
int dx[4]= {-1,0,1,0};
int dy[4] ={0,1,0,-1};

void solve()
{
    map[x][y]=1;

    int cnt =0;
    while(1)
    {
        if(dir == 0)    dir=3;
        else    dir--;

        cnt++;
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(map[nx][ny] == 0){
            x = nx;
            y = ny;
            map[x][y]=1;
            cnt=0;
        }
        else if(cnt==4){
            x-=dx[dir];
            y-=dy[dir];
            if(map[x][y]==-1)  break;
            cnt=0;
        }
        
    }
}

int main(void)
{
    cin >> N >> M ;
    cin >> x >> y >> dir;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j]==1)    map[i][j]=-1;
        }
    }
    solve();
    int cnt=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==1)    cnt++;
        }
    }
    cout << cnt;
    
    return 0;
}

