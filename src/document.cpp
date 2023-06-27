#include "../include/document.h"
#include <iostream>

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