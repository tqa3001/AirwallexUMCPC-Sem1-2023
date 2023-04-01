def update(minstack,  maxstack,  num):
    if minstack and num<minstack[-1]:
        minstack.append(num)
    elif not minstack:
        minstack.append(num)

    if maxstack and num>maxstack[-1]:
        maxstack.append(num)
    elif not maxstack:
        maxstack.append(num)

import collections 
tally = collections.defaultdict(int)
minstack = []
maxstack = []
n,q = map(int, input().split()) 

process = map(int, input().split()) 

for num in process:
    update(minstack,  maxstack,  num)
    tally[num]+=1
print(maxstack[-1]-minstack[-1])

for _ in range(q):
    step, num = map(int, input().split()) 

    if step == 1:
        tally[num]+=1
        update(minstack,  maxstack,  num)

    else:
        tally[num]-=1
        if num==maxstack[-1] and tally[num]==0:
            maxstack.pop()

        if num==minstack[-1] and tally[num]==0:
            minstack.pop()

    print(maxstack[-1]-minstack[-1])