// problem link
// https://leetcode.com/problems/redundant-connection/description/


// Source Code

class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(x == parent[x]){
            return x;
        }

        
        return parent[x] = find(parent[x]);
    }

    bool merge(int x, int y){
        int lx = find(x);
        int ly = find(y);

        if(ly == lx){
            return false;
        }

        parent[ly] = lx;

        return true;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        stack<vector<int>> stk;

        for(int i = 0;i <= n;i++){
            parent[i] = i;
        }

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            if(!merge(u, v)){
                stk.push(edge);
            }
        }

        for(int i = 0;i <= n;i++){
            cout << i << " " << parent[i] << endl;
        }

        return stk.top();
    }
};
