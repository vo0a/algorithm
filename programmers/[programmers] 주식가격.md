## [programmers] 주식가격

[문제](https://programmers.co.kr/learn/courses/30/lessons/42584?language=cpp)



```c++
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i = 0; i<prices.size(); i++){
        int p = prices[i], cnt = 0;
        for(int j = i+1; j<prices.size(); j++){
            cnt++;
            if(p > prices[j]) break;
        }
        answer.push_back(cnt);
    }
    return answer;
}
```





프로그래머스 고득점 키트 스택/큐 주식가격

