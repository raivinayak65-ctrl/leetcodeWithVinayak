
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long sumLeft = 0, sumRight = 0;

        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                int val = *left.rbegin();
                left.erase(left.find(val));
                sumLeft -= val;
                right.insert(val);
                sumRight += val;
            }

            while (left.size() < right.size()) {
                int val = *right.begin();
                right.erase(right.find(val));
                sumRight -= val;
                left.insert(val);
                sumLeft += val;
            }
        };

        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumLeft += val;
            } else {
                right.insert(val);
                sumRight += val;
            }
            balance();
        };

        auto remove = [&](int val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                sumLeft -= val;
            } else {
                it = right.find(val);
                right.erase(it);
                sumRight -= val;
            }

            balance();
        };

        auto getCost = [&]() -> long long {
            long long median = *left.rbegin();

            return median * (long long)left.size() - sumLeft
                 + sumRight - median * (long long)right.size();
        };

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);
            cost[i - x + 1] = getCost();
        }

        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0), curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            swap(prev, curr);
        }

        return prev[n];
    }
};
