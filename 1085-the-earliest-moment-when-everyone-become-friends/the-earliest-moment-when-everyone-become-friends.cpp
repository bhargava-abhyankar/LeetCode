class Solution {
public:

    int find(int num, vector<int> &parent)
    {
        if(num == parent[num]) {
            return num;
        }
        return (parent[num] = find(parent[num], parent));
    }

    void Union(int x, int y, vector<int> &parent, vector<int> &rank)
    {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        } else if (rank[x_parent] == rank[y_parent]) {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }


    static bool comp(vector<int> &a, vector<int> b)
    {
        return (a[0] < b[0]);
    }

    int earliestAcq(vector<vector<int>>& logs, int n) 
    {
        int components = n;
        vector<int> parent(n, 0);
        vector<int> rank(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        sort(logs.begin(), logs.end(), comp);

        for(int i = 0; i < logs.size(); i++) {

            if(find(logs[i][1], parent) != find(logs[i][2], parent)) {
                Union(logs[i][1], logs[i][2], parent, rank);
                n--;
            }

            if(n == 1)
                return(logs[i][0]);
        }

        return -1;
    }
};