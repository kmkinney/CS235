#pragma once

template<typename T>
struct TreeNode{
    T data;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    TreeNode(const T &node_data, TreeNode *p,
             TreeNode *l, TreeNode *r) : data(node_data), parent(p), left(l), right(r){};
};