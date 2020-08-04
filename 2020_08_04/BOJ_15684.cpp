#include <iostream>

using namespace std;

int N,M,H;
int map[35][15]={0,};
int MIN = 4;

int solve()
{
    for(int i=1 ;i<=N;i++){
        
        int x=1;
        int y=i;
        
        while (x <= H ){
            
            if(map[x][y] == 1)  y +=1;
            else if (map[x][y-1] == 1)  y -= 1;
            x++;
        }
        
        if( i != y) return 0;
    }
    return 1;
}

void DFS(int cnt, int idx  )
{
    if( cnt > 3)    return;
    
    if(solve()){
        if(MIN > cnt )  MIN = cnt;
        return;
    }
    
    for(int i= idx;i<=H;i++){
        for(int j = 1; j < N;j++)
        {
            if(map[i][j] != 0 || map[i][j-1] != 0 || map[i][j+1] != 0)   continue;
            else{
                map[i][j]=1;
                DFS(cnt+1,i);
                map[i][j]=0;
            }
        }
    }
}
int main(void)
{
    cin >> N >> M >> H;
    
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        map[a][b]=1;
    }
    
    DFS(0,1);
    
    if(MIN == 4)    cout << "-1";
    else    cout << MIN;
    
    return 0;
}

