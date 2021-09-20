## [programmers] 위클리 챌린지, 4주차_직업군 추천하기

[문제](https://programmers.co.kr/learn/courses/30/lessons/84325)



```c++
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

map<string, vector<string>> Table;
string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    
    for(int i =0; i < table.size(); i++) {
        string s = table[i];
        stringstream ss(s);
        string Job, lang;
        ss >> Job;
        while(ss >> lang) {
            Table[Job].push_back(lang);
        }
    }
    
    int Max = 0;
    for(auto Job: Table) {
        int sum = 0;
        for(int i = 0; i < Job.second.size(); i++) {
            for(int j = 0; j < languages.size(); j++) {
                if(languages[j] == Job.second[i]) {
                    sum += preference[j] * (5 - i);
                }
            }
        }
        if(sum == Max) answer = answer < Job.first ? answer : Job.first;
        else if(sum > Max) {            
            Max = sum;
            answer = Job.first;
        }
    }
    
    return answer;
}
```

- table의 길이는 5 이며 차례로 "직업군 5점 언어, 4점, 3점, 2점, 1점 언어" 형식의 문자열이며 하나의 공백으로 구분되어 있다.
- 개발자가 사용하는 `언어`와 `언어 선호도`가 주어지면, 그에 맞는 직업군을 추천해주는 문제이다.
- `언어` : languages의 길이는 1~9 이고 원소는 중복되어있지 않다.
- `언어 선호도` : preference의 길이는 languages의 길이와 같다. (정수: 1~10)
- 직업군별 점수 총합이 같다면, 사전 순으로 먼저 오는 직업군을 반환해야 한다.



프로그래머스 위클리 챌린지, 4주차_직업군 추천하기

