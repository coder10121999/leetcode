class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0;
        int face=0;
        string s=instructions;
        for(int steps=0;steps<4;steps++)
        {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='G')
            {
                if(face==0)
                    y+=1;
                else if(face==2)
                    y-=1;
                else if(face==1)
                    x+=1;
                else
                    x-=1;
            }
            else if(s[i]=='L')
            {
                face-=1;
                face+=4;
                face%=4;
            }
            else
            {
                face+=1;
                face%=4;
            }
        }
            if(x==0 && y==0)
                return true;
        }
        
        return false;
        
    }
};