
def perform(n, p):
    if p < n-1:
        return []
    out = []
    low = 0 
    c = 1
    for i in range(n-1, 0, -1):
        c += 1

        if low+c+i-1 >= p:
            r = p-low-i+1
            out.append(r)
            for k in range(i-1):
                out.append(1)
            low = p
            break

        low += c 
        out.append(c)
    if low<p:
        return []
    return out

def operate(l, listed):
    length = len(listed)
    for i in range(length):
        t = len(l)-(i+2)
        sp = t+listed[i]
        l = l[:t]+ list(reversed(l[t:sp])) + l[sp:]
    return l 

def solve():
    cin = input().split()
    n = int(cin[0])
    p = int(cin[1])
    l = [*range(1, n+1, 1)]
    opeL = perform(n,p)
    l = operate(l, opeL)
    result = " "
    if opeL:
        for item in l:
            result += str(item)+ " "
    else:
        result =" IMPOSSIBLE"
    print("Case #"+str(i+1)+": "+ str(result))

for i in range(int(input())):
    solve()