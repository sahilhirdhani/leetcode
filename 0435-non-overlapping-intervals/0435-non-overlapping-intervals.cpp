class Solution {
public:
    bool static cmp(pair <int,int>&a , pair<int,int> &b){
        return a.second < b.second;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {   
        vector <pair<int,int>> arr;
        int n = intervals.size();
        for(int i=0 ; i<intervals.size() ; i++){
            arr.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(arr.begin(),arr.end() , cmp);
        int endTime = arr[0].second;
        int ans = 0;
        for(int i=1 ; i<n ; i++){
            int start = arr[i].first;
            int end = arr[i].second;
            if(start >= endTime){
                endTime = end;
            }else{
                ans++;
            }
        }
        return ans;
    }
};