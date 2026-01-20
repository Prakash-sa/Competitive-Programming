# https://leetcode.com/problems/accounts-merge/description/

'''
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

Example 1:
Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

Example 2:
Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 

Constraints:

1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j].length <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j > 0) is a valid email.
'''

class DSU:
    def __init__(self,n):
        self.parent=[i for i in range(n)]
        self.rank=[1]*n

    def find(self,x):
        while x!=self.parent[x]:
            self.parent[x]=self.parent[self.parent[x]]
            x=self.parent[x]
        return x

    def union(self,a,b):
        p1,p2=self.find(a),self.find(b)
        if p1==p2:
            return False
        if self.rank[p1]>self.rank[p2]:
            self.parent[p2]=p1
            self.rank[p1]+=self.rank[p2]
        else:
            self.parent[p1]=p2
            self.rank[p2]+=self.rank[p1]
        return True

class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        dsu=DSU(len(accounts))
        email_to_acc={}

        for i,a in enumerate(accounts):
            for e in a[1:]:
                if e in email_to_acc:
                    dsu.union(i,email_to_acc[e])
                else:
                    email_to_acc[e]=i
    
        emailGroup=defaultdict(list)

        for e,i in email_to_acc.items():
            leader=dsu.find(i)
            emailGroup[leader].append(e)

        res=[]
        for i,emails in emailGroup.items():
            name=accounts[i][0]
            res.append([name]+sorted(emailGroup[i]))
        return res


# Here N is the number of accounts and K is the maximum length of an account.
# Time complexity: O(NKlogNK)
# While merging we consider the size of each connected component and we always choose the representative of the larger component to be the new representative of the smaller component, also we have included the path compression so the time complexity for find/union operation is α(N) (Here, α(N) is the inverse Ackermann function that grows so slowly, that it doesn't exceed 4 for all reasonable N (approximately N<10^600).
# We find the representative of all the emails, hence it will take O(NKα(N)) time. We are also sorting the components and the worst case will be when all emails end up belonging to the same component this will cost O(NK(logNK)).
# Hence the total time complexity is O(NK⋅logNK+NK⋅α(N)).

# Space complexity: O(NK)
# List representative, size store information corresponding to each group so will take O(N) space. All emails get stored in emailGroup and component hence space used is O(NK).
