#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
    priority_queue <int, vector<int>, greater<int> >q;
	//가장 작은 값을 front에 넣기 위해 우선 순위 큐 선언
	//greater내림차 
    int x ,n;
    cin >> n;
    
	for(int i = 0; i < n; i++){
        cin >> x;
        if (x == 0)
        {
            if (q.empty()) {
			 cout << '0'<< endl;
			}
            else{ 
				cout << q.top() << endl; 
				q.pop(); 
			}
        }
        else{
            q.push(x);
    	}
	}
    return 0;
}
/*1. 수가 0일때
  - 비어있으면 0출력
  - 비어있지 않으면 q.pop
    2. 수가 0이 아니면 q.push*/


