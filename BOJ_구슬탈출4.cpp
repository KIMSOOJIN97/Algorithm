#include <iostream>
#include <queue>

#define MAX 11

using namespace std;

struct pos{
    int x,y;
};

struct ball{
    int rx,ry;
    int bx,by;
    int cnt;
};

pos red,blue,goal;

int map[MAX][MAX]={0,};
int N,M;
bool visited[MAX][MAX][MAX][MAX]={false,};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


pos move(int x, int y,int dir)
{

    while(1){
        x+=dx[dir];
        y+=dy[dir];
        if(x < 0 || y <0 || x >= N || y >= M || map[x][y] != 0 ){
            x -= dx[dir];
            y -= dy[dir];
            break;
        }
        if(goal.x==x && goal.y== y) break;
    }

    return {x,y};
}

int BFS()
{
    queue <ball> q;
    
    q.push({red.x,red.y,blue.x,blue.y,0});
    visited[red.x][red.y][blue.x][blue.y]=true;
    
    while(!q.empty()){

        int rx = q.front().rx;   int ry= q.front().ry;
        int bx = q.front().bx;   int by= q.front().by;
        int cnt = q.front().cnt;
        q.pop();
        
        for(int i=0;i<4;i++){
            
            pos tmp_red = move(rx,ry,i);
            pos tmp_blue = move(bx,by,i);
            
            
            if((tmp_blue.x == goal.x) &&(tmp_blue.y==goal.y))  continue;
            if((tmp_red.x==goal.x)&&(tmp_red.y == goal.y))    return cnt+1;
            
            if((tmp_blue.x==tmp_red.x)&&(tmp_blue.y==tmp_red.y)){
                
                if(i==0){
                    if(rx < bx)  tmp_blue.x++;
                    else    tmp_red.x++;
                }
                else if(i == 1){
                    if(ry < by)  tmp_red.y--;
                    else    tmp_blue.y--;
                }
                else if(i == 2){
                    if (rx < bx) tmp_red.x--;
                    else    tmp_blue.x--;
                }
                else if(i == 3){
                    if( ry< by) tmp_blue.y++;
                    else    tmp_red.y++;
                }
            }
            
            if(visited[tmp_red.x][tmp_red.y][tmp_blue.x][tmp_blue.y])   continue;
            visited[tmp_red.x][tmp_red.y][tmp_blue.x][tmp_blue.y]=true;
            q.push({tmp_red.x,tmp_red.y,tmp_blue.x,tmp_blue.y,cnt+1});
        }
    }
    return -1;
}

int main(void)
{
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            
            char ch;
            cin >> ch;
            if(ch=='#') map[i][j]=-1;
            else if(ch=='O')    goal={i,j};
            else if(ch=='R')    red = {i,j};
            else if(ch=='B')    blue = {i,j};
        }
    }
    
    cout << BFS();
    
    return 0;
    
}

