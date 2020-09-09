#include "MapClass.h"

template <typename T1, typename T2>
MapClass<T1, T2>::MapClass(int size)
{
	mapMaxSize = size; //sets the maximum size of the current map
	map = new KeyValueClass<T1, T2>[mapMaxSize]; // initialize the map array to the size passed as a parameter
	mapSize = 0; // sets the current size of the map to empty
}

template <typename T1, typename T2>
MapClass<T1, T2>::~MapClass()
{
	delete[] map;
	// dealloc memory and delete pointer
}


template <typename T1, typename T2>
int MapClass<T1, T2>::Size() // Returns the number of elements in the map
{
	return mapSize;
}

template <typename T1, typename T2>
int MapClass<T1, T2>::MaxSize() // Returns the maximum number of elements that the map can hold
{
	return mapMaxSize;
}

template <typename T1, typename T2>
bool MapClass<T1, T2>::IsEmpty() // – Returns whether the map is empty
{
	if (mapSize == 0)
	{
		return true;
	}

	return false;
}

template <typename T1, typename T2>
void MapClass<T1, T2>::PairInsert(T1 key, T2 value) //Adds a new element to the map
{
	bool added = KeyExists(key); // checks to see if the key already exists in the map

	if(added) // if it is
	{
		for (int i = 0; i < mapSize; i++)
		{
			if (map[i].key == key)
			{
				map[i].value = value; // only changes the value related to that key
			}
		}
	}
	else
	{
		map[mapSize].key = key;		// sets the key of the next empty KVP to the key parameter
		map[mapSize].value = value; // sets the value of the next empty KVP to the value parameter
		++mapSize;					// adds 1 to the current size of the map
		SortMap();					// sorts the updated map
		if (mapSize == mapMaxSize)	// checks to see if the maps new size is equal to the maximum size
		{
			AddMemory();			// allocates more memory to the map
		}
		
	}
}

template <typename T1, typename T2>
T2 MapClass<T1, T2>::GetValue(T1 key) // returns a value of a key if it exists
{
	for (int i = 0; i < mapMaxSize; i++)
	{
		if (map[i].key == key)
		{
				return map[i].value;
		}
	}
}

template <typename T1, typename T2>
bool MapClass<T1, T2>::KeyExists(T1 key) // finds if a key already exists in the array
{
	for (int i = 0; i < mapSize; i++)
	{
		if (map[i].key == key)
		{
			return true;
		}
	}

	return false;
}

template <typename T1, typename T2>
void MapClass<T1, T2>::Erase(T1 key) // Removes the key value pair from the map
{
	if (KeyExists(key)) // checks to see if the key exists in the map
	{
		KeyValueClass<T1, T2>*newMap = new KeyValueClass<T1, T2>[mapSize]; // creates a new map of the same size
		//for (int i = 0; i < mapSize; i++)  // for loop cycles through old aray and copies KVP's that do not have the associated key
		//{
		//	if (!(map[i].key == key))
		//	{
		//	std::cout << "mapKey: " << map[i].key << " mapvalue: " << map[i].value << std::endl;
		//		newMap[i].key = map[i].key;
		//		newMap[i].value = map[i].value;
		//	}
		//}
		int modifier = 0;
		for (int i = 0; i < mapSize; i++)  // for loop cycles through old aray and copies KVP's that do not have the associated key
		{
			if ((map[i].key == key))
			{
				modifier++;
				std::cout << "mapKey: " << map[i].key << " mapvalue: " << map[i].value << std::endl;
				
			}
			newMap[i].key = map[i+modifier].key;
			newMap[i].value = map[i+modifier].value;
		}
		
		delete[] map; // deletes the old map
		map = newMap; // causes the old map pointer to point at newMap
		//SortMap(); // sorts the new map
		--mapSize; // reduces the map size by 1 to account for the KVP being removed

	}
}

template <typename T1, typename T2>
void MapClass<T1, T2>::Clear() // Removes all the elements from the map
{
	delete[] map; // deletes the old map
	mapSize = 0;  // sets the size of the new map back to 0 the default
	map = new KeyValueClass<T1, T2>[mapMaxSize]; // initializes a new map of the current max size
}

template <typename T1, typename T2>
void MapClass<T1, T2>::SortMap()
{
	int i; // position in the array being checked
	int j; // position in the array 1 before 'i'
	T1 key; // key being sorted by
	T2 value; // value attatched to the key being sorted

	for (i = 1; i < mapSize; i++)
	{
		key = map[i].key;
		value = map[i].value;
		j = i - 1;

		// moves every element one position to the right if it is greater than the current key
		while (j >= 0 && map[j].key < key)
		{
			map[j + 1] = map[j];

			j = j - 1;
		}
		map[j + 1].key = key;
		map[j + 1].value = value;
	}
}

template <typename T1, typename T2>
void MapClass<T1, T2>::AddMemory()
{
	// old array thats at capacity
	// allocate memory for new array which is 2x size
	mapMaxSize = mapMaxSize * 2;
	KeyValueClass<T1, T2>* newMap = new KeyValueClass<T1, T2>[mapMaxSize];

	// copy old array to new array
	for (int i = 0; i < mapSize; i++) 
	{									
		newMap[i].key = map[i].key;
		newMap[i].value = map[i].value;
	}
	// delete old array
	delete[] map;
	// assign old pointer to new array
	map = newMap;
}