/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //don't NEED root-left AND right here since its a perfect tree
        if(root == NULL || root->left == NULL || root->right == NULL) return root;
        root->left->next = root->right; //set left to right
        //if there is a node to the right of root set root's right child to the one to rights           left child
        if(root->next) root->right->next = root->next->left;
        //if we haven't reached the end recursivley call for left and right
        //again, we don't need left and right since its a perfect tree
        if(root->left || root->right) {
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};
