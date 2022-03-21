class Solution {
public:
    
    int findind(int first[],int last[],int from, int to){
        int maxv=-1;
                for(int i=0;i<26;i++){
                    if(first[i]>=from && first[i]<=to)
                        maxv=max(maxv,last[i]);
                }
        return maxv;
    }
    vector<int> partitionLabels(string s) {
        int first[26];
        int last[26];
        int n=s.length();
        for(int i=0;i<26;i++)
        {
            first[i]=-1;
            last[i]=-1;
        }
        for(int i=0;i<n;i++){
            if(first[s[i]-'a']==-1){
                first[s[i]-'a']=i;
            }
        }
        
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        int from=0;
        int to=last[s[from]-'a'];
        vector<int> arr;
        while(from<n){
            if(to==from){
                arr.push_back(1);
                from++;
                if(from==n)
                    break;
                to=last[s[from]-'a']; 
            }
            else{
                int maxv=findind(first,last,from,to);
                if(maxv==n-1){
                    arr.push_back(n-from);
                    from=n;
                    break;
                }
                else if(maxv<=to){
                    arr.push_back(to-from+1);
                    from=to+1;
                    to=last[s[from]-'a'];
                }
                else{
                    to=maxv;
                }
            }
            
        }
        if(from <= to)
            arr.push_back(to-from+1);
        
        return arr;
        
        
    }
};