1    nums=[1,2,3]
 2    backtrack([], 0)
 3        s <-- [[]]
 4        i=start=0 # for i in range(0, 3)
 5        nums[0]=1
 6        current <-- [1]
 7        backtrack([1], 1)
 8            s <-- [[], [1]]
 9            i=start=1 # for i in range(1, 3)
10            nums[1]=2
11            current <-- [1, 2]
12            backtrack([1,2], 2)
13                s <-- [[], [1], [1,2]]
14                i=start=2 # for i in range(2, 3)
15                nums[2]=3
16                current <-- [1,2,3]
17                backtrack([1,2,3], 3)
18                    s <-- [[], [1], [1,2], [1,2,3]]
19                    # start=3. loop does nothing
20                pop()
21                current=[1,2]
22                i:2 to 3
23                # loop `for i in range(2, 3)` ends
24            pop()
25            current=[1]
26            i:1 to 2
27            nums[2]=3
28            current <-- [1,3]
29            backtrack([1,3], 3)
30                s <-- [[], [1], [1,2], [1,2,3], [1,3]]
31                # loop does nothing
32            pop()
33            current=[1]
34            i:2 to 3
35            # loop `for i in range(1, 3)` ends
36        pop()
37        current=[]
38        i:0 to 1 # for i in range(0, 3)
39        nums[1]=2
40        current <-- [2]
41        backtrack([2], 2)
42            s <-- [[], [1], [1,2], [1,2,3], [1,3], [2]]
43            start=2 # for i in range(2, 3)
44            nums[2]=3
45            current <-- [2,3]
46            backtrack([2, 3], 3)
47                s <-- [[], [1], [1,2], [1,2,3], [1,3], [2], [2,3]]
48                # start=3. loop does nothing
49            pop()
50            current=[2]
51            i:2 to 3
52            # loop `for i in range(2, 3)` ends
53        pop()
54        current=[]
55        i:1 to 2 # for i in range(0, 3)
56        nums[2]=3
57        current <-- [3]
58        backtrack([3], 3)
59            s <-- [[], [1], [1,2], [1,2,3], [1,3], [2], [2,3], [3]]
60            # start=3. loop does nothing
61        pop()
62        current=[]
63        i: 2 to 3 # for i in range(0, 3)
64        # loop `for i in range(0, 3)` ends
65    # backtrack([], 0) finishes
