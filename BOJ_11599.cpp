#include <iostream>
#include <queue>

using namespace std;

struct pos{
    int x,y;
};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


/*
 뿌요를 놓고 난 후, 같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면 연결된 같은 색 뿌요들이 한꺼번에 없어진다.
 R은 빨강, G는 초록, B는 파랑, P는 보라, Y는 노랑이다.(모두 대문자로 주어진다.)
 1,2,3,4,5
 */

int map[12][6]={0,};

void solve()
{
    vector <int> v;

    for(int i=0;i<6;i++)
    {
        for(int j=11;j>=0;j--){
            if(map[j][i] != 0 ) v.push_back(map[j][i]);
            map[j][i]=0;
        }
        
        int idx = 11;
        for(int j=0;j<v.size();j++) map[idx--][i]=v[j];
        
        v.clear();
    }
}

bool BFS()
{
    bool check = false;
    vector <pos> v;

    int visited[12][6]={0,};
    queue <pos> q;
    int num =0;
    
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            
            if(map[i][j] != 0 && visited[i][j] == 0 ){
                num=1;
                q.push({i,j});
                visited[i][j]=1;
                v.push_back({i,j});
            }
            
            while(!q.empty()){
                
                int x = q.front().x;
                int y = q.front().y;
                q.pop();
                
                for(int k=0;k<4;k++){
                    
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    
                    if(nx < 0 || ny <0 || nx >= 12 || ny >= 6 || visited[nx][ny] != 0)  continue;
                    if(map[x][y] != map[nx][ny] )   continue;
                    q.push({nx,ny});
                    v.push_back({nx,ny});
                    visited[nx][ny] = 1;
                }
            }
            
            if(v.size() >=4){
                for(int k=0;k<v.size();k++)
                    map[v[k].x][v[k].y]=0;
                check=true;
            }
            v.clear();
        }
    }
    
    return check;
}

int main(void)
{
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            char ch1;
            cin >> ch1;
            if(ch1 == '.')  map[i][j] = 0;
            else if(ch1 == 'R')  map[i][j] = 1;
            else if(ch1 == 'G')  map[i][j] = 2;
            else if(ch1 == 'B')  map[i][j] = 3;
            else if(ch1 == 'P')  map[i][j] = 4;
            else if(ch1 == 'Y')  map[i][j] = 5;
        }
    }
    int cnt =0;
    
    while(1){
        if(!BFS())    break;
        solve();
        cnt++;
    }
    
    cout << cnt;
    return 0;
    
}

