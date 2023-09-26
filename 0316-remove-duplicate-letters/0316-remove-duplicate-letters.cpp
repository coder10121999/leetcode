class Solution {
public:
    string removeDuplicateLetters(string s) {

        int n = s.length();
        string ans = "";
        int arr[26] = {0};
        for(int i=0;i<n;i++) arr[s[i]-'a']++;

        vector<int> adj[26];
        for(int i=0;i<n;i++) {
            adj[s[i]-'a'].push_back(i);
        }

        int last[26];
        for(int i=0;i<n;i++) {
            last[s[i]-'a'] = i;
        }

        bool vis[26];
        int visco = 0;
        for(int i=0;i<26;i++) {
            if(arr[i] > 0)
            vis[i] = false;
            else
            {
                vis[i] = true;
                visco++;
            }
        }
        int ind = -1;
        while(visco != 26) {
            for(int i=0;i<26;i++) {
                if(vis[i] == false) {
                    int z = lower_bound(adj[i].begin(), adj[i].end(), ind) - adj[i].begin();
                    int flag = 0;
                    for(int j=0;j<26;j++) {
                        if(vis[j] == false && j!=i) {
                            if(last[j] < adj[i][z]) {
                                flag =1;
                                break;
                            }
                        }
                    }

                    if(flag == 0) {
                        ans+=(char)(97+i);
                        ind = adj[i][z];
                        visco++;
                        vis[i] = true;
                        break;
                    }
                }
            }
            // z ke first occurence after index ind has all non vis values last occurence after it
            // mark as vis
            // append to answer

            // remove and check on next 
        }

        // for(int i=s.length()-1;i>=0;i--) {
        //     if(arr[s[i]-'a'] == -1) {
        //         arr[s[i]-'a'] = i;
        //     }
        // }
        // vector<pair<int,int>> vec;
        // for(int i=0;i<26;i++) {
        //     if(arr[i] != -1)
        //     vec.push_back({arr[i], i});
        // }
        // sort(vec.begin(), vec.end());
        // // for(int i=0;i<vec.size();i++) {
        // //     cout<<vec[i].first<<" "<<vec[i].second<<"\n";
        // // }
        // for(int i=0;i<vec.size();i++) {
        //     char x = (char)(97+vec[i].second);
        //     //cout<<x<<"\n";
        //     ans+=x;
        // }
        return ans;
        // if(co[i] > 1) 
        // shift values less than i in cur string before i
    }
};