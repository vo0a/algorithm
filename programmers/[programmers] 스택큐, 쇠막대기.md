## [programmers] 스택큐, 쇠막대기

[문제](https://programmers.co.kr/learn/courses/30/lessons/42585)



```c++
#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0, cnt = 0;
    for(int i = 0; i<arrangement.size(); i++){
        if(arrangement[i] == '('){
            cnt++;
        }else{
            if(arrangement[i-1] == '('){ // 레이저
                cnt--;
                answer += cnt;
            }
            else {
                cnt--;
                answer++;
            }
        }
    }
    
    return answer;
}
```





프로그래머스 고득점 키트 스택큐 쇠막대기

