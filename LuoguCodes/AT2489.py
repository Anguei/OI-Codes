nums = []
for i in range(10):
    nums.append(int(raw_input()))
print nums[0] - (sum(nums) - nums[0])
