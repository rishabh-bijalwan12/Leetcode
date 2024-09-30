class CustomStack {
public:
    vector<int>st;
    int top=-1,size=0;
    CustomStack(int maxSize) {
        size=maxSize;
        st=vector<int>(maxSize,0);
    }
    
    void push(int x) {
        if(top<size-1){
            top++;
            st[top]=x;
        }
    }
    
    int pop() {
        if(top==-1)return -1;
        int val=st[top];
        top--;
        return val;
    }
    
    void increment(int k, int val) {
        int i=0;
        while(i<=top && i<k)st[i++]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */