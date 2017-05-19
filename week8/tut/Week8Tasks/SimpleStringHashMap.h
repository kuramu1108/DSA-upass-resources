#ifndef _SSHASHMAP_H
#define _SSHASHMAP_H

#include <string>
#include <vector>
#include <iostream>

class SimpleStringHashMap {

private:

  std::vector<std::string> map;
  std::vector<bool> everUsed;
  std::vector<bool> currentlyUsed;
  int mapSize;

  //void resize();

public:

  SimpleStringHashMap(int);
  bool insert(std::string);
  bool contains(std::string);
  bool remove(std::string);
  int hash(std::string);
  
};

#endif
