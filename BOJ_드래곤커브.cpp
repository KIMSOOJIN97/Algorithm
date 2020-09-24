#include <iostream>
#include <vector>

#define MAX 300

using namespace std;

int x,y,d,g;
int map[MAX][MAX]={0,};

int N;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};


void solve()
{
    vector <int> v;
    int cnt =0;
    
    for(int i=0;i<=g;i++){
        int idx = v.size();

        if(idx==0)   v.push_back(d);
        else{
            for(int j=idx-1;j>=0;j--){
                
                int dir = v[j];
                
                if(dir== 3) dir =0;
                else    dir++;
                
                v.push_back(dir);
            }
        }
    }
    
    for(int i=0;i<v.size();i++){
        
        int dir = v[i];
        map[x][y]=1;
        x += dx[dir];
        y += dy[dir];
        map[x][y]=1;
    }
}
int main(void)
{

    cin >> N;
    for(int i=0;i<N;i++){
        
        cin >> x >> y >> d >> g;
        solve();
    }
    int cnt =0;
    
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1])    cnt++;
        }
    }
    
    printf("%d\n",cnt);
    return 0;
}




