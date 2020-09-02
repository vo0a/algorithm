## [programmers] 탐욕법, 단속카메라

[문제](https://programmers.co.kr/learn/courses/30/lessons/42884)



```c++
#include <vector>
#include <algorithm>
using namespace std;
 
int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());
    
    int end = -30001;
    for (auto a : routes) {
        if (end < a[0]) {
            answer++;
            end = a[1];
        }
        if (end > a[1]) end = a[1];
    }
    return answer;
}
```





프로그래머스 고득점 키트 탐욕법 단속카메라

