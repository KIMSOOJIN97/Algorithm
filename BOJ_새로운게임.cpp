#include <iostream>
#include <vector>

#define MAX 12

using namespace std;

int N,K;
int color[MAX][MAX]={0,};
vector<int> map[MAX][MAX];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

struct HORSE{
    int x,y,dir;
};
HORSE horse[10];

bool move(int col , int idx)
{
    int x = horse[idx].x;
    int y = horse[idx].y;
    int dir = horse[idx].dir;
    
    int nx = x+dx[dir];
    int ny = y+dy[dir];
    
    
    vector<int> v;
    int _size = map[x][y].size();
    
    while(1)
    {
        int num = map[x][y][_size-1];
        _size--;
        map[x][y].pop_back();
        v.push_back(num);
        if(num==idx)    break;
    }
    if(col ==0){
        for(int i=v.size()-1;i>=0;i--)
        {
            int num = v[i];
            map[nx][ny].push_back(num);
            horse[num].x= nx;
            horse[num].y = ny;
        }
    }
    else {

        for(int i=0;i<v.size();i++)
        {
            int num = v[i];
            map[nx][ny].push_back(num);
            horse[num].x= nx;
            horse[num].y = ny;
        }
    }
    
    if(map[nx][ny].size() >= 4) return false;
    return true;
}


bool blue(int idx)
{
    bool res = true;
    
    int x = horse[idx].x;
    int y = horse[idx].y;
    int dir = horse[idx].dir;
    
    int nx = x+dx[dir];
    int ny = y+dy[dir];

    if(nx< 0 ||  ny < 0  || nx >= N || ny >= N || color[nx][ny]==2)   return true;
    else if(color[nx][ny]==0)  res = move(0,idx);
    else if(color[nx][ny]==1) res = move(1,idx);
    
    return res;
    
}

bool solve()
{
    
    for(int i=0;i<K;i++){
        bool res=true;
        int x = horse[i].x;
        int y = horse[i].y;
        int dir = horse[i].dir;
        
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        
        if(nx< 0 ||  ny < 0  || nx >= N || ny >= N || color[nx][ny]==2){
            
            if(dir ==0) horse[i].dir=1;
            else if(dir ==1) horse[i].dir=0;
            else if(dir ==2) horse[i].dir=3;
            else if(dir ==3) horse[i].dir=2;
            res = blue(i);
        }
        else if(color[nx][ny]==0)  res = move(0,i);
        else if(color[nx][ny]==1) res = move(1,i);
        
        if(res==false)  return false;
    }
    return true;
}
    
int main(void)
{
    scanf("%d %d",&N,&K);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&color[i][j]);
        }
    }
    
    for(int i=0;i<K;i++){
        int x,y,dir;
        scanf("%d %d %d",&x,&y,&dir);
        horse[i] = {x-1,y-1,dir-1};
        map[x-1][y-1].push_back(i);
    }
    
    int turn=0;
    
    while(1){
        turn++;
        if(!solve())    break;
        else if(turn > 1000){
            printf("-1");
            return 0;
        }
    }
    printf("%d",turn);

    return 0;
    
}

