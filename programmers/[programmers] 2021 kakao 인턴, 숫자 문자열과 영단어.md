## [programmers] 2021 kakao 인턴, 숫자 문자열과 영단어

[문제](https://programmers.co.kr/learn/courses/30/lessons/81301)



```c++
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string ch[11][2] = { {"zero", "0"}, {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"},
{"five","5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine","9"} };
int Size[11] = { 4, 3, 3, 5, 4, 4, 3, 5, 5, 4 };


int solution(string s) {
	int answer = 0;
	for (int i = 0; i < 10; i++) {
		while (s.find(ch[i][0]) != string::npos) {
			s.replace(s.find(ch[i][0]), Size[i], ch[i][1]);
		}
	}
	answer = stoi(s);
	return answer;
}
```

### Java

```java
class Solution {
    public int solution(String s) {
        String[][] mapArr = { {"0", "zero"}, 
                              {"1", "one"}, 
                              {"2", "two"}, 
                              {"3", "three"}, 
                              {"4", "four"}, 
                              {"5", "five"}, 
                              {"6", "six"}, 
                              {"7", "seven"}, 
                              {"8", "eight"}, 
                              {"9", "nine"} };

        for(String[] map : mapArr){
            s = s.replace(map[1], map[0]);
        }

        int answer = Integer.parseInt(s);
        return answer;
    }
}
```



프로그래머스 2021 kakao 인턴, 숫자 문자열과 영단어

