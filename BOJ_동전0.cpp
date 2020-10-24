#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    int arr[10]={0,};
    int N,K;
    int cnt =0;
    cin >> N >> K;
    for(int i=0;i<N;i++)    cin >> arr[i];
    
    int idx = N-1;
    
    while(K>0){
        
        int num = arr[idx];
        int tmp = K/num;
        
        if(tmp != 0)   K=K%num;
        cnt+= tmp;
        idx--;
    }
    
    cout << cnt;
    return 0;
}

