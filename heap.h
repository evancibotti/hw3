#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename Comparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, Comparator c = Comparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  // Need to add 5
  // the comparator used
  Comparator c;

  // the total degrees of the heap
  int heapdeg;

  // vector to store the elements of the of the heap
  std::vector<T> elements;

  // helper function for adding an element from heap
  void insert(int index);

  // helper function for removing an element from heap
  void remove(int index);
};

// Add implementation of member functions here
// constructor implementation
template <typename T, typename Comparator>
Heap<T, Comparator>::Heap(int m, Comparator c) : heapdeg(m), c(c) {
  // if the degrees are less than allowed fix them
  if(m <= 1){
    heapdeg = 2;
  }
}

// no new memory is created so can use default
template <typename T, typename Comparator>
Heap<T, Comparator>::~Heap() {}

// add an item to the end of the heap
template <typename T, typename Comparator>
void Heap<T, Comparator>::push(const T& item) {
  // add element to the end
  elements.push_back(item);
  // move the added item to its correct index
  insert(elements.size() - 1);
}

// return a boolean of if its empty or not
template <typename T, typename Comparator>
bool Heap<T, Comparator>::empty() const {
  // use vector class function
  return elements.empty();
}

// returns the size of the list in size_t type
template <typename T, typename Comparator>
size_t Heap<T, Comparator>::size() const {
  // use vector class function
  return elements.size();
}

// moves the chosen element to its correct spot in the heap
template <typename T, typename Comparator>
void Heap<T, Comparator>::insert(int index) {
  if(index == 0){
    return;
  }
  // store parent index
  int parentindex = (index-1)/heapdeg;

  // compare to see if child wins the comparison
  if(c(elements[index], elements[parentindex])){
    // swap the elements
    T temp = elements[index];
    elements[index] = elements[parentindex];
    elements[parentindex] = temp;
    // recursively call if swapped
    insert(parentindex);
  }
}

// moves the chosen element to the bottom of the heap
template <typename T, typename Comparator>
void Heap<T, Comparator>::remove(int index) {
  int lchild = heapdeg*index+1;

  if(lchild >= elements.size()){
     return;
  }

  int bchild = lchild;

  for(int i = 1; i < heapdeg; i++){
    int currchild = lchild + i;
    if (currchild < elements.size() && c(elements[currchild], elements[bchild])){
       bchild = currchild;
    }
  }
  
  if(c(elements[bchild], elements[index])){
    T temp = elements[index];
    elements[index] = elements[bchild];
    elements[bchild] = temp;
    remove(bchild);
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename Comparator>
T const & Heap<T,Comparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("the heap has no elements");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return elements[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename Comparator>
void Heap<T,Comparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("the heap has no elements");
  }

  // not sure on this!
  elements[0] = elements.back();
  elements.pop_back();
  if(empty() == 0){
    remove(0);
  }
}

#endif

