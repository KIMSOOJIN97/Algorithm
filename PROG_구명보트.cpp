#include <string>
#include <vector>
#include <algorithm>
#define MAX 50000

using namespace std;

bool visited[MAX]={0,};

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    int num = people.size()-1;
    sort(people.begin(), people.end());
    
    int idx =0;
    for(int i=num ; i>=0;i--){
        
        if(visited[i] == 1) break;
        
        int total = people[idx]+people[i];
        
        if(total <= limit)
        {
            visited[idx]=1;
            idx++;
        }
        
        visited[i]=1;
        answer++;

    }
    return answer;
}
