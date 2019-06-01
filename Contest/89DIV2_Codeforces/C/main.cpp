#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

int main(void){
	int n, k;
	int t;
	int cnt[11];
	while (cin >> n >> k) {
		string strIn; cin >> strIn;
		string strTmp, strRes;
		int iRes = 10000000, ans;
		int cnt[11];
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; i++) {
			cnt[strIn[i] - '0']++; //map to count the numbers
		}
		for (int i = 0; i < 10; i++) {
			t = k;
			strTmp = strIn;
			t -= cnt[i];
			ans = 0;
			if (t <= 0) {
				iRes = 0;
				strRes = strTmp;
				break;
			} else {
				for (int l = i - 1, r = i + 1; t; l--, r++) {
					if (t && r < 10 && cnt[r]){ // t > 0 
						int iTmp = (cnt[r] % t && cnt[r] < t ? cnt[r] : t);
						t -= iTmp;
						ans += iTmp * (r - i);
						for (int j = 0; j < n && iTmp; j++) {
							if ((strTmp[j] - '0') == r) {
								strTmp[j] = i + '0';
								iTmp--;
							}
						}
					}
					if (t && l >= 0 && cnt[l]) {
						int iTmp = (cnt[l] % t && cnt[l] < t ? cnt[l] : t);
						t -= iTmp;
						ans += iTmp * (i - l);
						for (int j = n - 1; j >= 0 && iTmp; j--) {
							if ((strTmp[j] - '0') == l) {
								strTmp[j] = i + '0';
								iTmp--;
							}
						}
					}
				}
			}
			if (iRes > ans) {
				iRes = ans;
				strRes = strTmp;
			} else if (iRes == ans) if (strRes > strTmp) {
				strRes = strTmp;
			}
		}
		cout << iRes << endl << strRes;
		cout << endl;
	}
	return 0;
}
