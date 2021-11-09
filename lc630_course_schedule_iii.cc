class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        std::sort(courses.begin(), courses.end(), [](const std::vector<int>& a, const std::vector<int>& b){
            return a[1] < b[1];
        });
        std::priority_queue<int, std::vector<int>> pq;
        int duration = 0;
        for (const std::vector<int>& course : courses) {
            duration += course[0]; 
            pq.push(course[0]);
            if (duration > course[1]) {
                duration -= pq.top();
                pq.pop(); 
            }
        }
        return pq.size();
    }
};
