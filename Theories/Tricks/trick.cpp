// codeforces.com/blog/entry/15643/
// 1
// tip for declare stl
pair<int, int> p;
p = {3, 4};

// more complex pair 
pair<int, pair<char, long long> > p;
p = {3, {'a', 8ll}};

// more examples
deque<vector<pair<int, int>>> d;
d = {{{3, 4}, {5, 6}, {{1,2}, {3,4}}}};
for(auto i : d){
	for (auto j : i){
		cout << j.first << " " << j.second << '\n';
	}
}

//2 name of argument in macros
#define what_is(x) cerr << #x << " is" << x << endl;
int a_variable = 15;
what_is(a_variable);
//print "a_variable is 15"


//3 hidden function
