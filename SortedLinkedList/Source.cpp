#include <iostream>
#include "SLinkedList.cpp"

using namespace std;

int main()
{
	SLinkedList<int> s;
	SLinkedList<int> s2;
	SLinkedList<int> intersection;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	
	s2.insert(10);
	cout << "min of second list = " << s2.getMin() << endl;
	s2.insert(9);
	cout << "min of second list = " << s2.getMin() << endl;
	s2.insert(8);
	cout << "min of second list = " << s2.getMin() << endl;

	cout << "\n";

	cout << "first list before merge :";
	s.printlist();

	cout << "second list before merge :";
	s2.printlist();

	cout << "\n";

	intersection = s.intersection(s2);
	cout << "Intersection between 2 lists before the merge:";
	intersection.printlist();

	cout << "\n";
	s.merge(s2);
	cout << "\n";

	cout << "first list after merge :";
	s.printlist();

	cout << "second list after merge :";
	s2.printlist();
	
	cout << "\n";
	
	intersection = s.intersection(s2);
	cout << "Intersection between 2 lists after the merge:";
	intersection.printlist();

	cout << "\n";

	cout << "first list after the intersection :";
	s.printlist();

	cout << "second list after the intersection :";
	s2.printlist();
	
	cout << "\n";

	return 0;
}