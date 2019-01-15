#include<bits\stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int64 long long

using namespace std;
using namespace __gnu_pbds;

	  template<
	  typename Key, // Key type
	  typename Mapped, // Mapped-policy
	  typename Cmp_Fn = std::less<Key>, // Key comparison functor
	  typename Tag = rb_tree_tag, // Specifies which underlying data structure to use
	  template<
	  typename Const_Node_Iterator,
	  typename Node_Iterator,
	  typename Cmp_Fn_,
	  typename Allocator_>
	  class Node_Update = null_node_update, // A policy for updating node invariants
	  typename Allocator = std::allocator<char> > // An allocator type
	  class tree;

int sum(){ return 0;}

template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

void sol(){
    cout << __builtin_popcount(5); //tra ve so bit 1 su dung
    cout << __builtin_clz(5); //tra ve so bit 0 khong su dung cho den 1
    cout << __builtin_ctz(5); //tra ve so bit 0 khong su dung phia sau 1
    cout << __builtin_ffs(5); //tra ve bit 1 dau tien
    cout << endl;
    string str = "Hello\tWorld\n";
    string r_str = R"(Hello\tWorld\n)";
    cout << str << r_str;
}

//====================================================
//code for debug
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

void debug() {
	int a = 4, b = 8, c = 9;
	error(a, b, c);
}

int main()
{
    #ifndef ONELINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif // ONELINE_JUDGE
    sol();
    return 0;
}
