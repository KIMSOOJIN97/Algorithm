#include <iostream>
#include <vector>

#define MAX 8
using namespace std;
/*
지도에서 0은 빈 칸, 6은 벽, 1~5는 CCTV의 번호
 */

int N,M;
int map[MAX][MAX]={0,};
int tmp[MAX][MAX]={0,};
int visited[8]={0,};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct pos {
    int x,y;
    int num;
};

int cnt=0;
vector <pos> CCTV;
int MIN =1e9;

void spread(int x, int y, int dir)
{
    while(1){
        if(tmp[x][y]==6)    return;
        if(x < 0 || y < 0 || x >= N || y >= M ) return;
        tmp[x][y]=-1;
        
        x += dx[dir];
        y+= dy[dir];
    }
}


void solve()
{
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)    tmp[i][j] = map[i][j];
    }
    
    for(int i=0;i<cnt;i++){
        
        int x = CCTV[i].x;
        int y = CCTV[i].y;
        
        if(CCTV[i].num==1){
            spread(CCTV[i].x, CCTV[i].y, visited[i]-1);
        }
        else if(CCTV[i].num==2){
            if(visited[i]==1){
                spread(x, y, 1);
                spread(x, y, 3);
            }
            else{
                spread(x, y, 0);
                spread(x, y, 2);
            }
        }
        else if(CCTV[i].num==3){
            if(visited[i]==1){
                spread(x, y, 0);
                spread(x, y, 1);
            }
            else if(visited[i]==2){
                spread(x, y, 1);
                spread(x, y, 2);
            }
            else if(visited[i]==3){
                spread(x, y, 2);
                spread(x, y, 3);
            }
            else if(visited[i]==4){
                spread(x, y, 3);
                spread(x, y, 0);
            }
        }
        else if(CCTV[i].num==4){
            if(visited[i]==1){
                spread(x, y, 0);
                spread(x, y, 1);
                spread(x, y, 2);
            }
            else if(visited[i]==2){
                spread(x, y, 1);
                spread(x, y, 2);
                spread(x, y, 3);

            }
            else if(visited[i]==3){
                spread(x, y, 2);
                spread(x, y, 3);
                spread(x, y, 0);

            }
            else if(visited[i]==4){
                spread(x, y, 3);
                spread(x, y, 0);
                spread(x, y, 1);

            }
        }
        else if(CCTV[i].num==5){
            spread(x, y, 0);
            spread(x, y, 1);
            spread(x, y, 2);
            spread(x, y, 3);

        }
    }
    int tmp1=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(tmp[i][j]==0)    tmp1++;
        }
    }
    
    if(tmp1 < MIN)  MIN = tmp1;
}

void DFS(int idx)
{
    if(idx == cnt)
    {
        solve();
        return;
    }
    
    if(CCTV[idx].num == 1){
        for(int i=1;i<=4;i++){
            visited[idx]=i;
            DFS(idx+1);
        }
    }
    else if(CCTV[idx].num == 2){
        for(int i=1;i<=2;i++){
            visited[idx]=i;
            DFS(idx+1);
        }
    }
    else if(CCTV[idx].num == 3){
        for(int i=1;i<=4;i++){
            visited[idx]=i;
            DFS(idx+1);
        }
    }
    else if(CCTV[idx].num == 4){
        for(int i=1;i<=4;i++){
            visited[idx]=i;
            DFS(idx+1);
        }
    }
    else if(CCTV[idx].num == 5) DFS(idx+1);
    
    return;
    
}
int main(void)
{
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
        {
            cin >> map[i][j];
            if(map[i][j] != 0 && map[i][j]!=6){
                CCTV.push_back({i,j,map[i][j]});
                cnt++;
            }
        }
    }
    
    DFS(0);
    
    cout << MIN << endl;
    
    
    return 0;
    
}

