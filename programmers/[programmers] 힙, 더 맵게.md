## [programmers] 힙, 더 맵게

[문제](https://programmers.co.kr/learn/courses/30/lessons/42626#)



```c++
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i =0 ; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    while(pq.size() >= 2 && pq.top() < K){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int newScoville = first + second*2;
        pq.push(newScoville);
        
        if(second == 0) return -1;
        
        answer++;
    }
    
    return pq.top() >= K ? answer : -1;
}
```





프로그래머스 고득점 키트 힙 더 맵게

