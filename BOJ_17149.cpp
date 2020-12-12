#include <iostream>
#include <algorithm>
#define MAX 501

using namespace std;

int W,H;
int block[MAX]={0,};


int main(void)
{
    int total=0;
    
    cin >> H >> W;
    for(int i=0;i<W;i++)    cin >> block[i];
    
    for(int i=1;i<W-1;i++){
        
        int right=0;
        int left=0;
        
        for(int j=0;j<i;j++)    left = max(left, block[j]);
        for(int j=W-1; j>i;j--) right =max(right, block[j]);
        
        total += max( 0 , min(left,right)-block[i]);
    }
   
    cout << total;
    return 0;
}

