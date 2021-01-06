#include <iostream>
#define MAX 11

using namespace std;

struct pos{
    int x,y;
};

pos red,blue,goal;

int map[MAX][MAX]={0,};
int N,M;
int ans=MAX*MAX;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


int move(int dir)
{
    int rx =red.x;
    int ry =red.y;
    
    while(1){
        rx+=dx[dir];
        ry+=dy[dir];
        if(rx < 0 || ry <0 || rx >= N || ry >= M || map[rx][ry] != 0 ){
            rx -= dx[dir];
            ry -= dy[dir];
            break;
        }
        if(goal.x==rx && goal.y== ry) break;
    }

    int bx =blue.x;
    int by =blue.y;
    
    while(1){
        bx+=dx[dir];
        by+=dy[dir];
        if(bx < 0 || by <0 || bx >= N || by >= M || map[bx][by] != 0 ){
            bx -= dx[dir];
            by -= dy[dir];
            break;
        }
        if(goal.x==bx && goal.y== by) break;
    }

    if((rx==goal.x)&&(ry == goal.y) && (bx == goal.x) &&(by==goal.y))    return -1;
    else if((rx==goal.x)&&(ry == goal.y))    return 1;
    else if((bx == goal.x) &&(by==goal.y))    return -1;
    
    if((rx==bx)&&(ry == by)){
        
        if(dir==0){
            if(red.x < blue.x)  bx++;
            else    ry++;
        }
        else if(dir == 1){
            if(red.y < blue.y)  ry--;
            else    by--;
        }
        else if(dir == 2){
            if (red.x < blue.x) rx--;
            else    bx--;
        }
        else if(dir == 3){
            if( red.y < blue.y) by++;
            else    ry++;
        }
    }
    if(red.x == rx &&red.y == ry && blue.x == bx && blue.y == by)   return -1;
    red={rx,ry};
    blue={bx,by};
    
    return 0;

}
bool DFS(int cnt)
{
    for(int i=0;i<4;i++){
        
        pos tmp_red=red;
        pos tmp_blue=blue;
        
        int res = move(i);
        
        if(res == -1)   continue;
        else if(res == 1){
            if(cnt < ans)   ans = cnt+1;
            return true;
        }
        
        if(DFS(cnt+1))  return true;
    
        red = tmp_red;
        blue = tmp_blue;
    }
    return false;
    
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
    
   
    DFS(0);
    if(ans == MAX * MAX)    cout << "-1";
    else   cout << ans;
    return 0;
    
}

