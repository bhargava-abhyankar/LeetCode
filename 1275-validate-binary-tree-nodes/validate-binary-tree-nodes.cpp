class Solution {
public:

    /* Four Properties of tree 
      1. Root should not have parent
      2. All nodes except root node should have only one parent.
      3. Number of components should be equal to 1 
      4. There should not be a cycle 
    */

    /* Method 1: Using DFS 
    
    int find_root(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        unordered_set<int> hash;
        hash.insert(leftChild.begin(), leftChild.end());
        hash.insert(rightChild.begin(), rightChild.end());

        for(int i = 0; i < n; i++) {
            if(hash.find(i) == hash.end()) {
                return i;
            }
        }

        return -1;
    }

    bool dfs(int i, int parent, vector<int>& leftChild, vector<int>& rightChild, vector<bool> &is_visited)
    {
        is_visited[i] = true;

        int x = leftChild[i], y = rightChild[i];

        if(x != -1 && is_visited[x] == false) {
            if(dfs(x, i, leftChild, rightChild, is_visited))
                return true;
        } else if (x != -1 && x != parent)
            return true;

        if(y != -1 && is_visited[y] == false) {
            if(dfs(y, i, leftChild, rightChild, is_visited))
                return true;
        } else if (y != -1 && y != parent)
            return true;

        return false;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        if(find_root(n, leftChild, rightChild) == -1)
            return false;

        vector<bool> is_visited(n, false);

        if(dfs(0, -1, leftChild, rightChild, is_visited) == true)
            return false;

        for(int i = 0; i < n; i++) {
            if(is_visited[i] == false)
                return false;
        }

        return true;
    }

    */

    int find_root(int n, vector<int>& leftChild, vector<int>& rightChild) {
    unordered_set<int> children;
    
    // Collect all nodes that are children
    for (int i = 0; i < n; i++) {
        if (leftChild[i] != -1) children.insert(leftChild[i]);
        if (rightChild[i] != -1) children.insert(rightChild[i]);
    }

    // Find the node which is not a child, which should be the root
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (children.find(i) == children.end()) {
            if (root == -1) {
                root = i;  // First root candidate found
            } else {
                return -1;  // More than one root found, invalid tree
            }
        }
    }

    return root;
}

bool dfs(int node, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& is_visited) {
    is_visited[node] = true;
    
    int left = leftChild[node], right = rightChild[node];
    
    // Traverse left child
    if (left != -1) {
        if (is_visited[left]) return true;  // Cycle detected
        if (dfs(left, leftChild, rightChild, is_visited)) return true;
    }

    // Traverse right child
    if (right != -1) {
        if (is_visited[right]) return true;  // Cycle detected
        if (dfs(right, leftChild, rightChild, is_visited)) return true;
    }
    
    return false;
}

bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    // Step 1: Find the root
    int root = find_root(n, leftChild, rightChild);
    if (root == -1) return false;  // No valid root or multiple roots

    // Step 2: Initialize the visited array
    vector<bool> is_visited(n, false);

    // Step 3: Perform DFS from the root
    if (dfs(root, leftChild, rightChild, is_visited)) {
        return false;  // Cycle detected
    }

    // Step 4: Check if all nodes are visited (tree must be connected)
    for (int i = 0; i < n; i++) {
        if (!is_visited[i]) {
            return false;  // A node is not visited, meaning the graph is disconnected
        }
    }
    
    return true;  // All checks passed, it's a valid binary tree
}

};