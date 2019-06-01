#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

typedef vector<int> vi;

class GoldMine {
public:
	int value(string m, int k){
		int cost = 0;
		vector<int> v(7);
       	sscanf(m.c_str(), "%d, %d, %d, %d, %d, %d, %d", &v[0], &v[1], &v[2], &v[3], &v[4], &v[5], &v[6]);
		for (int i = 0; i <= 6; i++) {
			if (k < i) {
				cost += v[i] * k * 60;
			}
			else {
				cost += v[i] * (50 * i - 20 * (k - i));	
			}
		}
        return cost;
	}
	vector <int> getAllocation(vector <string> mines, int miners) {
           int C[55][8], D[55][8];
           int P[55];
           int n = mines.size();
           for(int i = 0; i < n; i++) {
           	for(int k = 0; k <= 6; k++) {
              C[i][k] = value(mines[i], k);
            }
           }
          fill(P, P+55, 1);
          for(int i = 0; i < n; i++)
            for(int j = 1; j <= 6; j++)
              D[i][j] = C[i][j] - C[i][j-1];

          int s = 0;
          while(s < miners){
            int mi = 0, maxv = -1000000;
            for(int i = 0; i < n; i++){
              if(P[i] <= 6 && D[i][P[i]] > maxv){
                maxv = D[i][P[i]];
                mi = i;
              }
            }
            P[mi]++;
            s++;
          }
          vi ret;
          for(int i = 0; i < n; i++){
            ret.push_back(P[i]-1);
            cout<<ret[i]<<" ";
          }
          cout<<endl;
          return ret;
	}
};

double test0() {
	string t0[] = { "000, 030, 030, 040, 000, 000, 000",
  "020, 020, 020, 010, 010, 010, 010" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 4;
	GoldMine * obj = new GoldMine();
	clock_t start = clock();
	vector <int> my_answer = obj->getAllocation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = { 2,  2 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = { "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 8;
	GoldMine * obj = new GoldMine();
	clock_t start = clock();
	vector <int> my_answer = obj->getAllocation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = { 6,  2,  0,  0,  0 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = { "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 30;
	GoldMine * obj = new GoldMine();
	clock_t start = clock();
	vector <int> my_answer = obj->getAllocation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = { 4,  4,  4,  4,  4,  4,  4,  2,  0,  0 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = { "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 56;
	GoldMine * obj = new GoldMine();
	clock_t start = clock();
	vector <int> my_answer = obj->getAllocation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = { 2,  2,  2,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = { "100, 000, 000, 000, 000, 000, 000",
  "090, 010, 000, 000, 000, 000, 000",
  "080, 020, 000, 000, 000, 000, 000",
  "075, 025, 000, 000, 000, 000, 000",
  "050, 050, 000, 000, 000, 000, 000",
  "025, 075, 000, 000, 000, 000, 000",
  "020, 080, 000, 000, 000, 000, 000",
  "010, 090, 000, 000, 000, 000, 000",
  "000, 100, 000, 000, 000, 000, 000",
  "000, 090, 010, 000, 000, 000, 000",
  "000, 080, 020, 000, 000, 000, 000",
  "000, 075, 025, 000, 000, 000, 000",
  "000, 050, 050, 000, 000, 000, 000",
  "000, 025, 075, 000, 000, 000, 000",
  "000, 020, 080, 000, 000, 000, 000",
  "000, 010, 090, 000, 000, 000, 000",
  "000, 000, 100, 000, 000, 000, 000",
  "000, 000, 090, 010, 000, 000, 000",
  "000, 000, 080, 020, 000, 000, 000",
  "000, 000, 075, 025, 000, 000, 000",
  "000, 000, 050, 050, 000, 000, 000",
  "000, 000, 025, 075, 000, 000, 000",
  "000, 000, 020, 080, 000, 000, 000",
  "000, 000, 010, 090, 000, 000, 000",
  "000, 000, 000, 100, 000, 000, 000",
  "000, 000, 000, 100, 000, 000, 000",
  "000, 000, 000, 090, 010, 000, 000",
  "000, 000, 000, 080, 020, 000, 000",
  "000, 000, 000, 075, 025, 000, 000",
  "000, 000, 000, 050, 050, 000, 000",
  "000, 000, 000, 025, 075, 000, 000",
  "000, 000, 000, 020, 080, 000, 000",
  "000, 000, 000, 010, 090, 000, 000",
  "000, 000, 000, 000, 100, 000, 000",
  "000, 000, 000, 000, 090, 010, 000",
  "000, 000, 000, 000, 080, 020, 000",
  "000, 000, 000, 000, 075, 025, 000",
  "000, 000, 000, 000, 050, 050, 000",
  "000, 000, 000, 000, 025, 075, 000",
  "000, 000, 000, 000, 020, 080, 000",
  "000, 000, 000, 000, 010, 090, 000",
  "000, 000, 000, 000, 000, 100, 000",
  "000, 000, 000, 000, 000, 090, 010",
  "000, 000, 000, 000, 000, 080, 020",
  "000, 000, 000, 000, 000, 075, 025",
  "000, 000, 000, 000, 000, 050, 050",
  "000, 000, 000, 000, 000, 025, 075",
  "000, 000, 000, 000, 000, 020, 080",
  "000, 000, 000, 000, 000, 010, 090",
  "000, 000, 000, 000, 000, 000, 100" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 150;
	GoldMine * obj = new GoldMine();
	clock_t start = clock();
	vector <int> my_answer = obj->getAllocation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = { 0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  6,  6 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
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
	
//	time = test3();
	if (time < 0)
		errors = true;
	
//	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
