class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    SeatManager(int n) {
        ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
        int i=1;
        for(;i<=n;i++){
            minHeap.push(i);
        }
    }
    
    int reserve() {
        int t=minHeap.top();
        minHeap.pop();
        return t;
    }
    
    void unreserve(int seatNumber) {
        minHeap.push(seatNumber);
    }
};