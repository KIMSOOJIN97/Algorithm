#include <iostream>
#include <queue>
#include <vector>

#define MAX 21

using namespace std;
/*
 4개 이상 쌓이는 순간 게임이 종료된다.
  1부터 순서대로 →, ←, ↑, ↓의 의미를 갖는다.
 순서대로 행, 열의 번호, 이동 방향이
 */

struct Horse{
    int x, y ,dir;
};
int turn=0;

int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};

int color[MAX][MAX];
vector <int> map[MAX][MAX];

Horse horse[12];
int N , K;
int nx,ny;

void white(int idx)
{
    int x =horse[idx].x;
    int y =horse[idx].y;
    int dir = horse[idx].dir;
    nx = x+dx[dir];
    ny = y+dy[dir];
    
    vector <int> v;
    
    int size = map[x][y].size()-1;
    
    for(int i=size;i>=0;i--){
        
        int num = map[x][y][i];
        horse[num].x= nx;
        horse[num].y= ny;
        
        v.push_back(map[x][y][i]);
        map[x][y].pop_back();
        
        if(map[x][y][i] == idx) break;
    }
    
    size = v.size()-1;
    for(int i = size ; i>=0 ; i--)  map[nx][ny].push_back(v[i]);
}

void red(int idx)
{
    int x =horse[idx].x;
    int y =horse[idx].y;
    int dir = horse[idx].dir;
    nx = x+dx[dir];
    ny = y+dy[dir];
    
    vector <int> v;
    
    int size = map[x][y].size()-1;
    
    for(int i=size;i>=0;i--){
        int num = map[x][y][i];
        horse[num].x= nx;
        horse[num].y= ny;
        v.push_back(num);
        map[x][y].pop_back();
        
        if(num == idx) break;
    }
    
    for(int i = 0; i<v.size() ; i++)  map[nx][ny].push_back(v[i]);
}

void blue(int idx)
{
    int dir = horse[idx].dir;
    int x =horse[idx].x;
    int y =horse[idx].y;
    
    if(dir == 1 || dir == 2)    dir= dir%2 + 1;
    else if(dir == 3 || dir == 4)    dir= dir%2 + 3;
    
    
    nx = x+dx[dir];
    ny = y+dy[dir];
    
    if(nx< 1 || ny < 1 || nx > N || ny > N || color[nx][ny] == 2) return ;
   
    horse[idx].dir = dir;

    if(color[nx][ny] == 0)   white(idx);
    else if(color[nx][ny] == 1)   red(idx);
    
    
}

bool move()
{
    for(int k=0;k<K;k++){
        
        int x =horse[k].x;
        int y =horse[k].y;
        int dir = horse[k].dir;
        
        nx = x+dx[dir];
        ny = y+dy[dir];
        
        if(nx< 1 || ny < 1 || nx > N || ny > N || color[nx][ny] == 2) blue(k);
        else if(color[nx][ny] == 0)   white(k);
        else if(color[nx][ny] == 1)   red(k);
        
        if(nx< 1 || ny < 1 || nx > N || ny > N) continue;

        if(map[nx][ny].size() >= 4) {
            cout << turn;
            return false;
        }
    }
    return true;
}


void solve()
{

    while(1){
        turn++;
        if(turn > 1000) {
            cout << "-1";
            return;
        }
        if(!move())
            return;
        
        
    }
}

int main(void)
{
    cin >> N >> K;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            cin >> color[i][j];
    }
    
    for(int i=0;i<K;i++){
        
        cin >> horse[i].x >> horse[i].y >> horse[i].dir;
        map[horse[i].x][horse[i].y].push_back(i);
    }
    
    solve();
    
    return 0;
}

