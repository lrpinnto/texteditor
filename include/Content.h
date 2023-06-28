#pragma once
#include <SFML/Graphics.hpp>
#include "./document.h"
#include <string>

class Content
{

public:
    Content(document &docc);

    int linesCount();

    sf::String getLine(int lineNumber);

private:
    document &doc;
};
