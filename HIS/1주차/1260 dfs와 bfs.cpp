#include<iostream>
#include<vector>
#include<queue>
using namespace std;

queue<int> q;
int N, M, V;
int map[1001][1001];
int dfs_visited[1001][1001];
int bfs_visited[1001][1001];

void bfs(int start) {
	/* 해당 노드가 처음 방문 하는 경우, 출력! */
	if (bfs_visited[start][start] == 0) {
		bfs_visited[start][start] = 1;
		cout << start << " ";
	}
	/* 해당 노드에 처음 방문하며, 해당 간선을 처음 지나고, 실제 map에서는 이어져 있는 경우 */
	for (int x = 1; x <= N; x++) {
		if (map[start][x] == 1 && bfs_visited[start][x] == 0 && bfs_visited[x][x] == 0) {
			bfs_visited[start][x] = 1; // 방문 여부를 기록하고
			bfs_visited[x][start] = 1; // 반대 방향 방문 여부도 기록하고
			q.push(x); // queue에 넣는다.
		}
	}
	/* queue에 있는 애들을 싹다 비우면서 재귀동작시키기 */
	while (!q.empty()) {
		int next = q.front();
		q.pop();
		bfs(next);
	}
}

void dfs(int start) {
	/* 해당 노드가 처음 방문 하는 경우, 출력! */
	if (dfs_visited[start][start] == 0) {
		dfs_visited[start][start] = 1;
		cout << start << " ";
	}
	/* 이어져 있는 모든 애들에 대해 재귀 동작 */
	for (int x = 1; x <= N; x++) {
		if (map[start][x] == 1 && dfs_visited[start][x] == 0 && dfs_visited[x][x] == 0) {
			dfs_visited[start][x] = 1;
			dfs_visited[x][start] = 1;
			dfs(x);
		}
	}
}

int main() {
	cin >> N >> M >> V;
	int t1, t2;
	for (int i = 0; i < M; i++) {
		cin >> t1 >> t2;
		map[t1][t2] = 1; map[t2][t1] = 1;
	}
	dfs(V);
	cout << "\n";
	bfs(V);
}