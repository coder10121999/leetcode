class Solution {
public:
    string simplifyPath(string path) {
        
        int n=path.length();
        string newpath="";
        int f=0;
        for(int i=0;i<n;i++){
            if(f==1 && path[i]=='/'){
                continue;
            }
            if(path[i]=='/'){
                f=1;
                newpath+=path[i];
                continue;
            }
            newpath+=path[i];
            f=0;
        }
        
        vector<string> arr;
        string cur="";
        for(int i=0;i<newpath.length();i++){
            if(newpath[i]=='/'){
                if(cur!="")
                    arr.push_back(cur);
                cur="";
                continue;
            }
            cur+=newpath[i];
            
        }
        if(cur!="")
            arr.push_back(cur);
        
        string ans="";
        ans+='/';
        stack<string> st;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==".")
                continue;
            else if(arr[i]==".."){
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(arr[i]);
        }
        
        vector<string> vec;
        while(!st.empty()){
            vec.push_back(st.top());
            st.pop();
        }
        for(int i=vec.size()-1;i>=0;i--){
            ans+=vec[i];
            if(i!=0)
            ans+='/';
        }
        
        return ans;
    }
};