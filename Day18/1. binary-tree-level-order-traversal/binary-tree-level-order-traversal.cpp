//Iterative method
//Time complexity: O(N)
//Space complexity: O(N)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> v;
            for(int i=0;i<n;i++){
                TreeNode* cur=q.front();
                q.pop();
                v.push_back(cur->val);
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};

// Recursive function to print
// level order view of a binary tree.
//Time complexity: O(N)
//Space complexity: O(N)

class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    vector<int> levelorder(TreeNode* root, vector<int> &v,int k){
        if(root==NULL){
            return v;
        }
        if(k==1){
            v.push_back(root->val);
        }
        levelorder(root->left,v,k-1);
        levelorder(root->right,v,k-1);
        return v;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int h=height(root);
        for(int i=1;i<=h;i++){
            vector<int> v;
            vector<int> result=levelorder(root,v,i);
            ans.push_back(result);
        }
        return ans;
    }
};

//Recursive JAVA
public List<List<Integer>> levelOrder(TreeNode root) {
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    levelHelper(res, root, 0);
    return res;
}

public void levelHelper(List<List<Integer>> res, TreeNode root, int height) {
    if (root == null) return;
    if (height >= res.size()) {
        res.add(new LinkedList<Integer>());
    }
    res.get(height).add(root.val);
    levelHelper(res, root.left, height+1);
    levelHelper(res, root.right, height+1);
}