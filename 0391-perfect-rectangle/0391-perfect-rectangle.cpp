class Solution {
 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    int n = rectangles.size();

    if (n == 1) return true;

    map<pair<int, int>, int> pointCounts;

    for (auto& rect : rectangles) {
      pointCounts[{rect[0], rect[1]}]++;
      pointCounts[{rect[2], rect[3]}]++;
      pointCounts[{rect[0], rect[3]}]--;
      pointCounts[{rect[2], rect[1]}]--;
    }

    int numMarks = 0;

    for (auto it = pointCounts.begin(); it != pointCounts.end(); it++) {
      if (it->second != 0) {
        if (abs(it->second) != 1) return false;

        numMarks++;
      }
    }

    return numMarks == 4;
  }
};