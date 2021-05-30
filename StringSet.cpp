#include "StringSet.h"

StringSet::StringSet()
{
	maxSize = 2;
	curSize = 0;
	data = new std::string[maxSize];
}

StringSet::StringSet(const StringSet& s)
{
	maxSize = s.maxSize;
	curSize = s.curSize;
	data = new std::string[maxSize];
	for (int i = 0; i < s.curSize; i++)
	{
		data[i] = s.data[i];
	}
}

StringSet::~StringSet(){ delete data;}

StringSet StingSet::operator= (const StingSet& other)
{
	delete data;
	maxSize = other.maxSize;
	curSize = other.curSize;
	data = new std::string[maxSize];
	for (int i = 0; i < other.curSize; i++)
	{
		data[i] = other.data[i];
	}
	return *this;
}

void	StingSet::expand()
{
	maxSize *= 2;
	string	*newData = new std::string[maxSize];
	for (int i = 0; i < other.curSize; i++)
	{
		newData[i] = data[i];
	}
	delete data;
	data = newData;
}

StirngSet		StingSet::unions(const StringSet& other)
{
	StringSet	out = new StringSet();

	for (int i = 0; i < curSize; i++)
	{
		out.insert(data[i]);
	}
	for (int j = 0; j < other.curSize; j++)
	{
		out.insert(other.data[i]);
	}
	return out;
}

int					StingSet::find(std::string target)
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

// 5 Insert
// 6 Remove
// 8 Size
// 10 Intersection
// 11 Difference

void				StingSet::printSet()
{

}