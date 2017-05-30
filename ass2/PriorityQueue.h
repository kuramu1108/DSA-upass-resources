#ifndef _PR_QUEUE_H
#define _PR_QUEUE_H

/*
 * Some headers that may be useful.
 * The utility header is included for the
 * std::pair<X,Y> class, used below.
 */
#include <vector>
#include <list>
#include <utility>
#include <iostream>

/*
 * This class implements a priority queue ADT
 * with priorities specified in ints.
 * Lower priority values precede higher values in
 * the ordering.
 * The template type E is the element type.
 * See the tests for examples.
 */
template <typename E>
class PriorityQueue {

private:

  /*
   * You will probably want to add some data
   * members here.
   */
   // array structure heap (minHeap, smallest at root)
   // the ith element's element = 2i + 1, 2i + 2
   // the ith's parent = floor(i-1/2),
   std::vector< std::pair<int, E> > data;

public:

  /*
   * A constructor, if you need it.
   */
  PriorityQueue() {}

  /*
   * This function adds a new element "element" to the queue
   * with priorioty "priority".
   */
  void insert(int priority, E element) {
    if (priority >= 0) {
        data.push_back(std::pair<int, E>(priority, element));
        reposition(data.size()-1);
    }
  }

  /*
   * Similar to insert, but takes a whole vector of new things to
   * add.
   */
  void insert_all(std::vector<std::pair<int,E> > new_elements) {
    for (typename std::vector<std::pair<int, E> >::const_iterator it = new_elements.begin(); it != new_elements.end(); it++) {
      data.push_back(*it);
      reposition(data.size()-1);
    }
  }

  /*
   * Takes the lowest priority value element off the queue, 
   * and returns it.
   */
  E remove_front() {
    if (!empty()) {
      E e = peek();
      data[0] = data.back();
      data.pop_back();
      adjust(0);
      return e;
    } else return E();
  }

  /*
   * Returns the lowest priority value element in the queue, but leaves
   * it in the queue.
   */
  E peek() {
    if (!empty()) return data[0].second;
    else return E();
  }

  /*
   * Returns a vector containing all the elements in the queue.
   */
  std::vector<E> get_all_elements() {
    std::vector<E> elements;
    for (typename std::vector<std::pair<int, E> >::const_iterator it = data.begin(); it != data.end(); it++) 
      elements.push_back(it->second);
    return elements;
  }

  /*
   * Returns true if the queue contains element "element", false
   * otherwise.
   */
  bool contains(E element){
    for (typename std::vector<std::pair<int, E> >::const_iterator it = data.begin(); it != data.end(); it++) {
      if (it->second == element) return true;
    }
    return false;
  }

  /*
   * Returns the priority of the element that matches
   * "element". If there is more than one, return it returns
   * the lowest priority value.
   * If no element matches, return -1.
   */
  int get_priority(E element){
    if (contains(element)) {
      int low_priority = -1;
      for (typename std::vector<std::pair<int, E> >::const_iterator it = data.begin(); it != data.end(); it++) {
        if (it->second == element) {
          if (low_priority == -1)
            low_priority = it->first;
          else if (low_priority > it->first)
            low_priority = it->first;
        }
      }
      return low_priority;
    } else
      return -1;
  }

  /*
   * Returns a vector containing all the priorities.
   * The ordering of the vector should match that of the
   * return from get_all_elements().
   * That is, the priority of the element
   * get_all_elements()[i] should be get_all_prriorities()[i].
   */
  std::vector<int> get_all_priorities(){
    std::vector<int> priorities;
    for (typename std::vector<std::pair<int, E> >::iterator it = data.begin(); it != data.end(); it++) 
      priorities.push_back(it->first);
    return priorities;
  }

  /*
   * Finds the first (in priority order) element that matches
   * "element", and changes its priority to "new_priority".
   */
  void change_priority(E element, int new_priority) {
    if (contains(element)) {
      for (typename std::vector<std::pair<int, E> >::iterator it = data.begin(); it != data.end(); it++) {
        if(it->second == element) {
          it->first = new_priority;
          adjust(0);
          break;
        }
      }
    }
  }

  /*
   * Returns the number of elements in the queue.
   */
  int size() {
    return data.size();
  }

  /*
   * Returns true if the queue has no elements, false otherwise.
   */
  bool empty() {
    return data.empty();
  }

  /*
   * support function that reposition the element after insertion
   */
  void reposition(int position) {
    int parent = (position - 1)/2;
    while (position != 0 && data[position].first < data[parent].first) {
      
      std::pair<int, E> temp = data[position];
      data[position] = data[parent];
      data[parent] = temp;

      position = parent;
      parent = (position - 1)/2;
    }
  }

  /*
   * adjust the vector into a minheap again
   */
   void adjust(int n) {
     if (n * 2 + 1 < size() - 1 ) {
       int child_1 = n * 2 + 1;
       int child_2 = n * 2 + 2;
       int child_to_swap;
       if (data[n].first > data[child_1].first || data[n].first > data[child_2].first) {
         if (data[child_1].first >= data[child_2].first) child_to_swap = child_2; 
         else child_to_swap = child_1;
         std::pair<int, E> temp = data[n];
         data[n] = data[child_to_swap];
         data[child_to_swap] = temp;
         adjust(child_to_swap);
       }
     }
   }


};

#endif
