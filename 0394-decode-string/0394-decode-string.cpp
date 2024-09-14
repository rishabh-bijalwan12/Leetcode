class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans = "";
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                st.push(s[i]);
            } else {
        
                string decodedString = "";
                while (!st.empty() && st.top() != '[') {
                    decodedString = st.top() + decodedString;
                    st.pop();
                }
                
                
                st.pop();
                
                
                string num = "";
                while (!st.empty() && isdigit(st.top())) {
                    num = st.top() + num; 
                    st.pop();
                }
                
                int repeatCount = stoi(num); 
                
                
                string repeatedString = "";
                for (int j = 0; j < repeatCount; j++) {
                    repeatedString += decodedString;
                }
                
                
                for (char c : repeatedString) {
                    st.push(c);
                }
            }
        }
        
        
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};
