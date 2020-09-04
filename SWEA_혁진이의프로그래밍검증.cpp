#include <iostream>
#define MAX 21
using namespace std;

int T,R,C;
char map[MAX][MAX]={0,};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int dir = 1;
int mem = 0;

int visited[MAX][MAX][4][16]={0,};
bool flag;

void command(char ch)
{
    switch(ch)
    {
        case '<':   dir=3;  break;
        case '>':   dir=1;  break;
        case '^':   dir=0;  break;
        case 'v':   dir=2;  break;
        case '_':
            if(mem == 0)    dir =1;
            else    dir =3;
            break;
        case '|':
            if(mem == 0)    dir=2;
            else    dir=0;
            break;
        case '@':
            flag = true;
            break;
        case '+':
            if(mem == 15)   mem =0;
            else mem++;
            break;
        case '-':
            if(mem == 0)    mem =15;
            else    mem--;
            break;
        case '.':
            break;
        default:
            mem = ch - '0';
            break;
    }
    return ;
}

int move(int pos, int rc)
{
    int npos =pos;
    
    if(!rc) // row
    {
        npos = pos + dx[dir];
        if(npos < 0)    npos = R-1;
        else if (npos >=R)  npos = 0;
    }
    else{
        npos = pos+ dy[dir];
        if(npos < 0)    npos = C-1;
        else if(npos >= C)  npos = 0;
    }
    
    return npos;
}

void DFS(int x, int y)
{
    if(flag || visited[x][y][dir][mem]) return;
    
    visited[x][y][dir][mem]=1;
    
    int nx, ny;
    
    if(map[x][y]=='?'){
        
        for(int i=0;i<4;i++){
            dir = i;
            
            nx = move(x, 0);
            ny = move(y, 1);
            
            DFS(nx,ny);
            
            if(flag)    return;
        }
        return ;
    }
    
    command(map[x][y]);
    
    nx = move(x,0);
    ny = move(y,1);
    
    DFS(nx,ny);
}

void init()
{
    dir = 1;
    mem = 0;
    flag =false;
    
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            for(int k=0;k<4;k++){
                for(int l=0;l<16;l++)   visited[i][j][k][l]=0;
            }
        }
    }
}
int main(void)
{
    cin >> T;
    for(int k=0;k<T;k++){
        cin >> R >> C;
        for(int i =0;i<R;i++){
            for(int j=0;j<C ;j++){
                cin >> map[i][j];
            }
        }
        init();

        DFS(0,0);
        
        
        cout << "#"<<k+1;
        
        if(flag)    cout << " YES\n";
        else    cout << " NO\n";
    }
}
