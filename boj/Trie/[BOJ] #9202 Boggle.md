## [BOJ] #9202 Boggle

| 시간 제한 | 메모리 제한 | 정답 비율 |
| --------- | ----------- | --------- |
| 10 초     | 512 MB      | 24.042%   |

[문제](https://www.acmicpc.net/problem/9202)



| 메모리   | 시간    |
| -------- | ------- |
| 98956 KB | 3660 ms |

```c++
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
struct Node {
	bool valid;
	int children[26];
	Node() {
		valid = false;
		for (int i = 0; i < 26; i++) {
			children[i] = -1;
		}
	}
};
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
int scores[] = { 0,0,0,1,1,2,3,5,11 };
bool check[4][4];
vector<Node> trie;
int init() {
	Node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}
void add(int node, string& s, int index) {
	if (index == s.size()) {
		trie[node].valid = true;
		return;
	}
	int c = s[index] - 'A';
	if (trie[node].children[c] == -1) {
		int next = init();
		trie[node].children[c] = next;
	}
	add(trie[node].children[c], s, index + 1);
}
void search(int x, int y, string s, int node, vector<string>& board, vector<string>& words) {
	if (x < 0 || x >= 4 || y < 0 || y >= 4) {
		return;
	}
	if (check[x][y]) {
		return;
	}
	if (s.size() == 8) {
		return;
	}
	check[x][y] = true;
	int c = board[x][y] - 'A';
	int next = trie[node].children[c];
	if (next == -1) {
		check[x][y] = false;
		return;
	}
	s += board[x][y];
	if (trie[next].valid) {
		words.push_back(s);
	}
	for (int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		search(nx, ny, s, next, board, words);
	}
	check[x][y] = false;
}
int main() {
	int n, t;
	scanf("%d", &n);
	int root = init();
	vector<string> dictionary(n);
	for (int i = 0; i < n; i++) {
		cin >> dictionary[i];
		add(root, dictionary[i], 0);
	}
	scanf("%d", &t);
	while (t--) {
		vector<string> board(4);
		for (int i = 0; i < 4; i++) {
			cin >> board[i];
		}
		vector<string> words;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				search(i, j, "", root, board, words);
			}
		}
		sort(words.begin(), words.end());
		words.erase(unique(words.begin(), words.end()), words.end());
		int score = 0;
		string longest = "";
		int cnt = 0;
		for (string& s : words) {
			score += scores[s.size()];
			cnt += 1;
			if (longest.size() < s.size()) {
				longest = s;
			}
			else if (longest.size() == s.size() && longest > s) {
				longest = s;
			}
		}
		cout << score << ' ' << longest << ' ' << cnt << '\n';
	}
	return 0;
}
```





백준 9202 Boggle boj acmicpc

