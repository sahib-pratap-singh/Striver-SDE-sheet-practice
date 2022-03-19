//Iterative method
//Time complexity: O(N)
//Space complexity: O(N)
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> result;
        if(root==NULL){
            return result;
        }
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        map<int,int>mp;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                pair<Node*,int> p=q.front();
                q.pop();
                Node* cur=p.first;
                int hd=p.second;
                mp[hd]=cur->data;
                if(cur->left){
                    q.push(make_pair(cur->left,hd-1));
                }
                if(cur->right){
                    q.push(make_pair(cur->right,hd+1));
                }
            }
        }
        for(auto it=mp.begin();it!=mp.end();++it){
            
            result.push_back(it->second);
            
        }
        return result;
    }
};


// Recursive function to print
// bottom view of a binary tree.
//Time complexity: O(N)
//Space complexity: O(N)

void printBottomViewUtil(Node * root, int curr, int hd, map <int, pair <int, int>> & m)
{
    // Base case
    if (root == NULL)
        return;
     
    // If node for a particular
    // horizontal distance is not
    // present, add to the map.
    if (m.find(hd) == m.end())
    {
        m[hd] = make_pair(root -> data, curr);
    }
    // Compare height for already
    // present node at similar horizontal
    // distance
    else
    {
        pair < int, int > p = m[hd];
        if (p.second <= curr)
        {
            m[hd].second = curr;
            m[hd].first = root -> data;
        }
    }
     
    // Recur for left subtree
    printBottomViewUtil(root -> left, curr + 1, hd - 1, m);
     
    // Recur for right subtree
    printBottomViewUtil(root -> right, curr + 1, hd + 1, m);
}
 
void printBottomView(Node * root)
{
     
    // Map to store Horizontal Distance,
    // Height and Data.
    map < int, pair < int, int > > m;
     
    printBottomViewUtil(root, 0, 0, m);
     
     // Prints the values stored by printBottomViewUtil()
    map < int, pair < int, int > > ::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
    {
        pair < int, int > p = it -> second;
        cout << p.first << " ";
    }
}