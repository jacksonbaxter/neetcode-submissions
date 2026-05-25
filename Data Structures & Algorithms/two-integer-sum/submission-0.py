class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        find = {}

        for i in range(len(nums)):
            difference = target - nums[i]
            if difference in find:
                return [find[difference], i]
            find[nums[i]] = i