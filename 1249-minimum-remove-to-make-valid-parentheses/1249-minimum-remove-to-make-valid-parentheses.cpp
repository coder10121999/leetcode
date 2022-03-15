class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        stack<int> st;
        int fault[n];
        for(int i=0;i<n;i++)
            fault[i]=0;
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z')
                continue;
            else{
                if(s[i]=='(')
                    st.push(i);
                else{
                    if(st.empty())
                    {
                        fault[i]=1;
                        continue;
                    }
                    
                    if(s[st.top()]=='(')
                        st.pop();
                    
                }
            }
                
        }
        
        while(!st.empty()){
            fault[st.top()]=1;
            st.pop();
        }
        
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(fault[i]==0)
                ans+=s[i];
        }
        
        return ans;
    }
};