#include <vector>

using namespace std;

class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum_sq;
        long long sum_val;
        long long lazy;
    };

    int n;
    vector<Node> tree;

    void push(int node, int l, int r) {
        if (tree[node].lazy != 0) {
            long long lz = tree[node].lazy;
            int mid = l + (r - l) / 2;
            
            // Left child update
            tree[2 * node].sum_sq = (tree[2 * node].sum_sq + 2 * lz * tree[2 * node].sum_val + lz * lz * (mid - l + 1)) % MOD;
            tree[2 * node].sum_val = (tree[2 * node].sum_val + lz * (mid - l + 1)) % MOD;
            tree[2 * node].lazy = (tree[2 * node].lazy + lz) % MOD;

            // Right child update
            tree[2 * node + 1].sum_sq = (tree[2 * node + 1].sum_sq + 2 * lz * tree[2 * node + 1].sum_val + lz * lz * (r - mid)) % MOD;
            tree[2 * node + 1].sum_val = (tree[2 * node + 1].sum_val + lz * (r - mid)) % MOD;
            tree[2 * node + 1].lazy = (tree[2 * node + 1].lazy + lz) % MOD;

            tree[node].lazy = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            tree[node].sum_sq = (tree[node].sum_sq + 2 * val * tree[node].sum_val + val * val * (r - l + 1)) % MOD;
            tree[node].sum_val = (tree[node].sum_val + val * (r - l + 1)) % MOD;
            tree[node].lazy = (tree[node].lazy + val) % MOD;
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        tree[node].sum_sq = (tree[2 * node].sum_sq + tree[2 * node + 1].sum_sq) % MOD;
        tree[node].sum_val = (tree[2 * node].sum_val + tree[2 * node + 1].sum_val) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int len = nums.size();
        n = len;
        tree.assign(4 * n, {0, 0, 0});

        unordered_map<int, int> last_pos;
        long long total_sum = 0;
        long long current_total_squares = 0;

        for (int j = 0; j < n; ++j) {
            int x = nums[j];
            int p = -1;
            if (last_pos.find(x) != last_pos.end()) {
                p = last_pos[x];
            }
            last_pos[x] = j;

            // Range update [p+1, j] by +1
            update(1, 0, n - 1, p + 1, j, 1);

            // The root of the segment tree now holds the sum of squares of all subarrays ending at j
            current_total_squares = tree[1].sum_sq;
            total_sum = (total_sum + current_total_squares) % MOD;
        }

        return total_sum;
    }
};