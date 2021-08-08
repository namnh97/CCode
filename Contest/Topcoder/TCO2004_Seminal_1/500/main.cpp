#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

class BioScore {
public:
	double maxAvg(vector <string> knownSet){
		vector<int> ex(10);
		int n = knownSet.size();
		map<pair<char, char>, int> P, D;
		P[make_pair('A', 'C')] = P[make_pair('C', 'A')] = 0;
		P[make_pair('A', 'T')] = P[make_pair('T', 'A')] = 1;
        P[make_pair('A', 'G')] = P[make_pair('G', 'A')] = 2;
        P[make_pair('T', 'C')] = P[make_pair('C', 'T')] = 3;
        P[make_pair('G', 'C')] = P[make_pair('C', 'G')] = 4;
        P[make_pair('G', 'T')] = P[make_pair('T', 'G')] = 5;
          
        P[make_pair('A', 'A')] = 6;
        P[make_pair('C', 'C')] = 7;
        P[make_pair('T', 'T')] = 8;
        P[make_pair('G', 'G')] = 9;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				string s = knownSet[i], t = knownSet[j];
				for (int k = 0; k < s.size(); k++){
					ex[P[make_pair(s[k], t[k])]]++;
				}
			}
		}
		sort(ex.begin(), ex.begin() + 6);
		int ret = -10000000;
		for (int i = 1; i <= 10; i++){
			for (int j = 1; j <= 10; j++){
				for (int k = 1; k <= 10; k++){
					for (int l = 1; l <= 10; l++){
						if ((i + j + k + l) % 2 == 0){
							int t = 10 - (i + j + k + l) / 2;
							int v = (-10*ex[0]-10*ex[1]-10*ex[2]+t*ex[3]+10*ex[4]+10*ex[5]) + i*ex[6]+j*ex[7]+k*ex[8]+l*ex[9];
							ret = max(ret, v);
						}
					}
				}
			}
		}
	return (2 * (double) ret) / (n * (n - 1));
	}
};


double test0() {
	string t0[] = {"AAA","AAA","AAC"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BioScore * obj = new BioScore();
	clock_t start = clock();
	double my_answer = obj->maxAvg(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 30.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"ACTGACTGACTG","GACTTGACCTGA"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BioScore * obj = new BioScore();
	clock_t start = clock();
	double my_answer = obj->maxAvg(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = -4.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"ACTAGAGAC","AAAAAAAAA","TAGTCATAC","GCAGCATTC"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BioScore * obj = new BioScore();
	clock_t start = clock();
	double my_answer = obj->maxAvg(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 50.5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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

