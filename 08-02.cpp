class Solution {
public:
    bool leaf(Node * root) {
        return !root -> left && !root -> right;
    }
    
    void addleft(Node* root,vector<int>&ans){
        Node* curr=root->left;
        while(curr){
            if(!leaf(curr)) ans.push_back(curr->data);
            if(curr->left) curr=curr->left;
            else curr=curr->right;
        }
    }
    void addright(Node* root,vector<int>&ans){
        Node* curr=root->right;
        vector<int>temp;
        while(curr){
            if(!leaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr=curr->right;
            else curr=curr->left;
        }
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }
    
    void addleaf(Node* root,vector<int>&ans){
        if(leaf(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left) addleaf(root->left,ans);
        if(root->right) addleaf(root->right,ans);
    }
    vector <int> boundaryTraversal(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL) return ans;
        if(!leaf(root)) ans.push_back(root->data);
        addleft(root,ans);
        addleaf(root,ans);
        addright(root,ans);
        
        return ans;
    }
};