#include <iostream>
#include <queue>
#include <vector>

#define MAX 50

using namespace std;


int N,L,R;
int map[MAX][MAX]={0,};
int sum=0;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct pos{
    int x,y;
};
vector <pos> v;

void solve()
{
    int _size = v.size();
    int avg = sum/_size;
    
    for(int i=0;i<v.size();i++){
        int x = v[i].x;
        int y = v[i].y;
        map[x][y]= avg;
    }
}

int main(void)
{
    cin >> N>>L>>R;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)    cin >> map[i][j];
    }
    int cnt =0;
    queue <pos> q;
    
    
    while(1){
        
        bool flag = false;
        int visited[MAX][MAX]={0,};

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                    
                if(visited[i][j]==0){
                    q.push({i,j});
                    v.push_back({i,j});
                    visited[i][j]=1;
                    sum += map[i][j];
                }
                
                while(!q.empty()){
                    
                    int x = q.front().x;
                    int y = q.front().y;
                    
                    q.pop();
                                        
                    for(int k=0;k<4;k++){
                        
                        int nx =x+dx[k];
                        int ny =y+dy[k];
                        
                        if(nx < 0 || ny <0 || nx >= N || ny >= N || visited[nx][ny])   continue;
                        int comp= map[x][y] > map[nx][ny] ? map[x][y] - map[nx][ny] : map[nx][ny]-map[x][y];
                        
                        if(L <= comp && comp <= R){
                            q.push({nx,ny});
                            v.push_back({nx,ny});
                            visited[nx][ny]=1;
                            sum += map[nx][ny];
                        }
                    }
                }
                
                if(v.size() > 1){
                    solve();
                    flag = true;
                }
                v.clear();
                sum=0;
                
            }
        }
        if(!flag )  break;
        else    cnt++;

    }
    printf("%d",cnt);
    return 0;
    
}

