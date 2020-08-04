## [programmers] 이분탐색, 징검다리

[문제](https://programmers.co.kr/learn/courses/30/lessons/43236#)

```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int go(int left, int right, vector<int> rocks, int n) {
    if(left > right) return right;
    
	int mid = (left + right) / 2;
    int cnt = 0, pre = 0;
    for(int i = 0; i < rocks.size(); i++){
        if(cnt > n) break;
        if(rocks[i] - pre < mid) cnt++;
        else pre = rocks[i];
    }
    if(cnt <= n){
        return go(mid + 1, right, rocks, n);
    }
    else return go(left, mid - 1, rocks, n);
}

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;

	rocks.push_back(distance);
	sort(rocks.begin(), rocks.end());

	answer = go(0, distance, rocks, n);

	return answer;
}
```



```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int go(int distance, vector<int> rocks, int n){
    int ans = 0, left = 1, right = distance, mid = 0;
    
    while(left <= right){
        int cnt = 0, pre = 0;
        mid = (left + right) / 2;
        
        for(int i = 0; i < rocks.size(); i++){
            if(cnt > n) break;
            if(rocks[i] - pre < mid) cnt++;
            else pre = rocks[i];
        }
        
        if(cnt <= n){
            ans = mid > ans ? mid : ans;
            left = mid + 1;
        } 
        else right = mid - 1;
    }
    return ans;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    answer = go(distance, rocks, n);
    
    return answer;
}
```





프로그래머스 고득점 키트 이분탐색 징검다리

