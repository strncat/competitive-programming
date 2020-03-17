// based on the third best voted .....
// my original solution is shitty
class Solution {
public:
    vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six",
        "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> below_100 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty",
        "Sixty", "Seventy", "Eighty", "Ninety"};

    string convert(int num) {
        if (num < 20) { // base case
            return below_20[num];
        }
        // otherwise
        string s;
        if (num < 100) {
            s = below_100[num/10];
            if (num % 10 > 0) { s += " " + convert(num % 10); }
            return s;
        } else if (num < 1000) {
            s = convert(num/100) + " Hundred";
            if (num % 100 > 0) { s += " " +  convert(num % 100); }
            return s;
        } else if (num < 1000000) {
            s = convert(num/1000) + " Thousand";
            if (num % 1000 > 0) { s += " " +  convert(num % 1000); }
            return s;
        } else if (num < 1000000000) {
            s = convert(num/1000000) + " Million";
            if (num % 1000000 > 0) { s += " " +  convert(num % 1000000); }
            return s;
        } else {
            s = convert(num/1000000000) + " Billion";
            if (num % 1000000000 > 0) { s += " " +  convert(num % 1000000000); }
            return s;
        }
    }

    string numberToWords(int num) {
        if (num == 0) { return "Zero"; }
        return convert(num);
    }
};