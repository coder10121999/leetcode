class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0;
        int r=m-1;
        
       // if(taget<matrix[0][0] || target>matrix[m-1][n-1])
         //   return false;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(matrix[mid][0] <= target && matrix[mid][n-1]>= target)
            {
                int l2=0;
                int r2=n-1;
                while(l2<=r2)
                {
                    int mid2=l2+(r2-l2)/2;
                    if(matrix[mid][mid2]==target)
                        return true;
                    else if(matrix[mid][mid2]>target)
                        r2=mid2-1;
                    else
                        l2=mid2+1;
                }
                
                return false;
            }
            else if(target > matrix[mid][n-1])
                l=mid+1;
            else
                r=mid-1;
            
        }
        
        return false;
        
    }
};