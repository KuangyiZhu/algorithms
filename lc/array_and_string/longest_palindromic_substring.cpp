#include<string>

std::string longestPalindrome(std::string s){
  int len = s.length();
  if(len < 2)
    return s;
  int max_start=0, max_len=0;
  int i=0, j=0, k=0, l=0;
  while(i <= len-max_len/2){
    j=i;
    while(i<len-1 && s[i]==s[i+1])
      i++;
    k=i;
    while(j>0 && k<len-1 && s[j-1]==s[k+1]){
      j--;
      k++;
    }
    l = k-j+1;
    if(l > max_len){
      max_len = l;
      max_start = j;
    }
    i++;
  }
}
