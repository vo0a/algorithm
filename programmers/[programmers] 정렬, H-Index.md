## [programmers] 정렬, H-Index

[문제](https://programmers.co.kr/learn/courses/30/lessons/42747)

```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// h 번 이상 인용된 논문이 h 편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값 = H-Index
// h 는 0 ~ citations.size() 사이
int ans;
void go(int l, int r, vector<int> arr){
    if (l > r) return;
    int cnt = 0;
    int mid = (l+r) / 2;
    for(int i = arr.size() - 1; i >= 0; i--){
        if( arr[i] >= mid ) cnt++;
        else break;
    }
    
    if(cnt >= mid){
        ans = max(ans, mid);
        go(mid+1, r, arr);
    }
    else{
        go(l, mid-1, arr);
    }
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    go(0, citations.size(), citations);
    answer = ans;
    return answer;
}
```





프로그래머스 고득점 키트 정렬 H-Index

