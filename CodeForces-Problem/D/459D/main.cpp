#include<bits\stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int64 long long

using namespace std;
using namespace __gnu_pbds;

template<class Node_CItr, class Node_Itr, class Cmp_Fn, class _Alloc>
struct my_node_update{
    typedef int metadata_type;

    virtual Node_CItr
    node_begin() const = 0;
    virtual Node_CItr
    node_end() const = 0;

    int order_of_key(pair<int, int> x ){
        int ans = 0;
        auto it = node_begin();
        while(it != node_end()){
            auto l = it.get_l_child();
            auto r = it.get_r_child();
            if(Cmp_Fn()(x, **it)){
                it = l;
            }
            else{
                ans++;
                if(l != node_end()) ans += l.get_metadata();
                it = r;
            }
        }
        return ans;
    }

    void operator()(Node_Itr it, Node_CItr end_it){
        auto l = it.get_l_child();
        auto r = it.get_r_child();
        int left = 0, right = 0;
        if(l != end_it) left = l.get_metadata();
        if(r != end_it) right = r.get_metadata();
        const_cast<int&>(it.get_metadata()) = left+right+1;
    }
};

tree<
pair<int, int>,
null_type,
less<pair<int ,int >>,
rb_tree_tag,
my_node_update> me;

void sol(){

}

int main()
{
    #ifndef ONELINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif // ONELINE_JUDGE
    sol();
    return 0;
}
