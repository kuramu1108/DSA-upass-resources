#include "SimpleStringHashMap.h"

/*
 * Set everything up. As usual with C++, failure to
 * manually instantiate things with cause segfaults.
 */
SimpleStringHashMap::SimpleStringHashMap(int size){

}

/*
 * Skeleton for the extension exercise.
 */
//void SimpleStringHashMap::resize(){}

/*
 * Take a string, and put it somewhere in the map.
 * Probably a good idea if you used the hash(string)
 * function.
 *
 * If you have a collision, use linear probing to find
 * a spot to put it.
 *
 * The function returns true if the operation was successful,
 * false otherwise (i.e. when it's full).
 */
bool SimpleStringHashMap::insert(std::string value){

  
}

/*
 * Returns true if the map contains the passed in value.
 * False otherwise.
 */
bool SimpleStringHashMap::contains(std::string value){
 
  
}

/*
 * Removes the passed in value from the map, if it exists.
 * Returns true if the value was removed, false if it
 * wasn't there anyway.
 */
bool SimpleStringHashMap::remove(std::string value){

}

/*
 * As simple example of a hash function. Note the use
 * of the "% mapSize" to ensure the value is within
 * the specified size of the map. You can change this
 * if you feel adventurous.
 */
int SimpleStringHashMap::hash(std::string value){

  int hashValue = 0;

  for (int i = 0; i < value.size(); i++){
    hashValue += value[i];
  }

  return hashValue % mapSize;
  
}
