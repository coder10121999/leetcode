class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double ans=0.0;
        vector<vector<double>> arr;
        for(int i=0;i<=100;i++){
            vector<double> vec;
            for(int j=0;j<=i;j++)
                vec.push_back(0.0);
            arr.push_back(vec);
        }
        
        arr[0][0]=(double)poured;
        for(int i=0;i<100;i++){
            for(int j=0;j<=i;j++){
                if(arr[i][j]>1.0){
                    double left=arr[i][j]-1.0;
                    arr[i+1][j]+=left/2.0;
                    arr[i+1][j+1]+=left/2.0;
                    arr[i][j]=1.0;
                }
            }
        }
        
      /*  for(int i=0;i<=10;i++){
            for(int j=0;j<=i;j++)
                cout<<arr[i][j]<<" ";
            cout<<"\n";
        }*/
        
        return arr[query_row][query_glass];
    }
};