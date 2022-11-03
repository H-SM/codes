#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int maxDepth(TreeNode *root)
{
    return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
}



int main(){
    vector<string> str={"hello","hehe","he"};
    string x=longestCommonPrefix(str);
    cout<<x<<endl;
}