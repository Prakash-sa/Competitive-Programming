# 1

# dictionary={
#     'a':[0,1,2],
#     'b':[1,2,3],
#     'c':[0,3]
# }
# search=1

# answer=[]

# for key,values in dictionary.items():
#     my_set=set(values)
#     if search in my_set:
#         answer.append(key)

# for ans in answer:
#     print(ans)


# 2


import re
# import itertools

# list1 = [1, 2, 3]

# perm = []
# perm = list(itertools.permutations(list1, len(list1)))
# print(perm)

answer=[]
def perm(a, k=0):
   if k == len(a):
      answer.append(a)
   else:
      for i in range(k, len(a)):
         a[k], a[i] = a[i] ,a[k]
         perm(a, k+1)
         a[k], a[i] = a[i], a[k]


inp=[1,2,3]


# # answer=permutation(inp)
# # for i in inp:
# #     print(i)


# ## 3

# print("\n\n")
perm(inp)
print(answer)


# 4

inpstring = "MyPasswordFieldClass"
answer=""
first = True

for c in inpstring:
    if c.isupper() == True:
        if first == True:
            answer+= c.lower()
            first = False
        else:
            answer+= '.'+c.lower()
    else :
        answer+=c

print(answer)

# 5


s = ["Hi", "Hello World", "hey you"]
# buffer = "tags = { 'Hi', \"Hello World\", \"hey you\", \"Hi\' }"
# my_list = re.findall(r"['\"](.*?)['\"]", buffer)
matches = []
non_matches = []
for c in s:
    tmp = c.lower()
    if re.search('hello', tmp):
        matches.append(c)
    elif re.search('hey', tmp):
        matches.append(c)
    elif re.search('hi', tmp):
        matches.append(c)
    else:
        non_matches.append(c)

print("\n")
print("Matches ")
for ma in matches:
    print(ma)

print("\ndoes not match")

for dm in non_matches:
    print(dm)
