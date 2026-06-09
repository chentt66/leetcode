

# Brute force
class Solution(object):
    def earliestFinishTime(self, landStartTime, landDuration, waterStartTime, waterDuration):
        """
        :type landStartTime: List[int]
        :type landDuration: List[int]
        :type waterStartTime: List[int]
        :type waterDuration: List[int]
        :rtype: int
        """
        def min_time(start1, duration1, start2, duration2):
            finish_time = -1
            for i in range(len(start1)):
                for j in range(len(start2)):
                    next_start_time = start1[i] + duration1[i]
                    if finish_time == -1:
                        finish_time = max(next_start_time, start2[j]) + duration2[j]
                    else:
                        finish_time = min(finish_time, max(next_start_time, start2[j])+duration2[j])
            return finish_time
        
        return min(min_time(landStartTime, landDuration, waterStartTime, waterDuration), 
                   min_time(waterStartTime, waterDuration, landStartTime, landDuration))