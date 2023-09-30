class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int minv=0,maxv=0;
        int n=nums.size();
        // for each i store max a[i] smaller than a[i] rtmaxsm[]
        // for each i store min element on left side leftsm[]
        // for some i if rtmaxsum[] > leftsm[] return true
        int leftsm[n];
        for(int i=0;i<n;i++) leftsm[i] = INT_MIN;
        int val = nums[0];
        for(int i=1;i<n;i++){
            leftsm[i] = val;
            val = min(val, nums[i]);
        }
        int rtmaxsum[n];
        int pge[n];
        for(int i=0;i<n;i++) {
            rtmaxsum[i] = INT_MIN;
            pge[i] = INT_MIN;
        }
        stack<int> st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--) {
            if(st.empty()) st.push(i);
            while(!st.empty() && nums[st.top()] < nums[i]) {
                pge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++) {
            int prevind = pge[i];
            if(prevind != INT_MIN) {
                rtmaxsum[prevind] = max(rtmaxsum[prevind], nums[i]);
            }
        }

        for(int i=0;i<n;i++) {
            if(rtmaxsum[i] != INT_MIN && leftsm[i] != INT_MIN && rtmaxsum[i] > leftsm[i]) return true;
        }
        return false;


        
    }
};