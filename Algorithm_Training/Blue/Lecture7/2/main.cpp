//https://www.hackerrank.com/challenges/qheap1/problem
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
void debugOut() {
	cerr << endl;
}

vector<ll> heap;
void minHeapify(ll index) {
	ll smallest = index;
	ll left = 2 * index + 1;
	ll right = 2 * index + 2;
	if (left < (int)heap.size() && heap[left] < heap[smallest]) {
		smallest = left;
	}
	if (right < (int)heap.size() && heap[right] < heap[smallest]) {
		smallest = right;
	}
	if (smallest != index) {
		swap(heap[smallest], heap[index]);
		minHeapify(smallest);
	}
}

void push(ll value) {
	heap.push_back(value);
	ll index = heap.size() - 1;
	while (index != 0 && heap[(index - 1) / 2] > heap[index]) {
		swap(heap[index], heap[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}

ll search(ll value) {
	for (int i = 0; i < (int)heap.size(); i++) {
		if (heap[i] == value) {
			 return i;
		}
	}
	return -1;
}
void deleteValue(ll value) {
	ll index = search(value);
	if (index != -1) {
		heap[index] = heap[heap.size() - 1];
		heap.pop_back();
		minHeapify(index);
		while (index != 0 && heap[(index - 1) / 2] > heap[index]) {
			swap(heap[index], heap[(index - 1) / 2]);
			index = (index - 1) / 2;
		}
	}
}

int getMin() {
	if (!heap.empty()) {
		return heap[0];
	}
	return -1;
}

void solve() {
	ll q; cin >> q;
	while (q--) {
		ll op;
		cin >> op;
		if (op == 1) {
			ll element; cin >> element;
			push(element);
		} else if (op == 2) {
			ll element; cin >> element;
			deleteValue(element);
		} else {
			cout << getMin() << endl;
		}
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

