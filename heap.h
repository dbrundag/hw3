#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
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
  Heap(int m=2, PComparator c = PComparator());

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
	void trickleUp(int loc);
	void trickleDown(int loc);

	std::vector<T> items;
	int d;
	PComparator comp;
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c): d(m),comp(c) 
{ 
		//can't have 0-arry tree. Cannot divide by 0
		if(d <= 0)
		{
			d = 2;
		}
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){	}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
	items.push_back(item);
	trickleUp(items.size() - 1);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const { return items.empty();}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const { return items.size();}



template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int loc)
{
	while (loc != 0) 
	{
      std::size_t parent_index = (loc - 1) / d;
      T& current = items[loc];
      T& parent = items[parent_index];
      if (comp(parent, current)) 
			{
          break;
      }
      std::swap(current, parent);
      loc = parent_index;
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(int loc) 
{
	if((unsigned int)(loc * d + 1) >= items.size()) // if location is leaf node
	{
		return;
	}

	int leftmostChild = d * loc + 1;
	int betterChild = leftmostChild; // start w/ left

	//gotta make a loop to go through each child
	for(int i=1; i < d; i++)
	{
		if(items.size() > (unsigned int)(leftmostChild + i)) // if another child exist
		{
			int nChild =  leftmostChild + i; //nextChild

			if(comp(items[nChild], items[betterChild]))
			{
				betterChild = nChild;
			} 
		}
	}

	if(comp(items[betterChild], items[loc]))
	{
		std::swap(items[loc], items[betterChild]);
		trickleDown(betterChild);
	}
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top () const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
		throw std::underflow_error("heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return items[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty())
	{
		throw std::underflow_error("heap is empty");
  }

	items[0] = items.back();
	items.pop_back();
	if(items.empty()){
		return;
	}
	trickleDown(0);
}



#endif

