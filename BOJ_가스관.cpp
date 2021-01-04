#include <iostream>
#define MAX 26

using namespace std;

struct pos {
    int x,y;
};

char map[MAX][MAX]={0,};

int R,C;

int dx[4] ={-1,0,1,0};
int dy[4] ={0,1,0,-1};

pos start;

void solve(int x, int y)
{
    cout << x+1 << " " << y+1 << " ";
    bool dir[4] = {0,};
    
    for(int i=0;i<4;i++){
        
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx<0 || ny< 0 || nx >= R || ny >= C )   continue;
        
        if(map[nx][ny] != '.'){
            if(i == 0 && (map[nx][ny] == '1' || map[nx][ny] == '4' || map[nx][ny] == '|' || map[nx][ny] =='+'))  dir[i]=true;
            else if(i == 1 && (map[nx][ny] == '3' || map[nx][ny] == '4' || map[nx][ny] == '-' || map[nx][ny] =='+'))  dir[i]=true;
            else if(i == 2 && (map[nx][ny] == '2' || map[nx][ny] == '3' || map[nx][ny] == '|' || map[nx][ny] =='+'))  dir[i]=true;
            else if(i == 3 && (map[nx][ny] == '1' || map[nx][ny] == '2' || map[nx][ny] == '-' || map[nx][ny] =='+'))  dir[i]=true;

        }
    }
    if(dir[0] && dir[1] && dir[2] && dir[3])    cout << "+";
    else if(dir[1] && dir[2])   cout << "1";
    else if(dir[0] && dir[1])   cout << "2";
    else if(dir[0] && dir[3])   cout << "3";
    else if(dir[2] && dir[3])   cout << "4";
    else if(dir[0] && dir[2])   cout << "|";
    else if(dir[1] && dir[3])   cout << "-";
    
    return ;
}

void DFS(int x, int y, int dir)
{
    if(map[x][y] == '.'){
        solve(x,y);
        return ;
    }
    
    int nx = x+dx[dir];
    int ny = y+dy[dir];
    
    if(dir ==0 ){
        if(map[nx][ny] == '|' || map[nx][ny] == '+')    dir = 0;
        else if(map[nx][ny] =='1')    dir= 1;
        else if(map[nx][ny] =='4') dir = 3;
    }
    else if(dir == 1 ){
        if(map[nx][ny] == '-' || map[nx][ny] == '+')    dir = 1;
        else if(map[nx][ny] =='3')    dir= 0;
        else if(map[nx][ny] =='4') dir = 2;
    }
    else if(dir == 2){
        if(map[nx][ny] == '|' || map[nx][ny] == '+')    dir = 2;
        else if(map[nx][ny] =='2')    dir= 1;
        else if(map[nx][ny] =='3') dir = 3;
    }
    else if(dir == 3){
        if(map[nx][ny] == '-' || map[nx][ny] == '+')    dir = 3;
        else if(map[nx][ny] =='1')    dir= 2;
        else if(map[nx][ny] =='2') dir = 0;
    }
    DFS(nx,ny,dir);
    return;
}

int main(void)
{

    cin >> R>>C;
    for (int i=0; i<R; i++){
        for(int j=0;j<C;j++){
            cin >> map[i][j];
            if(map[i][j]== 'M')  start = {i,j};
        }
    }
    
    int Direction =0;
    
    for (int i = 0; i < 4; i++) {
        int nx =start.x + dx[i];
        int ny =start.y + dy[i];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (map[nx][ny] != '.') {
            if (nx ==start.x) {
                if (ny == start.y - 1)  Direction = 3;
                else if (ny == start.y+ 1)  Direction = 1;
            }
            else if (ny == start.y) {
                if (nx == start.x - 1)  Direction = 0;
                else if (nx ==start.x + 1)  Direction = 2;
            }
        }
    }

    DFS(start.x,start.y,Direction);
    return 0;
}


