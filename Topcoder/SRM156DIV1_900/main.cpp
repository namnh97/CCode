#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

class PathFinding {
public:
	int minTurns(vector <string>);
};

int PathFinding::minTurns(vector <string> board) {
	typedef struct state {
      int ax, ay, bx, by;
      int step;
    } state;

    state s;
    s.ax = s.ay = s.bx = s.by = -1;
    bool visited[20][20][20][20] = {false};
    int rows = board.size(), cols = board[0].size();

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (board[i][j] == 'A') {
          s.ax = i; s.ay = j;
        }
        if (board[i][j] == 'B') {
          s.bx = i; s.by = j;
        }
      }
    }

    // Invalid board in first place.
    if (s.ax == -1 || s.bx == -1) return -1;
    s.step = 0;

    queue<state> q;
    q.push(s);
    visited[s.ax][s.ay][s.bx][s.by] = true;
    while (!q.empty()) {
      state node = q.front();
      q.pop();
      if (node.ax == s.bx && node.ay == s.by && node.bx == s.ax &&
          node.by == s.ay) {
        return node.step;
      }

      for (int dx1 = -1; dx1 <= 1; ++dx1) {
        for (int dy1 = -1; dy1 <= 1; ++dy1) {
          for (int dx2 = -1; dx2 <= 1; ++dx2) {
            for (int dy2 = -1; dy2 <= 1; ++dy2) {
              int axx = node.ax + dx1;
              int ayy = node.ay + dy1;
              int bxx = node.bx + dx2;
              int byy = node.by + dy2;

              // Out of board.
              if (axx < 0 || axx >= rows || ayy < 0 || ayy >= cols ||
                  bxx < 0 || bxx >= rows || byy < 0 || byy >= cols) {
                continue;
              }

              if (board[axx][ayy] == 'X' || board[bxx][byy] == 'X') {
                continue; // obstacle.
              }

              // Crossed line (both moves)
              if (axx == node.bx && ayy == node.by && bxx == node.ax && byy == node.ay) {
                continue;
              }
              // Cross line (a single side move)
              if (axx == bxx && ayy == byy) continue;

              if (visited[axx][ayy][bxx][byy]) continue;
              state ns;
              ns.step = node.step + 1;
              ns.ax = axx, ns.ay = ayy, ns.bx = bxx, ns.by = byy;
              visited[axx][ayy][bxx][byy] = true;
              q.push(ns);
            }
          }
        }
      }
    }
    return -1;
}

double test0() {
	string t0[] = {"....",
 ".A..",
 "..B.",
 "...."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PathFinding * obj = new PathFinding();
	clock_t start = clock();
	int my_answer = obj->minTurns(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	string t0[] = {"XXXXXXXXX",
 "A...X...B",
 "XXXXXXXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PathFinding * obj = new PathFinding();
	clock_t start = clock();
	int my_answer = obj->minTurns(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
	string t0[] = {"XXXXXXXXX",
 "A.......B",
 "XXXXXXXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PathFinding * obj = new PathFinding();
	clock_t start = clock();
	int my_answer = obj->minTurns(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
double test3() {
	string t0[] = {"XXXXXXXXX",
 "A.......B",
 "XXXX.XXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PathFinding * obj = new PathFinding();
	clock_t start = clock();
	int my_answer = obj->minTurns(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 8;
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
double test4() {
	string t0[] = {"...A.XXXXX.....",
 ".....XXXXX.....",
 "...............",
 ".....XXXXX.B...",
 ".....XXXXX....."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PathFinding * obj = new PathFinding();
	clock_t start = clock();
	int my_answer = obj->minTurns(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 13;
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
double test5() {
	string t0[] = {"AB.................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "...................X",
 ".XXXXXXXXXXXXXXXXXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PathFinding * obj = new PathFinding();
	clock_t start = clock();
	int my_answer = obj->minTurns(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 379;
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
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
