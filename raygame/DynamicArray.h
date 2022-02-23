#pragma once
#include <exception>
template<typename T>
class DynamicArray
{
private:
	T* m_items;
	int m_length;

public:
	DynamicArray();
	~DynamicArray();
	void addItem(T item);
	void addItem(int item);
	void addItems(T items[], int size);
	bool removeItem(T item);
	void sortItem();
	int getLength();
	T getItem(int index);
	bool contains(T* actor);
	T operator [](int index);
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	m_length = 0;
	m_items = nullptr;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{}

template<typename T>
inline void DynamicArray<T>::addItem(T item)
{
	//Create a new array with a size one greater than our old array
	T* appendedArray = new T[getLength() + 1];
	//Copy the values from the old array to the new array
	for (int i = 0; i < getLength(); i++)
		appendedArray[i] = m_items[i];

	//Set the last value in the new array to be the actor we want to add
	appendedArray[getLength()] = item;
	//dealicating all of the old pointers in the array;
	delete[] m_items;
	//Set old array to hold the values of the new array
	m_items = appendedArray;
	m_length++;
}

template<typename T>
inline void DynamicArray<T>::addItem(int item)
{
	//Create a new array with a size one greater than our old array
	int* appendedArray = new int[getLength() + 1];
	//Copy the values from the old array to the new array
	for (int i = 0; i < getLength(); i++)
		appendedArray[i] = m_items[i];

	//Set the last value in the new array to be the actor we want to add
	appendedArray[getLength()] = item;
	//dealicating all of the old pointers in the array;
	delete[] m_items;
	//Set old array to hold the values of the new array
	m_items = appendedArray;
	m_length++;
}

template<typename T>
inline void DynamicArray<T>::addItems(T items[], int size)
{
	for (int i = 0; i < size; i++)
		addItem(items[i]);
}

template<typename T>
inline bool DynamicArray<T>::removeItem(T item)
{
	//Check to see if the actor was null
	if (!item || getLength() <= 0)
		return false;

	bool actorRemoved = false;
	//Create a new array with a size one less than our old array
	T* newArray = new T[getLength() - 1];
	//Create variable to access tempArray index
	int j = 0;
	//Copy values from the old array to the new array
	for (int i = 0; i < getLength(); i++)
	{
		//if the values are the same or the actor has been removed...
		if (item != m_items[i] || actorRemoved)
		{
			newArray[j] = m_items[i];//print that actor and...
			j++;//increament j
		}
		else
			actorRemoved = true;
	}
	//Set the old array to the new array
	if (actorRemoved)//if actor removed == true
	{
		delete[] m_items;//delets the items array 
		m_items = newArray;//set the items to the new array
		m_length--;//decrement length
	}
	//Return whether or not the removal was successful
	return actorRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItem()//This is insert sort but with Type T
{
	//key = 0 j= 0
	T valueHolder;
	int firstValue = 0;
	for (int i = 1; i < getLength(); i++)//for each index in collection
	{
		//set key to be the value at the curretn index
		valueHolder = m_items[i];
		//set j to be the previews index
		firstValue = i - 1;

		//start while loop
		while (firstValue >= 0 && m_items[firstValue] > valueHolder)//While j is greater than or equal to 0 value at j is greater than key
		{
			m_items[firstValue + 1] = m_items[firstValue];//set value at the index of j+1 to the value at index of j 
			firstValue--;//decrement j
		}//end while loop
		m_items[firstValue + 1] = valueHolder;//set collection at the index of j + 1 to be the key 
	}
	//only need it you dont have it take in a number that can very by user.
	//for (valueHolder = 0; valueHolder < getLength(); valueHolder++)
		//cout << m_items[valueHolder] << endl;
}

template<typename T>
inline int DynamicArray<T>::getLength()
{
	return m_length;
}

template<typename T>
inline T DynamicArray<T>::getItem(int index)
{
	//if index is negitive or the index is greater than the length...
	if (index < 0 || index >= getLength())
		return T();//return T's basic constructor

	return m_items[index];
}
template<typename T>
inline bool DynamicArray<T>::contains(T* actor)
{
	//Iterate through actor array
	for (int i = 0; i < m_length; i++)
	{
		//return the current actor if it matches the argument
		if (&m_items[i] == actor)
			return true;
	}
	return false;
}

template<typename T>
inline T DynamicArray<T>::operator[](int index)
{
	if (index > 0 || index < getLength()) {
		return m_items[index];
	}

	throw std::exception("You need help this was not good so do it again");
}