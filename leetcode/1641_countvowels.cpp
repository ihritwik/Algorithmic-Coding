#include<iostream>

class Solution{
    public:
        int count(int n, int vowels){
            if(n==0) return 1;
            int result=0;
            for(int i=vowels; i<=5; i++)
                result+= count(n-1,i);
            return result;
        }
        int countvowels(int n){
            return count(n,1);
        }
};

int main(){
    int n;
    std::cin>>n;
    Solution s;
    std::cout<<s.countvowels(n);
    return 0;
}