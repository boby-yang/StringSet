#pragma once

#include <string>

using std::string;


class StringSet {
private:
		int maxSize;
		int curSize;
		std::string *data;

public:
		StringSet(); // 1 Default Constructor (M)
		StringSet(const StringSet &s); // 2 Copy Constructor (M)
		~StringSet(); // 3 Destructor (M)

		StringSet StingSet::operator=(StingSet &other);// 4 Assigment Operator (M)
		bool insert(std::string in);

		void remove(sd::string in);

		int find(std::string target);// 7 Find (M)
		int size(const StringSet &in);

		StirngSet unions(const StringSet &other);// 9 Unions (M)
        StringSet intersection(const StringSet &other);
        StringSet difference(const StringSet &other);

		void expand(); // Helper: expand function (M)
		void printSet(); // Helper: prints all data in the set (M)


};
