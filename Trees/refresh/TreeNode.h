#pragma once

template<typename T>
struct TreeNode{
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(const T &node_data, TreeNode *l = NULL, TreeNode *r = NULL) 
            : data(node_data), left(l), right(r){};
};