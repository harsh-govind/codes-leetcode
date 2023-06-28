class Solution
{
public:
    string multiply(string num1, string num2)
    {
        string a = num1, b = num2;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string result(a.size() + b.size(), '0');

        for (int i = 0; i < a.size(); i++)
        {
            int carry = 0, x = a[i] - '0';
            for (int j = 0; j < b.size(); j++)
            {
                int y = b[j] - '0';
                int temp = x * y + carry + (result[i + j] - '0');
                carry = temp / 10;
                result[i + j] = temp % 10 + '0';
            }
            if (carry > 0)
            {
                result[i + b.size()] = carry + '0';
            }
        }

        while (result.size() > 1 && result.back() == '0')
        {
            result.pop_back();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
