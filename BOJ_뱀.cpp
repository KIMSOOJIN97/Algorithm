#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

struct pos{
    int x,y;
};

pos head;
queue <pos> tail;
int dir;
int map[MAX][MAX]={0,};
int N;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool move()
{
    int nx = head.x+dx[dir];
    int ny = head.y+dy[dir];
    
    if(nx<0 || ny <0 || nx >= N || ny >= N || map[nx][ny] == -1)  return true;
    
    tail.push({nx,ny});
    head = {nx,ny};
    if(map[nx][ny] == 1)    map[nx][ny] = -1;
    else{
        map[nx][ny] = -1;
        int tx = tail.front().x;
        int ty = tail.front().y;
        map[tx][ty]=0;
        tail.pop();
    }
    return false;
}

int main(void)
{
    dir =1;
    head = {0,0};
    tail.push({0,0});
    map[0][0]=-1;
    
    int K;
    scanf("%d %d",&N,&K);
    
    for(int i=0;i<K;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        map[x-1][y-1]= 1;
    }
    
    vector <pair<int , char>> rotate;
    int L;
    scanf("%d",&L);
    for(int i=0;i<L;i++)
    {
        int s;
        char d;
        cin >>s >>d;
        rotate.push_back({s,d});
    }
    int cnt =0;
    int _time=0;
    while(1)
    {
        _time++;
        if(move())  break;
        if(cnt < L && _time == rotate[cnt].first)
        {
            if(rotate[cnt].second == 'L')
            {
                if(dir ==0) dir = 3;
                else dir--;
            }
            else
            {
                if(dir ==3) dir =0;
                else    dir++;
            }
            cnt++;
        }
    }
    cout << _time;
    return 0;
}

