#include <iostream>
#define MAX 101
using namespace std;

int map[MAX][MAX]={0,};
int visited[MAX]={0,};
int N,M;

void DFS(int start)
{
    visited[start]=1;
    for(int i=2;i<=N;i++){
        if(map[start][i]==1 && visited[i]==0)  DFS(i);
    }
}

int main(void)
{
    int ans=0;
    
    cin >> N >> M;
    
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        
        map[a][b]=1;
        map[b][a]=1;
        
    }
    
    DFS(1);
    for(int i=2;i<=N;i++){
        if(visited[i]==1)   ans++;
    }
    cout << ans;
    
    return 0;
    
}

