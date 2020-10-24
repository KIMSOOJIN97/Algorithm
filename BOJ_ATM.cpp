#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int N;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector <int> v;

    
    cin >>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(),v.end());
    
    int res =0;
    for(int i=0;i<N;i++)    res +=  v[i] * (N-i);
    cout<< res;
    return 0;
}

