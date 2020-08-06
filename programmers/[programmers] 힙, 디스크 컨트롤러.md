## [programmers] 힙, 디스크 컨트롤러

[문제](https://programmers.co.kr/learn/courses/30/lessons/42627)



```c++
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
 
using namespace std;
 
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};
 
int solution(vector<vector<int>> jobs) {
    int answer = 0, j = 0, time = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    while (j < jobs.size() || !pq.empty()) {
        if (jobs.size() > j && time >= jobs[j][0]) {
            pq.push(jobs[j++]);
            continue;
        }
        if (!pq.empty()) {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else
            time = jobs[j][0];
    }
    return answer / jobs.size();
}
```

- `pq.top()[1]` 이렇게 사용할 수 있다는 것을 배웠다.
- `continue` 를 위처럼 사용하면 while문의 장점을 극대화할 수 있는 것 같다.



프로그래머스 고득점 키트 힙 디스크 컨트롤러

