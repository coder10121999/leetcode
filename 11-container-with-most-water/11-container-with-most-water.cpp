class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n=height.size();
        vector<pair<int,int>> right,left;
        int maxindr[n];
        int maxindl[n];
        int maxv=-1;
        for(int i=0;i<n;i++)
            maxindr[i]=0,maxindl[i]=0;
        
        for(int i=0;i<n;i++)
        {
            int z=height[i];
            int l=0;
            int r=right.size()-1;
            int ans=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(right[mid].first>=z)
                {
                    ans=right[mid].second;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            
            maxindr[i]=ans;
            if(z>maxv)
            {
            if(ans==-1)
                right.push_back({z,i});
            else
               right.insert(right.begin()+ans,{z,i});
            maxv=max(maxv,z);
            }
            
        }
        
        maxv=-1;
        
        for(int i=n-1;i>=0;i--)
        {
            int z=height[i];
            int l=0;
            int r=left.size()-1;
            int ans=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(left[mid].first>=z)
                {
                    ans=left[mid].second;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            
            maxindl[i]=ans;
            if(z>maxv)
            {
            if(ans==-1)
                left.push_back({z,i});
            else
               left.insert(left.begin()+ans,{z,i});
            maxv=max(maxv,z);
            }
            
        }
      /*  for(int i=0;i<n;i++)
            cout<<maxindr[i]<<" ";
        cout<<"\n";
        
        for(int i=0;i<n;i++)
            cout<<maxindl[i]<<" ";
        cout<<"\n";*/
        
        int area=-1;
        for(int i=0;i<n;i++)
        {
            int d1=0,d2=0;
            
            if(maxindr[i]!=-1)
                d1=abs(i-maxindr[i]);
            if(maxindl[i]!=-1)
                d2=abs(i-maxindl[i]);
            area=max(area,height[i]*max(d1,d2));
          //  cout<<area<<"\n";
        }
        
        return area;
        
        
        
        
    }
};