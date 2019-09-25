#include <iostream>
using namespace std;
int sugar (int n);

int main (void){
	ios_base::sync_with_stdio(0);


	int n;
	
	cin>>n;
	if(n<3 ||n>5000)
	return -1;
	
	cout<<sugar(n)<<"\n";
	
	}

int sugar (int n){
	
	int origin = n;
	int five=0; //5kg의 쌀을 가져갈 갯수 

	if (n<5) { //5kg의 가져갈 수 없는 경우 
		if(n==3) return 1;	 
		else return -1;
	}
	if(n%5==0)
		return n/5; 

	if(n>5){ //5kg의 쌀을 가져갈 수 있는지 없는지 판별 
		
		while((n-5)>0){				
			n -= 5;
			five++;
			
			if(n%3==0 && n<=5){ //5kg를 가져가고 나머지가 3의 배수면 계산 끝 
				return	five + (n/3);
				}

			if(n%3 !=0 && n<=5){ //나머지의 배수가 3이 아닐 때 5를 한번 빼고 3의 배수가 되는 지 확인 
				n += 5;
				if(n%3==0)
					return	(five-1) + (n/3);	
				if(origin %3 ==0) //5가 넘지만 5kg로 가져갈 수 없는 경우 
					return n/3;		
				}	
			 

		}
			
	}
}
