class Solution {
public:
    int maxPathLength(vector<vector<int>>& c, int k) {
        int x=c[k][0],y=c[k][1];
        sort(c.begin(),c.end(),[](auto &a,auto &b){
            if(a[0]==b[0])return  a[1]>b[1];
            else return a[0]<b[0];
        });
        int part=0;
        for(int i=0;i<c.size();i++){
            if(c[i][0]==x && c[i][1]==y){
                part=i;
                break;
            }
        }
        vector<int>t;
        for(int i=0;i<part;i++){
            int w=c[i][0];
            int h=c[i][1];
            if(h>=y || w>=x)continue;
            auto it=lower_bound(t.begin(),t.end(),h);
            if(it==t.end())t.push_back(h);
            else *it=h;
        }
        for(int i=part+1;i<c.size();i++){
            int w=c[i][0];
            int h=c[i][1];
            if(h<=y || w<=x)continue;
            auto it=lower_bound(t.begin(),t.end(),h);
            if(it==t.end())t.push_back(h);
            else *it=h;
        }
        return t.size()+1;

    }
};