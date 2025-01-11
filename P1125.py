word=str(input())
list1=[]
def prime(a):
    flag=True
    if (a<=1):
        flag=False
    for i in range(2,int(a**0.5+1)):
        if a%i==0:
            flag=False
            break
    return flag

for i in range(len(word)):
    c=word.count(word[i:i+1])
    list1.append(c)

maxn=0
minn=105
for i in range(len(list1)):
    minn=min(minn,list1[i])
    maxn=max(maxn,list1[i])

if prime(maxn-minn):
    print("Lucky Word")
    print(maxn-minn)
else:
    print("No Answer")
    print("0")