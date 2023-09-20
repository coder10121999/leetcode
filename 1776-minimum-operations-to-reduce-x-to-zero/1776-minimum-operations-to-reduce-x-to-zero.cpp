class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        int left[n+1];
        int right[n+1];
        left[0] = 0;
        for(int i=1;i<=n;i++) {
            left[i] = left[i-1]+nums[i-1];
        }
        right[n] = 0;
        for(int i=n-1;i>=0;i--) {
            right[i] = right[i+1]+nums[i];
        }
        for(int i=0;i<=n;i++) {
            cout<<left[i]<<" ";
        }
        cout<<"\n";
        for(int i=0;i<=n;i++) {
            cout<<right[i]<<" ";
        }
    
        int minop = INT_MAX;
        for(int i=0;i<=n;i++) {
            int cursum = left[i];
            int val = x -left[i];
            int operations = i;
            int l = i; // up range
            int r = n; // low range
            int ind = -1;
            while(l<=r) {
                int mid = (l + r)/2;
                if(right[mid] == val) {
                    ind = mid;
                    break;
                } else if(right[mid] < val) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            if(ind == -1) continue;
            else {
                operations+=(n-ind);
                minop = min(minop, operations);
            }
        }

        if(minop == INT_MAX) return -1;
        
        return minop;

        // 0 3 5 25 26 27 30
        // 30 27 25 5 4 3 0
        

    }
};