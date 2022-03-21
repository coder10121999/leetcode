class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        //map<int,int> mp;
        int n=pushed.size();
        int k=0;
        int m=popped.size();
        for(int i=0;i<n;i++){
            st.push(pushed[i]);
            while(k<m && !st.empty() && popped[k]==st.top()){
                st.pop();
                k++;
            }
        }
        
        if(st.empty() && k==m)
            return true;
        
        return false;
    }
};