```
nums=[1,2,3]
backtrack([], 0)
    s=[[ ]]
    i=0, nums[0]=1
    push(1) → current=[1]
    backtrack([1], 1)
        s=[[], [1]]
        i=1, nums[1]=2
        push(2) → current=[1,2]
        backtrack([1,2], 2)
            s=[[], [1], [1,2]]
            i=2, nums[2]=3
            push(3) → current=[1,2,3]
            backtrack([1,2,3], 3)
                s=[[], [1], [1,2], [1,2,3]]
                (start=3, loop skipped)
            pop() → current=[1,2]
            i=2 → 3  (loop range(2,3) ends)
        pop() → current=[1]
        i=1 → 2, nums[2]=3
        push(3) → current=[1,3]
        backtrack([1,3], 3)
            s=[[], [1], [1,2], [1,2,3], [1,3]]
            (start=3, loop skipped)
        pop() → current=[1]
        i=2 → 3  (loop range(1,3) ends)
    pop() → current=[]
    i=0 → 1, nums[1]=2
    push(2) → current=[2]
    backtrack([2], 2)
        s=[[], [1], [1,2], [1,2,3], [1,3], [2]]
        i=2, nums[2]=3
        push(3) → current=[2,3]
        backtrack([2,3], 3)
            s=[[], [1], [1,2], [1,2,3], [1,3], [2], [2,3]]
            (start=3, loop skipped)
        pop() → current=[2]
        i=2 → 3  (loop range(2,3) ends)
    pop() → current=[]
    i=1 → 2, nums[2]=3
    push(3) → current=[3]
    backtrack([3], 3)
        s=[[], [1], [1,2], [1,2,3], [1,3], [2], [2,3], [3]]
        (start=3, loop skipped)
    pop() → current=[]
    i=2 → 3  (loop range(0,3) ends)
(backtrack([], 0) done — 8 subsets collected)
```