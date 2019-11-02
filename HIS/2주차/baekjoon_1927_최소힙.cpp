#include<iostream>
#include<queue>
using namespace std;

/*
시간 제한이 매우 짧았던 문제. 3가지를 꼭 해줘야한다.
1. ios_base::sync_with_stdio(0);
	  cpp의 iostream을 c의 stdio와 동기화시키는 역할.
	  본래는 iostream, stdio의 버퍼를 모두 사용해서 딜레이가 발생하는데 이 코드를 통해 0, 즉, false로 설정하면 c++만의 독립적인 버퍼가 생성된다.
2. cin.tie(0);
	  cin이 뒤에 cout 나오더라도 cin을 먼저하게하는 코드라는 것 같다.
3. cout<<"\n";
	  endl 대신 "\n"을 쓰자. 훨씬 빠르다.

*** 이와 같은 시간 초과 문제는 10825번 국영수에서도 겪었다. 단, 이번 문제가 시간 초과를 더 각박하게 잡았다. ***
*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int, vector<int>, greater<int>> pq;

	int N = 0, t;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (t != 0) pq.push(t);
		else if (pq.empty()) cout << 0 << "\n";
		else {
			cout << pq.top() << "\n";
			pq.pop();
		}
	}
}