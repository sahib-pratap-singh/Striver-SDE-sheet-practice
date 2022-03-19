//Approach 1

//Time complexity: O(N)
//Space complexity: O(N)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root==p or root==q){
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL and right!=NULL){
            return root;
        }
        if(left==NULL){
            return right;
        }
        return left;
    }
};

//Approach 2
//Iterative solution

//Time Complexity: O(N)
//Space complexity: O(N)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> nodestack;
        unordered_map<TreeNode*,TreeNode*> parent;
        
        nodestack.push(root);
        parent[root]=NULL;
        
        while(!parent.count(p) || !parent.count(q)){
            TreeNode* cur=nodestack.top();
            nodestack.pop();
            
            if(cur->left!=NULL){
                parent[cur->left]=cur;
                nodestack.push(cur->left);
            }
            if(cur->right!=NULL){
                parent[cur->right]=cur;
                nodestack.push(cur->right);
            }
        }
        
        set<TreeNode*> ancestor;
        while(p!=NULL){
            ancestor.insert(p);
            p=parent[p];
        }
        while(!ancestor.count(q)){
            q=parent[q];
        }
        return q;
    }
};

//Approach 3

//Time complexity: O(N)
//Space complexity: O(N)
class solution {
public:
int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return dfsHeight (root) != -1;
    }
};