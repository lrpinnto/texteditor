#include "../include/document.h"

Text_iterator &Text_iterator::operator++()
{
    ++pos;
    if (pos == (*ln).end())
    {
        ++ln;
        pos = (*ln).begin();
    }
    return *this;
}

Text_iterator document::end()
{
    auto last = lines.end();
    --last;
    return Text_iterator(last, (*last).end());
}

Text_iterator document::begin()
{
    return Text_iterator(lines.begin(), (*lines.begin()).begin());
}

sf::String document::getLine(int lineNumber) {

    auto p {lines.begin()};

    int lastLine = this->lines.size() - 1;

    if (lineNumber < 0 || lineNumber > lastLine) {
        throw std::runtime_error("lineNumber "+std::to_string(lineNumber) + " is not a valid number line. "
                  + "Max is: " + std::to_string(lines.size() - 1));
    }

    else {
        std::advance(p,lineNumber);

        return sf::String(std::string((*p).begin(),(*p).end()));   // a bit ugly but converts vector<char> to std::string and then to sf::String
    }
}

// TO DO: CHANGE THIS TO READ FILES
void document::init(const std::string& filename)
{
    char currentDir[FILENAME_MAX];
    if (!GETCWD(currentDir, FILENAME_MAX)) 
        throw std::runtime_error("Error retrieving current directory.");

    std::ifstream file( static_cast<std::string>(currentDir) + "/../" + filename);
    if(!file)
        throw std::runtime_error("Unable to open file " + filename);

    std::string line;

    while (std::getline(file, line)) {
        std::vector<char> lineVector(line.begin(), line.end());
        lines.push_back(lineVector);
    }
    file.close();
}