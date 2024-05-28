class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
       int leftPtr = 0, size = s.size(), rightPtr = 0;
       int currCost = 0, maxLen = 0;
       while(rightPtr < size){
          currCost += abs(s[rightPtr] - t[rightPtr]);
          if(currCost > maxCost){
            while(leftPtr <= rightPtr && currCost > maxCost){
                  currCost -= abs(s[leftPtr] - t[leftPtr]);
                  leftPtr++;
            }
          }
          if(leftPtr <= rightPtr){
            maxLen = max(maxLen, rightPtr - leftPtr + 1);
          }
          rightPtr++;
       }  
       return maxLen;
    }
};