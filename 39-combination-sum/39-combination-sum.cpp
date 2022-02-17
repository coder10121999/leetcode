class Solution {
public:
    vector<vector<int>> tmpans;
    void comb(vector<int> vec,vector<int> curvec,int target,int st){
        if(target<0)
            return;
        
        if(target ==0){
          //  sort(curvec.begin(),curvec.end());
            //for(int i=0;i<curvec.size();i++)
              //  cout<<curvec[i]<<" ";
            //cout<<"\n";
            tmpans.push_back(curvec);
            return;
        }
        
        for(int i=st;i<vec.size();i++){
            curvec.push_back(vec[i]);
            comb(vec,curvec,target-vec[i],i);
            curvec.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        
        vector<int> curvec;
        comb(candidates,curvec,target,0);
        for(auto it=tmpans.begin();it!=tmpans.end();it++){
            vector<int> z = *it;
           // for(int i=0;i<z.size();i++)
             //   cout<<z[i]<<" ";
            //cout<<"\n";
            ans.push_back(z);
        }
            
        return ans;
        
        
    }
};