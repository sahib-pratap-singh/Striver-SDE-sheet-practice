// Recursive function to print
// left view of a binary tree.
//Time complexity: O(N)
//Space complexity: O(N)
void leftViewUtil(struct Node *root,int level, int *max_level)
{
    // Base Case
    if (root == NULL) return;
 
    // If this is the first Node of its level
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }
 
    // Recur for left subtree first,
    // then right subtree
      leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
     
}

//Iterative method
//Time complexity: O(N)
//Space complexity: O(N)
vector<int> leftView(Node *root)
{
   vector<int> ans;
   if(root==NULL){
       return ans;
   }
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       int n=q.size();
       for(int i=0;i<n;i++){
           Node* cur=q.front();
           q.pop();
           if(i==0){
               ans.push_back(cur->data);
           }
           if(cur->left){
               q.push(cur->left);
           }
           if(cur->right){
               q.push(cur->right);
           }
           
       }
   }
   return ans;
}