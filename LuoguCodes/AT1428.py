nums = map(int, raw_input().split())
nums.sort()
if nums[0] == nums[2]:
    print(nums[0])
else:
    if nums[0] == nums[1]:
        print(nums[2])
    elif nums[1] == nums[2]:
        print(nums[0])
