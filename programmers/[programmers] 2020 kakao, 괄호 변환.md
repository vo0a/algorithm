## [programmers] 2020 kakao, 괄호 변환

[문제](https://programmers.co.kr/learn/courses/30/lessons/60058)



```c++
#include <string>
#include <vector>
#include <stack>
using namespace std;

// pos는 v의 위치이자 u의 길이
bool isCorrect(string str, int* pos){
    bool ret = true;
    int left = 0, right = 0;
    stack<char> st;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            left++;
            st.push('(');
        } 
        else { 
            right++;
            if(st.empty()) ret = false;
            else st.pop();
        }
        if(left == right){
            *pos = i + 1;
            return ret;
        }
    }
    return true;
}

string solution(string p) {
    if(p.empty()) return p;
    
    int pos;
    bool correct = isCorrect(p, &pos);
    string u = p.substr(0, pos);
    string v = p.substr(pos);
    
    if(correct){
        return u + solution(v);
    }
    
    string answer = "(" + solution(v) + ")";
    for(int i = 1; i < u.length() -1; i++){
        if(u[i] == '(') answer += ")";
        else answer += "(";
    }
    return answer;
}
```



프로그래머스 2020 kakao, 괄호 변환

