#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) 
    {
        vector<char> to_compare_set1, to_compare_set2;
        vector<char> answer (to_compare_set1.size()+to_compare_set2.size());
        vector<string> response;
        for (auto &ch : words[0]){
                to_compare_set1.push_back(ch);}

        sort(to_compare_set1.begin(), to_compare_set1.end());
        for (int i =1; i<words.size(); i++){
            for (auto &ch : words[i]){
                to_compare_set2.push_back(ch);
            }
            sort(to_compare_set2.begin(), to_compare_set2.end());
            answer.erase(answer.begin(), answer.end());
            //run intersection to update the answer
            auto last = set_intersection(to_compare_set1.begin(), to_compare_set1.end(), to_compare_set2.begin(), to_compare_set2.end(), std::back_inserter(answer));
            to_compare_set1 = answer;
            to_compare_set2.erase(to_compare_set2.begin(), to_compare_set2.end());
        }  
        for (auto ch : answer){
            string str(1,ch);
            response.push_back(str);
        }
        return (response);
    }
};