#include<iostream>
#include<queue>
using namespace std;

int n, m, v, x, y;
int graph[1001][1001];
int visit[1001];

// 깊이 우선 탐색 ( 스택으로 구현하려 했으나, 재귀 호출 함수의 구현이 더 간단 )
void dfs(int start) {

	cout << start << ' ';		// 처음 시작 지점 출력
	visit[start] = 1;			// 처음 시작 지점을 방문

	// 노드의 번호를 고려하여 1부터 시작
	for (int i = 1; i <= n; i++) {

		if (visit[i] == 1 || graph[start][i] == 0)    // 방문하였거나, 그래프의 출발 지점에서 i로 가는 길이 없다면 패스!
			continue;

		dfs(i);	// 길이 있다면 그 지점부터 다시 시작을 한다.
	}
}

// 너비 우선 탐색
void bfs(int start) {

	queue<int> q;		// 큐를 사용하여 너비 우선 탐색 진행
	q.push(start);		// 시작 지점 번호를 삽입
	visit[start] = 0;	// 시작 지점 방문 ( 앞서 dfs에서 진행하여 1로 초기화 되어있으므로, 0을 방문 표시로 의미를 둔다.)

	while (!q.empty()) {	// 큐가 비어있을 때 까지 
		start = q.front();	// 시작 지점을 큐에 맨 앞으로 초기화

		cout << q.front() << ' ';
		q.pop();

		for (int i = 1; i <= n; i++) {

			if (visit[i] == 0 || graph[start][i] == 0)	// 방문했거나, 그래프의 간선이 없는 경우 패스
				continue;

			q.push(i);		// 간선 존재 시, 큐에 삽입
			visit[i] = 0;	// 방문했다고 표시
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;	// 2차원 배열 형태이므로 x,y랑 y,x 둘다 1로 초기화
	}

	dfs(v);
	cout << '\n';
	bfs(v);

	return 0;
}
