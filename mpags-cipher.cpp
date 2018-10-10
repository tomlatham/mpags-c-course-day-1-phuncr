#include <iostream>
#include <string>
#include <locale>
#include <vector>

int main(int argc, char* argv[])
{
    const std::vector<std::string> cmdLineArgs{argv, argv+argc};
    std::string input_file{""};
    std::string output_file{""};

    for(size_t i{0}; i<cmdLineArgs.size(); ++i)
    {
        std::cout << cmdLineArgs[i] << std::endl;
    }

    for(size_t i{0}; i<cmdLineArgs.size(); ++i)
    {
        if(cmdLineArgs[i]=="-h" || cmdLineArgs[i]=="--help")
        {
            std::cout << "mpags-cipher is a simple command line tool for encrypting/decrypting text using classical ciphers" << std::endl;
        }
        else if(cmdLineArgs[i]=="-i")
        {
            input_file = cmdLineArgs[i+1];
            std::cout << input_file << std::endl;
            ++i;
        }
        else if(cmdLineArgs[i]=="-o")
        {
            output_file = cmdLineArgs[i+1];
            std::cout << output_file << std::endl;
            ++i;
        }
    }

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
                default:
                    break;
            }
        }
    }

    std::cout << msg << std::endl;

    return(0);
}
