#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/trie_policy.hpp>

#define int64 long long

using namespace std;
using namespace __gnu_pbds;

typedef trie<
string,
null_type,
trie_string_access_traits<>,
pat_trie_tag,
trie_prefix_search_node_update>
pref_trie;

void sol(){
    pref_trie base;
    base.insert("sun");
    string x;
    while(cin >> x){
        if(x[0] == '?'){
            cout << x.substr(1) << endl;
            auto range=base.prefix_range(x.substr(1));
            int t = 0;
            for(auto it=range.first; t<20 && it != range.second; it++, t++){
                cout << " " << *it << endl;
            }
        }
        else{
            base.insert(x.substr(1));
        }
    }
}


int main()
{
    #ifndef ONELINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif // ONELINE_JUDGE
    sol();
    return 0;
}
