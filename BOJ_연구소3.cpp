#include <iostream>
#include <vector>
#include <queue>

#define MAX 50

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int visited[10] ={0,};

int map[MAX][MAX]={0,};
int tm[MAX][MAX];

int N,M;
int empty=0;
int min_time=2501;

vector <pair<int,int>> v;
queue <pair<int,int>> q;

void BFS()
{
    int min=0;
    int total=0;
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if( nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(map[nx][ny] != 1 && tm[nx][ny] ==-1)
            {
                tm[nx][ny] = tm[x][y]+1;
                
                if(map[nx][ny] == 0 ){
                    total++;
                    min = tm[nx][ny];
                }
                q.push(make_pair(nx,ny));
                
            }
        }
    }
    
    if(empty == total){
        if(min < min_time)  min_time = min;
    }
}
void DFS(int cnt, int idx)
{
    if(cnt == M)
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                tm[i][j] =-1;
            }
        }
        
        for(int i=0;i<v.size() ; i++){
            
            if(visited[i] ==1 ){
                q.push(make_pair(v[i].first,v[i].second));
                tm[v[i].first][v[i].second] = 0;
            }
        }
        BFS();
        return ;
    }
    
    for(int i=idx; i<v.size(); i++)
    {
        visited[i] = 1;
        DFS(cnt+1,i+1);
        visited[i]=0;
        
    }
}
int main(void)
{
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            if(map[i][j]==2)    v.push_back(make_pair(i,j));
            else if(map[i][j] == 0) empty++;
            
        }
    }
    
    
    DFS(0,0);
    
    if(min_time == 2501)    cout << "-1";
    else    cout << min_time;
    
    return 0;
    
}

