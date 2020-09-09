#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "MapClass.h"
#include "MapClass.cpp"


#include <iostream>

bool random();

class TestClass
{
public:
	TestClass() {};
	TestClass(int inputInt) { Test = inputInt; };

	void setValue(int i)
	{
		Test = i;
	}

	bool operator == (TestClass& obj)
	{
		return Test == obj.Test;
	}
	bool operator < (TestClass& obj)
	{
		return Test < obj.Test;
	}

	friend std::ostream& operator <<(std::ostream& os, const TestClass& dt);

private:
	int Test;
};

std::ostream& operator <<(std::ostream& os, const TestClass& test)
{
	os << test.Test;
	return os;
}

int main()
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

	MapClass<int, std::string>* map = new MapClass<int, std::string>(5); // declares a map size of 5

	std::cout << "Map max Size: " << map->MaxSize() << std::endl << std::endl; // outputs the maximum size of the map

	for (int i = 0; i < 10; i++) // adds 10 elements, in the process calling KeyExists() and as the map size must be extended, calls SortMap() and AddMemort()
	{
		map->PairInsert(i, "one"); // inserts a KVP into the map
	}

	map->printMap();			// prints the map	

	std::cout << "Get Value 3: " << map->GetValue(3) << std::endl; // outputs the value associated to key 3

	std::cout << "Map Size: " << map->Size() << std::endl << std::endl; // outputs the size of the map

	std::cout << "Erasing at key '3': " << std::endl;
	map->Erase(3);				// erases the KVP with key "3"

	map->printMap();			// prints the map again

	std::cout << "Map Size: " << map->Size() << std::endl << std::endl; // outputs the size of the map

	std::cout << "Clearing the map... " << std::endl;
	map->Clear(); // clears the map

	std::cout << "Is the map empty? " << std::boolalpha << map->IsEmpty() << std::endl; // outputs the size of the map

	delete map;


	/////////////////////////////////////////////////////////////


	MapClass<char, bool>* map2 = new MapClass<char, bool>(5); // declares a map size of 5

	std::cout << "Map max Size: " << map2->MaxSize() << std::endl << std::endl; // outputs the maximum size of the map

	for (char i = 'a' - 0; i < 'a' + 24; ++i) // adds 10 elements, in the process calling KeyExists() and as the map size must be extended, calls SortMap() and AddMemort()
	{
		bool randBool = random();

		map2->PairInsert(i, randBool); // inserts a KVP into the map
	}

	map2->printMap();			// prints the map	

	std::cout << "Get Value C: " << map2->GetValue('c') << std::endl; // outputs the value associated to key 'c'

	std::cout << "Map Size: " << map2->Size() << std::endl << std::endl; // outputs the size of the map

	std::cout << "Erasing at key 'c': " << std::endl;
	map2->Erase('c');				// erases the KVP with key "C"

	map2->printMap();			// prints the map again

	std::cout << "Map Size: " << map2->Size() << std::endl << std::endl; // outputs the size of the map

	std::cout << "Clearing the map... " << std::endl;
	map2->Clear(); // clears the map

	std::cout << "Is the map empty? " << std::boolalpha << map2->IsEmpty() << std::endl; // outputs the size of the map

	delete map2;



	////////////////////////////////////////////////////////////////////



	MapClass<std::string, float>* map3 = new MapClass<std::string, float>(5); // declares a map size of 5

	std::cout << "Map max Size: " << map3->MaxSize() << std::endl << std::endl; // outputs the maximum size of the map

	// adds 10 elements, in the process calling KeyExists() and as the map size must be extended, calls SortMap() and AddMemort()
	map3->PairInsert("One", 1.2); // inserts a KVP into the map
	map3->PairInsert("Two", 6.7f); // inserts a KVP into the map
	map3->PairInsert("Three", 9.1f); // inserts a KVP into the map
	map3->PairInsert("Four", 2.0f); // inserts a KVP into the map
	map3->PairInsert("Five", 563.2f); // inserts a KVP into the map
	map3->PairInsert("Six", 108.2f); // inserts a KVP into the map
	map3->PairInsert("Seven", 9.0f); // inserts a KVP into the map
	map3->PairInsert("Eight", 0.0f); // inserts a KVP into the map
	map3->PairInsert("Nine", 17.6f); // inserts a KVP into the map
	map3->PairInsert("Ten", 12.3f); // inserts a KVP into the map

	map3->printMap();			// prints the map	

	std::cout << "Get Value Four: " << map3->GetValue("Four") << std::endl; // outputs the value associated to key "Four"

	std::cout << "Map max Size: " << map3->MaxSize() << std::endl; // outputs the maximum size of the map

	std::cout << "Map Size: " << map3->Size() << std::endl << std::endl; // outputs the size of the map

	std::cout << "Erasing at key 'Four': " << std::endl;
	map3->Erase("Four");				// erases the KVP with key "Four"

	map3->printMap();			// prints the map again

	std::cout << "Map Size: " << map3->Size() << std::endl << std::endl; // outputs the size of the map

	std::cout << "Clearing the map... " << std::endl;
	map3->Clear(); // clears the map

	std::cout << "Is the map empty? " << std::boolalpha << map3->IsEmpty() << std::endl; // outputs the size of the map

	delete map3;


	//////////////////////////////////////
	MapClass<TestClass, std::string>* map4 = new MapClass<TestClass, std::string>(5); // declares a map size of 5

	std::cout << "Map max Size: " << map4->MaxSize() << std::endl << std::endl; // outputs the maximum size of the map
	TestClass class1(1);
	class1.setValue(1);
	map4->PairInsert(class1, "One"); // inserts a KVP into the map

	TestClass class2(2);
	class2.setValue(2);
	map4->PairInsert(class2, "Two"); // inserts a KVP into the map

	TestClass class3(3);
	class3.setValue(3);
	map4->PairInsert(class3, "Three"); // inserts a KVP into the map

	TestClass class4(4);
	class4.setValue(4);
	map4->PairInsert(class4, "Four"); // inserts a KVP into the map

	TestClass class5(5);
	class5.setValue(5);
	map4->PairInsert(class5, "Five"); // inserts a KVP into the map

	TestClass class6(6);
	class6.setValue(6);
	map4->PairInsert(class6, "Six"); // inserts a KVP into the map

	TestClass class7(7);
	class7.setValue(7);
	map4->PairInsert(class7, "Seven"); // inserts a KVP into the map

	TestClass class8(8);
	class8.setValue(8);
	map4->PairInsert(class8, "Eight"); // inserts a KVP into the map

	TestClass class9(9);
	class9.setValue(9);
	map4->PairInsert(class9, "Nine"); // inserts a KVP into the map

	TestClass class10(10);
	class10.setValue(10);
	map4->PairInsert(class10, "Ten"); // inserts a KVP into the map


	map4->printMap();			// prints the map	

	std::cout << "Get Value class3: " << map4->GetValue(class3) << std::endl; // outputs the value associated to key class3

	std::cout << "Map Size: " << map4->Size() << std::endl << std::endl; // outputs the size of the map

	std::cout << "Erasing at key 'class3': " << std::endl;
	map4->Erase(class3);				// erases the KVP with key "class3"

	map4->printMap();			// prints the map again

	std::cout << "Map Size: " << map4->Size() << std::endl << std::endl; // outputs the size of the map

	std::cout << "Clearing the map... " << std::endl;
	map4->Clear(); // clears the map

	std::cout << "Is the map empty? " << std::boolalpha << map4->IsEmpty() << std::endl; // outputs the size of the map

	delete map4;

	//////////////////////////////////////////////////////////////////////

	MapClass<int, TestClass>* map5 = new MapClass<int, TestClass>(5); // declares a map size of 5

	std::cout << "Map max Size: " << map5->MaxSize() << std::endl << std::endl; // outputs the maximum size of the map

	TestClass classOne(1);
	classOne.setValue(1);
	map5->PairInsert(1, classOne); // inserts a KVP into the map

	TestClass classTwo(2);
	classTwo.setValue(2);
	map5->PairInsert(2, classTwo); // inserts a KVP into the map

	TestClass classThree(3);
	classTwo.setValue(3);
	map5->PairInsert(3, classTwo); // inserts a KVP into the map

	TestClass classFour(4);
	classTwo.setValue(4);
	map5->PairInsert(4, classTwo); // inserts a KVP into the map

	TestClass classFive(5);
	classTwo.setValue(5);
	map5->PairInsert(5, classTwo); // inserts a KVP into the map

	TestClass classSix(6);
	classOne.setValue(6);
	map5->PairInsert(6, classOne); // inserts a KVP into the map

	TestClass classSeven(7);
	classTwo.setValue(7);
	map5->PairInsert(7, classTwo); // inserts a KVP into the map

	TestClass classEight(8);
	classTwo.setValue(8);
	map5->PairInsert(8, classTwo); // inserts a KVP into the map

	TestClass classNine(9);
	classTwo.setValue(9);
	map5->PairInsert(9, classTwo); // inserts a KVP into the map

	TestClass classTen(10);
	classTwo.setValue(10);
	map5->PairInsert(10, classTwo); // inserts a KVP into the map


	


	map5->printMap();			// prints the map	

	std::cout << "Get Value class3: " << map5->GetValue(5) << std::endl; // outputs the value associated to key 5

	std::cout << "Map Size: " << map5->Size() << std::endl << std::endl; // outputs the size of the map

	std::cout << "Erasing at key '5': " << std::endl;
	map5->Erase(5);				// erases the KVP with key "5"

	map5->printMap();			// prints the map again

	

	std::cout << "Map Size: " << map5->Size() << std::endl << std::endl; // outputs the size of the map

	std::cout << "Clearing the map... " << std::endl;
	map5->Clear(); // clears the map

	std::cout << "Is the map empty? " << std::boolalpha << map5->IsEmpty() << std::endl; // outputs the size of the map

	delete map5;
	_CrtDumpMemoryLeaks();
	system("pause");
}

bool random() 
{
	if (rand() % 2 == 0)
	{
		return true;
	}
	else return false;
}