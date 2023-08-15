#User function Template for python3

class Solution:
    def maxOnes(self, arr, n):
        
        # Your code goes here
        max_ending_here = 0
        max_so_far = 0
        ones_count = 0
    
        for i in range(n):
            max_ending_here += 1 if arr[i] == 0 else -1
            max_so_far = max(max_so_far, max_ending_here)
            ones_count += arr[i]
            max_ending_here = max(0, max_ending_here)
        
        if max_so_far == 0 and ones_count == 0:
            return n - 1
        
        return max_so_far + ones_count
                    
                    
       


#{ 
 # Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        ob=Solution()
        print(ob.maxOnes(a, n))

        T -= 1


if __name__ == "__main__":
    main()



# } Driver Code Ends