## [programmers] DP, 도둑질

[문제](https://programmers.co.kr/learn/courses/30/lessons/42897)



```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1000005];

int solution(vector<int> money) {
    int answer = 0;
    dp[1] = money[0];
    for(int i = 2; i <= money.size(); i++){
        dp[i] = max(dp[i - 1], dp[i- 2] + money[i - 1]);
    }
    answer = dp[money.size()];
    return answer;
}
```

이 코드부터 시작해서 모든 집들이 동그랗게 배치되어 있기 때문에 첫 번째 집을 포함하고있는 값을 판단하기 위해서 이차원 배열로 dp 배열을 변형했다.



```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1000005][2]; // maxSum, firstSelect

int solution(vector<int> money) {
    int answer = 0;
    dp[1][0] = money[0];
    dp[1][1] = 1;
    for(int i = 2; i <= money.size(); i++){
        if(i == money.size()){
            if(!dp[i - 2][1]){
                dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + money[i - 1]);
            }
            else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 2][0]);
            }
            break;
        }
        if(dp[i - 1][0] > dp[i- 2][0] + money[i - 1]){
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
        }
        else {
            dp[i][0] = dp[i - 2][0] + money[i - 1];
            dp[i][1] = dp[i - 2][1];
        }        
    }
    answer = dp[money.size()][0];
    return answer;
}
```

옳게 고쳤다고 생각했는데, 40점 -> 75점. 

디버깅 후 `break;`문을 추가하고 75점이 되었지만 아직 실패..



프로그래머스 고득점 키트 DP 도둑질

