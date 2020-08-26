## [programmers] 탐욕법, 구명보트

[문제](https://programmers.co.kr/learn/courses/30/lessons/42885#)



```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int chk[50005];

int solution(vector<int> people, int limit) {
	int answer = 0, size = people.size();
	sort(people.begin(), people.end());
	
    int left = 0, right = size - 1;
    while(left < right){
        if(people[left] + people[right] <= limit){
            chk[left] = chk[right] = 1;
            left++; right--;
            answer++;
        }
        else {
            right--;
        }
    }

	for (int i = 0; i < people.size(); i++) {
		if (!chk[i]) answer++;
	}

	return answer;
}
```

처음에 투포인터를 떠올리며 구상은 했는데, 구현할 때 되니 까맣게 잊어버리고 이중 for문을 사용한 것 같다.  허허;; 





## 시도 1

```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int chk[50005];

int solution(vector<int> people, int limit) {
	int answer = 0, size = people.size();
	sort(people.begin(), people.end());
	for (int i = 0; i < size / 2; i++) {
		if (chk[i]) continue;
		for (int j = size - 1; j > i; j--) {
			if (chk[j] || i == j) continue;
			if (people[i] + people[j] <= limit) {
				chk[i] = chk[j] = 1;
				answer++; break;
			}
		}
	}

	for (int i = 0; i < people.size(); i++) {
		if (!chk[i]) answer++;
	}

	return answer;
}
```

> 정확성 테스트는 다 맞았지만, 효율성 테스트는 0점
>
> 무인도에 갇힌 사람이 최대 50000 으로 이중for문이 괜찮다고 생각한 것이 경기도 오산,,
>
> 어떻게 효율적으로 할 수 있을까 고민해봐야겠다.



프로그래머스 고득점 키트 탐욕법 구명보트

