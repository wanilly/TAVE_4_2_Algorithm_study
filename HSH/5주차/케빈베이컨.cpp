/*
<플로이드 와샬 알고리즘 ( 일명 와플 )>
- 그래프에서 모든 최단 경로를 구하는 방법
- 다익스트라에서는 음의 가중치를 가진 간선 못 씀 -> 와플은 가능!
- 와플은 모든 정점에 대한 경로를 계산하므로 '2차원 배열'로 거리를 저장
- optimal substructure : 특정 경로 안에 무수히 많은 경로가 있을 때, 중간 정점들이
						 각각 최단거리이면, 이를 모두 이은 경로도 최단거리이다.
- 와플은 2개의 테이블을 사용 -> 모든 경로 비용 저장 and 각 정점까지 가기 직전의 정점 저장

ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

<케빈 베이컨의 6단계 법칙>

6다리 안에 서로 아는 사람으로 연결됨!

케빈 베이컨 게임
- 임의의 두 사람이 최소 몇 단계 만에 이어지냐?
- ex) 산기대 안윤빈 -------------> 성균관대 송민규 (과연 몇단계?)
- 이 예시를 '미국 할리우드 배우'에 적용한다!
- ex) 산기대 한승훈 -------------> 톰 크루즈
- 단계의 총 합이 가장 적은 사람이 승!

케빈 베이컨 수
- 백준 judge에 유저 중에서 케빈 베이컨 수가 적은 놈을 찾아보자
- 이 수는 모든 사람과 케빈 베이컨 게임을 했을 때 나오는 단계의 합!
- ex) 유저 5명
	1 - 3
	1 - 4
	2 - 3
	3 - 4
	4 - 5 끼리 친구일 때,

	<1> 은 2까지 (2)단계
		   3까지 (1)단계
		   4까지 (1)단계
	+      5까지 (2)단계
	ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
		   총합  (6)단계

- 모두 <1>과 같이 <2>, <3>, <4>, <5>를 구하면
- 순서대로, 6, 8, 5, 5, 8
- 따라서 가장 적은 합을 가진 3과 4가 이 게임의 승자

입력 : n(유저 수) / m(관계 수) / 나머지는 친구 관계
출력 : 승자 번호를 출력 ( 여러명이면 번호가 가장 작은 승자 )

설계
- 관계 입력을 2차원 배열 형태로 구현 by 와플
- 1번 주자부터 총 합을 구하는 반복문
- 총 합을 저장할 map형태 ( 번호, 총 합 )

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 /* 무한대 (연결이 없는 경우) */

typedef struct GraphType {
	int n; // 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int n, m;					// 유저 수, 관계 수
vector<int> distance(MAX_VERTICES);
vector<int> found(MAX_VERTICES);
vector<int> res(n);			// 각 유저의 단계 총 합 저장할 벡터

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
	for (i = 0; i < g->n; i++) /* 초기화 */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE; /* 시작 정점 방문 표시 */
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


	// 관계 입력 과정
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		d[x - 1][y - 1] = 1;	// 관계가 있으면 1
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

	// 이 게임은 누가 이길까? ( i : 게임 유저 , j : 만나는 유저 )
	for (int i = 0; i < n; i++) {

	}
}