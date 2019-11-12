#include <iostream>
#include <memory>
#include "ap_error.h"

/* a scoped enum is used for the insertion "method" */
enum class method { push_back, push_front };

template <class T>
class List { 
   /* the linked list is a node class
	* a node is defined as a structure */
	struct node {
	   /* the node structure is made of a unique_ptr
	    * to a node and a templated value */
    	std::unique_ptr<node> next;
    	T value;
       /* the copy constructor takes as input a reference
        * and a pointer to a node structure (the ownership
        * of the object is transfered since using unique_ptr) */
    	node(const T& v, node* p) : next{p}, value{v} {
      	std::cout << "copy ctor" << std::endl;
    	}
       /* the move constructor takes as input an rvalue (a
        * a temporary value) and a pointer to a node structure 
        * (for which there is no need to use std::move())*/
    	node(T&& v, node* p) : next{p}, value{std::move(v)} {
      	std::cout << "move ctor" << std::endl;
    	}
       /* the custom constructor takes as input the memory
        * address of a pointer to a node and initialises a
        * node with its value and its pointer (if it's not 
        * nullptr) as unique */
    	explicit node(const std::unique_ptr<node>& p) : value{p->value} {
      	if (p->next)
        	next = std::make_unique<node>(p->next);
    	}
	};

   /* definition of a unique_ptr to a node
    * which is part of the class list */
	std::unique_ptr<node> head;

   /* this function returns a pointer to the last
    * node struct of the list (get() return *this) */
	node* tail() noexcept {
 		auto tmp = head.get();

  		while (tmp->next)
   			tmp = tmp->next.get();

 	 	return tmp;
	}

   /* takes as input an rvalue and (using the move ctor)
    * assigns to the pointer to the last structure (tail)
    * the unique_ptr to a node constructed (by default) 
    * with the rvalue and the nullptr */
	template <class OT>
	void push_back(OT&& v) {
		node* last = tail();
		last->next = std::make_unique<node>(std::forward<OT>(v), nullptr);
	}
	
   /* takes as input an rvalue and (using the move ctor)
    * assigns to the pointer to the first structure (head)
    * the unique_ptr to a node constructed (by default) with
    * the rvalue and the released head pointer */
	template <class OT>
	void push_front(OT&& v) {
    	head = std::make_unique<node>(std::forward<OT>(v), head.release());
  	}
   /* release() releases ownership of the stored pointer 
    * by returning its value and replacing it with nullptr */

 	public:
 	   /* the class has a default constructor, a default
		* move constructor and a default move assignment */
  		List() noexcept = default;
  		List(List&& l) noexcept = default;
  		List& operator=(List&& l) noexcept = default;
		
	   /* definition of a list copy constructor 
	    * (the node custom ctor is called recursively)
	    * and of a list copy assignment */
		List(const List& l) {
 		head = std::make_unique<node>(l.head);
		}
  		List& operator=(const List& l);

       /* this function takes as input an rvalue and a "method" 
        * if there is no head pointer one is constructed else
        * the new node is added to the list (this function can
        * be called with an lvalue instead of an rvalue and the 
        * distinction is preserved by using std_::forward()) */
		template <class OT>
		void insert(OT&& v, const method m) {
 	 	if (!head) {
   			head = std::make_unique<node>(std::forward<OT>(v), nullptr);
    	return;
 	 	}
 	 	switch (m) {
 	 	   /* std_::forward() casts "v" to the value
 	 	    * category (lvalue or rvalue) used to
 	 	    * pass it (perfect forwarding) */
  	 		case method::push_back:
      		push_back(std::forward<OT>(v));
      		break;

   			case method::push_front:
     		push_front(std::forward<OT>(v));
      		break;
      		
   	 		default:
      		AP_ERROR(false) << "Unknown insertion method";
    		break;
  		};
  	   /* the library "ap_error.h" is
        * used for error handling */
		}
   
	template <class O>
	friend std::ostream& operator<<(std::ostream&, const List<O>&);
   /* the overloaded << operator is defined as friend 
    * so the "insert" function can access it */
};

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& l) {
   /* overloading of the << operator 
    * the node pointer is moved among
    * the pointers to other nodes */
	auto tmp = l.head.get();
	while (tmp) {
	os << tmp->value << " ";
	tmp = tmp->next.get();
	}
	return os;
}

int main() {
	try {
    	List<int> l{};

       /* the move ctor is called every
        * time a "method" is called */
    	l.insert(4, method::push_back);
    	l.insert(5, method::push_back);
   		l.insert(3, method::push_front);

    	std::cout << l << std::endl;

	   /* the list copy calls the custom ctor
	    * the insertion of 14 calls the move ctor 
	    * the insertion of "a" calls the copy ctor
	    * (14 is an rvalue while "a" is a lvalue) */ 
    	auto ol = l; 
    	int a = 9;
    	l.insert(14, method::push_front);
    	l.insert(a, method::push_front);

    	std::cout << l << std::endl;
    	std::cout << ol << std::endl;

   /* this block of code is tried and if some exceptions are
	* thrown by the library "ap_error.h" they are now catched */
  	} catch (std::exception& e) {
    	std::cerr << e.what() << std::endl;
  	} catch (...) {
    	std::cerr << "Unknown exception" << std::endl;
  	}

	return 0;
}