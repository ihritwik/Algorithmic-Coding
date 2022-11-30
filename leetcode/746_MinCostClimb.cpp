#include<iostream>
#include<vector>


int MinCostClimb(std::vector<int> cost){
    int len=cost.size();
    for(int i=2;i<len;i++){
        cost[i]+=std::min(cost[i-1],cost[i-2]);
    }
    return std::min(cost[len-1],cost[len-2]);
}

// int MinCostClimb(std::vector<int> cost){
//     int len=cost.size();
//     int step1=0;
//     int step2=0;
//     for(int i=len-1;i>=0;i--){
//         int curr=cost[i]+std::min(step1,step2);
//         step1=step2;
//         step2=curr;
//     }
//     return std::min(step1,step2);
// }

int main(){
    int n;
    std::cin>>n;
    std::vector <int> v;
    
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        v.push_back(x);
    }
    int res=MinCostClimb(v);
    std::cout<<res<<std::endl;
    return 0;
}