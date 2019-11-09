#include <iostream>
#define MAX_SIZE 13
using namespace std;
int lotto[MAX_SIZE];
int combination[MAX_SIZE];
int k;

void DFS(int idx, int cnt){
	if(cnt==6){
		for(int i=0; i<6; i++){
			cout<<combination[i]<<" "; 
		}	
		cout<<"\n";
		return;
	}
	for(int i=idx; i<k; i++){
		combination[cnt] = lotto[i]; //���տ� ���� �ִ� �� 
		DFS(i+1, cnt+1); //��ͷ� ���� ��� ȣ��   
	}
}  

int main (void){
	
	while(cin >>k && k){ //0�� �Է��� ������ �ޱ� 
		for(int i=0; i<k; i++){
			cin>>lotto[i];
		}
		DFS(0,0);//0���� Ž�� 
		cout<<"\n";
	}	
	return 0;
}

