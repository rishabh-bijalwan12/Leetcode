class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),ans=0,one,zero,diff;
        vector<int>ps(n,0);
        for(int i=0;i<n;i++)if(s[i]=='1')ps[i]=1;
        for(int i=1;i<n;i++)ps[i]+=ps[i-1];
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                one=(i==0)?ps[j]:ps[j]-ps[i-1];
                zero=(j-i+1)-one;
                if(zero*zero > one){
                    diff=(zero*zero)-one-1;
                    j=j+diff;
                }
                else{
                    if(zero*zero==one){
                        ans++;            
                    }
                    else{
                        ans++;
                        diff=sqrt(one)-zero;
                        if((j+diff)>=n){
                            ans+=n-j-1;
                        }
                        else{
                            ans+=diff;
                        }
                        j=j+diff;
                    }
                }
            }
        }
        return ans;
    }
};