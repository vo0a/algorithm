## [programmers] DFS/BFS, 타겟 넘버

[문제](https://programmers.co.kr/learn/courses/30/lessons/43165)



```c++
#include <string>
#include <vector>
using namespace std;

int go(vector<int> numbers, int target, int idx, int sum){
    if(idx >= numbers.size()){
        if(sum == target){
            return 1;
        }
        else return 0;
    }
    int ret = 0;
    ret += go(numbers, target, idx+1, sum - numbers[idx]);
    ret += go(numbers, target, idx+1, sum + numbers[idx]);
    return ret;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int idx = 0, sum = 0;
    answer = go(numbers, target, idx, sum);
    
    return answer;
}
```





프로그래머스 고득점 키트 DFS/BFS 타겟 넘버

