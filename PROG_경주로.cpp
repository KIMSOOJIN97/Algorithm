#include <string>
#include <vector>
#include <queue>

#define MAX 25

using namespace std;

int map[MAX][MAX]={0,};
bool visited[MAX][MAX][4] ={0,};

struct pos{
    int x,y,dir,cost;
};

int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

int solution(vector<vector<int>> board) {
    int answer = 1e9;
    int N = board.size();

    queue <pos> q;

    map[0][0]=-1;
    if(board[0][1]!=1)
    {
        map[0][1] = 100;
        q.push({0,1,0,100});
    }
    if(board[1][0]!=1)
    {
        map[1][0] = 100;
        q.push({1,0,1,100});
    }
    while(!q.empty())
    {
        int x= q.front().x;
        int y= q.front().y;
        int dir= q.front().dir;
        int cost = q.front().cost;
        q.pop();
        
        if(x==N-1 && y==N-1){
            if(cost  < answer) answer= cost;
            continue;
        }
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            int charge = cost;
            if(nx< 0 || ny < 0 || nx >= N || ny >= N|| board[nx][ny] ) continue;
            int ndir =i;
            
            charge += 100;
            if(ndir != dir) charge += 500;
            
            if(map[nx][ny] == 0 || map[nx][ny] >= charge ) {
                map[nx][ny] = charge;
                q.push({nx,ny,ndir,charge});
            }
        }
    }
    return answer;
}
