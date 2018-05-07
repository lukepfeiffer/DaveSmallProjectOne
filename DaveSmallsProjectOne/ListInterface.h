/*
 * ListInterface.h
 *
 *  Created on: May 5, 2018
 *      Author: luke
 */
#include <cstddef>
#include <iostream>
#ifndef LISTINTERFACE_H_
#define LISTINTERFACE_H_

namespace cop3530 {
	template <typename T>

	class ListInterface {
		public:

			//adds the specified element to the list at the specified position, shifting the element originally at that and those in subsequent positions one position to the ”right.“
			virtual void insert( T element, int position ) = 0;

			//appends the specified element to the list.
			virtual void push_back( T element ) = 0;

			//prepends the specified element to the list.
			virtual void push_front( T element ) = 0;

			//replaces the existing element at the specified position with the specified element and return the original element.
			virtual T replace( T element, int position ) = 0;

			//removes and returns the the element at the specified position, shifting the subsequent elements one position to the ”left.“
			virtual T remove( int position ) = 0;

			//removes and returns the element at the list's tail.
			virtual T pop_back() = 0;

			//removes and returns the element at the list's head.
			virtual T pop_front() = 0;

			//returns (without removing from the list) the element at the specified position.
			virtual T item_at( int position ) = 0;

			//returns the element at the list's tail.
			virtual T peek_back() = 0;

			//returns the element at the list's head.
			virtual T peek_front() = 0;

			//returns true IFF the list contains no elements.
			virtual bool is_empty() = 0;

			//returns true IFF the no more elemtns can be added to the list.
			virtual bool is_full() = 0;

			//returns the number of elements in the list as a size_t.
			virtual std::size_t length() = 0;

			//removes all elements from the list.
			virtual void clear() = 0;

			//returns true IFF at least one of the elements of the list matches the specified element.
			virtual bool contains( T element ) = 0;

			//If the list is empty, inserts "<empty list>" into the ostream;
			//otherwise, inserts, enclosed in square brackets, the list's elements,
			//separated by commas, in sequential order.
			virtual void print( std::ostream &out) = 0;

			//— Allocates, initializes, and returns an array containing a copy of the list's elements in sequential order.
			virtual T* contents() = 0;

			virtual ~ListInterface(){};
	};

} /* namespace pa1 */

#endif /* LISTINTERFACE_H_ */
