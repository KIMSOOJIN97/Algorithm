#include <iostream>
#include <vector>
#include <cmath>

#define MAX 50

using namespace std;

int R,C,T;
int map[MAX][MAX]={0,};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int air_x;

void spread()
{
    int tmp[MAX][MAX]={0,};
    
    for(int i=0;i<R;i++){
        for(int j=0; j<C ; j++){
            if(map[i][j] == 0 || map[i][j] == -1 ) continue;

            int cnt =0;
            int num =  trunc(map[i][j]/5);
            vector <pair<int , int >> v;
            
            
            for(int k=0;k<4;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if(nx < 0 || ny <0 || nx >= R || ny >= C )  continue;
                if(map[nx][ny] == -1)   continue;
                cnt++;
                tmp[nx][ny] += num;
            }
            
            map[i][j] = map[i][j] - num*cnt;
        }
    }
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            map[i][j] += tmp[i][j];
        }
    }
}

void air_cleaner_up()
{
    int x1 = air_x-1;
    
    int tmp1 = map[x1][C-1];
    int tmp2 = map[0][C-1];
    int tmp3 = map[0][0];
    
    for(int i = C-1 ; i > 1 ; i--)
        map[x1][i] = map[x1][i-1];
    
    for(int i = 0; i< x1-1; i++ )
        map[i][C-1] = map[i+1][C-1];
    
    for(int i = 0 ; i<= C-3 ; i++ )
        map[0][i] = map[0][i+1];
    
    for(int i = x1 -1 ; i > 1 ; i--)
        map[i][0] = map[i-1][0];
    
    map[x1-1][C-1] = tmp1;
    map[0][C-2] = tmp2;
    map[1][0] = tmp3;
    
}
void air_cleaner_down()
{
    int x2 = air_x;
    
    int tmp1 = map[x2][C-1];
    int tmp2 = map[R-1][C-1];
    int tmp3 = map[R-1][0];

    for(int i=C-1; i > 1 ; i--)
        map[x2][i] = map [x2][i-1];
    for(int i = R-1 ; i > x2+1 ; i--)
        map[i][C-1] = map[i-1][C-1];
    for(int i=0;i< C-2 ; i++)
        map[R-1][i] = map[R-1][i+1];
    for(int i=x2+1;i<R-2;i++)
        map[i][0] = map[i+1][0];
    
    map[x2+1][C-1] = tmp1;
    map[R-1][C-2] = tmp2;
    map[R-2][0] = tmp3;
    
}

int main(void)
{
    cin >> R >> C >> T;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> map[i][j];
            if(map[i][j] == -1)
                air_x = i;
        }
    }
    
    
    for(int k=0;k<T;k++){
        spread();
        air_cleaner_up();
        air_cleaner_down();
        map[air_x][1] =0;
        map[air_x-1][1] =0;
/*
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cout << map[i][j] << " ";
                
            }
            cout << endl;
        }
        cout << endl ;*/
    }
    
    int sum=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j] != -1)
                sum += map[i][j];
        }

    }
   
    cout << sum ;
    return 0;
    
}

