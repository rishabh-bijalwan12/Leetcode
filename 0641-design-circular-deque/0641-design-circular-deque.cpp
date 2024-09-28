class MyCircularDeque {
public:
    int f=-1,r=-1,size=0;
    vector<int>q;
    MyCircularDeque(int k) {
        size=k;
        q=vector<int>(k,0);
    }
    
    bool insertFront(int value) {
        if(r==(f-1) || (r+1%size)==f)return false;
        if(f==-1 && r==-1){
            f=0,r=0;
            q[f]=value;
            return true;
        }
        f=(f==0)?size-1:f-1;
        q[f]=value;
        return true;
    }
    
    bool insertLast(int value) {
        if(((r+1)%size)==((f)%size))return false;
        if(f==-1 && r==-1){
            f=0,r=-1;
        }
        r=(r+1)%size;
        q[r]=value;
        return true;
    }
    
    bool deleteFront() {
        if(f==-1)return false;
        if(f==r){
            f=-1,r=-1;
            return true;
        }
        f=(f+1)%size;
        return true;
    }
    
    bool deleteLast() {
        if(r==-1)return false;
        if(f==r){
            f=-1,r=-1;
            return true;
        }
        r=r-1;
        if(r==-1)r=size-1;
        return true;
    }
    
    int getFront() {
        if(f==-1)return -1;
        return q[f];
    }
    
    int getRear() {
        if(r==-1)return -1;
        return q[r];
    }
    
    bool isEmpty() {
        if(f==-1)return true;
        return false;
    }
    
    bool isFull() {
        if((r+1)%size==f)return true;
        
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */