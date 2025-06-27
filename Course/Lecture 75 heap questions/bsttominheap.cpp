void inorderTraversal(Node* root, vector<int>& arr)
{
    if (root == NULL)
        return;
 
    // first recur on left subtree
    inorderTraversal(root->left, arr);
 
    // then copy the data of the node
    arr.push_back(root->data);
 
    // now recur for right subtree
    inorderTraversal(root->right, arr);
}
 
// function to convert the given BST to MIN HEAP
// performs preorder traversal of the tree
void BSTToMinHeap(Node* root, vector<int> arr, int* i)
{
    if (root == NULL)
        return;
 
    // first copy data at index 'i' of 'arr' to
    // the node
    root->data = arr[++*i];
 
    // then recur on left subtree
    BSTToMinHeap(root->left, arr, i);
 
    // now recur on right subtree
    BSTToMinHeap(root->right, arr, i);
}