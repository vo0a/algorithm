## [programmers] 2018 kakao 후보키

> 1 << colsize

1을 오른쪽으로 colsize만큼 옮기라는 뜻인데 연산을 하고나면 2의 colsize 승이 된다.(colsize번째 비트만 1로 켜짐) 아래 문제에서는 컬럼개수가 4개로 16이 되어 포문에서는 0부터 15까지 볼 수 있다.

>n&1

n 과 1을 엔드연산한건데 여기서 1은 인트 1로 1111111 비트연산자가 아니다. 00000001 과 같다. 따라서 마지막 비트가 켜져있는지 아닌지 확인이 가능한 것.

>if(!(subset & 1 << k)) continue; //k 번째 비트만 켜지게 됨.

`subset & 1 << k ` 여기서 우선순위가 가장 높은것은 쉬프트 연산자로 1 << k를 먼저 하게 된다. 그러면 k번째 비트가 1로 되어 subset에 해당 k번째 비트가 1인지 알 수 있게 된다. 그렇게 &연산자를 통하여 1이 나오면 후보키에 포함된다는 것이고 0이라면 후보키가 아니라는 것을 알 수 있다.

이런 방법으로 현재보고자하는 컬럼들의 속성들만 순회할 수 있다.

>(n & *it) == n

이 연산의 결과가 n이라면 n에 포함된 모든 비트가 동일하게 켜져 있거나 모두 포함하게 켜져있다. = 최소성 만족 못함.



정답 코드

```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int countBits(int n) {
    int ret = 0;
    while(n){
        if(n&1) ret ++;//ture 라면 첫 번째 비트가 켜져있다는 뜻.
        n = n >>1; //오른 쪽으로 하나씩 없앤다.
    }
    return ret;
}

bool comp(int a, int b){ //켜진 비트 카운트.
    int x = countBits(a), y = countBits(b);
    return x > y; //내림차순으로 정렬
}

bool check(vector<vector<string>> relation, int rowsize, int colsize, int subset){
    for(int a = 0; a < rowsize -1; a++){
        for(int b = a+1; b< rowsize; b++){
            bool isSame = true;
            for(int k = 0; k < colsize; k++){
                if(!(subset & 1 << k)) continue; //k 번째 비트만 켜지게 됨.
                if(relation[a][k] != relation[b][k]){
                    isSame = false;
                    break;
                }
            }
            if (isSame) return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int rowsize = relation.size();
    int colsize = relation.front().size();
    vector<int> candidates;
    
    for (int i = 1; i < 1 << colsize; i++){
        if (check(relation, rowsize, colsize, i))
            candidates.push_back(i);
    }
    
    sort(candidates.begin(), candidates.end(), comp);
    
    while(!candidates.empty()){
        int n = candidates.back();
        candidates.pop_back();
        answer++;
        // 지워가면서 순회할거기때문에 iterator 증가하는 부분은 적지 않음.
        for(vector<int>::iterator it = candidates.begin(); it != candidates.end();){
            if((n & *it) == n)
                // n에 포함된 모든 비트가 동일하게 켜져 있거나 모두 포함하게 켜져있다. = 최소성 만족 못함.
                it = candidates.erase(it);
            else it++;
        }
    }
    
    return answer;
}
```





맞은 사람 코드

```c++
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

bool possi(vector<int>& vec, int now) {
	for (int i = 0; i < vec.size(); i++)
		if ((vec[i] & now) == vec[i])return false;
	return true;
}
int solution(vector<vector<string>> relation) {
	int n = relation.size();
	int m = relation[0].size();
	vector<int> ans;
	for (int i = 1; i < (1 << m); i++) {
		set<string> s;
		for (int j = 0; j < n; j++) {
			string now = "";
			for (int k = 0; k < m; k++) {
				if (i & (1 << k))now += relation[j][k];
			}
			s.insert(now);
		}
		if (s.size() == n && possi(ans, i)) ans.push_back(i);
	}
	return ans.size();
}
```

