#include <iostream>
using namespace std;


int main(void) {
int n,k,m =0;
int a[11];
	cin>>n>>k;
	
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}

	for(int i=n; i>0; i--){
		m+=k /a[i];
		k%=a[i];
	}
	cout<<m;
}

