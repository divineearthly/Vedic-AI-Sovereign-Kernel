#include <iostream>
#include <vector>
#include <algorithm>

// Function to implement Urdhva-Tiryagbhyam (Vedic Multiplication)
// This simplified version handles two positive integers.
int vedic_multiply(int num1, int num2) {
    std::string s_num1 = std::to_string(num1);
    std::string s_num2 = std::to_string(num2);

    // Pad with leading zeros if lengths are different
    int len1 = s_num1.length();
    int len2 = s_num2.length();
    int max_len = std::max(len1, len2);

    // Reverse strings for easier right-to-left processing
    std::reverse(s_num1.begin(), s_num1.end());
    std::reverse(s_num2.begin(), s_num2.end());

    // Store digits as integers
    std::vector<int> n1_digits(max_len, 0);
    std::vector<int> n2_digits(max_len, 0);

    for (int i = 0; i < len1; ++i) n1_digits[i] = s_num1[i] - '0';
    for (int i = 0; i < len2; ++i) n2_digits[i] = s_num2[i] - '0';

    std::vector<int> result_digits(2 * max_len, 0);
    int carry = 0;

    for (int i = 0; i < 2 * max_len - 1; ++i) {
        int sum = carry;
        for (int j = 0; j <= i; ++j) {
            if (j < max_len && (i - j) < max_len) {
                sum += n2_digits[j] * n1_digits[i - j];
            }
        }
        result_digits[i] = sum % 10;
        carry = sum / 10;
    }
    result_digits[2 * max_len - 1] = carry;

    std::string result_str = "";
    // Find the first non-zero digit from the right (most significant) for final result
    int first_digit_idx = 2 * max_len - 1;
    while (first_digit_idx > 0 && result_digits[first_digit_idx] == 0) {
        first_digit_idx--;
    }

    for (int i = first_digit_idx; i >= 0; --i) {
        result_str += std::to_string(result_digits[i]);
    }

    if (result_str.empty()) return 0;
    return std::stoi(result_str);
}

int main() {
    int a = 12;
    int b = 13;
    int result = vedic_multiply(a, b);
    std::cout << "Vedic Multiplication of " << a << " and " << b << " = " << result << std::endl;

    a = 99;
    b = 88;
    result = vedic_multiply(a, b);
    std::cout << "Vedic Multiplication of " << a << " and " << b << " = " << result << std::endl;

    a = 123;
    b = 456;
    result = vedic_multiply(a, b);
    std::cout << "Vedic Multiplication of " << a << " and " << b << " = " << result << std::endl;

    return 0;
}
