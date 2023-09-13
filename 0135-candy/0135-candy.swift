class Solution {
    func candy(_ ratings: [Int]) -> Int {
        let n = ratings.count
        var temp = Array(repeating: 1, count: n)
        var ans = 0
        if n >= 2 {
          for i in 1...n-1 {
             if ratings[i] > ratings[i-1] {
               temp[i] = max(temp[i],temp[i-1]+1)
             }
          }
          for i in (0...n-2).reversed() {
            if ratings[i] > ratings[i+1] {
              temp[i] = max(temp[i],temp[i+1]+1)
            }
          }
        }
        ans = temp.reduce(0,+)
        return ans
    }
}