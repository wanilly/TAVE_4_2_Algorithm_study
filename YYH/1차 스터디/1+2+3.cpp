#include <iostream>
using namespace std;
int dpf(int n);
int dp[1000] = {0};
int main (void) {
	int t;
	int n;
		
	cin>>t;
	
	while(t--){
		cin>>n;
		cout<<dpf(n)<<"\n";
	}
	
}

int dpf(int n){
	if(n<0) return 0;
	if(n<=1) return 1; 
	if(dp[n]) return dp[n];
	return dp[n] = dpf(n-1)+dpf(n-2)+dpf(n-3);
}
