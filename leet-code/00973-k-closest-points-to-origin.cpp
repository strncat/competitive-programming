// a max heap solution
// pre-calculate the distance to the origin from each point
// add K point initially, after that whenever we have more
// than K points, pop one to maintain addition to the heap
// in log(K) ... so the total time is still nlog(k)
// TODO: K-SELECT or QUICK SELECT
class Solution {
public:
    typedef struct {
        int dist_sqrd = 0;
        vector<int> coordinate;
    } Point;

    struct compare {
        bool operator()(Point const& p1, Point const& p2) {
            return p1.dist_sqrd < p2.dist_sqrd;
        }
    };

    int distance_squared_to_origin(vector<int>& point) {
        return point[0]*point[0] + point[1]*point[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        std::priority_queue<Point, std::vector<Point>, compare> q;

        for (int i = 0; i < points.size(); i++) {
            Point p;
            p.coordinate = std::vector<int>(2);
            p.coordinate[0] = points[i][0];
            p.coordinate[1] = points[i][1];
            p.dist_sqrd = distance_squared_to_origin(points[i]);
            q.push(p);

            // always maintain K entries only
            if (q.size() > K) {
                q.pop();
            }
        }

        vector<vector<int>> closest;
        while (!q.empty()) {
            Point p = q.top(); q.pop();
            closest.push_back(p.coordinate);
        }

        return closest;
    }
};
