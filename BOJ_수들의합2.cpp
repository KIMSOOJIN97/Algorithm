#include <iostream>
#define MAX 10000

using namespace std;

int main(void)
{
    int N,M;
    int arr[MAX]={0,};
    
    cin >> N >> M;
    for(int i=0;i<N;i++)    cin >> arr[i];
    
    int start =0;
    int end= 0;
    int total =arr[end];
    
    int res=0;
    
    while(end < N){
        if(total >= M){
            if(total == M)  res++;
            total -= arr[start];
            if(start == end ){
                end++;
                total+=arr[end];
            }
            start++;

        }
        else{
            end++;
            total+=arr[end];
        }
    }
    cout << res;
    return 0;
    
}

