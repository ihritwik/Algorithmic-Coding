class Solution {
public:

    int max_area = 0;
    int dfs(vector<vector<int>>& g, int i, int j, int m, int n){
        int c =1;
        if (i<0 || j<0 || i>m-1 || j>n-1 || g[i][j]==0)
            return 0;
        g[i][j]=0; 
        c=c + dfs(g,i-1, j, m, n);
        c=c + dfs(g,i+1, j, m, n);
        c=c+dfs(g,i, j-1, m, n);
        c=c+dfs(g,i, j+1, m, n);
        return c;        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m==0 || n==0) return 0;
        //cout<<m<<" "<<n<<endl;
        int count =0;
        int count_per_island = 0;
        for (int p=0; p<m; p++){
            for (int q=0; q<n;q++){
                if (grid[p][q]==1){
                    count++;
                    count_per_island = dfs(grid,p, q, m, n);
                    max_area= max(max_area, count_per_island);
                }
            }
        }    
        return max_area;
    }
};
