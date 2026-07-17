# https://leetcode.com/problems/web-crawler/description/

'''
Given a url startUrl and an interface HtmlParser, implement a web crawler to crawl all links that are under the same hostname as startUrl. 

Return all urls obtained by your web crawler in any order.

Your crawler should:

Start from the page: startUrl
Call HtmlParser.getUrls(url) to get all urls from a webpage of given url.
Do not crawl the same link twice.
Explore only the links that are under the same hostname as startUrl.


As shown in the example url above, the hostname is example.org. For simplicity sake, you may assume all urls use http protocol without any port specified. For example, the urls http://leetcode.com/problems and http://leetcode.com/contest are under the same hostname, while urls http://example.org/test and http://example.com/abc are not under the same hostname.

The HtmlParser interface is defined as such: 

interface HtmlParser {
  // Return a list of all urls from a webpage of given url.
  public List<String> getUrls(String url);
}
Below are two examples explaining the functionality of the problem, for custom testing purposes you'll have three variables urls, edges and startUrl. Notice that you will only have access to startUrl in your code, while urls and edges are not directly accessible to you in code.

Note: Consider the same URL with the trailing slash "/" as a different URL. For example, "http://news.yahoo.com", and "http://news.yahoo.com/" are different urls.

 

Example 1:



Input:
urls = [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.google.com",
  "http://news.yahoo.com/us"
]
edges = [[2,0],[2,1],[3,2],[3,1],[0,4]]
startUrl = "http://news.yahoo.com/news/topics/"
Output: [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.yahoo.com/us"
]
Example 2:



Input: 
urls = [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.google.com"
]
edges = [[0,2],[2,1],[3,2],[3,1],[3,0]]
startUrl = "http://news.google.com"
Output: ["http://news.google.com"]
Explanation: The startUrl links to all other pages that do not share the same hostname.
 

Constraints:

1 <= urls.length <= 1000
1 <= urls[i].length <= 300
startUrl is one of the urls.
Hostname label must be from 1 to 63 characters long, including the dots, may contain only the ASCII letters from 'a' to 'z', digits  from '0' to '9' and the hyphen-minus character ('-').
The hostname may not start or end with the hyphen-minus character ('-'). 
See:  https://en.wikipedia.org/wiki/Hostname#Restrictions_on_valid_hostnames
You may assume there're no duplicates in url library.
'''

# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
#class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """

class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        def get_hostname(url):
            return url.split('/')[2]
        
        start_hostname=get_hostname(startUrl)
        q=collections.deque([startUrl])
        visited=set([startUrl])
        while q:
            url=q.popleft()
            for next_url in htmlParser.getUrls(url):
                if get_hostname(next_url)==start_hostname and next_url not in visited:
                    q.append(next_url)
                    visited.add(next_url)
        return visited
        
    
'''
In an interview, you probably want to mention to use DFS for different domains and BFS for paths under each domain considering factors like pressure to a website, infinitely deep paths, TCP keepalive, etc.
Also, don't forget to use a probabilistic filter like bloomfilter in front of a hash set.


Complexity Analysis
Let n be the total number of URLs (urls.length), m be the number of edges in the graph, and l be the maximum length of a URL (urls[i].length).

Time complexity: O(m⋅l).
Let k be the number of traversed vertices. We add each of these vertices to the set and to the queue in up to O(l) per vertex. The total time for inserting into the set and into the queue is thus O(k⋅l).

The most time-consuming part is calling htmlParser.getUrls(url) to get the edges outgoing from url and iterating over all nextUrl. When processing nextUrl, we call getHostname(nextUrl) and search nextUrl in the hash set. Both of these can take O(nextUrl.length)=O(l) time. The complexity equals the sum of all the O(l) work done.

The total number of elements in htmlParser.getUrls(url) over all URLs is m – the total number of edges in the graph. Each element can have a length of O(l). The sum of lengths of the elements of htmlParser.getUrls(url) over all URLs is O(m⋅l).

The total complexity is O(k⋅l+m⋅l). Since k=O(m), we can simplify this expression to O(m⋅l).

Space complexity: O(n⋅l).
For each visited url, we call htmlParser.getUrls(url) and store its return value. For one url, htmlParser.getUrls(url) contains O(n) elements (in the worst case, there are edges from the url to all other vertices), each having a length up to O(l). The total length of the elements of htmlParser.getUrls(url) for one url could therefore be O(n⋅l). Unlike in the previous approach, we do not store them simultaneously for all vertices, but only for one vertex at a time.

The total length of the queue elements does not exceed the total length of all URLs – O(n⋅l).

So the total space complexity is O(n⋅l).
'''
