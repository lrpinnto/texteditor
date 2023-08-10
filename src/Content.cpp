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
    return this->doc.getLine(lineNumber);
}

void Content::addTextToPos(char ch, int x, int y)
{
    this->doc.addTextToPos(ch,x,y);
}