class Solution {
public:
    void dfs(vector<vector<char>>& g, int i, int j, int m, int n){
        if (i<0 || j<0 || i>m-1 || j>n-1 || g[i][j]=='0')
            return;
        g[i][j]='0';
        dfs(g,i-1, j, m, n);
        dfs(g,i+1, j, m, n);
        dfs(g,i, j-1, m, n);
        dfs(g,i, j+1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        cout<<m<<" "<<n<<endl;
        int count =0;
        for (int p=0; p<m; p++){
            for (int q=0; q<n;q++){
                if (grid[p][q]=='1'){
                    count++;
                    dfs(grid,p, q, m, n);
                }
            }
        }    
        return count;
    }
};
