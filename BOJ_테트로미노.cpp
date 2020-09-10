#include <iostream>
#define MAX 500


using namespace std;

int N,M;

int map[MAX][MAX]={0,};
int visited[MAX][MAX]={0,};

int max_sum=0;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int max(int a , int b)
{
    if(a>b) return a;
    else    return b;
}

void solve(int x, int y)
{
    //ㅗ
    if(x-1 >= 0 && y-1 >= 0 && y+1 < M )    max_sum = max(max_sum, map[x][y-1]+ map[x][y] + map[x][y+1] + map[x-1][y] );
    //ㅏ
    if( x-1 >= 0 && x+1 < N && y+1 < M )    max_sum = max(max_sum, map[x-1][y] + map[x][y] + map[x+1][y] + map[x][y+1]);
    //ㅜ
    if( y-1 >= 0 && y+1 < M && x+1 < N)     max_sum = max(max_sum, map[x][y] + map[x][y-1] + map[x][y+1] + map[x+1][y]);
    //ㅓ
    if(y-1 >= 0 && x-1 >= 0 && x+1 < N)     max_sum = max(max_sum, map[x][y] + map[x][y-1] + map[x-1][y] + map[x+1][y]);
}

void DFS(int cnt, int sum,int x, int y)
{
    if(cnt == 3)    {
        if(max_sum < sum)   max_sum = sum;
        return;
    }
    
    for(int i=0;i<4;i++){
        
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx< 0 || ny <0 || nx >=N || ny >= M || visited[nx][ny])  continue;
        
        visited[nx][ny]=1;
        DFS(cnt+1,sum+map[nx][ny] , nx,ny);
        visited[nx][ny]=0;
    }
}

int main(void)
{
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)    cin >> map[i][j];
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            visited[i][j]=1;
            DFS(0,map[i][j],i,j);
            solve(i,j);
            visited[i][j]=0;
        }
    }
    cout << max_sum;
    return 0;
}

