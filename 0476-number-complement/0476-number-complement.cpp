class Solution {
public:
    int findComplement(int num) {
      int ans=0;
      int i=31;
      while(num>>i==0)i--;
      for(;i>=0;i--){
        if(num>>i & 1){
            ans+=0;
        }
        else{
            int x=pow(2,i);
            ans+=x;
        }
      }  
      return ans;
    }
};