class Solution {
public:
    // Function to serialize a tree and return a list
    // containing nodes of tree.
    vector<int> serialize(Node* root)
    {
        vector<int> ans;
        if (!root)
            return { -1 };
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr == NULL) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(curr->data);
            }
            if (curr != NULL) {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
    }

    // Function to deserialize a list and construct the
    // tree.
    Node* deSerialize(vector<int>& A)
    {
        Node* root = new Node(A[0]);
        if (A.size() == 0)
            return NULL;
        if (A[0] == -1)
            return NULL;
        queue<Node*> q;
        // root->data=A[0];
        int i = 1;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            int lef = A[i++];
            if (lef == -1) {
                curr->left = NULL;
            }
            else {
                Node* leftnode = new Node(lef);
                curr->left = leftnode;
                q.push(leftnode);
            }
            int rig = A[i++];
            if (rig == -1) {
                curr->right = NULL;
            }
            else {
                Node* rightnode = new Node(rig);
                curr->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};
