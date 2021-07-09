## [programmers] 스택큐, 프린터

[문제](https://programmers.co.kr/learn/courses/30/lessons/42587)



### C++

```c++
#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
priority_queue<int> pq;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i =0; i<priorities.size(); i++){
        q.push(i);
        pq.push(priorities[i]);
    }
    while(1){
        if(priorities[q.front()] == pq.top()){
            answer++;
            if(q.front() == location){
                break;
            }
            q.pop();
            pq.pop();            
        }else{
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }
    
    return answer;
}
```



### Java

```java
import javafx.util.Pair;

import java.util.Collections;
import java.util.LinkedList;
import java.util.PriorityQueue;

class Solution {
    public int solution(int[] priorities, int location) {
        LinkedList<Pair<Integer, Integer>> queue = new LinkedList<>();
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(Collections.reverseOrder());


        for (int i = 0; i < priorities.length; i++) {
            queue.add(new Pair<>(priorities[i], i));
            priorityQueue.add(priorities[i]);
        }

        int count = 0;
        while (!queue.isEmpty()) {
            int value = queue.peek().getKey();
            int index = queue.poll().getValue(); // 반환하면서 pop

            if (value != priorityQueue.peek()) {
                queue.add(new Pair<>(value, index));
            } else {
                count++;
                priorityQueue.remove();
                if (location == index) {
                    break;
                }
            }
        }

        return count;
    }
}
```





프로그래머스 고득점 키트 스택큐 프린터

