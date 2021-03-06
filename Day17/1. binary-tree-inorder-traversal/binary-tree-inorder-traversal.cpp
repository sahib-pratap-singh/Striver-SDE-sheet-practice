//Approach 1

//Recursive method
//Time complexity: O(N)
//Space complexity: O(N)


class Solution {
public:
    vector<int> v;
    TreeNode* inorder(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        inorderTraversal(root->left);
        v.push_back(root->val);
        inorderTraversal(root->right);
        return root; 
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return v;
    }
};

//Iterative method using stack
//Time complexity: O(N)
//Space complexity: O(N)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* cur=root;
        while(!s.empty()){
            while(cur && cur->left){
                s.push(cur->left);
                cur=cur->left;
            }
            cur=s.top();
            s.pop();
            if(cur!=NULL){
                ans.push_back(cur->val);
                s.push(cur->right);
                cur=cur->right;
            }
        }
        return ans;
    }
};

//Morris traversal
//Time complexity: O(N)
//Space complexity: O(1)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        while(root){
            if(root->left){
                TreeNode* pre=root->left;
                while(pre->right && pre->right!=root)
                    pre=pre->right;
                
                if(pre->right==NULL){
                    pre->right=root;
                    root=root->left;
                }
                else{
                    ans.push_back(root->val);
                    pre->right=NULL;
                    root=root->right;
                }
            }
            else{
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};