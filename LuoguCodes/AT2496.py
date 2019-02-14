nums1, nums2 = [], []
for i in range(10):
    nums1.append(int(raw_input()))
for i in range(10):
    nums2.append(int(raw_input()))
nums1.sort()
nums2.sort()
print nums1[9] + nums1[8] + nums1[7], nums2[9] + nums2[8] + nums2[7]
