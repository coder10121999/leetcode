typedef long long int ll;
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        vector<pair<ll, ll>> vec;
        ll co = 0;
        string ans = "";
        for(int i=0;i<s.length();i++) {
            if(s[i] >= 'a' && s[i]<='z') {
                co++;
            } else {
                vec.push_back({co, s[i]-'0'});
                co = 0;
            }
        }
        if(co>0) {
            vec.push_back({co, -1});
        }
        vector<pair<ll,ll>> sum = vec;
        for(int i=0;i<sum.size();i++) {
            sum[i].first += i>0 ? sum[i-1].first : 0;
            cout<<sum[i].first<<" "<<sum[i].second<<"\n";
        }

        vector<ll> range;
        for(int i=0;i<(2*vec.size());i++) {
            int z = range.size();
            if(i%2 == 0) {
                range.push_back(z == 0 ? vec[i/2].first : vec[i/2].first + range[z-1]);
            } else {
                if(vec[i/2].second != -1)
                range.push_back(vec[i/2].second * range[z-1]);
            }
        }
        int pt = -1;
        for(int i=0;i<range.size();i++) {
            if(k<=range[i]) {
                pt = i;
                break;
            }
        }

        for(int i=pt;i>=0;i--) {
            ll x = vec[i/2].first;
            ll d = vec[i/2].second;

            if(i%2 == 0) {
                if(k > range[i]-x) {
                    k-=(range[i]-x);
                    ll prevsum = i > 0 ? sum[(i-1)/2].first + (i-1)/2 : -1;
                    ans+=s[prevsum+k];
                    return ans;
                    // val = sum of all xi before cur x + i/2
                    // anser is [val , val+x] in original string
                }
            } else {
                if(k% range[i-1] == 0) k = range[i-1];
                else k = k%range[i-1];
            }
        }
        return ans;
    }
};