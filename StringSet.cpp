#include "StringSet.h"

StringSet::StringSet()
{
	maxSize = 2;
	curSize = 0;
	data = new string[maxSize];
}

StringSet::StringSet(const StringSet& s)
{
	maxSize = s.maxSize;
	curSize = s.curSize;
	data = new string[maxSize];
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
	data = new string[maxSize];
	for (int i = 0; i < other.curSize; i++)
	{
		data[i] = other.data[i];
	}
	return *this;
}

void	StingSet::expand()
{
	maxSize *= 2;
	string	*newData = new string[maxSize];
	for (int i = 0; i < other.curSize; i++)
	{
		newData[i] = data[i];
	}
	delete data;
	data = newData;
}

StingSet::StirngSet		unions(const StringSet& other)
{
	StringSet	out = new StringSet();

	for (int i = 0; i < curSize; i++)
	{
		if (out.find(data[i]) != -1)
		{

		}
	}
}

// 5 Insert
// 6 Remove
// 7 Find (M)
// 8 Size
// 10 Intersection
// 11 Difference