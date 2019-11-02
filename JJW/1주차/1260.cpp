#include <iostream>
#include <queue>

using namespace std;

int N, M, V; // 정점의 개수 , 간선의 개수, 탐색을 시작할 정점의 번호  
int visit[1001]; //  방문했던 노드 체크 
int A[1001][1001]; // 인접행렬 값을 받기 위한 행렬   방문시 = 1 미방문 0 
int DFS(int V){
	cout << V << ' '; // 첫 start 정점 번호 출력
    visit[V] = 1; // 방문 하였으므로 visit[start] = 1로 방문 체크
    for (int i = 1; i <= N; i++) // 정점의 갯수대로 반복문을 돌면서 방문을 했거나 인접행렬에 0이 있으면 지나가                                                    고, dfs(i) 재귀
    {
        if (visit[i] == 1 || A[V][i] == 0) 
		continue;
        DFS(i);
    }
    
}
int BFS(int V){
	queue<int> q;
	q.push(V); // 첫 queue에 있는 값 push
    visit[V] = 1; // 정점 방문 
      while (!q.empty()) { //queue가 빌 때까지 while문
       	V = q.front(); 
        cout << V << " ";
        q.pop();
        for (int i = 1; i <= N; i++)
        {
            if (A[V][i] ==1 && visit[i] == 1){
            	continue;
            	q.push(i);
            	visit[i] = 0;
        	}
        }
    }

}
int main(){
	ios_base::sync_with_stdio(0);
	int x,y; // x node, y node
	cin >> N >> M>> V; 
	for(int i = 0; i < M; i++){
		cin >> x >> y;
		A[x][y] = A[y][x] = 1; // 인접행렬의 값이 서로 같아서  
	}
	cout << BFS(V) << endl;
	cout << DFS(V) << endl;
	
	return 0;
}
