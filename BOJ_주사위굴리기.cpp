#include <iostream>
#define MAX 20
using namespace std;

/*
 
 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다.
 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다
 
 */

int N,M;
int map[MAX][MAX]={0,};
int x,y;

int dx[5]={0,0,0,-1,1};
int dy[5]={0,1,-1,0,0};

int dice[6]={0,};



void solve(int dir)
{
    x += dx[dir];
    y += dy[dir];
    
    if(x<0 || y<0 || x>=N || y>= M){
        x -= dx[dir];
        y -= dy[dir];
        return;
    }
    
    int tmp=0;
    
    if(dir==1){
        tmp = dice[0];
        dice[0] = dice[3];
        dice[3]=dice[5];
        dice[5]=dice[2];
        dice[2] = tmp;
    }
    else if(dir==2){
        tmp = dice[0];
        dice[0] = dice[2];
        dice[2]=dice[5];
        dice[5]=dice[3];
        dice[3] = tmp;
    }
    else if(dir==3){
        tmp = dice[0];
        dice[0] = dice[4];
        dice[4]=dice[5];
        dice[5]=dice[1];
        dice[1] = tmp;
    }
    else{
        tmp = dice[0];
        dice[0] = dice[1];
        dice[1]=dice[5];
        dice[5]=dice[4];
        dice[4] = tmp;
    }
    
    if(map[x][y]==0){
        map[x][y]=dice[5];
    }
    else{
        dice[5]=map[x][y];
        map[x][y]=0;
    }
    
    cout << dice[0]<<"\n";
}

int main(void)
{
    int K;
    
    cin >> N >> M;
    cin >> x >> y;
    cin >> K;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)    cin >> map[i][j];
    }
    
    for(int i=0;i<K;i++)
    {
        int dir;
        cin >> dir;
        
        solve(dir);
    }
    
    return 0;
}

