class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int num)
    {
        if(num == parent[num]) {
            return num;
        }
        return (parent[num] = find(parent[num]));
    }

    void Union(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

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
        rank.resize(n, 1);
        parent.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        sort(logs.begin(), logs.end(), comp);

        for(int i = 0; i < logs.size(); i++) {

            if(find(logs[i][1]) != find(logs[i][2])) {
                Union(logs[i][1], logs[i][2]);
                n--;
            }

            if(n == 1)
                return(logs[i][0]);
        }

        return -1;
    }
};