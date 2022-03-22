class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0;
        stack<string> st;
       // int cur=0,z=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                if(st.top()=="(")
                {
                    st.pop();
                    int val=1;
                    if(!st.empty() && st.top()!="("){
                        int z=stoi(st.top());
                        val+=z;
                        st.pop();
                    }
                    
                    st.push(to_string(val));
                }
                else{
                    int z=stoi(st.top());
                    z*=2;
                    st.pop();
                    st.pop();
                    if(!st.empty() && st.top() != "("){
                        int val=stoi(st.top());
                        z+=val;
                        st.pop();
                       // st.push((char)val);
                    }
                    
                    st.push(to_string(z));
                    
                }
            }
            else
                st.push("(");
        }
        
        while(!st.empty()){
            ans+=stoi(st.top());
            st.pop();
        }
        
        return ans;
            
        
    }
};