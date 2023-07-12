// problem link
class Solution {
public:
    vector<int>tree;
    vector<int>nums;
    int query(int ind, int l, int r, int start, int end){
        
        if(r < start || l > end)return INT_MIN;
        
        if(l <= start && end <= r)return tree[ind];
        
        if(start == end){
            return tree[ind];
        }
        
        int mid = (start + end) / 2;
        
        auto ll = query(2 * ind + 1, l, r, start, mid);
        auto rr = query(2 * ind + 2, l, r, mid + 1, end);
        
        return max({ll, rr});
    }
    int update(int ind, int l, int r, int start, int end, int val){

        if(r < start || l > end)return tree[ind];
        if(start == end){
            tree[ind] = val;
            return val;
        }
        long long int mid = start + (end - start) / 2;
        //int ll = 0, rr = 0;
        
        auto ll = update(2 * ind + 1, l, r, start, mid, val);
        //else
        auto rr = update(2 * ind + 2, l, r, mid + 1, end, val);
        
        tree[ind] = max(ll, rr);
        return tree[ind];
    }
    int lengthOfLIS(vector<int>& nums, int k) {

        int ans = 0;
        int mx = *max_element(nums.begin(), nums.end());
        tree.resize(4 * mx + 12, 0);
        this->nums = nums;
        
        for(int i = 0; i < nums.size(); i++){
            int cur = nums[i];

                int prev = cur - k;
                int val = query(0, prev, cur - 1, 0, mx);
                int val1 = query(0, cur, cur, 0, mx);
                if(val1 >= val + 1)continue;
                ans = max(ans, val + 1);
                update(0, cur, cur, 0, mx, val + 1);
            // }
        }
        return ans;
    }
};
