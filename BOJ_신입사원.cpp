#include <iostream>
#include <algorithm>
#include <vector>

#define MAX  100000

using namespace std;

int main(void)
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T,N;
    
    cin >> T ;
    
    for(int i=0;i<T;i++){
        
        int res =1;
        
        vector <pair<int,int>> v;
        
        cin >> N;
        
        for(int j=0;j<N;j++){
            
            int a,b;
            cin >> a >> b;
            v.push_back({a,b});
        }
        
        sort(v.begin(),v.end());
        int tmp = v[0].second;
        
        for(int k=1;k<N;k++){
            if(v[k].second < tmp )  res++;
            if(tmp > v[k].second)   tmp = v[k].second;
        }
        cout << res <<"\n";
    }
    return 0;
}

