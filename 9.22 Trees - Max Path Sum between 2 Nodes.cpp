//https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/


//Always think about the return type of the dfs for questions related to tree, then the question will become straight-forward


class Solution {
public:

    /*
        Note, path is always going to be like this
          /\                            /                           \
         /  \           OR             /                OR           \
        /    \                        /                               \

       \
        \       Such a path isn't allowed as each node must be traversed only once
        /\

    */

    /*
        In questions relating to Trees, always try to think about the return type of the dfs, thenn the question will be straight forward
    */

    int ans=INT_MIN;

    int dfs(TreeNode* root){

        if(!root) return 0;

        int inLeft = dfs(root->left);
        int inRight = dfs(root->right);
        int maxIncludingRoot = root->val + max({inLeft,inRight,0});

        ans = max({ans,maxIncludingRoot,inLeft+inRight+root->val});
        return maxIncludingRoot;


    }

    int maxPathSum(TreeNode* root) {
        int temp = dfs(root);
        return ans;
    }
};
