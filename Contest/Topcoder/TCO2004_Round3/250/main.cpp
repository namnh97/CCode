#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;
struct interval{
	int s, f;
	interval(int s, int f) : s(s), f(f){}
};

bool operator<(interval a, interval b){
	return a.f < b.f || (a.f == b.f && a.s < b.s);
}

class Boxing {
public:
	int maxCredit(vector <int>, vector <int>, vector <int>, vector <int>, vector <int>);
};

int Boxing::maxCredit(vector <int> a, vector <int> b, vector <int> c, vector <int> d, vector <int> e) {
	set<interval> S;
	string s = "00111";
	do{
		vector<vector<int>> t(3);
		int k = 0;
		for (int i = 0; i < 5; i++){
			if(s[i] == '1'){
				switch(i){
					case 0:
					t[k] = a;
					break;
					
					case 1:
					t[k] = b;
					break;

					case 2:
					t[k] = c;
					break;

					case 3:
					t[k] = d;
					break;

					case 4:
					t[k] = e;
					break;
				}
			k += 1;
			}
		}
		for (int x : t[0]){
			for (int y : t[1]){
				for (int z : t[2]){
					int mn = min(x, min(y, z)), mx = max(x, max(y, z));
					if(mx - mn <= 1000){
						S.insert(interval(mn, mx));
					}
				}
			}
		}
	}while(next_permutation(s.begin(), s.end()));
	int lf = -1, r = 0;
	cout << " ===== " << endl;
	for (interval t : S){
		cout << t.s << " " << t.f << endl;
		if (lf < t.s){
			lf = t.f;
			r++;
		}
	}
	return r;
}



double test0() {
	int t0[] = {1,2,3,4,5,6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,3,4,5,6,7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,2,3,4,5,6};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {0,1,2};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {1,2,3,4,5,6,7,8};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	Boxing * obj = new Boxing();
	clock_t start = clock();
	int my_answer = obj->maxCredit(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {100,200,300,1200,6000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	vector <int> p1;
	int t2[] = {900,902,1200,4000,5000,6001};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {0,2000,6002};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {1,2,3,4,5,6,7,8};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	Boxing * obj = new Boxing();
	clock_t start = clock();
	int my_answer = obj->maxCredit(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {5000,6500};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {6000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {6500};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {6000};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {0,5800,6000};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	Boxing * obj = new Boxing();
	clock_t start = clock();
	int my_answer = obj->maxCredit(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
