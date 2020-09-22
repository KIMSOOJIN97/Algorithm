#include <iostream>
#define MAX 4001

using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]= {1,-1,0,0};
int num=0;

struct ATOM{
    int x,y,dir,energy;
    bool die;
};

ATOM atom[1000];
int total=0;

int map[MAX][MAX];


bool solve(void)
{
  
    for(int i=0;i<num;i++){
        int x= atom[i].x;
        int y = atom[i].y;
        map[x][y]=0;
    }

    for(int i=0;i<num;i++){
        if(atom[i].die == true) continue;
        
        int dir = atom[i].dir;
        
        atom[i].x += dx[dir];
        atom[i].y += dy[dir];
        
        if(atom[i].x < 0 || atom[i].y < 0 || atom[i].x > 4000 || atom[i].y > 4000){
            atom[i].die= true;
        }
        else{
            map[atom[i].x][atom[i].y ]+= atom[i].energy;
        }
    }
    int cnt =0;
    
    for(int i=0;i<num;i++){
        
        if(atom[i].die == true){
            cnt ++;
            continue;
        }
        
        int x = atom[i].x;
        int y = atom[i].y;
        
        if(map[x][y] != atom[i].energy) {
            total += atom[i].energy;
            atom[i].die = true;
        }
    }
    if(cnt == num)  return false;
    else    return true;
    
}
int main(void)
{
    int T;
    scanf("%d",&T);
    
    for(int k=0;k<T;k++){
        scanf("%d",&num);
        total=0;
        
        for(int i=0;i<num;i++){
            
            int x,y,dir,energy;
            scanf("%d %d %d %d",&x , &y, &dir, &energy);
            x+=1000;
            y+=1000;
            x*=2;
            y*=2;
            atom[i]={x,y,dir,energy,false};

        }
        
        for(int i=0;i<4000;i++){
            bool res =solve();
            if(res == false)    break;
        }
        printf("#%d %d\n",k+1,total);
        
        
    }
    return 0;
}

