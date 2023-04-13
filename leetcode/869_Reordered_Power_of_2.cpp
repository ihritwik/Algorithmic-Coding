class Solution {
public:
    vector<int> find_digit_count(int n){
        vector<int> data(10,0);
        int rem;
        while(n>0){
            rem=n%10;
            n=n/10;
            data[rem]++;
        }
        return data;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> to_compare;
        to_compare = find_digit_count(n);
        for (int i=0; i<32; i++){
            if (to_compare==find_digit_count(1<<i))
                return true;
        }
        return false;
    }
};
