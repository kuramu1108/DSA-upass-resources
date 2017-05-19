#include "SimpleStringHashMap.h"

SimpleStringHashMap::SimpleStringHashMap(int size){

  map = std::vector<std::string>(size);
  everUsed = std::vector<bool>(size);
  currentlyUsed = std::vector<bool>(size);
  mapSize = size;
  
}

bool SimpleStringHashMap::insert(std::string value){

  int startHash = hash(value);

  for (int i = startHash; i < startHash + mapSize; i++){

    if (!currentlyUsed[i % mapSize]){

      map[i % mapSize] = value;
      currentlyUsed[i % mapSize] = true;
      everUsed[i % mapSize] = true;
      return true;

    }

  }

  return false;
  
}

bool SimpleStringHashMap::contains(std::string value){
 
  int startHash = hash(value);

  for (int i = startHash; i < startHash + mapSize; i++){

    if (everUsed[i % mapSize]){

      if (map[i % mapSize] == value) return true;

    }
    else {

      return false;

    }

  }

  return false; 
  
}

bool SimpleStringHashMap::remove(std::string value){

  int startHash = hash(value);

  for (int i = startHash; i < startHash + mapSize; i++){

    if (everUsed[i % mapSize]){

      if (map[i % mapSize] == value){

	map[i % mapSize] = "";
	currentlyUsed[i % mapSize] = false;
	return true;

      }

    }
    else {

      return false;

    }

  }

  return false;

}

int SimpleStringHashMap::hash(std::string value){

  int hashValue = 0;

  for (int i = 0; i < value.size(); i++){
    hashValue += value[i];
  }

  return hashValue % mapSize;
  
}
