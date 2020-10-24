#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool sortsec(pair<int,int> a,pair<int,int> b)
{
    return a.second < b.second;
}

int main(void)
{
    int N;
    cin >> N;
    
    vector <pair<int,int>> v;
    
    for(int i=0;i<N;i++){
        int s,e;
        cin >> s >> e;
        v.push_back({s,e});
    }
    
    sort(v.begin(), v.end());
    sort(v.begin(), v.end(), sortsec);

    int cnt =1;
    int num = v[0].second;
    
    for(int i=1;i<N;i++){
        
        if(num <= v[i].first){
            cnt++;
            num = v[i].second;
        }
    }
    cout << cnt;
    return 0;
}

