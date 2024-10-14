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

        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) hash.insert(leftChild[i]);
            if (rightChild[i] != -1) hash.insert(rightChild[i]);
        }

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
        int root = find_root(n, leftChild, rightChild);

        if( root == -1)
            return false;

        vector<bool> is_visited(n, false);

        if(dfs(root, -1, leftChild, rightChild, is_visited))
            return false;

        for(int i = 0; i < n; i++) {
            if(is_visited[i] == false)
                return false;
        }

        return true;
    }

    */

    /* Method 2: Using dfs iteration 

    int find_root(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        unordered_set<int> hash;

        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1)
                hash.insert(leftChild[i]);
            if(rightChild[i] != -1)
                hash.insert(rightChild[i]);
        }

        for(int i = 0; i < n; i++) {
            if(hash.find(i) == hash.end())
                return i;
        }

        return -1;
    }

    bool dfs(int root, int n, vector<int>& leftChild, vector<int>& rightChild, vector<bool> &is_visited)
    {
        stack<int> st;
        st.push(root);
        is_visited[root] = true;

        while(!st.empty()) {
            int cur = st.top();
            st.pop();

            int x = leftChild[cur], y = rightChild[cur];

            if((x != -1 && is_visited[x] == true) || (y != -1 && is_visited[y] == true))
                return true;
            
            if(y != -1) {
                st.push(y);
                is_visited[y] = true;
            }
                
            if(x != -1) {
                st.push(x);
                is_visited[x] = true;
            }
        }

        return false;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        int root = find_root(n, leftChild, rightChild);

        if(root == -1)
            return false;
        
        vector<bool> is_visited(n, false);

        if(dfs(root, n, leftChild, rightChild, is_visited))
            return false;
        
        for(int i = 0; i < n; i++) {
            if(is_visited[i] == false)
                return false;
        }
        
        return true;
    }

    */

    /* Method 3: Using BFS

    int find_root(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        unordered_set<int> hash;

        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1)
                hash.insert(leftChild[i]);
            if(rightChild[i] != -1)
                hash.insert(rightChild[i]);
        }

        for(int i = 0; i < n; i++) {
            if(hash.find(i) == hash.end())
                return i;
        }

        return -1;
    }

    bool bfs(int root, int n, vector<int>& leftChild, vector<int>& rightChild, vector<bool> &is_visited)
    {
        queue<int> q;
        q.push(root);
        is_visited[root] = true;

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            int x = leftChild[cur], y = rightChild[cur];

            if ((x != -1 && is_visited[x] == true) || (y != -1 && is_visited[y] == true)) {
                return true;
            }

            if(x != -1) {
                is_visited[x] = true;
                q.push(x);
            }

            if(y != -1) {
                is_visited[y] = true;
                q.push(y);
            }
        }

        return false;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        int root = find_root(n, leftChild, rightChild);

        if(root == -1)
            return false;
        
        vector<bool> is_visited(n, false);

        if(bfs(root, n, leftChild, rightChild, is_visited))
            return false;
        
        for(int i = 0; i < n; i++) {
            if(is_visited[i] == false)
                return false;
        }

        return true;
    }

    */


    /* Method 4: Using Union Find */

    vector<int> parent;

    int find(int x)
    {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }

    bool Union(int p, int child, int &components)
    {
        if(find(child) != child)
            return false;
        
        if(find(p) == child)
            return false;
        
        parent[child] = p;
        components--;
        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        int components = n;
        parent.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) {
                if(Union(i, leftChild[i], components) == false)
                    return false;
            }

            if(rightChild[i] != -1) {
                if(Union(i, rightChild[i], components) == false)
                    return false;
            }
        }

        if(components > 1)
            return false;
        
        return true;
    }

};