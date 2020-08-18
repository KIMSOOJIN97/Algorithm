#include <iostream>
#define MAX 21
using namespace std;


int N;
int map[MAX][MAX]={0,};

int x,y;
int d1,d2;

int MIN = 987654321;

void separate()
{
    if(x + d1 + d2 > N )  return;
    if( y-d1 < 1) return;
    if( y+d2 > N) return;
    
    int area[MAX][MAX]={0,};
    
    for(int i=0;i<=d1;i++){
        area[x+i][y-i]=5;
        area[x+d2+i][y+d2-i]=5;
    }
    for(int i=0;i<=d2;i++){
        area[x+i][y+i]=5;
        area[x+d1+i][y-d1+i]=5;
    }
    
    
    for(int i=1;i<x+d1;i++){
        for(int j=1;j<=y;j++){
            if(area[i][j]==5)   break;
            area[i][j]=1;
        }
    }
    
    for(int i=1;i<=x+d2;i++){
        for(int j=N;j>y;j--){
            if(area[i][j]==5)   break;
            area[i][j]=2;
        }
    }
    
    for(int i = x+d1 ; i<= N ; i++){
        for(int j=1;j<y-d1+d2;j++){
            if(area[i][j]==5)   break;
            area[i][j]=3;
        }
    }
    for(int i = x+d2+1 ; i<= N ; i++){
        for(int j=N;j>=y-d1+d2;j--){
            if(area[i][j]==5)   break;
            area[i][j]=4;
        }
    }
    for(int i=x;i<=x+d1+d2;i++){
        for(int j=0;j<=N;j++){
            if(area[i][j]==0)   area[i][j]=5;
        }
    }

    int people[5]={0,};
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(area[i][j]==1)   people[0] += map[i][j];
            else if(area[i][j]==2)   people[1] += map[i][j];
            else if(area[i][j]==3)   people[2] += map[i][j];
            else if(area[i][j]==4)   people[3] += map[i][j];
            else if(area[i][j]==5)   people[4] += map[i][j];

        }
    }
    int min = people[0];
    int max = people[0];
    
    for(int i=1;i<5;i++){
        if(min > people[i]) min=people[i];
        if(max < people[i]) max = people[i];
    }
    
    if( MIN > max - min)    MIN=max-min;
}

int main(void)
{
    cin >> N ;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            cin >> map[i][j];
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                for(int l=1;l<=N;l++){
                    
                    x = i;
                    y = j;
                    d1 = k;
                    d2 = l;

                    separate();
                }
            }
        }
    }
    cout << MIN;
    return 0;
}

