#include <string>
#include <vector>

using namespace std;


// 벽 부분을 1, 공백 부분을 0으로 부호화 했을 때 얻어지는 이진수
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

    vector <string> answer;
    
        for(int i=0;i<n;i++)
        {
            string num ="";
            for(int j=n-1;j>=0;j--){
                if(arr1[i] & (1<<j) || arr2[i] & ( 1<<j))   num +="#";
                else    num += " ";
            }
            answer.push_back(num);
        }
        return answer;

    }
