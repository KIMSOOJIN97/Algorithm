#include <iostream>
#define MAX 101

using namespace std;

int N,K,L;
int map[MAX][MAX]={0,};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct MOVE{
    int time;
    char dir;
};

MOVE mv[100];

void solve()
{
    int visited[MAX][MAX]={0,};
    int tm=0;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)    visited[i][j]=-1;
    }
    
    int tx=1,ty=1;
    int hx=1,hy=1;
    int dir=1;
    int idx =0;
    
    while(1)
    {
        visited[hx][hy]=dir;
        tm++;
        hx += dx[dir];
        hy += dy[dir];
        
        if(hx<1 || hy<1 || hx > N || hy > N || visited[hx][hy] != -1)    break;
        if(map[hx][hy]==1){
            map[hx][hy]=0;
        }
        else{
            int d = visited[tx][ty];
            visited[tx][ty] = -1;
            tx += dx[d];
            ty += dy[d];
        }
        
        if(idx < L && tm == mv[idx].time){
            if(mv[idx].dir == 'L'){
                if(dir ==0)  dir =3;
                else    dir--;
            }
            else{
                if(dir== 3) dir =0;
                else    dir++;
            }
            idx++;
        }
    }
    cout << tm;
}
int main(void)
{
    
    cin >> N >>K;
    
    for(int i=0;i<K;i++){
        int x,y;
        cin >> x>>y;
        map[x][y]=1;
    }
    
    cin >> L;
    for(int i=0;i<L;i++){
        int t;
        char d;
        cin >> t >> d;
        
        mv[i]={t,d};
    }
    
    solve();
        
    return 0;
    
}

