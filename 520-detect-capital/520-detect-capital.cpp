class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        int cocap=0,colow=0;
        for(int i=0;i<n;i++)
        {
            if(word[i]>='A' && word[i]<='Z')
             cocap++;
            else if(word[i]>='a' && word[i]<='z')
             colow++;
        }
        
        if(cocap==n)
            return true;
        if(colow==n)
            return true;
        
        if(cocap==1 && word[0]>='A' && word[0]<='Z')
            return true;
        
        return false;
        
    }
};