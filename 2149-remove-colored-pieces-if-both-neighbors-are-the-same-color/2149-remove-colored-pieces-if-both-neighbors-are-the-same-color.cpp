class Solution {
public:
    bool winnerOfGame(string colors) {
        int coA = 0;
        int coB = 0;
        int n = colors.length();
        for(int i=1;i<n-1;i++) {
            if(colors[i] == 'A') {
                if(colors[i-1] == 'A' && colors[i+1] == 'A') coA++;
            } else {
                if(colors[i-1] == 'B' && colors[i+1] == 'B') coB++;
            }
        }
        return coA > coB;
    }
};