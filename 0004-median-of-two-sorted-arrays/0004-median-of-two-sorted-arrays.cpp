class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // n + m is odd 
        // find (n+m)/2th element
        // n+m is even
        // find (n+m)/2th ans (n+m)/2 - 1 th element
        vector<int> vec;
        int m = nums1.size();
        int n = nums2.size();
        int pt1 = 0, pt2 = 0;
        while(pt1 != m || pt2 != n) {
            //cout<<pt1<<" "<<pt2<<"\n";
            if(pt1 == m) {
                vec.push_back(nums2[pt2]);
                pt2++;
                continue;
            }

            if(pt2 == n) {
                vec.push_back(nums1[pt1]);
                pt1++;
                continue;
            }

            if(nums1[pt1] <= nums2[pt2]) {
                vec.push_back(nums1[pt1]);
                pt1++;
            } else {
                vec.push_back(nums2[pt2]);
                pt2++;
            }
        }
        //for(int i=0;i<vec.size();i++) cout<<vec[i]<<" ";
        int mid = (m+n)/2;
        bool isOdd = (m+n)%2 == 1;
        double val = isOdd ? vec[mid] : (vec[mid] + vec[mid-1])/2.0;
        return val;
        return 0.0;
    }
};