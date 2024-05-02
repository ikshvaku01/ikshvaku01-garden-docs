---
title: Serialize & Deserialize A Binary Tree
published: 2024-05-02
tags: ["tree", "Data-Structure"]
category: GEEKSFORGEEKS
draft: false
---
# [02-05-2024. Serialize & Deserialize A Binary Tree](https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1)

## Problem :
Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

- **serialize() :** stores the tree into an array **a** and returns the array.
- **deSerialize() :** deserializes the array to the tree and returns the root of the tree.

**Note:** Multiple nodes can have the same data and the node values are **always** **positive integers**. Your code will be correct if the tree returned by **deSerialize(serialize(input_tree))** is same as the input tree. Driver code will print the in-order traversal of the tree returned by `deSerialize(serialize(input_tree))`.
### Example 1:
```
Input:
      1
    /   \
   2     3
Output: 2 1 3
```
### Example 2:
```
         10
       /    \
      20    30
    /   \
   40  60
Output: 40 20 60 10 30
```
### **Your Task:**  
The task is to complete two functions **serialize** which takes the root node of the tree as input and stores the tree into an array and **deSerialize** which deserializes the array to the original tree and returns the root of it.

**Expected Time Complexity:** O(Number of nodes).  
**Expected Auxiliary Space:** O(Number of nodes).

**Constraints:**  
1 <= Number of nodes <= 10<sup>4</sup> 
1 <= Data of a node <= 10<sup>9</sup>
## CODE : 
* [CHECK THE CPP CODE IN REPOSITORY](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-SOLUTION-CLUSTER/COMPETITIVE-CODING/GEEKSFORGEEKS/1f0ccffa-edfd48f9ba64-53dfdeea2fee/SerializeandDeserializeABinaryTree.cpp)

```cpp
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);
    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();
        // Get the current Node's value from the string
        string currVal = ip[i];
        // If the left child is not null
        if (currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->left);
        }
        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        // If the right child is not null
        if (currVal != "N") {
            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution
{
    public:
    vector<int> serialize(Node *root) 
    {
        vector<int> v;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* node=q.front();
            q.pop();
            if(node)
            v.push_back(node->data);
            else
            v.push_back(-1);            
            if(node)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return v;
    }
    Node * deSerialize(vector<int> &A)
    {
        Node* root=new Node(A[0]);
        queue<Node*> q;
        q.push(root);
        int i=1;        
        while(!q.empty() and i<A.size())
        {
            Node* node=q.front();
            q.pop();
            bool FR=0;
            bool FL=0;
            if(A[i]==-1)
            {
                node->left=NULL;
                FL=1;
            }
            if(A[i+1]==-1)
            {
                node->right=NULL;
                FR=1;
            }
            if(!FL)
            {
                Node* newNode1=new Node(A[i]);
                node->left=newNode1;
                q.push(newNode1);
            }
            if(!FR)
            {
                Node* newNode1=new Node(A[i+1]);
                node->right=newNode1;
                q.push(newNode1);
            }
            i+=2;
        }
        return root;
    }
};
//{ Driver Code Starts.
void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void _deleteTree(Node* node)
{
    if (node == NULL) return;
    /* first delete both subtrees */
    _deleteTree(node->left); 
    _deleteTree(node->right);
    /* then delete the node */
    //cout << "Deleting node: " << node->data << endl;
    delete node;
}
/* Deletes a tree and sets the root as NULL */
void deleteTree(Node** node_ref)
{
    _deleteTree(*node_ref);
    *node_ref = NULL;
}
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        Node* temp = root;
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
```

## Editorial :
### [Authors Expected Approach](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-SOLUTION-CLUSTER/COMPETITIVE-CODING/GEEKSFORGEEKS/1f0ccffa-edfd48f9ba64-53dfdeea2fee/expectedAuthorsApproach.cpp)
#### Intuition :

We can implement serialization and deserialization of a binary tree using a recursive approach. The intuition behind this code is to convert a binary tree into a list of values and then reconstruct the tree from the list of values. The serialization function recursively traverses the tree in a pre-order fashion, appending node values to a list. The deserialization function uses a helper function to create nodes from the list of values and reconstruct the original binary tree.

