#include <iostream>
#include <algorithm>
#define MAX 501

using namespace std;

int DP[MAX][MAX]={0,};
int map[MAX][MAX]={0,};
int dx[4] ={-1,1,0,0};
int dy[4] ={0,0,-1,1};
int res=0;
int N;


int DFS(int x, int y)
{
    if(DP[x][y])   return DP[x][y];
    DP[x][y] =1;
    
    for(int i=0;i<4;i++){
        
        int nx= x+dx[i];
        int ny= y+dy[i];
        
        if(nx < 0 || ny <0 || nx >= N || ny >= N)   continue;
        if(map[nx][ny] <= map[x][y])    continue;
        
        DP[x][y] = max(DP[x][y] , DFS(nx,ny)+1);
        

    }
    return DP[x][y];
}


int main(void)
{
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            res = max(res , DFS(i,j));
        }
    }
    cout << res;
    
    return 0;
    
}

