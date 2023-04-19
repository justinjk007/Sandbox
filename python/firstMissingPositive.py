class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:

        # Find the smallest postive int in the array O(n)
        # Assuming 1 is the smallest
        smallest_int = 1
        for i in nums:
            if(i < smallest_int and i > 0):
                smallest_int = i

        # Check if the smallest int exist in the array, it could be 1 but 1 doesn't exist
        for i in nums:
            if(i == smallest_int):
                smallest_int = i+1

        # # Since the integer must be a missing one, if something in
        # # the array is what we have as the smallest int, make the
        # # next int our new smallest int
        # if(i == smallest_int):
        #     smallest_int = i+1

        return smallest_int
