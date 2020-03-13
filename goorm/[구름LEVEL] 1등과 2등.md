## [구름LEVEL] 1등과 2등

| 난이도 | 정답률 |
| ------ | ------ |
| ★★     | 65.2%  |





```c++
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int chk[100005], idx, idx2, findnexti;
string s, ss;

int func(string findnum) {
	memset(chk, 0, sizeof(chk));
	string findnum2 = findnum == "12" ? "21" : "12";

	if (s.find(findnum) != string::npos) {
		idx = s.find(findnum);
		chk[idx] = 1; chk[idx + 1] = 1;
		if (s.find(findnum2) != string::npos) {
			idx2 = s.find(findnum2);
			if (chk[idx2] || chk[idx2 + 1]) {
				if (chk[idx2]) {
					chk[idx2 + 1] = 1; 
					findnexti = idx2 + 1;
				}
				else {
					chk[idx2] = 1; 
					findnexti = idx + 1;
				}
				ss = s.substr(findnexti + 1);
				if (ss.find(findnum2) != string::npos) {
					return 1;
				}
			}
			else {
				return 1;
			}
		}
	}
	else {
		return 0;
	}
	return 0;
}

int main() {
	cin >> s;
	if (func("12")) {
		printf("Yes");
	}
	else if (func("21")) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}

```



### 더 간결하고 쉬운 방법

알아보기 복잡했던 함수내용을 아래처럼 간단하게 바꿀 수 있다.

```c++
if (AB != string::npos && str.substr(AB + 2).find("21") != string::npos ||
		BA != string::npos && str.substr(BA + 2).find("12") != string::npos)
    cout << "Yes";
else
    cout << "No";
```





구름LEVEL 1등과 2등 goorm goormlevel

