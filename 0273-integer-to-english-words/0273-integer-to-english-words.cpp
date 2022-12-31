class Solution {
public:
  void append_space(string& result) {
    if (!result.empty()) {
      result += " ";
    }
  }

  void small_number_to_words(string& result, int num) {
    assert(num > 0 && num <= 999);

    static const string one_to_nine[] = {
      "N/A", "One", "Two", "Three", "Four", "Five",
             "Six", "Seven", "Eight", "Nine"
    };

    static const string ten_multiples[] = {
      "N/A", "Ten", "Twenty", "Thirty", "Forty", "Fifty",
             "Sixty", "Seventy", "Eighty", "Ninety"
    };

    static const string eleven_to_nineteen[] = {
      "N/A", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
             "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    if (num >= 100) {
      append_space(result);
      result += one_to_nine[num / 100];
      result += " Hundred";
      num %= 100;
    }

    if (num >= 10) {
      append_space(result);
      if (num < 11 || num > 19) {
        result += ten_multiples[num / 10];
        num %= 10;
      } else {
        result += eleven_to_nineteen[num - 10];
        return;
      }
    }

    if (num >= 1) {
      append_space(result);
      result += one_to_nine[num];
    }
  }

  #define ONE_BILLION int(1e9)
  #define ONE_MILLION int(1e6)
  #define ONE_THOUSAND int(1e3)

  string numberToWords(int num) {
    string result;

    if (num >= ONE_BILLION) {
      small_number_to_words(result, num / ONE_BILLION);
      result += " Billion";
      num %= ONE_BILLION;
    }

    if (num >= ONE_MILLION) {
      small_number_to_words(result, num / ONE_MILLION);
      result += " Million";
      num %= ONE_MILLION;
    }

    if (num >= ONE_THOUSAND) {
      small_number_to_words(result, num / ONE_THOUSAND);
      result += " Thousand";
      num %= ONE_THOUSAND;
    }
    
    if (num >= 1) {
      small_number_to_words(result, num);
    } else if (num == 0 && result.empty()) {
      result = "Zero";
    }
    return result;
  }
};