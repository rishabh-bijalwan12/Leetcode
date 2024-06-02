class Solution {
public:
    void reverserecursion(int i,int j,vector<char>& s){
        
        if(i>j)
        return;
            swap(s[i],s[j]);
            i++,j--;
          reverserecursion(i,j,s);
    }
    void reverseString(vector<char>& s) {
         reverserecursion(0,s.size()-1,s);
    }
};