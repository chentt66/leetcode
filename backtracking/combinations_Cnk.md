```
n=3, k=2
backtrack([], 1)
    len(current)==0<2
    i=1, push(1) → current=[1]
    backtrack([1], 2)
        len(current)==1<2
        i=2, push(2) → current=[1,2]
        backtrack([1,2], 3)
            len(current)==2==k
            cnk=[[1,2]]
            return
        pop() → current=[1]
        i=2→3, push(3) → current=[1,3]
        backtrack([1,3], 4)
            len(current)==2==k
            cnk=[[1,2], [1,3]]
            return
        pop() → current=[1]
        i=3→4 (loop range(2,4) ends)
    pop() → current=[]
    i=1→2, push(2) → current=[2]
    backtrack([2], 3)
        len(current)==1<2
        i=3, push(3) → current=[2,3]
        backtrack([2,3], 4)
            len(current)==2==k
            cnk=[[1,2], [1,3], [2,3]]
            return
        pop() → current=[2]
        i=3→4 (loop range(3,4) ends)
    pop() → current=[]
    i=2→3, push(3) → current=[3]
    backtrack([3], 4)
        len(current)==1<2
        i=start=4 (loop range(4,4) skipped)
    pop() → current=[]
    i=3→4 (loop range(1,4) ends)
(backtrack([], 1) done — 3 combinations collected)
```