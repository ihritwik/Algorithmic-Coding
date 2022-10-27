from typing import List
class Solution:
    # Approach 1: Time Complexity -> O(nlogn)
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        points.sort(key=lambda point: point[0]**2 + point[1]**2)
        return points[:k]
if __name__ == "__main__":
    ob = Solution()
    points= [[3,3],[5,-1],[-2,4]]
    k = 2
    print(ob.kClosest(points, k))



