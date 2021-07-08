## [programmers] 스택큐, 기능개발

[문제](https://programmers.co.kr/learn/courses/30/lessons/42586#)



### C++

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



### Java

```java
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> list = new ArrayList<>();
        int[] check = new int[progresses.length];
        for(int i = 0; i < progresses.length; i++){
            if(check[i] != 0) continue;

            check[i] = 1;
            int day = 0, count = 1;
            while (progresses[i] < 100){
                progresses[i] += speeds[i];
                day++;
            }

            for(int j = i + 1; j < progresses.length; j++){
                if(progresses[j] > 100) continue; // 더 이상 할 필요 없음
                progresses[j] += day * speeds[j];
            }
            for(int j = i + 1; j < progresses.length; j++){
                if(progresses[j] >= 100) {
                    check[j] = 1;
                    count++;
                }
                else break;
            }

            list.add(count);
        }

        int[] answer = list.stream().mapToInt(Integer::intValue).toArray();
        return answer;
    }
}
```





프로그래머스 고득점 키트 스택큐, 기능개발

