#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
queue<int>q;
 int main(){
 	int n, k; // n는 사람의 총 인원, k번째 사람을 제거  
	cout << "사람의 총 인원 수:" ;
 	cin >> n;
 	cout << "k번째 사람제거 :";
 	cin >> k;
 	//K번째가 아닌 사람들을 ,front 에서 나간 후 다시 넣어 
    for(int i = 0; i <= n; i++){
    	q.push(i); 
	}
    for(int i = 0; i < n-1; i++){
    	for (int j = 0; j < k -1 ; j++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();

	}     
    cout << endl;
 	return 0; 
 }
 //front가 k의 배수번째가 아닌 경우, pop(제거)한 후 push(맨 뒤로 보낸다)을 한다.
 //k의 배수번째인 경우, pop(제거)하며 출력한다.
 //queue가 공백이 될때까지 1-2 번을 반복하여 실행한다.
