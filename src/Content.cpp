#include "../include/Content.h"

Content::Content(document &docc)
    : doc{docc}
{
}

int Content::linesCount()
{
    return 1;
}

sf::String Content::getLine(int lineNumber)
{
    return sf::String(std::string("bla bla bla"));
}
