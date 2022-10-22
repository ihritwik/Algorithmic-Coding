int lengthOfLIS(vector<int>& nums) 
    {
        // Approach 2: Time Complexity = O(n*lg n)   
        // initialize sub array that contains the first element of nums
        
        if (nums.size() == 0) {
            return 0;
        }
        
        if (nums.size() == 1) {
            return 1;
        }
        
        vector<int> sub (nums.size());
        sub[0] = 1;
        int result = 0;
        for (int i = 1; i <nums.size(); i++){
            int max_length = 0;
            for (int j = 0; j<=i; j++){
                if (nums[j]<nums[i]){
                    if (sub[j]>max_length){
                        max_length = sub[j];
                    }
                }        
            }
            
            if (max_length > result){
                result = max_length;
            }
                sub[i] = max_length + 1;
        }
        result = 0;
        int max_length = 0;
         for (int i = 1; i<sub.size(); i++)
         {
             cout << sub[i] << " ";
             if (sub[i] > max_length) {
                 max_length = sub[i];
             }
         }
         return max_length;    
    }