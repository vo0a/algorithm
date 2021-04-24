## [programmers] 탐욕법, 체육복

[문제](https://programmers.co.kr/learn/courses/30/lessons/42862)



```c++
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	int chk[31] = {0};
	int lostLength = lost.size();
	int reserveLength = reserve.size();
	int answer = n - lostLength;

	for (int i = 0; i < lostLength; i++) {
		chk[lost[i]]++;
	}
	for (int i = 0; i < reserveLength; i++) {
		if (chk[reserve[i]]) answer++;
		chk[reserve[i]]++;
	}

	for (int i = 0; i < reserveLength; i++) {
		if (chk[reserve[i]] == 2)continue;
		for (int j = 0; j < lostLength; j++) {
			if (chk[lost[j]] == 2)continue;
			if (abs(reserve[i] - lost[j]) == 1) {
                chk[lost[j]]++;
				answer++;
                break;
			}
		}
	}

	return answer;
}
```

체육복을 잃어버린 친구와, 체육복 여분을 가진 친구가 동시에 존재할 수 있는 경우가 있기 때문에 해당하는 친구들에 대해서는 사전에 체육복을 입을 수 있고, 체육복을 더 이상 빌려줄 수 없음을 체크해준다.

따라서 위의 경우에 해당하지 않는 친구들에 한해서 체격 차이가 1인 친구들 끼리 체육복을 빌려줄 수 있음을 확인하고 나면 answer이 정답이 된다.

### Java

```java
class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = n - lost.length;
        int[] chk = new int[31];
        for(int i = 0; i<lost.length; i++){
            chk[lost[i]]--;
        }
        for(int i = 0; i<reserve.length; i++){
            chk[reserve[i]]++;
        }

        for(int i = 0; i < reserve.length; i++){
            if(chk[reserve[i]] == 0) { answer++; continue; }
            if(chk[reserve[i] - 1] < 0){
                chk[reserve[i] - 1]++; chk[reserve[i]]--;
                answer++;
            }
            else if(chk[reserve[i] + 1] < 0){
                chk[reserve[i] + 1]++; chk[reserve[i]]--;
                answer++;
            }
        }

        return answer;
    }
}
```





프로그래머스 고득점 키트 탐욕법 체육복

