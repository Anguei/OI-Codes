nums = []
for i in range(5):
    nums.append(int(raw_input()))
print min(nums[:3]) + min(nums[-2:]) - 50
