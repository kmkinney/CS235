#pragma once

template<typename T>
struct TreeNode
{
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(const T &x, TreeNode *l=NULL, TreeNode *r=NULL)
        : data(x), left(l), right(r) {};
    bool operator==(const TreeNode &right){
        return data == right.data;
    }
    bool operator< (const TreeNode &right){
        return data < right.data;
    }
    bool operator> (const TreeNode &right){
        return data > right.data;
    }
};
