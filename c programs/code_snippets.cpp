#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define debug 1
#define ll long long

void traverse(vector<int>& ans , TreeNode* root){
    if(root == nullptr){return ;}
    ans.push_back(root->val);
    traverse(ans , root->left);
    traverse(ans , root->right);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    traverse(ans , root);
    return ans;
}


void traverse_inorder(vector<int>& ans , TreeNode* root){
    if(root==nullptr){return ;}
    traverse_inorder(ans , root->left);
    ans.push_back(root->val);
    traverse_inorder(ans, root->right);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    traverse_inorder(ans , root);
    return ans;
}


void traverse_postorder(vector<int>& ans , TreeNode* root){
    if(root==nullptr){return ;}
    traverse_postorder(ans , root->left);
    
    traverse_postorder(ans, root->right);
        ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    traverse_postorder(ans , root);
    return ans;
}


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;

    if(root!=NULL) {q.push(root);}
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left!=NULL) {q.push(node->left);}
            if(node->right != NULL) {q.push(node->right);}
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}



vector<int> preorderTraversal_usingstack(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    if(root!=NULL){st.push(root);}
    while(!st.empty()){
    root = st.top();
    st.pop();
    ans.push_back(root->val);
    if(root->right !=NULL){st.push(root->right);}
    if(root->left != NULL){st.push(root->left);}

    }
    return ans;
}


vector<int> inorderTraversal_usingstack(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        //if(root!=NULL){st.push(root);}
        TreeNode* node = root;
        while(true){
            if(node!=NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()==true){break;}
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right ;
            }
        }
        return ans;
    }