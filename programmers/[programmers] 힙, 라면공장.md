## [programmers] 힙, 라면공장

[문제](https://programmers.co.kr/learn/courses/30/lessons/42629#)



```c++
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int> pq;
    int rest = stock;
    int idx = 0, date = 0;
    while(rest < k){
        stock--;
        date++;
        if(idx < dates.size() && date == dates[idx]){
            pq.push(supplies[idx++]);
        }
        if(stock == 0){
            rest += pq.top();
            stock = pq.top();
            pq.pop();
            answer++;
        }
    } 
    
    return answer;
}
```

>  현재 공장에 남아있는 밀가루 수량(stock)이 0될 때마다 지나왔던 날(dates)의 밀가루 수량(supplies)중 가장 큰 값을 더해주고, 더할 때마다 누적하여 버틸수 있는 날(rest)을 구한다. 
>
> 똑같이 rest가 k 이상이 될 때까지 반복한다.



프로그래머스 고득점 키트 힙 라면공장

