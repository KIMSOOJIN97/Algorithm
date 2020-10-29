#include <iostream>
#define _max(a,b) ((a) > (b) ? (a) : (b))
#define _min(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int N;
int map[3];
int DP[2][3]={0,};
int DP_min[2][3]={0,};

int main(void)
{
    scanf("%d",&N);
    
    for(int i=1;i<=N;i++)
    {
        scanf("%d %d %d",&map[0],&map[1],&map[2]);

        DP[1][0]=map[0] + _max(DP[0][0],DP[0][1]);
        DP[1][1]=map[1] + _max(DP[0][0],_max(DP[0][1],DP[0][2]));
        DP[1][2]=map[2] + _max(DP[0][1],DP[0][2]);
        
        DP[0][0]= DP[1][0];
        DP[0][1]= DP[1][1];
        DP[0][2]= DP[1][2];

        DP_min[1][0]=map[0] + _min(DP_min[0][0],DP_min[0][1]);
        DP_min[1][1]=map[1] + _min(DP_min[0][0],_min(DP_min[0][1],DP_min[0][2]));
        DP_min[1][2]=map[2] + _min(DP_min[0][1],DP_min[0][2]);

        DP_min[0][0]= DP_min[1][0];
        DP_min[0][1]= DP_min[1][1];
        DP_min[0][2]= DP_min[1][2];
    }
    
    cout << _max(DP[1][0],_max(DP[1][1],DP[1][2])) << " "<<_min(DP_min[1][0],_min(DP_min[1][1],DP_min[1][2]));
    
    return 0;
    
}

