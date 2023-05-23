#include <iostream>
#include <cmath>
#include <vector>

int main()
{


    const std::string numeralChars = "IVXLCDM";

    int n = 42;
    int placesIndex = (log(n)/log(10));
    int singleDigit = 0;

    std::string result;

    for (int i = placesIndex; i >= 0; i--)
    {
        // get each place digit seperately
        singleDigit = n / pow(10, i);

        // subtract digit with proper number of zeros from original number to process next digit place
        n -= singleDigit * (pow(10, i));

        // SET BEGINNING INDEX OF NUMERALCHARS (
        int j = i * 2 + 1;

        auto repeat = [&result, &singleDigit, &numeralChars](int index) {
            for (int i = 0; i < (singleDigit % 5); i++)
                result += numeralChars[index];
        };

        if (singleDigit % 5 == 4) // if "4" or "9"
            result += {numeralChars[j - 1], numeralChars[j + (singleDigit / 9)]};

        else
        {
            if (singleDigit >= 5)
                result += numeralChars[j];

            repeat(j - 1);
        }
    }

    std::cout << result;




    return 0;
}
