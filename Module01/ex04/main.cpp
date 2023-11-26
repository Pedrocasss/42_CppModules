#include "replace.hpp"

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        std::string toFind = argv[2];
        std::string toReplace = argv[3];
        std::ifstream in_file(argv[1]);
        if (toFind.empty() || toReplace.empty())
        {
            std::cerr << "No empty arguments!" << std::endl;
            return 1;
        }
        if (!in_file)
        {
            std::cerr << "Error opening this file: " << argv[1] << std::endl;
            return 1;
        }
        std::ostringstream outStringStream;
        outStringStream << in_file.rdbuf();
        in_file.close();
        std::string content = outStringStream.str();
        if (content.empty())
        {
            std::cerr << "Empty file" << std::endl;
            return 1;
        }
        replaceString(content, toFind, toReplace);
        std::ofstream outputFile((std::string(argv[1]) + ".replace").c_str());
	    if(!outputFile)
	    {
		    std::cerr << "Error creating the replacement file." << std::endl;
		    return 1;
	    }
	    outputFile << content;
	    outputFile.close();
	    return 0;
    }
    else
    {
        std::cerr << "Wrong arguments!" << std::endl;
        std::cerr << "Usage : ./replace <filename> <string to find> <string to replace>!" << std::endl;
    }
}