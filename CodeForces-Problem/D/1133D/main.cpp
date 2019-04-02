#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

map<pair<int, int>, int> m;
int n;
int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main(void){
	cin >> n;
	int a[n];
	int b[n];
	int cnt = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		cin >> b[i];
		if (a[i] == 0){
			if (b[i] == 0) cnt++;
			continue;
		}
	int gcdNumber = gcd(a[i], b[i]);
		int num = a[i] / gcdNumber;
		int den = b[i] / gcdNumber;
		if (m[make_pair(num, den)] == 0){
			m[make_pair(num, den)] = 1;
		} else {
			m[make_pair(num, den)]++;
		}
	}
	map<pair<int, int>, int>::iterator it;
	int max = 0;
	for (it = m.begin(); it != m.end(); it++){
		if(it->second > max){
			max = it->second;
		}
	}
	printf("%d", max + cnt);
	return 0;
}
