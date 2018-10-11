#include <iostream>
#include <string>
#include <locale>
#include <vector>

int main(int argc, char* argv[])
{
    const std::vector<std::string> cmdLineArgs{argv, argv+argc};

    // Add a typedef that assigns another name for the given type for clarity
    typedef std::vector<std::string>::size_type size_type;
    const size_type nCmdLineArgs {cmdLineArgs.size()};

    // Options that might be set by the command-line arguments
    bool helpRequested {false};
    bool versionRequested {false};
    std::string input_file{""};
    std::string output_file{""};

    /*
    for(size_type i{0}; i<nCmdLineArgs; ++i)
    {
        std::cout << cmdLineArgs[i] << std::endl;
    }
    */

    // Process command line arguments - ignore zeroth element, as we know this to
    // be the program name and don't need to worry about it
    for(size_type i{1}; i<nCmdLineArgs; ++i)
    {
        if(cmdLineArgs[i]=="-h" || cmdLineArgs[i]=="--help")
        {
            helpRequested = true;
        }
        else if(cmdLineArgs[i]=="--version")
        {
            versionRequested = true;
        }
        else if(cmdLineArgs[i]=="-i")
        {
	    // check whether this is the last argument
	    if (i == nCmdLineArgs-1) {
		std::cerr << "[error] -i requires a filename argument" << std::endl;
		// exit main with non-zero return to indicate failure
		return 1;
	    }
	    else {
		input_file = cmdLineArgs[i+1];
		++i;
	    }
        }
        else if(cmdLineArgs[i]=="-o")
        {
	    // check whether this is the last argument
	    if (i == nCmdLineArgs-1) {
		std::cerr << "[error] -o requires a filename argument" << std::endl;
		// exit main with non-zero return to indicate failure
		return 1;
	    }
	    else {
		output_file = cmdLineArgs[i+1];
		++i;
	    }
	}
	else {
	    // Have encountered an unknown argument
	    // Output error message and return non-zero exit status to indicate failure
	    std::cerr << "[error] unknown argument '" << cmdLineArgs[i] << "'\n";
	    return 1;
	}
    }

    // Handle help, if requested
    if (helpRequested) {
	// Line splitting for readability
	std::cout
	    << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
	    << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
	    << "Available options:\n\n"
	    << "  -h|--help        Print this help message and exit\n\n"
	    << "  --version        Print version information\n\n"
	    << "  -i FILE          Read text to be processed from FILE\n"
	    << "                   Stdin will be used if not supplied\n\n"
	    << "  -o FILE          Write processed text to FILE\n"
	    << "                   Stdout will be used if not supplied\n\n";
	// Help requires no further action, so return from main
	// with 0 used to indicate success
	return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
	std::cout << "0.1.0" << std::endl;
	return 0;
    }

    // Warn that input file option not yet implemented
    if (!input_file.empty()) {
	    std::cout << "[warning] input from file ('"
		    << input_file
		    << "') not implemented yet, using stdin\n";
    }

    std::string msg{""};
    //std::locale loc;

    char in_char{'x'};
    while(std::cin >> in_char)
    {
	// Loop until the user
	// presses Enter then Ctrl+D

	//if(std::isalpha(in_char,loc))
	if(std::isalpha(in_char))
	{
	    msg += std::toupper(in_char);
	}
	else
	{
	    switch(in_char)
	    {
		case '0':
		    msg += "ZERO";
		    break;
		case '1':
		    msg += "ONE";
		    break;
		case '2':
		    msg += "TWO";
		    break;
		case '3':
		    msg += "THREE";
		    break;
		case '4':
		    msg += "FOUR";
		    break;
		case '5':
		    msg += "FIVE";
                    break;
                case '6':
                    msg += "SIX";
                    break;
                case '7':
                    msg += "SEVEN";
                    break;
                case '8':
                    msg += "EIGHT";
                    break;
                case '9':
                    msg += "NINE";
                    break;
                default:
                    break;
            }
        }
    }

    // Warn that output file option not yet implemented
    if (!output_file.empty()) {
	    std::cout << "[warning] output to file ('"
		    << output_file
		    << "') not implemented yet, using stdout\n";
    }

    std::cout << msg << std::endl;

    return 0;
}
