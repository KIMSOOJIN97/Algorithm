#include <string>

#define MAX 11

using namespace std;

int solution(string dirs) {
    
    int answer = 0;
    int visited[MAX][MAX][4]={0,};
    
    int x=5;
    int y=5;

    int _size = dirs.size();
    
    for(int i=0;i<_size;i++)
    {
        int dir=0;
        int nx=x;
        int ny=y;
        
        switch(dirs[i])
        {
            case 'U':
                ny +=1;
                dir =0;
                break;
            case 'D':
                ny -=1;
                dir=1;
                break;
            case 'R':
                nx +=1;
                dir=2;
                break;
            case 'L':
                nx -=1;
                dir=3;
                break;
        }
        if(nx<0 || ny<0 || nx >10 || ny>10) continue;
        if(visited[x][y][dir]==0){
            answer+=1;
            visited[x][y][dir] =1;
            if(dir==0)  dir=1;
            else if (dir==1)    dir=0;
            else if(dir==2) dir=3;
            else if(dir==3) dir=2;
            visited[nx][ny][dir]=1;
        }
        x=nx;
        y=ny;
    }
    return answer;
}

