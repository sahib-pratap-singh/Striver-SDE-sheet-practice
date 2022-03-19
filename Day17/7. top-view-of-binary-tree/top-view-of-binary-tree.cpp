//Iterative method
//Time complexity: O(N)
//Space complexity: O(N)
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> result;
        if(root==NULL){
            return result;
        }
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        map<int,vector<int>>mp;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                pair<Node*,int> p=q.front();
                q.pop();
                Node* cur=p.first;
                int hd=p.second;
                if(!mp.count(hd))
                    mp[hd].push_back(cur->data);
                if(cur->left){
                    q.push(make_pair(cur->left,hd-1));
                }
                if(cur->right){
                    q.push(make_pair(cur->right,hd+1));
                }
            }
        }
        for(auto it=mp.begin();it!=mp.end();++it){
            for(auto i=it->second.begin();i!=it->second.end();++i){
                result.push_back(*i);
            }
        }
        return result;
    }

};

// Recursive function to print
// top view of a binary tree.
//Time complexity: O(N)
//Space complexity: O(N)

void fillMap(Node* root, int d, int l,
             map<int, pair<int, int> >& m)
{
    if (root == NULL)
        return;
 
    if (m.count(d) == 0) {
        m[d] = make_pair(root->data, l);
    }
    else if (m[d].second > l) {
        m[d] = make_pair(root->data, l);
    }
 
    fillMap(root->left, d - 1, l + 1, m);
    fillMap(root->right, d + 1, l + 1, m);
}
 
// function should print the topView of
// the binary tree
void topView(struct Node* root)
{
 
    // map to store the pair of node value and its level
    // with respect to the vertical distance from root.
    map<int, pair<int, int> > m;
 
    // fillmap(root,vectical_distance_from_root,level_of_node,map)
    fillMap(root, 0, 0, m);
 
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->second.first << " ";
    }
}