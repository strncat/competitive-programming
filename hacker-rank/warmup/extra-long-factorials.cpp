//
//  Extra long factorials
//  Created by Fatima B on 9/27/15.
//

#include <iostream>

int make_equal_length(std::string &a, std::string &b) {
    int alen = (int) a.length();
    int blen = (int) b.length();
    if (alen < blen) {
        for (int i = 0; i < blen - alen; i++) { a = '0' + a; }
    } else {
        for (int i = 0; i < alen - blen; i++) { b = '0' + b; }
    }
    return alen;
}

std::string sum(std::string a, std::string b) {
    int carry = 0, sum;
    std::string c = "";

    // append zeros
    make_equal_length(a, b);

    // equal length strings
    int n = (int) a.length();
    int i;
    for (i = n - 1; i >= 0; i--) {
        sum = a[i] - '0' + b[i] - '0' + carry;
        carry = sum/10;
        c = std::to_string(sum%10) + c; // expensive?
    }

    if (carry > 0) {
        c = std::to_string(carry) + c;
    }
    //std::cout << a << " + " << b << " = " << c << std::endl;
    return c;
}

std::string multiply_single(std::string a, char d) {
    int alen = (int) a.length();
    int t = 0;
    int carry = 0;
    std::string result = "";

    for (int i = alen - 1; i >= 0; i--) {
        t = ((d - '0') * (a[i] - '0')) + carry;
        result = std::to_string(t%10) + result;
        carry = t/10;
    }
    if (carry > 0) {
        result = std::to_string(carry) + result;
    }
    //std::cout << a << " * " << d << " = " << result << std::endl;
    return result;
}

std::string multiply(std::string a, std::string b) {
    int blen = (int) b.length();
    std::string t;
    std::string final = "";

    // multiply a with each digit of b!
    for (int i = blen - 1; i >= 0; i--) {
        t = multiply_single(a, b[i]);
        // append zeros
        for (int j = blen - 1; j > i; j--) {
            t = t + '0';
        }
        final = sum(final, t);
    }
    return final;
}

void test_multiply() {
    std::string result = multiply("123", "56");
    if (result.compare("6888") != 0) {
        printf("123 * 56 != %s\n", result.c_str());
    }
    result = multiply("99", "990");
    if (result.compare("98010") != 0) {
        printf("99 * 990 != %s\n", result.c_str());
    }
}

void test_sum() {
    std::string result = sum("234", "459");
    if (result.compare("693") != 0) {
        printf("234 + 459 != %s\n", result.c_str());
    }
    result = sum("9234", "459");
    if (result.compare("9693") != 0) {
        printf("9234 + 459 != %s\n", result.c_str());
    }
    result = sum("99990", "90009");
    if (result.compare("189999") != 0) {
        printf("99990 + 90009 != %s\n", result.c_str());
    }
}

void test_single_multiplication() {
    std::string result = multiply_single("234", '9');
    if (result.compare("2106") != 0) {
        printf("234 * 9 != %s\n", result.c_str());
    }
    result = multiply_single("9990", '9');
    if (result.compare("89910") != 0) {
        printf("9990 * 9 != %s\n", result.c_str());
    }
}


int main() {
    int n;
    scanf("%d", &n);
    std::string result = std::to_string(n), current = "";
    for (int i = n-1; i > 0; i--) {
        result = multiply(std::to_string(i), result);
    }
    std::cout << result;
    return 0;
}
