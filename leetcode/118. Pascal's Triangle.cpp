#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> response(numRows);
        if (numRows==1){
            response[0].push_back(1);
            return response;
        }
        if (numRows==2){
            response[0].push_back(1);
            response[1].push_back(1);
            response[1].push_back(1);
            return response;
        }
        //construct an initial array
        //                 1
        //               1   1
        response[0].push_back(1);
        response[1].push_back(1);
        response[1].push_back(1);
        //cout<<response[0][0]<<endl;
        //cout<<response[1][0]<<"  "<<response[1][1]<<endl;
        for(int i= 2; i<numRows;i++){
            response[i].push_back(1);
            //cout<<response[i][0]<<"  ";
            for (int j = 1; j<i;j++){
                response[i].push_back(response[i-1][j-1] + response[i-1][j]);
                //cout<<response[i][j]<<"  ";
            }
            response[i].push_back(1);
            //cout<<response[i][i]<<endl;
        }
        return response;
    }
};