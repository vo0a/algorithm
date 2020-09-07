## [programmers] 스택큐, 기능개발

[문제](https://programmers.co.kr/learn/courses/30/lessons/42586#)



```c++
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx = 0;
    while(idx < progresses.size()){
        if(progresses[idx] < 100){
            int diff = (100 - progresses[idx]) / speeds[idx];
            if((100 - progresses[idx]) % speeds[idx]) diff += 1;
            
            for(int i = idx; i< progresses.size(); i++){
                if(progresses[i] < 100)
                    progresses[i] += (diff * speeds[i]);
            }
        }
        int cnt = 0;
        for(int i = idx; i<progresses.size(); i++){
            if(progresses[i]>=100){
                cnt++; idx++;
            }else break;
        }
        answer.push_back(cnt);
    }
    return answer;
}
```





프로그래머스 고득점 키트 스택큐, 기능개발

