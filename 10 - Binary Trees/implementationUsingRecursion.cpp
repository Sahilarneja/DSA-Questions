#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    // Function to create a tree
    Node* createTree() {
        cout << "Enter value of Node " << endl;
        int data;
        cin >> data;

        if (data == -1) {
            return NULL;
        }

        Node* newNode = new Node(data); // Step 1: create a root node

        // Step 2: create left subtree
        cout << "left of node: "<< newNode->data << endl;
        newNode->left = createTree();

        // Step 3: create right subtree
        cout << "right of node: "<< newNode->data << endl;
        newNode->right = createTree();

        return newNode;
    }
};

void preOrderTraversal(Node* root){
    //base case 
    if(root == NULL){
        return;
    }

    //NLR
    //N
    cout<< root->data << " ";
    //L
    preOrderTraversal(root->left);
    //R
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    //base case 
    if(root == NULL){
        return;
    }

    //LNR
    //L
    inOrderTraversal(root->left);
    //N
    cout<< root->data << " ";
    //R
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    //base case 
    if(root == NULL){
        return;
    }

    //LRN
    //L
    postOrderTraversal(root->left);
    //R
    postOrderTraversal(root->right);
    //N
    cout<< root->data << " ";
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();
        cout << front->data << " ";  // Visit the node

        // Push left and right child of the node to queue if they exist
        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }
}

int main() {
    // Create an initial node object to call createTree function
    Node temp(0);  // Temporary node to call createTree function

    // Call the createTree function on this node to build the tree
    Node* root = temp.createTree();

    // If tree is successfully created
    if (root != NULL) {
        // cout << "Pre-order Traversal of the tree: ";
        levelOrderTraversal(root);  // Perform pre-order traversal
        cout << endl;
    } else {
        cout << "Tree is empty!" << endl;
    }

    return 0;
}