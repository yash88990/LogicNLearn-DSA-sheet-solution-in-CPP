#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int, pair<int, int>> row_min_max;
        map<int, pair<int, int>> col_min_max;

        for (const auto& building : buildings) {
            int x = building[0];
            int y = building[1];

            if (row_min_max.find(x) == row_min_max.end()) {
                row_min_max[x] = {y, y};
            } else {
                row_min_max[x].first = min(row_min_max[x].first, y);
                row_min_max[x].second = max(row_min_max[x].second, y);
            }

            if (col_min_max.find(y) == col_min_max.end()) {
                col_min_max[y] = {x, x};
            } else {
                col_min_max[y].first = min(col_min_max[y].first, x);
                col_min_max[y].second = max(col_min_max[y].second, x);
            }
        }

        int covered_count = 0;

        for (const auto& building : buildings) {
            int x = building[0];
            int y = building[1];

            bool is_vertically_covered = (x != col_min_max[y].first && 
                                          x != col_min_max[y].second);

            bool is_horizontally_covered = (y != row_min_max[x].first && 
                                            y != row_min_max[x].second);

            if (is_vertically_covered && is_horizontally_covered) {
                covered_count++;
            }
        }

        return covered_count;
    }
};