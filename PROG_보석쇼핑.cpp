#include <string>
#include <vector>
#include <set>
#include <iostream>

#define MAX 100001

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> ruby_type;
    int size = gems.size();
    int start,end;
    
    for(int i=0;i<size;i++) ruby_type.insert(gems[i]);
    int type_num = ruby_type.size();

    int len = MAX;
    for(int i=0;i<=size - type_num; i++)
    {
        set <string> tmp;
        int idx = i;
        while(idx < size){
            tmp.insert(gems[idx]);
            if(tmp.size() == type_num ){
                int tmp_len = idx - i;
                if(len > tmp_len)
                {
                    len = tmp_len;
                    start=i;
                    end = idx;                    
                }
                break;
            }
            idx++;
        }
    }
    answer.push_back(start+1);
    answer.push_back(end+1);

    return answer;
}
