#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO{
    int idx;
    int P;
};

struct POS{
    int x,y;
};


int dx[5]={0,-1,0,1,0};
int dy[5]={0,0,1,0,-1};

int movA[100]={0,};
int movB[100]={0,};

int M,BC;

vector <INFO> map[11][11];

POS A,B;

int x,y,C,P;
int MAX=0;

bool comp(int a, int b) {
    return a > b;
}


void charge()
{
        int AP, BP;
        
        if(map[A.x][A.y].size() ==0 )   AP=0;
        else    AP = map[A.x][A.y][0].P;
        
        if(map[B.x][B.y].size()==0)  BP=0;
        else    BP= map[B.x][B.y][0].P;
        
        if(AP==0 && BP ==0) return;
        
        if(AP && BP && (map[A.x][A.y][0].idx ==  map[B.x][B.y][0].idx))
        {
            int tmp1 =0;
            int tmp2 =0;
            
            if(map[A.x][A.y].size() > 1)    tmp1 =map[A.x][A.y][1].P;
            if(map[A.x][B.y].size() > 1)    tmp2 =map[B.x][B.y][1].P;
            
            int res =0;
            if(tmp1> tmp2 ) res = tmp1;
            else res = tmp2;
            
            MAX = MAX + res + AP ;
        }
        else    MAX = MAX+AP + BP;
}

void move()
{
    charge();
    
    for(int i=0;i<M;i++)
    {
        A.x += dx[movA[i]];
        A.y += dy[movA[i]];
        
        B.x += dx[movB[i]];
        B.y += dy[movB[i]];
        
        charge();
    }
    return ;
}
/*
 . 같은 위치에 2개 이상의 BC가 설치된 경우는 없다.
 */

void spread(int idx)
{
    map[x][y].push_back({idx,P});
    queue <POS> q;
    
    q.push({x,y});
    
    int visited[11][11]={0,};
    visited[x][y]=1;
    
    while(!q.empty()){
        
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        if(visited[x][y] == C+1)    continue;

        for(int i=1;i<5;i++){
            
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx < 1 || ny < 1 || nx > 10 || ny > 10 || visited[nx][ny])  continue;

            visited[nx][ny]=visited[x][y]+1;
            q.push({nx,ny});
            
            int size = map[nx][ny].size();
            INFO tmp ={idx,P};
          
            if(size != 0){
                
                if(size==2  && map[nx][ny][1].P < P)    map[nx][ny].pop_back();
                else if(size ==2 )  continue;
                
                map[nx][ny].push_back({idx,P});
           
                if(map[nx][ny][0].P < P ){
                    map[nx][ny][1] = map[nx][ny][0];
                    map[nx][ny][0] = tmp;
                }
            }
            else    map[nx][ny].push_back({idx,P});
        }
    }
    //cout << "HERE"
}

void init()
{
    MAX =0;
    A={1,1};
    B={10,10};
    
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++)  map[i][j].clear();
    }
}

int main(void)
{
    int T;
    cin >>T;
    
    for(int k=0;k<T;k++){
        
        init();
        cin >> M >> BC;
        for(int i=0;i<M;i++)    cin >> movA[i];
        for(int i=0;i<M;i++)    cin >> movB[i];
        
        for(int i=0;i<BC;i++){
            cin >> y >> x >> C >> P;
            spread(i);
        }
        
        move();

        cout << "#" << k+1 << " " << MAX ;
    }
    return 0;
}

