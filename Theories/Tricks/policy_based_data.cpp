// https://codeforces.com/blog/entry/11080
#include <ext/pb_ds/assoc_container.hpp> //common file
#include <ext/pb_ds/tree_policy.hpp> //including tree_order_statistics_node_update

#include <ext/pb_ds/detail/standard_policies.hpp>

//example to declare this structure

template<
	typename Key, //key type
	typename Mapped, //Mapped-policy
	typename Cmp_Fn = std::less<Key>, //Key comparison function
	//tag class denoting a tree structure which we will use (rb_tree_tab, splay_tree_tag, ov_tree_tag)
	typename Tag = rb_tree_tag, //Specifies which underlying data structure to use
	template<
		typename Const_Node_Iterator,
		typename Node_Iterator,
		typename Cmp_Fn_,
		typename Allocator_>
		class Node_Update = null_node_update, //A policy for updating node invariants 
		typename Allocator = std::allocator<char> >
		class tree;

//first example 
typedef tree<
	int, 
	null_type,
	less<int>
	rb_tree_tag,
	tree_order_statistics_node_update>
	ordered_set;
