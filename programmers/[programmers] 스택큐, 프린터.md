## [programmers] 스택큐, 프린터

[문제](https://programmers.co.kr/learn/courses/30/lessons/42587)



```c++
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;
queue<p> q;
priority_queue<int> pq;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i =0; i<priorities.size(); i++){
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    while(1){
        if(q.front().first == pq.top()){
            answer++;
            if(q.front().second == location){
                break;
            }
            q.pop();
            pq.pop();            
        }else{
            p front = q.front();
            q.pop();
            q.push({front.first, front.second});
        }
    }
    
    return answer;
}
```





프로그래머스 고득점 키트 스택큐 프린터

