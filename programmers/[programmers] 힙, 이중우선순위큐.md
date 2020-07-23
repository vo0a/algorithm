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



### set - multiset 

```c++
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> arguments) {
    vector<int> answer;
    multiset<int> que;
    multiset<int>::iterator iter;
    string sub;

    for(auto s : arguments) {
        sub =s.substr(0, 2);
        if(sub=="I ") que.insert(stoi(s.substr(2,s.length()-2))); 
        else if(s.substr(2,1)=="1"&&que.size()>0) { que.erase(--que.end()); }
        else if(que.size()>0) { que.erase(que.begin()); }
    }

    if(que.size()==0) { answer.push_back(0); answer.push_back(0); }
    else { 
        iter = --que.end(); answer.push_back(*iter); 
        iter = que.begin(); answer.push_back(*iter);
    }

    return answer;
}
```

공부하기





프로그래머스 고득점 키트 힙 이중우선순위큐

