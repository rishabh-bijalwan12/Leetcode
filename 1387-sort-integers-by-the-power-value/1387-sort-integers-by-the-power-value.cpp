class Solution {
public:
    int f(int x){
        if(x==1)return 0;
    
        int a=0,b=0;
        if(x%2==0)a=1+f(x/2);
        if(x%2!=0)b=1+f(3*x+1);

        return a+b;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>ans;
        for(int i=lo;i<=hi;i++){
            int x=f(i);
            ans.push_back({x,i});
        }
        sort(ans.begin(),ans.end());
        return ans[k-1].second;
    }
};