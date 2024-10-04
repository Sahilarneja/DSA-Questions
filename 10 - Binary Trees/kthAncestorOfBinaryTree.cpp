// https://www.naukri.com/code360/problems/kth-ancestor-of-a-node-in-binary-tree_842561
BinaryTreeNode<int>* findAncestorHelper(BinaryTreeNode<int>* root, int target, int& K) {
    // Base case: If root is NULL
    if (root == NULL) {
        return NULL;
    }
    
    // If we find the target node, we start returning from here
    if (root->data == target) {
        return root;
    }
    
    // Recur for the left and right subtrees
    BinaryTreeNode<int>* leftAns = findAncestorHelper(root->left, target, K);
    BinaryTreeNode<int>* rightAns = findAncestorHelper(root->right, target, K);

    // If either of them returns a valid node, we decrement K
    if (leftAns != NULL || rightAns != NULL) {
        K--;
        
        // If K becomes 0, this is the Kth ancestor, return the current node
        if (K == 0) {
            return root;
        }

        // Otherwise, propagate the non-null answer upwards
        return leftAns != NULL ? leftAns : rightAns;
    }
    
    return NULL;
}


int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) {
    int K = k;  // To store remaining K during recursion
    BinaryTreeNode<int>* ancestor = findAncestorHelper(root, targetNodeVal, K);
    
    
    if (K > 0 || ancestor == NULL) {
        return -1;
    }
    
    
    return ancestor->data;
}

