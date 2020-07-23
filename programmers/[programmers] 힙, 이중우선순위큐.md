## [programmers] 힙, 이중우선순위큐

[문제](https://programmers.co.kr/learn/courses/30/lessons/42628)



```c++
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    for(int i = 0; i<operations.size(); i++){
        string str = operations[i];
        if(str[0] == 'I'){
            // 숫자 삽입
            string sub = str.substr(2);
            int num = stoi(sub);
            dq.push_back(num);
            sort(dq.begin(), dq.end());
        }
        else if (!dq.size()) continue;
        else if( str[2] == '-'){
            // 최솟값 삭제
            dq.pop_front();
        }
        else{
            // 최댓값 삭제
            dq.pop_back();
        }
    }
    
    if(dq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    return answer;
}
```





프로그래머스 고득점 키트 힙 이중우선순위큐

