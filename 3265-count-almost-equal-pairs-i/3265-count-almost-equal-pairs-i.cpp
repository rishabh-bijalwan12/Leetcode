class Solution {
public:
    int countPairs(vector<int>& nums) {
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
            
                string s = to_string(nums[i]);
                string t = to_string(nums[j]);

                while(s.size()<t.size())s="0"+s;
                while(t.size()<s.size())t="0"+t;

                if(s.size()==t.size()){
                    if(s==t){
                        ans++;
                        continue;
                    }

                    int diffCount = 0;
                    vector<int>a;
                    for(int k = 0; k < s.size(); k++) {
                        if(s[k] != t[k]){
                            a.push_back(k);
                            diffCount++;
                        }
                    }
                
                    if(diffCount == 2){
                        swap(s[a[0]],s[a[1]]);
                        if(s==t)ans++;
                    }
                }        
            }
        }
        return ans;
    }
};
