/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        function<void(Node*)> post = [&](Node* r) {
            if(!r) return;
            for(auto i : r->children)
                post(i);
            res.push_back(r->val);
        };
        post(root);
        return res;
    }
};