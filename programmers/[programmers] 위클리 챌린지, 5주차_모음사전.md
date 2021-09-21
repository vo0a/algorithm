## [programmers] 위클리 챌린지, 5주차_모음사전

[문제](https://programmers.co.kr/learn/courses/30/lessons/84512)



```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
void DFS(string s) {
    if(s.size() == 5) return;
    for(auto c : string("AEIOU")) {
        string next = s + c;
        v.push_back(next);
        DFS(next);
    }
}

int solution(string word) {
    DFS("");
    sort(v.begin(), v.end());
    return lower_bound(v.begin(), v.end(), word) - v.begin() + 1; // index를 반환하니까 '번째'로 반환하려면 +1 해야함
}
```

- 사전에 알파벳 모음 'A', 'E', 'I', 'O', 'U'만을 사용하여 만들 수 있는, 길이 5 이하의 모든 단어가 수록되어 있습니다. 사전에서 첫 번째 단어는 "A"이고, 그다음은 "AA"이며, 마지막 단어는 "UUUUU"입니다. 
- 단어 word가, 사전에서 **몇 번째 단어인지 return** 하는 문제
- word의 길이는 1 이상 5 이하
- word는 알파벳 대문자 'A', 'E', 'I', 'O', 'U'로만 이루어져 있다.



프로그래머스 위클리 챌린지, 5주차_모음사전

