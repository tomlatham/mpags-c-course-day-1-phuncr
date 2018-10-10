#include <iostream>
#include <string>
#include <locale>

int main()
{
    std::string msg{""};
    std::locale loc;

    char in_char{'x'};
    while(std::cin >> in_char)
    {
        // Loop until the user
        // presses Enter then Ctrl+D

        if(std::isalpha(in_char,loc))
        {
            msg = msg + (char)(toupper(in_char));
        }
        else
        {
            switch(in_char)
            {
                case '0':
                    msg = msg + "ZERO";
                    break;
                case '1':
                    msg = msg + "ONE";
                    break;
                case '2':
                    msg = msg + "TWO";
                    break;
                case '3':
                    msg = msg + "THREE";
                    break;
                case '4':
                    msg = msg + "FOUR";
                    break;
                case '5':
                    msg = msg + "FIVE";
                    break;
                case '6':
                    msg = msg + "SIX";
                    break;
                case '7':
                    msg = msg + "SEVEN";
                    break;
                case '8':
                    msg = msg + "EIGHT";
                    break;
                case '9':
                    msg = msg + "NINE";
                    break;
            }
        }

    }

    std::cout << msg << std::endl;

    return(0);
}
