#pragma once
#include <list>
#include <string>
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <sstream>

using Line = std::vector<char>;

class Text_iterator
{
private:
    std::list<Line>::iterator ln;
    Line::iterator pos;

public:
    Text_iterator(std::list<Line>::iterator ll, Line::iterator pp)
        : ln{ll}, pos{pp} {}

    char &operator*() { return *pos; }
    Text_iterator &operator++();
    bool operator==(const Text_iterator &other) const
    {
        return ln == other.ln && pos == other.pos;
    }
    bool operator!=(const Text_iterator &other) const
    {
        return !(*this == other);
    }
};

class document
{
public:
    document() { lines.push_back(Line{}); }
    void init(const std::string&);
    Text_iterator begin();
    Text_iterator end();
    sf::String getLine(int lineNumber);

private:
    std::list<Line> lines;
};
