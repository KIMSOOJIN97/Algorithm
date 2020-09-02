
#include <iostream>
#include <queue>

#define MAX 10

using namespace std;

int N,M;
int map[MAX][MAX]={0,};
int MIN = 11;

int dx[4]={-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct POS{
    int rx,ry,bx,by;
    int cnt;
};

POS pos;


void move(int & x , int & y,int dir)
{
    
    while(1){
        
        x += dx[dir];
        y += dy[dir];
        
        if(map[x][y]==-1) {
            x -= dx[dir];
            y -= dy[dir];
            return;
        }
        else if(map[x][y]==1){
            return ;
        }
    }
}

void BFS()
{
    int visited[10][10][10][10]={0,};
    
    queue <POS> q;
    q.push({pos.rx, pos.ry, pos.bx, pos.by,0});
    
    visited[pos.rx][pos.ry][pos.bx][pos.by]=1;
    
    while(!q.empty()){
        
        POS tmp = q.front();
        
        if(tmp.cnt > 10 )   break;
        
        if(map[tmp.rx][tmp.ry]) {
            MIN = tmp.cnt;
            break;
        }
        
        q.pop();

        for(int i=0;i<4;i++){
            
            int rx = tmp.rx;
            int ry = tmp.ry;
            int bx = tmp.bx;
            int by = tmp.by;
            
            move(rx, ry,i);
            move(bx, by,i);
            
            if(map[bx][by] ==1) continue;
            else if( bx == rx && by == ry){
                
                if( i == 0)   tmp.rx > tmp.bx ? rx++ : bx++;
                else if (i == 1)  tmp.ry > tmp.by ? by-- : ry--;
                else if(i == 2)   tmp.rx > tmp.bx ? bx-- : rx--;
                else if (i == 3)  tmp.ry > tmp.by ? ry++ : by++;
                
            }
            
            if(!visited[rx][ry][bx][by]){
                q.push({rx, ry ,bx,by,tmp.cnt+1});
                visited[rx][ry][bx][by]=1;
            }

        }
        
    }
    
    
}


int main(void)
{
    
    cin >> N >> M ;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char ch;
            cin >> ch;
            if(ch == '.')   map[i][j]=0;
            else if(ch == '#')  map[i][j] = -1;
            else if(ch == 'O')  {
                map[i][j] = 1;
                            }
            else if(ch == 'R')  {
                map[i][j] = 0;
                pos.rx =i;
                pos.ry = j;
            }
            else if(ch == 'B')  {
                map[i][j] = 0;
                pos.bx =i;
                pos.by= j;
            }
        }
    }
    
    BFS();
    if(MIN == 11) cout << "-1";
    else    cout << MIN;
    return 0;
}