#### Implementation : 
1. ****Serialization (******`**serialize**`** ****function)****:
    - If the `root` is null, it appends -1 to the `A` list to indicate an empty node and returns.
    - If the `root` is not null, it appends the data of the current node to the `A` list.
    - The function then recursively calls `serialize` on the left and right subtrees of the current node.
2. ****Deserialization (******`**kewl**`** ****function)****:
    - The `kewl` function takes an ArrayList `A` containing the serialized values and a `Passing` object `ps` with an index.
    - If the index `ps.index` is equal to the size of `A` or the current element in `A` is -1, it means there are no more elements or an empty node, so it increments the index and returns null.
    - If the current element in `A` is not -1, it creates a new node with the current element as the data, increments the index, and assigns this node as the `root`.
    - The function then recursively calls `kewl` on the left and right subtrees of the current node and returns the root node.
3. ****Deserialization (******`**deSerialize**`** ****function)****:
    - The `deSerialize` function initializes a `Passing` object `ps` with an index of 0.
    - It then calls the `kewl` function with the serialized list `A` and `ps` to construct the binary tree.
    - Finally, it returns the root of the reconstructed binary tree.
#### Complexity :
- ****Time Complexity :****Time complexity for both serialization and deserialization is O(n), where n is the number of nodes or elements.
- ****Space Complexity:**** Space complexity is O(n) for storing all nodes into an array.

### [Alternate Approach](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-SOLUTION-CLUSTER/COMPETITIVE-CODING/GEEKSFORGEEKS/1f0ccffa-edfd48f9ba64-53dfdeea2fee/alternateApproach.cpp)
#### Intuition : 

We can do BFS with the help of a queue to serialize and deserialize the tree.

#### Implementation :
****Serialization (******`**serialize**`** ***function)****:
1. Initialize an empty vector `ans` to store the serialized values.
2. Check if the given `root` is null. If it's null, return a vector containing a single element `-1`, which signifies an empty tree.
3. Create a queue `q` to perform a level-order traversal of the binary tree.
4. Enqueue the `root` node into the queue.
5. Start a loop that continues until the queue `q` is empty:
    - Dequeue the front node `curr` from the queue.
    - Check if `curr` is null. If it is, add `-1` to the `ans` vector, indicating an empty node.
    - If `curr` is not null, add the data of `curr` to the `ans` vector.
    - Enqueue the left and right children of `curr` into the queue (even if they are null).
6. After the loop, the `ans` vector contains the serialized values of the binary tree.
7. Return the `ans` vector.

****Deserialization (******`**deSerialize**`** ****function)****:
1. Create a `Node` pointer `root` and initialize it with a `Node` object created with the first element of the input vector `A`. This initializes the root of the reconstructed binary tree.
2. Check if the size of the input vector `A` is 0. If it is, return `NULL` because there are no elements to deserialize.
3. Check if the first element of `A` is `-1`. If it is, return `NULL` because this indicates an empty tree.
4. Create a queue `q` to facilitate the deserialization process.
5. Initialize an integer `i` to 1 (to skip the first element, which is already used to initialize the root node).
6. Enqueue the `root` into the queue.
7. Start a loop that continues until the queue `q` is empty:
    - Dequeue the front node `curr` from the queue.
    - Get the next element from the input vector `A` and assign it to `lef`. This element represents the left child of `curr`.
    - If `lef` is `-1`, set the left child of `curr` to `NULL`.
    - If `lef` is not `-1`, create a new `Node` object with `lef` as the data and set it as the left child of `curr`. Enqueue the left child into the queue.
    - Get the next element from the input vector `A` and assign it to `rig`. This element represents the right child of `curr`.
    - If `rig` is `-1`, set the right child of `curr` to `NULL`.
    - If `rig` is not `-1`, create a new `Node` object with `rig` as the data and set it as the right child of `curr`. Enqueue the right child into the queue.
8. After the loop, the `root` points to the root of the reconstructed binary tree.
9. Return the `root`.
#### Complexity
- ****Time Complexity : O(n),**** Both serialization and deserialization operations have a time complexity of O(n), where n is the number of nodes in the binary tree.
- ****Space Complexity : O(n),**** Both the serialization and deserialization functions have a space complexity of O(n) due to the storage of values in data structures.
## SIMILAR PROBLEMS:
