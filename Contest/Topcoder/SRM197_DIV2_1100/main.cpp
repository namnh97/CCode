#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

class QuickSums {
public:
	int minSums(string numbers, int sum) {
		int V[10][10][101];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 101; k++) {
					V[i][j][k] = 100000;
				}
			}
		}
		int N = numbers.size(); 
		for (int q = 0; q < N; q++) {
			for(int i = 0; i < N - q; i++) {
				string st = numbers.substr(i, q + 1);
				if(atoi(st.c_str()) < 101) {
					V[i][i + q][atoi(st.c_str())] = 0;
				}
			}
		}
        for(int l=1;l<N;l++) {
            for(int i=0;i<N-l;i++) {
                int j=i+l;
                for(int k=i;k<j;k++)
                    for(int q1=0;q1<100;q1++)
                        for(int q2=0;q2+q1<=100;q2++)
                            if(V[i][k][q1]<100000 && V[k+1][j][q2] < 100000)
                                V[i][j][q1+q2]=min(V[i][j][q1+q2],V[i][k][q1]+V[k+1][j][q2]+1);
			}
		}
		if(V[0][N - 1][sum] < 100000) return V[0][N - 1][sum];
		return -1;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1;
	cout << "]" << endl;
	QuickSums *obj;
	int answer;
	obj = new QuickSums();
	clock_t startTime = clock();
	answer = obj->minSums(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	string p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = "99999";
	p1 = 45;
	p2 = 4;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "1110";
	p1 = 3;
	p2 = 3;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "0123456789";
	p1 = 45;
	p2 = 8;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "99999";
	p1 = 100;
	p2 = -1;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "382834";
	p1 = 100;
	p2 = 2;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "9230560001";
	p1 = 71;
	p2 = 4;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING