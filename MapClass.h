#pragma once

#ifndef _MAPCLASS_H_
#define _MAPCLASS_H_

#include "KeyValueClass.h"


template<typename T1, typename T2>
class MapClass
{
public:

	MapClass(int size);
	~MapClass();

	//Some basic functions associated with Map :

	//begin() – Returns an iterator to the first element in the map
	//end() – Returns an iterator to the theoretical element that follows last element in the map
	//erase(iterator position) – Removes the element at the position pointed by the iterator

	int Size();							// Returns the number of elements in the map
	int MaxSize();						// Returns the maximum number of elements that the map can hold
	bool IsEmpty();						// Returns whether the map is empty
	void PairInsert(T1 key, T2 value);  // Adds a new element to the map
	T2 GetValue(T1 key);				// Returns a value of a key if it exists
	bool KeyExists(T1 key);				// Finds if a key already exists in the array
	void Erase(T1 key);					// Removes the key value ‘g’ from the map	
	void Clear();						// Removes all the elements from the map

	void printMap()
	{
		for (int i = 0; i < mapSize; i++)
		{
			std::cout << map[i].key << " " << map[i].value << std::endl;
		}
		std::cout << std::endl;		// adds a seperating line in the console
	}
private:
	int mapMaxSize = 0;		// The maximum size of the array
	int mapSize;				// The current size of the array

	template<typename T1, typename T2>
	class KeyValueClass
	{
	public:

		T1 key;
		T2 value;

	private:
	};

	KeyValueClass<T1, T2> *map;
	void SortMap();
	void AddMemory(); // 
};
#endif