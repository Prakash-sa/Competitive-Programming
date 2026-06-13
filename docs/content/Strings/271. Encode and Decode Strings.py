# https://leetcode.com/problems/encode-and-decode-strings/description/

"""
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
"""


class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string."""
        encode_string = []
        for s in strs:
            encode_string.append(str(len(s)) + "/:" + s)
        return "".join(encode_string)

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings."""
        res, i = [], 0
        while i < len(s):
            j = s.find("/:", i)
            length = int(s[i:j])
            j += 2
            res.append(s[j : j + length])
            i = j + length
        return res


"""
Chunked Transfer Encoding
Intuition
Chunked transfer encoding is a method used in data communication protocols to send data in self-contained chunks, each of which is accompanied by its length or size. In the context of our problem, this technique can be very useful.

In our encoding process, instead of just joining all the strings together with a delimiter, we would precede each string with its length, followed by a delimiter, and then the string itself. This way, even if our string contains the delimiter, we can correctly identify the string boundaries.

When we decode our encoded string, we know that the first item before the delimiter is the length of the string.

Consider an example for a list of strings using chunked transfer encoding.

Suppose we have the following list of strings: ["Hello", "World", "/:Example/:"]. As you can see, our last string even contains the /: character sequence that we might choose as our delimiter.

Let's see how we would encode and decode this using chunked transfer encoding.

Encoding:

For the encoding, we take each string's length, followed by a delimiter (we'll use /:), and then the string itself.

For "Hello", the length is 5. So we start our encoded string with 5/:Hello.

Next, for "World", the length is 5 as well. So we add 5/:World to our encoded string.

Finally, for "/:Example/:", the length is 11. We add 11/:/:Example/: to our encoded string.

After processing all strings, our encoded string becomes 5/:Hello5/:World11/:/:Example/:.

Decoding:

For the decoding process, we start reading the encoded string.

First, we read until we encounter /:, which gives us 5. This tells us that the length of our first string is 5. So, we read the next 5 characters to get "Hello".

Next, we again read until /: to get 5, indicating that our next string is of length 5. Reading the next 5 characters gives us "World".

Finally, reading until the next /: gives us 11. Reading the next 11 characters gives us "/:Example/:".

After processing the whole encoded string, we are left with the original list of strings: ["Hello", "World", "/:Example/:"].

Through this process, we have successfully encoded and decoded our list of strings using chunked transfer encoding. Even though our list contained a string with the delimiter sequence, we were still able to accurately encode and decode the list.

The advantage of this method is that it doesn't matter what characters our string consists of. It could include the delimiter, or any other special or non-ASCII characters, and we would still correctly encode and decode the list of strings. This is because we always know where each string starts and ends, thanks to the length prefix.

Numbers being in the string can't confuse the algorithm either since the number characters would be after the delimiter /:. For example, let's say we had ["Hello", "32World", "Example"]. It would encode to "5/:Hello7:/32World7:/Example". We read the 7, then stop upon seeing the delimiter, and the 32 being a number is irrelevant.

Algorithm
Note: we are using /: as a delimiter solely for continuity (as we used it in the previous approach). However, we could use any non-digit delimiter for this approach, like # for example.
"""

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))

# Chunked Transfer Encoding

# Complexity Analysis
# Let n denote the total number of characters across all strings in the input list and k denote the number of strings.

# Time Complexity: O(n).

# We are iterating through each string once.

# Space Complexity: O(k).

# We don't count the output as part of the space complexity, but for each word, we are using some space for the length and delimiter.
