#pragma once

#include <string>
#include <iostream>

//using std::string;


class StringSet {
private:
		int maxSize;
		int curSize;
		std::string *data;

public:
		StringSet();
		StringSet(const StringSet &s);
		~StringSet();

		StringSet operator=(const StringSet &other);
		bool insert(std::string in);

		void remove(std::string in);

		int find (std::string target) const;
		int size();

		StringSet unions(const StringSet &other);
        StringSet intersection(const StringSet &other);
        StringSet difference(const StringSet &other);

		void expand(); // Helper: expand function (M)
		void printSet(); // Helper: prints all data in the set (M)
};
