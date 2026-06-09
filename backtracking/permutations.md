```
nums=[1,2,3], n=3

backtrack(start=0)
    start≠n, loop i in range(0,3)
    i=0: swap(nums[0],nums[0]) → nums=[1,2,3] (no-op swap)
        backtrack(start=1)
            start≠n, loop i in range(1,3)
            i=1: swap(nums[1],nums[1]) → nums=[1,2,3] (no-op swap)
                backtrack(start=2)
                    start≠n, loop i in range(2,3)
                    i=2: swap(nums[2],nums[2]) → nums=[1,2,3] (no-op swap)
                        backtrack(start=3)
                            start==n → append [1,2,3] ✓
                            return
                        swap back(nums[2],nums[2]) → nums=[1,2,3]
                    (loop range(2,3) ends)
                return
            swap back(nums[1],nums[1]) → nums=[1,2,3]
            i=1→2: swap(nums[1],nums[2]) → nums=[1,3,2]
                backtrack(start=2)
                    start≠n, loop i in range(2,3)
                    i=2: swap(nums[2],nums[2]) → nums=[1,3,2] (no-op swap)
                        backtrack(start=3)
                            start==n → append [1,3,2] ✓
                            return
                        swap back(nums[2],nums[2]) → nums=[1,3,2]
                    (loop range(2,3) ends)
                return
            swap back(nums[1],nums[2]) → nums=[1,2,3]
            (loop range(1,3) ends)
        return
    swap back(nums[0],nums[0]) → nums=[1,2,3]
    i=0→1: swap(nums[0],nums[1]) → nums=[2,1,3]
        backtrack(start=1)
            start≠n, loop i in range(1,3)
            i=1: swap(nums[1],nums[1]) → nums=[2,1,3] (no-op swap)
                backtrack(start=2)
                    i=2: swap(nums[2],nums[2]) → nums=[2,1,3] (no-op swap)
                        backtrack(start=3)
                            start==n → append [2,1,3] ✓
                            return
                        swap back(nums[2],nums[2]) → nums=[2,1,3]
                    (loop range(2,3) ends)
                return
            swap back(nums[1],nums[1]) → nums=[2,1,3]
            i=1→2: swap(nums[1],nums[2]) → nums=[2,3,1]
                backtrack(start=2)
                    i=2: swap(nums[2],nums[2]) → nums=[2,3,1] (no-op swap)
                        backtrack(start=3)
                            start==n → append [2,3,1] ✓
                            return
                        swap back(nums[2],nums[2]) → nums=[2,3,1]
                    (loop range(2,3) ends)
                return
            swap back(nums[1],nums[2]) → nums=[2,1,3]
            (loop range(1,3) ends)
        return
    swap back(nums[0],nums[1]) → nums=[1,2,3]
    i=1→2: swap(nums[0],nums[2]) → nums=[3,2,1]
        backtrack(start=1)
            start≠n, loop i in range(1,3)
            i=1: swap(nums[1],nums[1]) → nums=[3,2,1] (no-op swap)
                backtrack(start=2)
                    i=2: swap(nums[2],nums[2]) → nums=[3,2,1] (no-op swap)
                        backtrack(start=3)
                            start==n → append [3,2,1] ✓
                            return
                        swap back(nums[2],nums[2]) → nums=[3,2,1]
                    (loop range(2,3) ends)
                return
            swap back(nums[1],nums[1]) → nums=[3,2,1]
            i=1→2: swap(nums[1],nums[2]) → nums=[3,1,2]
                backtrack(start=2)
                    i=2: swap(nums[2],nums[2]) → nums=[3,1,2] (no-op swap)
                        backtrack(start=3)
                            start==n → append [3,1,2] ✓
                            return
                        swap back(nums[2],nums[2]) → nums=[3,1,2]
                    (loop range(2,3) ends)
                return
            swap back(nums[1],nums[2]) → nums=[3,2,1]
            (loop range(1,3) ends)
        return
    swap back(nums[0],nums[2]) → nums=[1,2,3]
    (loop range(0,3) ends)

permutations = [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,2,1], [3,1,2]]
```


```
nums=[1,2,3]
backtrack([])
    len(current)==0
    num=1, push(1) → current=[1]
    backtrack([1])
        len(current)==1
        num=1 (already in current, skip)
        num=2, push(2) → current=[1,2]
        backtrack([1,2])
            len(current)==2
            num=1 (already in current, skip)
            num=2 (already in current, skip)
            num=3, push(3) → current=[1,2,3]
            backtrack([1,2,3])
                len(current)==3
                p=[[1,2,3]]
                return
            pop() → current=[1,2]
            (loop ends)
        pop() → current=[1]
        num=3, push(3) → current=[1,3]
        backtrack([1,3])
            len(current)==2
            num=1 (already in current, skip)
            num=2, push(2) → current=[1,3,2]
            backtrack([1,3,2])
                len(current)==3
                p=[[1,2,3], [1,3,2]]
                return
            pop() → current=[1,3]
            num=3 (already in current, skip)
            (loop ends)
        pop() → current=[1]
        (loop ends)
    pop() → current=[]
    num=2, push(2) → current=[2]
    backtrack([2])
        len(current)==1
        num=1, push(1) → current=[2,1]
        backtrack([2,1])
            len(current)==2
            num=1 (already in current, skip)
            num=2 (already in current, skip)
            num=3, push(3) → current=[2,1,3]
            backtrack([2,1,3])
                len(current)==3
                p=[[1,2,3], [1,3,2], [2,1,3]]
                return
            pop() → current=[2,1]
            (loop ends)
        pop() → current=[2]
        num=2 (already in current, skip)
        num=3, push(3) → current=[2,3]
        backtrack([2,3])
            len(current)==2
            num=1, push(1) → current=[2,3,1]
            backtrack([2,3,1])
                len(current)==3
                p=[[1,2,3], [1,3,2], [2,1,3], [2,3,1]]
                return
            pop() → current=[2,3]
            num=2 (already in current, skip)
            num=3 (already in current, skip)
            (loop ends)
        pop() → current=[2]
        (loop ends)
    pop() → current=[]
    num=3, push(3) → current=[3]
    backtrack([3])
        len(current)==1
        num=1, push(1) → current=[3,1]
        backtrack([3,1])
            len(current)==2
            num=1 (already in current, skip)
            num=2, push(2) → current=[3,1,2]
            backtrack([3,1,2])
                len(current)==3
                p=[[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2]]
                return
            pop() → current=[3,1]
            num=3 (already in current, skip)
            (loop ends)
        pop() → current=[3]
        num=2, push(2) → current=[3,2]
        backtrack([3,2])
            len(current)==2
            num=1, push(1) → current=[3,2,1]
            backtrack([3,2,1])
                len(current)==3
                p=[[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
                return
            pop() → current=[3,2]
            num=2 (already in current, skip)
            num=3 (already in current, skip)
            (loop ends)
        pop() → current=[3]
        num=3 (already in current, skip)
        (loop ends)
    pop() → current=[]
    (loop ends)
(backtrack([]) done — 6 permutations collected)
```