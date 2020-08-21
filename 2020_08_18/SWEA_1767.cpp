#include <iostream>
#include <vector>

#define MAX 12

using namespace std;

struct pos{
    int x,y;
};

int T,N;

int core_num=0;
int min_len =1e9;

int map[MAX][MAX]={0,};

int dx[4] ={-1,0,1,0};
int dy[4] = {0,1,0,-1};

vector <pos> core;

bool fill_line(int x, int y , int d)
{
    int nx = x + dx[d];
    int ny = y + dy[d];

    while (nx < N && nx >= 0 && ny < N && ny >= 0){
        if(map[nx][ny] > 0 )    return false;
        nx += dx[d];
        ny += dy[d];
    }
    
    nx = x+dx[d], ny = y+dy[d];
    
    while (nx < N && nx >= 0 && ny < N && ny >= 0){
        map[nx][ny]=1;
        nx += dx[d];
        ny += dy[d];
    }
    return true;
}

void restore_line(int x, int y , int d)
{
    int nx = x+dx[d];
    int ny = y+dy[d];
    
    while (nx < N && nx >= 0 && ny < N && ny >= 0){
        map[nx][ny]=0;
        nx += dx[d];
        ny += dy[d];
    }
}

int filled_line(int x ,int y , int d)
{
    if(d==0)    return x;
    else if(d==1)   return N-1-y;
    else if(d==2)   return N-1-x;
    else    return y;
}


void DFS(int cnt, int connect, int sum)
{
    if( cnt >= core.size())
    {
        if(core_num < connect) {
            min_len = sum;
            core_num = connect;
        }
        else if(core_num == connect){
            if( min_len > sum)  min_len = sum;
        }
        return;
    }
        
    int x= core[cnt].x;
    int y= core[cnt].y;
    
    int flag=0;
    
    if(x==0 || y== 0 || x == N-1 || y ==N-1)    flag=1;
    
    if(flag)    DFS(cnt+1,connect+1,sum);
    else{
        for(int i=0;i<4;i++){

            if(fill_line(x,y,i)){
                DFS(cnt+1, connect+1, filled_line(x,y,i)+sum);
                restore_line(x,y,i);
            }
            else    DFS(cnt+1, connect, sum);
        }
    }
    return ;
}

int main(void)
{
    cin >> T ;
    for(int k=0;k<T;k++){
        cin >> N;
        core.clear();

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> map[i][j];
                if(map[i][j]==1)    core.push_back({i,j});
            }
        }

        core_num=0;
        min_len = 1e9;
        
        DFS(0,0,0);
        
        cout << "#" << k+1 << " " << min_len << "\n";
    }
    
    return 0;
}

