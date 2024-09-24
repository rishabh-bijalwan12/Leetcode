class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxi=0;
        unordered_set<string>st;
        for(int i=0;i<arr1.size();i++){
            string s=to_string(arr1[i]);
            string s2="";
            for(int j=0;j<s.size();j++){
                s2+=s[j];
                st.insert(s2);
            }
        }
        for(int i=0;i<arr2.size();i++){
            string s=to_string(arr2[i]);
            string s2="";
            for(int j=0;j<s.size();j++){
                s2+=s[j];
                if(st.find(s2)!=st.end()){
                    int n=s2.size();
                    maxi=max(maxi,n);
                }
            }
        }
        return maxi;
    }
};