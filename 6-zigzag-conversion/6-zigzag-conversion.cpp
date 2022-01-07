class Solution {
public:
    string convert(string s, int numRows) {
        vector<char> vec[numRows];
        string ans="";
        int ind=-1;
        char x;
        int itr=0;
        int f=0;
        int n=s.length();
        
        if(numRows==1)
            return s;
        
        while(true)
        {
            
            int z= itr % (numRows-1);
        for(int i=0;i<numRows;i++)
        {
        
            
            if(z==0)
            {
                ind++;
                if(ind==s.length())
                {
                    f=1;
                    break;
                }
                x=s[ind];
            }
            else
            {
                if(numRows-z==(i+1))
                {
                    ind++;
                    if(ind==s.length())
                    {
                    f=1;
                    break;
                    }
                    x=s[ind];
                }
                else 
                    x=' ';
            }
            
          //  cout<<x<<"\n";
            vec[i].push_back(x);
        }
             if(f==1 || ind==s.length())
                break;
            itr++;
            
        }
    
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<vec[i].size();j++)
            {
                if(vec[i][j]!=' ')
                    ans+=vec[i][j];
            }
                
        }
        
        return ans;
    }
};