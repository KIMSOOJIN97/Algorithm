#include <iostream>
#define MAX 11

using namespace std;


struct pos{
    int x,y;
};

pos R,B;

int N,M;
int map[MAX][MAX]={0,};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int solve(int dir)
{
    int rx = R.x;
    int ry = R.y;
    
    while(1){
        if(map[rx][ry] != 0)    break;
        rx += dx[dir];
        ry += dy[dir];
    }
    
    int bx = B.x;
    int by = B.y;

    while(1){
        if(map[bx][by] != 0)    break;
        bx += dx[dir];
        by += dy[dir];
    }
    
    if(map[rx][ry] == 1 && map[bx][by] != 1)    return 1;
    else if(map[rx][ry] == 1 && map[bx][by] == 1)    return -1;
    else if(map[bx][by] == 1)   return -1;
    
    rx-= dx[dir];
    ry-= dy[dir];
    
    bx -= dx[dir];
    by -= dy[dir];
    
    if(rx == bx && ry == by){
        if(dir == 0 ) R.x > B.x ? rx++ : bx++ ;
        else if (dir == 1) R.y > B.y ? by-- : ry--;
        else if(dir == 2)   R.x > B.x ? bx-- : rx--;
        else if(dir == 3)   R.y > B.y ? ry++ : by++;

    }
    
    R={rx,ry};
    B={bx,by};
    
    return 0;
}

int DFS(int cnt)
{
    if(cnt >= 10 )  return 0;
    
    for(int i=0;i<4;i++){
        
        pos tmp_R = R;
        pos tmp_B = B;
        
        int res = solve(i);
        
        if(res==1 ) return 1;
        else if(res == -1)  continue;
        
        if(DFS(cnt+1) == 1)  return 1;
        
        R = tmp_R;
        B = tmp_B;
    }
    return -1;
}

int main(void)
{
    cin >> N >> M ;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char ch;
            cin >> ch;
            
            if (ch == '#')  map[i][j]=-1;
            else if(ch == 'O')  map[i][j] = 1;
            else if(ch == 'R')  {
                R.x = i;
                R.y = j;
            }
            else if(ch == 'B')  {
                B.x = i;
                B.y = j;
            }
        }
    }
    
    if(DFS(0) == 1) cout << "1";
    else cout << "0";
    
    return 0;
    
}



