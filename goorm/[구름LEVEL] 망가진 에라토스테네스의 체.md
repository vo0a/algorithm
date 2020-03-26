## [구름LEVEL] 망가진 에라토스테네스의 체

| 난이도 | 정답률 |
| ------ | ------ |
| ★★     | -%     |





```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n;
bool isPrime(ll num) {
	for (ll i = 2; i * i <= num; i++) {
		if (!(num % i)) return 0;
	}
	return 1;
}
int main() {
	scanf("%lld", &n);
	if (n == 1) {
		printf("0");
		return 0;
	}
	for (ll i = 2; i * i <= n; i++) {
		if (!(n % i)) {
			if (isPrime(i) && isPrime(n / i)) {
				printf("1");
				return 0;
			}
			else { // 하나라도 나눠지는데 소수들의 곱이 아니면 0
				printf("0");
				return 0;
			}
		}
	}
	printf("1");
	return 0;
}
```





구름LEVEL 망가진 에라토스테네스의 체 goorm goormlevel

