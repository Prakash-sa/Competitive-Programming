// https://leetcode.com/explore/featured/card/top-interview-questions-easy/127/strings/883/

bool isPalindrome(string s) {
    int left=0,right=s.size()-1;
    while(left<right){
        while(left<right && !isalnum(s[left]))left++;
        while(right>left && !isalnum(s[right]))right--;
        if(tolower(s[left])!=tolower(s[right]))return false;
        left++,right--;
    }
    return true;
    
}


