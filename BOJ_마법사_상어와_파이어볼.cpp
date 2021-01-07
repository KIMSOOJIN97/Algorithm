#include <iostream>
#include <vector>

#define MAX 51

using namespace std;

struct FIRE{
    int x,y;
    int m,s,d;
};

int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

int N,M,K;
vector <int> map[MAX][MAX];
vector <FIRE> fire;

void solve()
{
    vector <FIRE> tmp;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int num = map[i][j].size();

            if(num >= 2){
                int m=0,s=0,d=0;
                bool odd = false;
                bool even = false;
                for(int k=0;k<num;k++){
                    int idx = map[i][j][k];
                    m += fire[idx].m;
                    s += fire[idx].s;
                    if(fire[idx].d%2 == 0)  even=true;
                    else    odd= true;
                }
                m = m/5;
                s = s/num;
                
                if(m!=0){
                    if(odd && even)  d=1;
                    else    d=0;
                    
                    for(int k=0;k<4;k++){
                        tmp.push_back({i,j,m,s,d});
                        d+=2;
                    }
                }
            }
            else if(num==1)    {
                int idx = map[i][j][0];
                tmp.push_back(fire[idx]);
            }
            map[i][j].clear();
        }
    }
    fire.clear();
    fire = tmp;
}

void move()
{
    for(int i=0;i<fire.size();i++){
                
        int x= fire[i].x;
        int y= fire[i].y;
        int s= fire[i].s;
        int d= fire[i].d;
        
        s = s%N;
        x = x+dx[d]*s;
        y = y+dy[d]*s;
        
        if(x < 0)   x+=N;
        if(x >= N) x -=N;
        
        if(y < 0)   y+=N;
        if(y >= N) y-= N;
        
        fire[i].x = x;
        fire[i].y = y;
        map[x][y].push_back(i);
    }
}

int main(void)
{
    cin >> N >> M >> K;
    
    for(int i=0;i<M;i++){
        int x,y,m,s,d;
        cin >> x >> y >> m >> s >> d;
        fire.push_back({x,y,m,s,d});
    }
    
    for(int i=0;i<K;i++){
        move();
        solve();
    }
    
    int ans=0;
    for(int i=0;i<fire.size();i++)  ans += fire[i].m;
    
    cout << ans;
    return 0;
}

