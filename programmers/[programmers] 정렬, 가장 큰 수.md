## [programmers] 정렬, 가장 큰 수

[문제](https://programmers.co.kr/learn/courses/30/lessons/42746#)



```c++
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<string, int> p;

string solution(vector<int> numbers) {
    string answer = "";
    vector<p> sorted;
    string num = "";
    for(int i = 0; i< numbers.size(); i++){
        num = to_string(numbers[i]);
        string str = num + num + num;
        sorted.push_back({str, i});
    }
    
    sort(sorted.rbegin(), sorted.rend()); // 내림차순 정렬
    for(int i = 0; i< sorted.size(); i++){
        num = to_string(numbers[sorted[i].second]);
        answer += num;
    }    
    
    if(answer[0] == '0') return "0";    
    else return answer;
}
```



### stoi 의 한계점

```c++
if(!stoi(answer)) answer = "0";
return answer;
```

마지막 부분을 위와 같이 작성하고 제출했을 때는 11번 테스트케이스만 맞고, 나머지 테스트는 전부 틀린거로 나왔다. 

분명 '실행'으로 테스트케이스 돌렸을 때는 맞아서 제출을 했는데 틀려서 당황..



> **알고보니 stoi에는 문자열길이에 제한이 있다.** 
>
> "0"이 아닌 다른 문자를 11개 이상(10개 초과) 포함하는 문자열에 대해서는 stoi를 통해 int형으로 변환하지 못하고 오류를 발생시킨다.



이러한 문제점을 찾았고, 해결하기 위해서 answer문자열의 첫 번째 문자가 0인지 판단해서 답을 출력하는 코드로 바꿔서 정답을 맞을 수 있었다.





프로그래머스 고득점 키트 정렬 가장 큰 수

