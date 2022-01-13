class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end());
        int ans=0;
        
        int st=points[0][0];
        int en=points[0][1];
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]<=en)
            {
                st=max(st,points[i][0]);
                en=min(en,points[i][1]);
                continue;
            }
            else
            {
                ans++;
                st=points[i][0];
                en=points[i][1];
            }
        }
        
        return ans+1;
        
    }
};