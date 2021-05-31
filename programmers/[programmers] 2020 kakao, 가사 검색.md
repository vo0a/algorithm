## [programmers] 2020 kakao, 가사 검색

[문제](https://programmers.co.kr/learn/courses/30/lessons/60060)



```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Trie {
private:
    Trie* child[26];
    int count;
public:
    // array 멤버가 0으로 초기화, int가 0으로 초기화
    Trie() : child(), count(0) {}
    void Insert(string str) {
        Trie* curr = this;
        
        for(char ch : str){
            curr -> count++;
            if(curr->child[ch - 'a'] == nullptr){
                curr->child[ch - 'a'] = new Trie();
            }
            curr = curr->child[ch - 'a'];
        }
        
        curr->count++;
    }
    
    int Search(string str) {
        Trie* curr = this;
        for(char ch : str){
            if(ch == '?') return curr->count;
            curr = curr->child[ch - 'a'];
            if(curr == nullptr) return 0;
        }
        return curr->count;
    }
};

Trie TrieRoot[10000];
Trie ReTrieRoot[10000];

vector<int> solution(vector<string> words, vector<string> queries) {  
    vector<int> answer;  
    
    for(string str : words){
        TrieRoot[str.length() - 1].Insert(str);
        reverse(str.begin(), str.end());
        ReTrieRoot[str.length() - 1].Insert(str);
    }
    
    for(string str : queries){
        if(str[0] != '?') 
            answer.push_back(TrieRoot[str.length() - 1].Search(str));
        else {
            reverse(str.begin(), str.end());
            answer.push_back(ReTrieRoot[str.length() - 1].Search(str));
        }
    }
    
    return answer;
}
```

- query의 길이를 기반으로 검색 결과를 찾아야 한다.
  - word의 길이를 인덱스로 하는 트라이를 만든다 : TrieRoot[], ReTrieRoot[]
- `?`가 접두사로 주어질 경우를 고려하여 트라이를 두 개 만든다.
  - 하나는 str[0] ... str[length-1] : TrieRoot
    - ?가 접미사일때 사용할 트리
  - 다른 하나는 str[length-1] ... str[0] : ReTrieRoot
    - ?가 접두사일때 사용할 트리



### 틀림

```c++
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    map<string, int> m;
    
    for(string wd : words){        
        for(int i = 0; i < 1 << wd.length(); i++){
            int a = i;
            string s = "";
            for(int j = 0; j < wd.length(); j++){
                if (a % 2) s += wd[j];
                else s += "?";
                a /= 2;
		    }
		    m[s]++;
        }
    }
    
    vector<int> answer;
    for(string q : queries){
        answer.push_back(m[q]);
    }    
    
    return answer;
}
```

- 길이가 최대 100,000 이라서 시간 초과날 줄은 알았지만 13점...ㅜ.
- 문제를 다시 보니, ?가 `접두사 또는 접미사`로 주어진다는 힌트가 있었다. 따라서 해당 문제는 트라이 자료구조로 풀 수 있다.



프로그래머스 2020 kakao, 가사 검색

