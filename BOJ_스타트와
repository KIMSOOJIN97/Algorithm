#include <iostream>
#include <vector>

#define MAX 20

using namespace std;

int N;
int map [MAX][MAX]={0,};
int visited[20]={0,};
int MIN = 1e9;


void solve()
{
    int start=0;
    int link=0;
    
    vector <int> s;
    vector <int> l;

    for(int i=0;i<N;i++)
    {
        if(visited[i])  s.push_back(i);
        else    l.push_back(i);
    }
    
    for(int i=0;i<N/2;i++)
    {
        for(int j=0;j<N/2;j++){
            start += map[s[i]][s[j]];
            link += map[l[i]][l[j]];
        }
    }
    
    int res = start > link ? start-link : link - start;
    if( MIN > res)  MIN = res;
    
}

void DFS(int cnt,int idx)
{
    if(cnt == N/2)
    {
        solve();
        return;
    }
    
    for(int i=idx;i<N;i++){
        if(visited[i]==0)
        {
            visited[i]=1;
            DFS(cnt+1,i+1);
            visited[i]=0;
        }
    }
}
int main(void)
{
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            scanf("%d",&map[i][j]);
    }
    
    DFS(0,0);
    cout << MIN;
    return 0;
}

