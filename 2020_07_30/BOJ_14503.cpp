#include <iostream>

using namespace std;

/*
현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
로봇 청소기는 이미 청소되어있는 칸을 또 청소하지 않으며, 벽을 통과할 수 없다.
 */

//0:북 , 1:동, 2:남, 3:서
//0: 빈칸, 1:벽

int N,M;
int map[50][50];
int cnt=0; // number of clean space by robot

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


void DFS(int x , int y, int dir){
    
    map[x][y]=2;

    for(int i=0;i<4;i++){
        
        if(dir == 0)    dir = 3;
        else    dir-=1;
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(map[nx][ny]==0){
            DFS(nx,ny,dir);
            return;
        }
    }
    /* 후진 하는 경우 */
    x-=dx[dir];
    y-=dy[dir];
    if(map[x][y]==1)    return;
    else    DFS(x,y,dir);

}
int main(void)
{
    int x,y,dir;
    
    cin >> N >> M ;
    cin >> x >> y >> dir;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            cin >> map[i][j];
    }
    
    DFS(x,y,dir);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            if(map[i][j]==2)    cnt++;
    }
    cout << cnt;
    return 0;
    
}

