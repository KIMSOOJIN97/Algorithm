#include <iostream>
#include <algorithm>

#define MAX 100000

using namespace std;

int N,M;
int arr[MAX]={0,};
int target;

bool BSearch()
{
    int mid;
    int low =0;
    int high = N-1;
    
    while(low <= high)
    {
        mid = (low + high)/2;
        if(arr[mid] == target)  return true;
        else if(arr[mid] < target)  low = mid +1;
        else    high= mid-1;
    }
    return false;
}


int main(void)
{
    
    scanf("%d",&N);
    for(int i=0;i<N;i++)    scanf("%d",&arr[i]);

    sort(arr,arr+N);
    
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%d",&target);
    
        if(BSearch()) printf("1\n");
        else printf("0\n");

    }
    return 0;
}

