# https://leetcode.com/problems/encode-and-decode-strings/description/

'''
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:
string encoded_string = encode(strs);
and Machine 2 does:
vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.
Implement the encode and decode methods.
You are not allowed to solve the problem using any serialize methods (such as eval).

Example 1:
Input: dummy_input = ["Hello","World"]
Output: ["Hello","World"]
Explanation:
Machine 1:
Codec encoder = new Codec();
String msg = encoder.encode(strs);
Machine 1 ---msg---> Machine 2
Machine 2:
Codec decoder = new Codec();
String[] strs = decoder.decode(msg);
Example 2:
Input: dummy_input = [""]
Output: [""]
 

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] contains any possible characters out of 256 valid ASCII characters.
 
Follow up: Could you write a generalized algorithm to work on any possible set of characters?
'''

class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        encode_string=[]
        for s in strs:
            encode_string.append(str(len(s))+':'+s)
        return "".join(encode_string)
        

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """ 
        res,i=[],0
        while i<len(s):
            j=i
            while s[j]!=':':
                j+=1
            length=int(s[i:j])
            j+=1
            res.append(s[j:j+length])
            i=j+length
        return res

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))

# Complexity Analysis
# Let n denote the total number of characters across all strings in the input list and k denote the number of strings.

# Time Complexity: O(n).

# We are iterating through each string once.

# Space Complexity: O(k).

# We don't count the output as part of the space complexity, but for each word, we are using some space for the length and delimiter.