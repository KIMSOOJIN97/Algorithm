#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    
    int pos = routes[0][1];
    
    for(int i=1;i<routes.size();i++){
        if(routes[i][1] < pos)  pos = routes[i][1];
        else if(routes[i][0] > pos){
            answer++;
            pos = routes[i][0];
        }
    }
    return answer;
}

