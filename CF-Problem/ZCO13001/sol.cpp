#include<iostream>
#include<algorithm>
#define int64 long long 


using namespace std;

int main(void){
	int n;
	cin >> n;
	int64 a[n];
	for(int i=1; i<=n; i++){
		cin >> a[i];	
	}
	sort(a+1, a+n+1);
	int result = 0;
	for(int i=1; i<=n; i++){
		result -= (n-i) * a[i];
		cout << (n-i) * a[i] << " " ;
		result += (i-1) * a[i];		
		cout << (i-1) * a[i] << endl;
	}
	cout << result;	return 0;
}