class Solution {
public:
    vector<int> missingRolls(vector<int>& r, int mean, int n) {
        int t=r.size()+n;
        int x=0;
        for(auto y:r)x+=y;

        int sum=(mean*t)-x;

        if(sum<n || 6*n<sum){
            return {};
        }
        
        sum-=n;
        
        vector<int>ans(n,1);

        int five=sum/5;
        int i=0;
        while(five!=0){
            ans[i]+=5;
            five--,i++;
        }

        sum%=5;

        cout<<sum;

        for(int i=0;i<n;i++){
            if(ans[i]+sum<=6){
                ans[i]+=sum;
                break;
            }
        }

        return ans;

    }
};