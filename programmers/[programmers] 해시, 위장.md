## [programmers] 해시, 위장

[문제](https://programmers.co.kr/learn/courses/30/lessons/42578)



```c++
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> m;
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(int i = 0; i < clothes.size(); i++){
        m[clothes[i][1]]++;
    }
    
    for(auto e: m){
        answer *= (e.second + 1);
    }
    
    return answer - 1;
}
```

>  경우의 수를 세는데 헷갈렸는데
>  `종류별 의상 개수 + 1`을 모두 곱해준 뒤 -1을 해주면 된다.
>
> 그 이유는
>
> - 종류별로 입지 않는 경우도 있으니 +1을 해준 상태로 곱해야 하고,
>
> - 그렇게 종류별로 의상 개수를 곱하고나면, answer에는 마지막에 아무것도 입지 않는 경우가 있기 때문에 아무것도 입지 않는 경우를 제외하기 위해서 -1을 해줘야 한다.



프로그래머스 고득점 키트 해시 위장

