/*
<�÷��̵� �ͼ� �˰��� ( �ϸ� ���� )>
- �׷������� ��� �ִ� ��θ� ���ϴ� ���
- ���ͽ�Ʈ�󿡼��� ���� ����ġ�� ���� ���� �� �� -> ������ ����!
- ������ ��� ������ ���� ��θ� ����ϹǷ� '2���� �迭'�� �Ÿ��� ����
- optimal substructure : Ư�� ��� �ȿ� ������ ���� ��ΰ� ���� ��, �߰� ��������
						 ���� �ִܰŸ��̸�, �̸� ��� ���� ��ε� �ִܰŸ��̴�.
- ������ 2���� ���̺��� ��� -> ��� ��� ��� ���� and �� �������� ���� ������ ���� ����

�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�

<�ɺ� �������� 6�ܰ� ��Ģ>

6�ٸ� �ȿ� ���� �ƴ� ������� �����!

�ɺ� ������ ����
- ������ �� ����� �ּ� �� �ܰ� ���� �̾�����?
- ex) ���� ������ -------------> ���հ��� �۹α� (���� ��ܰ�?)
- �� ���ø� '�̱� �Ҹ���� ���'�� �����Ѵ�!
- ex) ���� �ѽ��� -------------> �� ũ����
- �ܰ��� �� ���� ���� ���� ����� ��!

�ɺ� ������ ��
- ���� judge�� ���� �߿��� �ɺ� ������ ���� ���� ���� ã�ƺ���
- �� ���� ��� ����� �ɺ� ������ ������ ���� �� ������ �ܰ��� ��!
- ex) ���� 5��
	1 - 3
	1 - 4
	2 - 3
	3 - 4
	4 - 5 ���� ģ���� ��,

	<1> �� 2���� (2)�ܰ�
		   3���� (1)�ܰ�
		   4���� (1)�ܰ�
	+      5���� (2)�ܰ�
	�ѤѤѤѤѤѤѤѤѤ�
		   ����  (6)�ܰ�

- ��� <1>�� ���� <2>, <3>, <4>, <5>�� ���ϸ�
- �������, 6, 8, 5, 5, 8
- ���� ���� ���� ���� ���� 3�� 4�� �� ������ ����

�Է� : n(���� ��) / m(���� ��) / �������� ģ�� ����
��� : ���� ��ȣ�� ��� ( �������̸� ��ȣ�� ���� ���� ���� )

����
- ���� �Է��� 2���� �迭 ���·� ���� by ����
- 1�� ���ں��� �� ���� ���ϴ� �ݺ���
- �� ���� ������ map���� ( ��ȣ, �� �� )

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 /* ���Ѵ� (������ ���� ���) */

typedef struct GraphType {
	int n; // ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int n, m;					// ���� ��, ���� ��
vector<int> distance(MAX_VERTICES);
vector<int> found(MAX_VERTICES);
vector<int> res(n);			// �� ������ �ܰ� �� �� ������ ����

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	for (i = 0; i < g->n; i++) /* �ʱ�ȭ */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE; /* ���� ���� �湮 ǥ�� */
	distance[start] = 0;
	for (i = 0; i < g->n - 1; i++) {
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w < g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w] < distance[w])
					distance[w] = distance[u] + g->weight[u][w];
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int x, y, sum = 0, tmp = 0, cnt = 0;


	// ���� �Է� ����
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		d[x - 1][y - 1] = 1;	// ���谡 ������ 1
	}

	GraphType g = { 7,
		{{ 0, 7, INF, INF, 3, 10, INF },
		{ 7, 0, 4, 10, 2, 6, INF },
		{ INF, 4, 0, 2, INF, INF, INF },
		{ INF, 10, 2, 0, 11, 9, 4 },
		{ 3, 2, INF, 11, 0, INF, 5 },
		{ 10, 6, INF, 9, INF, 0, INF },
		{ INF, INF, INF, 4, 5, INF, 0 } }
	};
	shortest_path(&g, 0);

	// �� ������ ���� �̱��? ( i : ���� ���� , j : ������ ���� )
	for (int i = 0; i < n; i++) {

	}
}