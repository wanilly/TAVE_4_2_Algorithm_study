#include<iostream>
using namespace std;
int T, t, dp[12] = { 0, }; // 모든 값은 0으로 셋팅

int main() {
	/*점화식 : dp[n] = dp[n-1] + dp[n-2] + dp[n-3]*/
	/*다른 말로 메모이제이션이라 한다*/
	cin >> T;
	dp[1] = 1; dp[2] = 2; dp[3] = 4; // 1, 2, 3은 기본 값으로 지정
	for (int i = 0; i < T; i++) {
		cin >> t;
		for (int j = 4; j <= t; j++)
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		cout << dp[t] << endl;
	}
}