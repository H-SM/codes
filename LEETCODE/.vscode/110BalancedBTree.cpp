#include<bits/stdc++.h>
#include<string.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   };

    /*
    bool isSameTree(TreeNode* p, TreeNode* q) {
         bool isbalance(TreeNode* p, TreeNode* q){
    if(p==NULL&&q==NULL)return true;
    if(p==NULL||q==NULL)return false;
    return isbalance(p->right , q->right) && isbalance(p->left , q->left);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        if(root->right==NULL&&root->left==NULL)return true;
        if(root->right==NULL||root->left==NULL)return false;
        return isbalance(root->right , root->left);
    }
    }

    */
   bool ans;
    int checkBalance(TreeNode* root){
        if(!root)
            return 0;
        if(!ans) // if Answer is already False then return it.
            return 0;
        int leftSubTree = checkBalance(root->left);
        int rightSubTree = checkBalance(root->right);
        if(abs(leftSubTree-rightSubTree) > 1){
            ans = false;
        }
        return 1 + max(leftSubTree, rightSubTree);
    }
    bool isBalanced(TreeNode* root){
        ans = true;
        int temp = checkBalance(root);
        return ans;
    }
int main(){
    vector<string> str={"hello","hehe","he"};
    string x=longestCommonPrefix(str);
    cout<<x<<endl;
}