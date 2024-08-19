class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        long long ve=1,hr=1;
        sort(h.rbegin(),h.rend());
        sort(v.rbegin(),v.rend());
        long long ans=0;
        long long i=0,j=0;
        while(i<h.size() && j<v.size()){
            if(h[i]>=v[j]){
                ans+=h[i]*ve;
                hr++;
                i++;
            }
            else{
                ans+=v[j]*hr;
                ve++;
                j++;
            }
        }
        while(i<h.size()){
            ans+=h[i]*ve;
            hr++;
            i++;
        }
        while(j<v.size()){
            ans+=v[j]*hr;
            ve++;
            j++;
        }
        return ans;
    }
};