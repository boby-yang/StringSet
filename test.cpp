#include "StringSet.h"

using std::cout;
using std::endl;

void basicTest()
{
	StringSet sset1;
	sset1.insert("cat");
	sset1.insert("bat");
	sset1.insert("rat");
	cout << "insert success: " << sset1.insert("badger") << endl;
	sset1.printSet();

	StringSet sset2;
	sset2.insert("elephant");
	sset2.insert("bat");
	sset2.insert("hamster");
	sset2.insert("weasel");
	sset2.remove("weasel");
	cout << "index of weasel = " << sset2.find("weasel") << endl;

	// Use the copy constructor to build a StringSet with sset1 U sset2
	StringSet sset3(sset1.unions(sset2));
	cout << "Union of" << endl;
	sset1.printSet();
	cout << "and" << endl;
	sset2.printSet();
	sset3.printSet();

	// Testing intersection
	StringSet sset4;
	sset4 = sset2.intersection(sset1);
	cout << "Intersection of" << endl;
	sset1.printSet();
	cout << "and" << endl;
	sset2.printSet();
	sset4.printSet();

	// Use overloaded assignment operator to make a StringSet with sset2 - sset1
	sset4 = sset2.difference(sset1);
	cout << "Difference of" << endl;
	sset2.printSet();
	cout << "and" << endl;
	sset1.printSet();
	sset4.printSet();

	cout << "end basic test" << endl;
}

int		main()
{
	basicTest();


	return 0;
}