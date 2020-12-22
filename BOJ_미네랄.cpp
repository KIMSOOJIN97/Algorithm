#include <iostream>
#include <queue>

#define MAX 101

using namespace std;

struct pos{
    int x,y;
};

int R,C;
int map[MAX][MAX]={0,};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void left(int idx)
{
    for(int i=0;i<C;i++){
        if(map[idx][i] == 1 ){
            map[idx][i] =0;
            return;
        }
    }
}
void right(int idx)
{
    for(int i=C-1;i>0;i--){
        if(map[idx][i] == 1 ){
            map[idx][i] =0;
            return;
        }
    }
}

void solve()
{
    int tmp[MAX][MAX]={0,};
    int cnt =0;

    queue <pos> q;
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j]==1 && tmp[i][j]==0){
                q.push({i,j});
                cnt++;
                tmp[i][j]= cnt;
            }
            while(!q.empty()){
                
                int x = q.front().x;
                int y = q.front().y;
                
                for(int k=0;k<4;k++){
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    
                    if(nx < 0 || ny < 0 || nx >= R || ny >= C || tmp[nx][ny] != 0)  continue;
                    tmp[nx][ny] = tmp[x][y];
                    q.push({nx,ny});
                }
                
            }
        }
    }
}
int main(void)
{
    cin >> R >> C;
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            char ch;
            cin >> ch;
            if(ch == 'x')   map[i][j]=1;
        }
    }
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        if(i%2 == 0)    left(num);
        else    right(num);
        
        solve();
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j]==0)    cout <<".";
            else    cout <<"x";
        }
        cout <<"\n";
    }
    return 0;
}

