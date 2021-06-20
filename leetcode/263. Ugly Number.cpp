class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        vector<int> factors = {2, 3, 5};
        
        for(int i = 0; i < factors.size(); i++){
            int factor = factors[i];
            
            while((n % factor) == 0)
                n /= factor;
        }
        
        if(n == 1) return true;
        return false;
    }
};