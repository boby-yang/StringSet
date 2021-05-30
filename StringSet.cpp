#include "StringSet.h"

StringSet::StringSet()
{
	maxSize = 2;
	curSize = 0;
	data = new std::string[maxSize];
}

StringSet::StringSet(const StringSet &s)
{
	maxSize = s.maxSize;
	curSize = s.curSize;
	data = new std::string[maxSize];
	for (int i = 0; i < s.curSize; i++)
	{
		data[i] = s.data[i];
	}
}

StringSet::~StringSet()
{ delete[] data; }

StringSet StringSet::operator=(const StringSet &other)
{
	delete[] data;
	maxSize = other.maxSize;
	curSize = other.curSize;
	data = new std::string[maxSize];
	for (int i = 0; i < other.curSize; i++)
	{
		data[i] = other.data[i];
	}
	return *this;
}

void StringSet::expand()
{
	maxSize *= 2;
	std::string *newData = new std::string[maxSize];
	for (int i = 0; i < curSize; i++)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}

StringSet StringSet::unions(const StringSet &other)
{
	StringSet out = StringSet();

	for (int i = 0; i < curSize; i++)
	{
		out.insert(data[i]);
	}
	for (int j = 0; j < other.curSize; j++)
	{
		out.insert(other.data[j]);
	}
	return out;
}

int StringSet::find (std::string target) const
{
	for (int i = 0; i < curSize; i++)
	{
		if (data[i].compare(target) == 0)
		{
			return i;
		}
	}
	return -1;
}

bool StringSet::insert(std::string in)
{
	if (find(in) != -1)
	{
		return false;
	}
	if (curSize == maxSize)
	{
		expand();
	}
	data[curSize] = in;
	curSize += 1;
	return true;
}

void StringSet::remove(std::string in)
{
	int index = find(in);
	if (index != -1)
	{
		data[index] = data[curSize - 1];
		curSize -= 1;
	}
}

int StringSet::size()
{
    return curSize;
}

StringSet StringSet::intersection(const StringSet &other)
{
    StringSet out = StringSet();
    for (int i = 0; i < curSize; ++i)
    {
        if (other.find(data[i]) != -1)
        {
            out.insert(data[i]);
        }
    }
    return out;
}

StringSet StringSet::difference(const StringSet &other)
{
    StringSet out = StringSet();
    for (int i = 0; i < curSize; ++i)
    {
        if (other.find(data[i]) == -1)
        {
            out.insert(data[i]);
        }
    }
    return out;
}

void StringSet::printSet()
{
	for (int i = 0; i < curSize; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}