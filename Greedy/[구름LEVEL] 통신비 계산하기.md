## [구름LEVEL] 통신비 계산하기

| 난이도 | 정답률 |
| ------ | ------ |
| ★★     | 31.7%  |





```c++
#include <iostream>
#include <algorithm>
using namespace std;
int pre_plan, use, pre_charge, recommend_plan,  recommend_charge = 200000;
int plan[][2] = { {29900, 300},{34900, 1000},{39900, 2000},{49900, 6000},{59900, 11000},{69900, -1} };
int main() {
	scanf("%d %d", &pre_plan, &use);

	int charge = 0, tmp = 0;
	for (int i = 0; i < 6; i++) {
		if (i == 5) tmp = 0;
		else {
			if (use > plan[i][1]) {
				tmp = use - plan[i][1];
			}
			else {
				tmp = 0;
			}

			if (tmp * 20 > 25000 && tmp < 5000) {
				tmp = 25000;
			}
			else if (tmp * 20 > 180000) {
				tmp = 180000;
			}
			else tmp *= 20;
		}
		if (plan[i][0] == pre_plan) {	
			pre_charge = plan[i][0] + tmp;
			continue;
		}
		charge = plan[i][0] + tmp;
		if (charge < recommend_charge) {
			recommend_charge = charge;
			recommend_plan = plan[i][0];
		}
	}

	printf("%d %d %d", recommend_plan, pre_charge, recommend_charge);

	return 0;
}
```





구름LEVEL 통신비 계산하기 goorm goormlevel

