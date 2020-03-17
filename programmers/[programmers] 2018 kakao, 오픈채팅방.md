## [programmers] 2018 kakao 오픈채팅방



```
tok = strtok(NULL, " ");
```


while문 내부에 첫번째 파라메터로 NULL을 주게되면 내부 버퍼에 저장되어있는 포인터에서 다음 " "를 찾고 그 뒤에 문자열의 주소를 반환하게 된다.

이렇게 해서 계속해서 순회하면 모든 문자열을 잘라낼 수 있다.

```c++
vector<char> str(record[i].begin(), record[i].end());
str.push_back('\0');
char* p_str = &str[0];
char* tok = strtok(p_str, " ");
```

```c++
for(string input:record)
    {
        stringstream ss(input);
        ss>>command;
        ss>>uid;
        if(command=="Enter" || command=="Change")
        {
            ss>>ID;
            m[uid]=ID;
        }
    }
```







내 풀이

```c++
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	typedef pair<string, int> p;
	vector<p> v;
	vector<string> answer;
	map<string, string> user;
	string uid, nickname;
	for (int i = 0; i < record.size(); i++) {
		vector<char> str(record[i].begin(), record[i].end());
		str.push_back('\0');
		char* p_str = &str[0];
		char* tok = strtok(p_str, " ");
		
		if (!strcmp(tok, "Enter")) {
			tok = strtok(NULL, " ");
			uid = tok;
			tok = strtok(NULL, " ");
			nickname = tok;
			user[uid] = nickname;
			v.push_back({ uid, 1 });
		}
		else if (!strcmp(tok, "Leave")) {
			tok = strtok(NULL, " ");
			uid = tok;
			v.push_back({ uid, 0 });
		}
		else { // Change
			tok = strtok(NULL, " ");
			uid = tok;
			tok = strtok(NULL, " ");
			nickname = tok;
			user[uid] = nickname;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second) {
			nickname = user[v[i].first];
			answer.push_back(nickname + "님이 들어왔습니다.");
		}
		else {
			nickname = user[v[i].first];
			answer.push_back(nickname + "님이 나갔습니다.");
		}
	}
	return answer;
}

int main() {
	solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });
	return 0;

}
```



- sstream 이용하면 더 쉬움.

```c++
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;


vector<string> solution(vector<string> record) {
    vector<string> answer;
    string command;
    string ID;
    string uid;
   map<string,string> m;


    for(string input:record)
    {
        stringstream ss(input);
        ss>>command;
        ss>>uid;
        if(command=="Enter" || command=="Change")
        {
            ss>>ID;
            m[uid]=ID;
        }
    }

   for(string input:record)
    {
        stringstream ss(input);
        ss>>command;
        ss>>uid;
        if(command=="Enter")
        {
         ID=(m.find(uid)->second);

            string temp = ID+"님이 들어왔습니다.";
         answer.push_back(temp);

        }
      else if(command=="Leave")
      {
         ID=(m.find(uid)->second);
            string temp = ID+"님이 나갔습니다.";
         answer.push_back(temp);
      }
    }
    return answer;
}
```

