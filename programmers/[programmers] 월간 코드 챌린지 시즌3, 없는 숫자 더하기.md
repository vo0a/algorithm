## [programmers] 월간 코드 챌린지 시즌3, 없는 숫자 더하기

[문제](https://programmers.co.kr/learn/courses/30/lessons/86051)



```c++
#include <string>
#include <vector>
using namespace std;
vector<int> arr(10);

int solution(vector<int> numbers) {
    int answer = 0;
    for(auto num : numbers) {
        arr[num] = 1;
    }
    
    for(int i = 0 ; i <= 9; i++ ) {
        if(arr[i] == 0) answer += i;
    }
    
    return answer;
}
```



프로그래머스 월간 코드 챌린지 시즌3, 없는 숫자 더하기

