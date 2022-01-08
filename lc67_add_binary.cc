class Solution {
public:
    string addBinary(string a, string b) {
        std::ostringstream output_stream;
        int carry = 0;
        int index_a = a.size() - 1;
        int index_b = b.size() - 1;
        while (index_a >= 0 && index_b >= 0) {
            int bit_a = a[index_a] == '1' ? 1 : 0;
            int bit_b = b[index_b] == '1' ? 1 : 0;
            int sum = bit_a + bit_b + carry;
            output_stream << sum % 2;
            carry = sum / 2;
            --index_a;
            --index_b;
        }
        while (index_a >= 0) {
            int bit_a = a[index_a] == '1' ? 1 : 0;
            int sum = bit_a + carry;
            output_stream << sum % 2;
            carry = sum / 2;
            --index_a;
        }
        while (index_b >= 0) {
            int bit_b = b[index_b] == '1' ? 1 : 0;
            int sum = bit_b + carry;
            output_stream << sum % 2;
            carry = sum / 2;
            --index_b;
        }
        if (carry) {
            output_stream << carry; 
        }
        string output_string = output_stream.str();
        std::reverse(output_string.begin(), output_string.end());
        return output_string;
    }
};
