#include<iostream>
#include<queue>
using namespace std;

int n, m, v, x, y;
int graph[1001][1001];
int visit[1001];

// ���� �켱 Ž�� ( �������� �����Ϸ� ������, ��� ȣ�� �Լ��� ������ �� ���� )
void dfs(int start) {

	cout << start << ' ';		// ó�� ���� ���� ���
	visit[start] = 1;			// ó�� ���� ������ �湮

	// ����� ��ȣ�� ����Ͽ� 1���� ����
	for (int i = 1; i <= n; i++) {

		if (visit[i] == 1 || graph[start][i] == 0)    // �湮�Ͽ��ų�, �׷����� ��� �������� i�� ���� ���� ���ٸ� �н�!
			continue;

		dfs(i);	// ���� �ִٸ� �� �������� �ٽ� ������ �Ѵ�.
	}
}

// �ʺ� �켱 Ž��
void bfs(int start) {

	queue<int> q;		// ť�� ����Ͽ� �ʺ� �켱 Ž�� ����
	q.push(start);		// ���� ���� ��ȣ�� ����
	visit[start] = 0;	// ���� ���� �湮 ( �ռ� dfs���� �����Ͽ� 1�� �ʱ�ȭ �Ǿ������Ƿ�, 0�� �湮 ǥ�÷� �ǹ̸� �д�.)

	while (!q.empty()) {	// ť�� ������� �� ���� 
		start = q.front();	// ���� ������ ť�� �� ������ �ʱ�ȭ

		cout << q.front() << ' ';
		q.pop();

		for (int i = 1; i <= n; i++) {

			if (visit[i] == 0 || graph[start][i] == 0)	// �湮�߰ų�, �׷����� ������ ���� ��� �н�
				continue;

			q.push(i);		// ���� ���� ��, ť�� ����
			visit[i] = 0;	// �湮�ߴٰ� ǥ��
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;	// 2���� �迭 �����̹Ƿ� x,y�� y,x �Ѵ� 1�� �ʱ�ȭ
	}

	dfs(v);
	cout << '\n';
	bfs(v);

	return 0;
}
