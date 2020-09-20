#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    int size = prices.size();

    for(int i=0;i<size ; i++)
    {
        int idx = i;
        int time=0;
        for(int j= idx+1 ;j<size ;j++ ){
            time+=1;
            if(prices[j] < prices[i])   break;
        }
        answer.push_back(time);
    }
    return answer;
}

