#include <iostream>
#include <vector>

#define MAX 300001

using namespace std;

int D,N;
int depth[MAX]={0,};
int pizza[MAX]={0,};

int main(void)
{
    cin >> D >> N;
    for(int i=0;i<D;i++){
        cin >> depth[i];
        if( i>0 &&  depth[i-1] < depth[i])   depth[i] = depth[i-1];
    }
    
    for(int i=0;i<N;i++)    cin >> pizza[i];
    
    int idx = 0;
    for(int i=D-1 ; i>=0; i--){
        if(depth[i] >= pizza[idx])  idx++;
        if(idx==N){
            cout << i+1;
            break;
        }
        if(i==0){
            cout <<"0";
            break;
        }
    }
    return 0;
    
}

