#include <iostream>
#define MAX 1000
using namespace std;

int main(void)
{
    int N;
    int arr[MAX]={0,};
    
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)    scanf("%d",&arr[i]);
    for(int i=N-1;i>=1;i--){
        for(int j=0;j<i;j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    
    for(int i=0;i<N;i++)    printf("%d\n",arr[i]);
    
    return 0;

}

