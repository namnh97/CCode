#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

int main(void){
	int testCase; cin >> testCase;
	while(testCase--){
		char input[20];
		scanf("%s", input);
		int m = strlen(input);
		int C = 1;
		while(C < m && isdigit(input[C])){
			++C;
		}
		if(C > 1 && C < m){
			int col = 0;
			for(int i = C + 1; i < m; i++){
				col = col * 10 + (input[i] - '0');
			}
			int pow = 26;
			while(col > pow){
				col -= pow;
				pow *= 26;
			}
			col -= 1;
			while(pow != 1){
				pow /= 26;
				printf("%c", char((col / pow)+ 'A'));
				col %= pow;
			}
			input[C] = 0;
			printf("%s\n", input + 1);
		}
		else {
			int col = 0, val = 0, pow = 1;
			int i = 0;
			while(isalpha(input[i])){
				col += pow;
				pow *= 26;
				val = val * 26 + input[i] - 'A';
				i++;
			}
			col += val;
			printf("R%sC%d\n", input + i, col);
		}
	}
	return 0;
}
