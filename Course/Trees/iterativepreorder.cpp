vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root==NULL) return preorder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            if(root->right) st.push(root->right);
            if(root->left) st.push(root->left);
            preorder.push_back(root->val);
        }
        return preorder;
    }