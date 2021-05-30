#pragma once
#include <string>
using std::string;


class						StringSet {
private:
		int 						maxSize;
		int 						curSize;
		std::string*		data;

public:
		StringSet(); // 1 Default Constructor (M)
		StringSet(const StringSet& s); // 2 Copy Constructor (M)
		~StringSet(); // 3 Destructor (M)

		StringSet		StingSet::operator= (StingSet& other);// 4 Assigment Operator (M)
		// 5 Insert
		// 6 Remove
		int					find(std::string target);// 7 Find (M)
		// 8 Size
		StirngSet		unions(const StringSet& other);// 9 Unions (M)
		// 10 Intersection
		// 11 Difference

		void				expand(); // Helper: expand function (M)
		


};
