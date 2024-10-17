class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        string t=s;
        priority_queue<char>pq;
        for(int i=0;i<s.size();i++){
            pq.push(s[i]);
        }
        int temp=0,i=0,j=0;
        while(i<s.size() && temp!=1 || !pq.empty()){
            auto x=pq.top();
            pq.pop();
            int ind;
            for(int k=0;k<t.size();k++){
                if(x==t[k]){
                    ind=k;
                    t[k]='A';
                }
            }
            if(x != s[i]){
                j=ind;
                swap(s[i],s[j]);
                break;
            }
            i++;
        }
        num=stoi(s);
        return num;
    }
};