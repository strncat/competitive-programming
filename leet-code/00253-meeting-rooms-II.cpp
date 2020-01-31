
class Solution {
public:
    struct CompareMeetings {
        bool operator()(int const & p1, int const & p2) {
            // return "true" if p1 is a higher end time
            return p1 > p2;
        }
    };

    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) { return 0; }
        
        std::sort(intervals.begin(), intervals.end(),
          [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[0] < b[0];
          });
        
        std::priority_queue<int, vector<int>, CompareMeetings> q;
        
        // start by allocating a room to the first meeting and add this meeting to q
        q.push(intervals[0][1]);
                
        // for each next meeting, check if we can use the room on top of the heap first
        for (int i = 1; i < intervals.size(); i++) {
            int earliestEndingTime = q.top();
            // if current meeting fits in this room, great, remove that old meeting
            if (intervals[i][0] >= earliestEndingTime) {
                q.pop();
            }
            // we either allocate a new room or update the old room with the new end time
            // either way, we add the new end time to the heap
            q.push(intervals[i][1]);
        }
        
        return q.size();
    }
};