class Solution {
public:
    int nthUglyNumber(int n) {
    priority_queue<long, vector<long>, greater<long>> minHeap;
    set<long> seen;
    
    minHeap.push(1);
    seen.insert(1);

    long uglyNumber = 1;

    for (int i = 0; i < n; ++i) {
        uglyNumber = minHeap.top();
        minHeap.pop();
        for (int factor : {2, 3, 5}) {
            long newUgly = uglyNumber * factor;
            if (seen.find(newUgly) == seen.end()) {
                seen.insert(newUgly);
                minHeap.push(newUgly);
            }
        }
    }

    return uglyNumber;
    }
};