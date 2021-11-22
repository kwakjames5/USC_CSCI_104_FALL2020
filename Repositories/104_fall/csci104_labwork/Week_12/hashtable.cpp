#include "hashtable.h"
#include <iostream>

using namespace std;

#define A 54059 
#define B 76963 
#define C 86969 

/**
Hash function for the CS104 hash table.
*/
unsigned hash_str(const char* s)
{
   unsigned h = 31;
   while (*s) {
     h = (h * A) ^ (s[0] * B);
     s++;
   }
   return h % C; 
}

/**
Creates a hash table of the given input size. Creates the array and vectors used for the hash table.
*/
HashTable::HashTable(int size) {
	this->size = size;
	data.resize(size);
}

/**
No clean up necessary if we are using smart pointers!
*/
HashTable::~HashTable() {

}

/**
Inserts key and value pair to HashTable, unless it is a duplicate key.
@param key is the key.
@param value is the value.
Note: insert should do nothing if the key already exists in the hash table.
*/
void HashTable::insert(string str) {
	unsigned hash = hash_str(str.c_str());
	hash = hash % size;
	// TODO
	// check if hash has anything there
	// if it does: linear probe
		// linear probe until you find an empty spot / are confident there are no more empty spots
		// if empty spot: insert there
	// if it doesn't, insert at hash


	for(int i = 0; i < size; i++)
	{
		if(data[hash] == nullptr)
		{
			// found empty spot
			data[hash] = make_unique<string>(str);
			return;
		}

		if(*(data[hash]) == str)
		{
			return;
		}

		hash++;
		hash = hash % size;
	}

	return;
}

/**
Finds if key exists and returns true if it does.
@param key is the key to find.
*/
bool HashTable::find(string key) {
	unsigned hash = hash_str(key.c_str());
	hash = hash % size;
	// TODO
	// check if hash has anything there
	// if it doesn't, then we know what to return
	// if it does, check if what's there is what we're looking for
		// if it is, return
		// linear probe until we are sure that we have an answer (sentinal) if(data[hash] == sentinal) then..
	for(int i = 0; i < size; i++)
	{
		if(data[hash] == nullptr)
		{
			return false;
		}
		if(*(data[hash]) == key)
		{
			return true;
		}
		
		hash++;
		hash = hash % size;
	}

	return false;
}

/**
Removes key if it exists.
@param key is key to remove.
Note: remove should do nothing if the key does not exist in the hash table.
*/
void HashTable::remove(string str) {
	unsigned hash = hash_str(str.c_str());
	hash = hash % size;
	// TODO
	// find the str, (if not there then nothing to do)
	// remove the string, then use linear probing to replace everything coming after which may have had their probing squence disripted
	// --> remove the string, then put a sentinal there


	for(int i = 0; i < size; i++)
	{
		if(data[hash] != nullptr && *(data[hash]) == str)
		{
			data[hash].reset();
			// worry about replacing everything after

			int curr = (hash + 1) % size;
			for(int i = 0; i < size; i++)
			{
				if(data[curr] == nullptr)
				{
					return;
				}

				string temp = *data[curr];
				data[curr].reset();
				insert(temp);

				curr++;
				curr = curr % size;
			}
			return;
		}
		hash++;
		hash = hash % size;
	}

	return;
}

void HashTable::print() {
	for(int i = 0; i < size; i++) {
		cout << i << ": " << (data[i] == nullptr ? " " : *data[i]) << endl;
	}
}
