from collections import defaultdict

class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        groups = defaultdict(list)
        for pid, group_size in enumerate(groupSizes):
            groups[group_size].append(pid)
        
        ans = []
        for group_size, pid_list in groups.items():
            for begin_idx in range(0, len(pid_list), group_size):
                ans.append(pid_list[begin_idx:begin_idx+group_size])
        
        return ans