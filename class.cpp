#include <string>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <boost/algorithm/string.hpp> 
#include <exception>
#include <ctime>

using namespace std;


int main(int argc, char** argv) {

    int opt;
    string input = "";
    string header = "";
    string source = "";
    string t_text = "";
    string my_name = "My Name";

    // Get input
    if ( (argc <= 1) || (argv[argc-1] == NULL) || (argv[argc-1][0] == '-') ) {
        cerr << "Error! No class name specified." << endl;
        return 1;
    }
    if ( argc > 2 )
    {
        cerr << "Error! Multiple inputs." << endl; 
        return 1;
    }
    else {
        input = argv[argc-1];
    }
    for (int i = 0; i < input.size(); ++i)
    {
        if ( !(isalpha(input[i]) || isdigit(input[i])) )
        {
            cerr << "Error! " << input << " is not a valid input. Only enter the class name - no file extensions." << endl;
            return 1;
        }
    }

    // Get time
    time_t t = time(0);
    struct tm * now = localtime( & t );
    t_text = to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);


    // Write text
    header = input;
    boost::algorithm::to_lower(header);
    header += ".h";
    source = input;
    boost::algorithm::to_lower(source);
    source += ".cpp";
    string header_ifndef = input;
    boost::algorithm::to_upper(header_ifndef);
    header_ifndef += "_H";

    string headertext = "// "+header+"\n// "+t_text+"\n#ifndef "+header_ifndef+"\n#define "+header_ifndef+"\n\n";
    headertext += "class "+input+"\n{\n// Private variables\nprivate:\n\n// Public variables\npublic:\n\n";
    headertext += "// Private methods\nprivate:\n\n// Public methods\npublic:\n\n};\n\n";
    headertext += "#endif";
    string sourcetext = "// "+source+"\n// "+t_text+"\n\n#include \""+header+"\"\n";

    opterr = 0;

    // Create file
    try
    {
        ifstream s(source);
        ifstream h(header);
        if( !h.good() && !s.good() ) // Check that neither file already exists.
        {
            
            ofstream sourcefile;
            sourcefile.open (source, std::ofstream::out | std::ofstream::trunc);
            sourcefile << sourcetext;
            sourcefile.close();

            ofstream headerfile;
            headerfile.open (header, std::ofstream::out | std::ofstream::trunc);
            headerfile << headertext;
            headerfile.close();

            cout << "Successfully created " << source << " and " << header << "." << endl;

        }
        else
        {
            cout << "Error! The following already exists:";
            if (s.good()) cout << " " << source;
            if (h.good()) cout << " " << header;
            cout << endl;
        }
    } catch (const std::exception &e) {
        cout << "Error! " << e.what();
    }


    return 0;
}