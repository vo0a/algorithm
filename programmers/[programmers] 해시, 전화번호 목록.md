## [programmers] 해시, 전화번호 목록

[문제](https://programmers.co.kr/learn/courses/30/lessons/42577)



```c++
#include <string>
#include <vector>
using namespace std;

class TRIE {
public:
	TRIE* child[11]; // 0~9
	bool is_terminal;
	TRIE() {
		is_terminal = false;
		for (int i = 0; i < 10; ++i) child[i] = nullptr;
	}

	~TRIE() {
		for (int i = 0; i < 10; ++i) {
			if (child[i] != nullptr)
				delete(child[i]);
		}
	}

	void insert(string key) {
		if (key[0] == '\0') {
			is_terminal = true;
		}
		else {
			int idx = key[0] - '0';
			if (child[idx] == nullptr) {
				child[idx] = new TRIE();
			}
			child[idx]->insert(key.substr(1));
		}
	}

	bool find(string key) {
		if (key[0] == '\0') return false;
		if (is_terminal) return true;

		int idx = key[0] - '0';
		if (child[idx] == nullptr) {
			return false;
		}
		return child[idx]->find(key.substr(1));
	}
};


bool solution(vector<string> phone_book) {
    bool answer = true;
    
    TRIE *root = new TRIE;
    for(int i = 0; i < phone_book.size(); i++){
        root->insert(phone_book[i]);
    }
    
    for(int i = 0; i < phone_book.size(); i++){
        if(root->find(phone_book[i])){
            answer = false;
            break;
        }
    }
    
    return answer;
}
```





프로그래머스 고득점 키트 해시 전화번호 목록

