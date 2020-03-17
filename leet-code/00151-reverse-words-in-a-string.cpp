// warning: shitty question
class Solution {
public:
    // reverse in place
void reverseWord(string &s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

string reverseWords(string s) {
    if (s.length() == 0) { return s; }
    // reverse each word seperated by space
    int n = s.length();
    int start = 0;
    int write_index = 0;
    string result = s;
    
    // first pass to get rid of extra white spaces
    int i = 0;
    while (s[i] == ' ') { i++; }
    for (; i < n-1; i++) {
        if (s[i] == ' ' && s[i+1] == ' ') { continue; }
        result[write_index++] = s[i];
    }
    if (s[n-1] != ' ') { result[write_index++] = s[n-1]; }
    result.resize(write_index);
       
    // second pass to actually reverse
    for (int i = 1; i < write_index; i++) {
        if (result[i] == ' ') {
            // reverse everything between start and i
            reverseWord(result, start, i-1);
            start = i+1;
        }
    }
    reverseWord(result, start, write_index-1); // reverse last word
    reverseWord(result, 0, write_index-1); // reverse the whole line
    return result;
}
};