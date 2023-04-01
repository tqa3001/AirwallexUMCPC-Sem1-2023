cookie = input()

tally = [0,0] #i=0  -> o's, i=1, -> 're'
i=0
while i<len(cookie):
    if cookie[i]=='o':
        tally[0]+=1
    if cookie[i]=='r':
        tally[1]+=1
        i+=1 #needs to skip following e
    i+=1

# normal oreo has 2x o, 1x re
o = tally[0]//2+tally[0]%2
c = tally[1]-o if tally[1]>o else 0
print(c+o)