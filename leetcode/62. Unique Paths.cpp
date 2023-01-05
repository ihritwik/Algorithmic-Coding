#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> response(m, std::vector<int>(n, 1));
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                response[i][j] = response[i][j-1] + response[i-1][j];
            }
        }
        return response[m-1][n-1];
    }
};