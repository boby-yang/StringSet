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

/*
 * Pre: StringSet object need to be created, also maxSize need to be > 0
 * Param: None
 * Post: size of StringSet will be doubled, data will move to newly allocated memory
 *       old memory will be freed
 */
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

/*
 * Pre: StringSet obj need to be created, Other StringSet object need to be passed in
 * Param: const reference of a StringSet
 * Post: a new StringSet obj containing both StringSet obj will be made and returned
 */
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

/*
 * Pre: StringSet obj need to be created.
 * Param: target string to find
 * Post: look for target string, return index if found, -1 if not found
 */
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

/*
 * Pre: StringSet obj need to be created.
 * Param: data string to insert
 * Post: return false if string already present, return true if successfully added.
 *       size of StringSet will double (by calling expand), if current size is full. increment curSize.
 */
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

/*
 * Pre: StringSet obj need to be created.
 * Param: target string to remove
 * Post: if target string is found, replace it with the last data string, and decrement curSize.
 */
void StringSet::remove(std::string target)
{
	int index = find(target);
	if (index != -1)
	{
		data[index] = data[curSize - 1];
		curSize -= 1;
	}
}

/*
 * Pre: StringSet obj need to be created.
 * Param: None
 * Post: return curSize of StringSet obj.
 */
int StringSet::size()
{
    return curSize;
}

/*
 * Pre: StringSet obj need to be created, Other StringSet object need to be passed in
 * Param: const reference of a StringSet
 * Post: makes a new StringSet obj with elements that is in both StringSet obj, and returns it.
 */
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

/*
 * Pre: StringSet obj need to be created, Other StringSet object need to be passed in
 * Param: const reference of a StringSet
 * Post: makes a new StringSet obj with elements that is not in the other StringSet obj, and returns it.
 */
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

/*
 * Pre: StringSet obj need to be created.
 * Param: none
 * Post: prints all data string with a space to std::cout.
 */
void StringSet::printSet()
{
	for (int i = 0; i < curSize; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}