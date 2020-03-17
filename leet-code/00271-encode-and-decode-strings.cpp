// I just decided to go ahead with their method and also practice simple string to int and int to string
class Codec {
public:
    string my_itos(int n) {
        string s;
        while (n) {
            int d = n%10;
            n = n/10;
            s += d + '0';
        }
        int len = s.size();
        while (len < 4) {
            s.push_back('0');
            len++;
        }
        std::reverse(s.begin(), s.end());
        return s;
    }

    int my_stoi(string s) {
        int n = 0;
        for (int i = 0; i < 4; i++) {
            n *= 10;
            n += (s[i]-'0');
        }
        return n;
    }

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;
        for (auto s = strs.begin(); s != strs.end(); s++) {
            encoded += my_itos(s->length()) + *s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        if (s.size() == 0) { return vector<string>(); }
        vector<string> decoded;
        int i = 0;
        while (i < s.length()) {
            // (1) read first 4 bytes into length
            int n = my_stoi(s.substr(i,4));
            i += 4;
            // (2) read string from i+4 to i+n
            decoded.push_back(s.substr(i,n));
            i += n;
        }
        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));