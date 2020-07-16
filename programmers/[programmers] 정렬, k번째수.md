## [programmers] 정렬, k번째수

[문제](https://programmers.co.kr/learn/courses/30/lessons/42748)



```c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    int idx = 0;
    while(idx < commands.size()){
        vector<int> cut;
        for(int i = commands[idx][0] - 1; i < commands[idx][1]; i++){
            cut.push_back(array[i]);
        }
        sort(cut.begin(), cut.end());
        answer.push_back(cut[commands[idx++][2] - 1]);
    }
    return answer;
}
```



### 정렬

정렬할 때 **시작지점**과 **끝지점**을 지정해서 할 수 있다.

```c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for(int i = 0; i < commands.size(); i++) {
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        answer.push_back(temp[commands[i][0] + commands[i][2]-2]);
    }

    return answer;
}
```





프로그래머스 고득점 키트 정렬 k번째수

