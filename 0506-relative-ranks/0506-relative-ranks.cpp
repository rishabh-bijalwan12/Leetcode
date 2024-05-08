class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int , int> m;
        vector<int> v;
        for(int i : score) v.push_back(i);
        sort(v.begin() , v.end());
        int k = 1;
        for(int i = v.size() - 1 ; i >= 0 ; i--){
            m[v[i]] = k++;
        }
        vector<string> ans;

        for(int i : score){
            if(m[i] == 1) ans.push_back("Gold Medal");
            else if(m[i] == 2) ans.push_back("Silver Medal");
            else if(m[i] == 3) ans.push_back("Bronze Medal");
            else ans.push_back(to_string(m[i]));
        }
        return ans;
    }
};