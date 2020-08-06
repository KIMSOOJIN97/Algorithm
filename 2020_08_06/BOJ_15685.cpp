#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

int dx[4] = { 0 ,-1 , 0 ,1};
int dy[4] = {1,0,-1,0};

int map[MAX][MAX] = {0,};

vector <int> dir;

int N=0;
int x ,y ,d ,g;

void solve()
{
    int S = dir.size();
    
    for(int i=S-1;i>=0;i--){
        int ndir = (dir[i]+1)%4;
        
        x = x + dx[ndir];
        y = y + dy[ndir];
        map[x][y]=1;
        dir.push_back(ndir);
        
    }
}

//드래곤 커브의 시작 점, d는 시작 방향, g는 세대이
//x, y, d, g

int main(void)
{
    cin >> N ;
    
    for(int i=0;i<N;i++)
    {
        dir.clear();
        
        cin >> y >> x >> d >> g ;
        
        map[x][y]= 1;
        
        x+= dx[d];
        y += dy[d];
                
        map[x][y] = 1;
        
        
        dir.push_back({d});

        for(int j=0;j<g;j++)
            solve();
                
    }
    
    int cnt =0 ;
    
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1] ) cnt++;
        }
    }
    
    cout << cnt;
    
    return 0;
}


