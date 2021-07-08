## [programmers] 스택큐, 주식가격

[문제](https://programmers.co.kr/learn/courses/30/lessons/42584?language=cpp)



### C++

```c++
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i = 0; i<prices.size(); i++){
        int p = prices[i], cnt = 0;
        for(int j = i+1; j<prices.size(); j++){
            cnt++;
            if(p > prices[j]) break;
        }
        answer.push_back(cnt);
    }
    return answer;
}
```



### Java

```java
package Programmers;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class 주식가격 {

    public static int[] solution(int[] prices) {
        List<Integer> result = new ArrayList<>();
        for(int i = 0; i < prices.length; i++){
            int count = 0;
            for(int j = i + 1; j < prices.length; j++){
                count++;
                if(prices[i] > prices[j]) break;
            }
            result.add(count);
        }
        int[] answer = result.stream().mapToInt(Integer::intValue).toArray();
        return answer;
    }

    public static void main(String[] args) {
        Arrays.stream(solution(new int[]{1, 2, 3, 2, 3})).forEach(num -> System.out.println(num));

    }
}
```

- List to int[] 로 변환하기 위해서 구아바나 아바치 커먼 랭을 사용하는게 아니라면 stream().mapToInt()로 해결하는 것이 최선인 것 같다.
- count++을 하는 시점이 조금 까다로웠다. 다음 날 가격이 내려간다고 해도 count는 증가해야돼서..

```java
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        for(int i = 0; i < prices.length; i++){
            int count = 0;
            for(int j = i + 1; j < prices.length; j++){
                count++;
                if(prices[i] > prices[j]) break;
            }
            answer[i] = count;
        }
        
        return answer;
    }
}
```

- 애초에 answer 배열 크기가 prices의 크기와 같으므로 애초에 이렇게 접근해도 됨



프로그래머스 고득점 키트 스택/큐 주식가격

