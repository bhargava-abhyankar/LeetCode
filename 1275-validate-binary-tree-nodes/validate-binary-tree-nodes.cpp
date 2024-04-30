class Solution {
public:
    vector<int> parent;

    int find(int x)
    {
        if(parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    bool Union(int p, int child, int &component)
    {
        if(find(child) != child) {
            return false;
        }

        if(find(p) == child) {
            return false;
        }

        parent[child] = p;
        component--;
        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        parent.resize(n);
        int component = n;

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < n; i++) {

            if(leftChild[i] != -1) {
                if(Union(i, leftChild[i], component) == false) {
                    return false;
                }
            }

            if(rightChild[i] != -1) {
                if(Union(i, rightChild[i], component) == false) {
                    return false;
                }
            }
        }

        if(component != 1) {
            return false;
        }

        return true;
    }
};