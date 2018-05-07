/*
 * ADTList.h
 *
 *  Created on: May 5, 2018
 *      Author: luke
 */

#include "ListInterface.h"
#include "Node.h"
#include <limits>
#include <iostream>

#ifndef ADTLIST_H_
#define ADTLIST_H_

namespace cop3530{
	template <typename T>
	class SSLL : public ListInterface<T> {

		public:
			SSLL<T>();
	        SSLL(const SSLL&); //copy contructor
	        SSLL& operator =(const SSLL&); //copy assignment operator
			SSLL<T>(int size);
			virtual ~SSLL<T>();
		    void insert( T element, int position ) override; //TODO check if it works
		    void push_back( T element ) override; //Donzo
		    void push_front( T element ) override; //Donzo
		    T replace( T element, int position ) override; //Donzo
		    T remove( int position ) override; //Donzo
		    T pop_back( void ) override; //Donze
		    T pop_front( void ) override; //Donzo
		    T item_at( int position ) override; //Donzo
		    T peek_back( void ) override; //Donzo
		    T peek_front( void ) override; //Donzo
		    bool is_empty( void ) override; //Donzo
		    bool is_full() override; //Donzo
		    size_t length( void ) override; //Donzo
		    void clear( void ) override; //Donzo
			bool contains( T element ) override; //Donzo
			void print( std::ostream &out ); //Donzo
			void print();
		    T * contents() override; //Donzo


		private:
		    Node<T> * head;
		    Node<T> * tail;
		    size_t maxSize;
	};

	template <typename T>
	SSLL<T>::SSLL() {
		head = 0;
		tail = 0;
		maxSize = std::numeric_limits<int>::max();;
	}

	template <typename T>
	SSLL<T>::SSLL( int maxSize ) {
		head = 0;
		tail = 0;
		this->maxSize = maxSize;
	}

	/*
	 * Insertion into a SLLL
	 * @return void
	 * @param none
	 */
	template <typename T>
	void SSLL<T>::insert( T element, int index ){
		Node<T> * newNode = new Node<T>();
		newNode->data = element;

		//If head is null, set the head pointer to this.
		if( head == 0 ){
			this->head = newNode;
			this->tail = newNode;
			return;
		}

		//If head points to null, set next to the new node
		if( index == 0 ){
			Node<T> * temp = head;
			head = head->next;
			head->next = temp;
			return;
		}

		Node<T> * previous = head;
		Node<T> * curr = head->next;

		//Iterate over the linked list and keep track of the previous.
		//If the value is not null, set the next once the index value is reached.
		int counter = 1;
		while( curr != 0 ){
			if( counter == index ){
				previous->next = newNode;
				newNode->next = curr;
				return;
			}

			curr = curr->next;
			previous = previous->next;
			++counter;

		}
	}

	/*
	 * Pushes the specified element to the back of the list
	 * @return void
	 * @param T element
	 */
	template <typename T>
	void SSLL<T>::push_back( T element ){
		Node<T> * newNode = new Node<T>();
		newNode->data = element;

		//If list is empty, set head and tail
		if( is_empty() ){
			head = newNode;
			tail = newNode;
			return;
		}

		//Set tail-> next as newNode
		Node<T> * temp = tail;
		temp->next = newNode;
		//Update data
		this->tail = newNode;
	}

	/*
	 * Pushes the specified element to the front of the list
	 * @return void
	 * @param T element
	 */
	template <typename T>
	void SSLL<T>::push_front( T element ){
		Node<T> * newNode = new Node<T>();
		newNode->data = element;

		//If list is empty, set head and tail
		if( is_empty() ){
			head = newNode;
			tail = newNode;
			return;
		}

		//Create temp of head
		Node<T> * temp = head;

		//Set head as new node
		head = newNode;

		//Set newNode next as the old head
		newNode->next = temp;
	}
	/*
	 * Replace an element at an index with a new element
	 * @return the removed value from the list
	 * @param T element, int index
	 */
	template <typename T>
	T SSLL<T>::replace( T element, int index ){
		if( is_empty() ){
			throw std::domain_error( "The list is empty." );
		}

		Node<T> newNode;
		newNode.data = element;

		if( index == 0 ){
			//Create temp value for head
			Node<T> * tempNode = head;

			//Set head equal to the new Element
			T temp = tempNode->data;
			head = &newNode;

			//Delete tempNode and return temp value
			delete tempNode;
			return temp;
		}

		Node<T> * prev = head;
		Node<T> * curr = head->next;
		int currIndex = 0;

		while( curr != 0 ){
			if( currIndex == index ){
				//Set the previous node next to the new Node
				//Set the newNode next equal to the curr next, effectively replacing curr
				prev->next = &newNode;
				newNode.next = curr->next;

				//Wrapping up the method
				T temp = curr->data;
				delete curr;
				return temp;
			}
			prev = curr;
			curr = curr->next;
			++currIndex;
		}

		throw std::out_of_range("The specified index was outside of the list");
	}
	/*
	 * Removes the item at the specified index
	 * @return T of the removed element
	 * @param index
	 */
	template <typename T>
	T SSLL<T>::remove( int index ){
		//If list is empty, throw exception
		if( is_empty() ){
			throw std::domain_error( "The list is empty." );
		}

		//If index is 0, set head to next value and return head data
		if( index == 0 ){
			T temp = head->data;
			Node<T> * tempNode = head;
			head = head->next;

			delete tempNode;
			return temp;
		}

		Node<T> * prev = head;
		Node<T> * curr = head->next;
		int currIndex = 1;

		while( curr != 0 ){
			if( currIndex == index ){
				//If tail is removed, update tail;
				if( curr == tail ){
					tail = prev;
				}

				//Create temp value
				T temp = curr->data;
				//Remove curr from list
				prev->next = curr->next;

				//Delete curr and return temp
				delete curr;
				return temp;
			}

			prev = curr;
			curr = curr->next;
			++currIndex;

		}
		throw std::out_of_range("The specified index was outside of the list");
	}
	/*
	 * Removes and returns the last element in the list
	 * @return T tail->data
	 * @param none
	 */
	template <typename T>
	T SSLL<T>::pop_back() {
		//Throw exception if list is empty
		if( is_empty() ){
			throw std::domain_error( "The list is empty." );
		}

		//If head == tail (list length = 1), special case
		if( head == tail ){
			T temp = head->data;
			head->data = 0;
//			delete head;

			head = 0;
			tail = 0;
			delete head;
			return temp;
		} else {
			//Iterate over list until we get the element before the tail.
			Node<T> * curr = head;
			while( curr->next != tail ){
				curr = curr->next;
			}

			//Create variable of data; and delete tail
			Node<T> * temp = tail;
			this->tail = curr;
			curr->next = 0;
			T tempData = temp->data;
			delete temp;

			return tempData;
		}
	}

	/*
	 * Returns and removes the head of the list
	 * @return T head->data
	 * @param none
	 */
	template <typename T>
	T SSLL<T>::pop_front(){

		//If list is empty, throw exception
		if( is_empty() ){
			throw std::domain_error( "The list is empty." );
		}

		//Get data of head.
		T temp = head->data;

		//Return temp
		this->head = this->head->next;
		return temp;
	}

	/*
	 * Returns the element at a specified index
	 * @return element at index
	 * @param none
	 */
	template <typename T>
	T SSLL<T>::item_at( int index ){
		Node<T> * curr = head;
		int currIndex = 0;
		while( curr != 0 ){
			if( currIndex == index ){
				return curr->data;
			}

			curr = curr->next;
		}

		throw std::out_of_range("The specified index was outside of the list");
	}

	/*
	 * Returns the tail of the list
	 * @return tail of the list
	 * @param none
	 */
	template <typename T>
	T SSLL<T>::peek_back(){
		return tail->data;
	}

	/*
	 * Returns the head of the list
	 * @return head of the list
	 * @param none
	 */
	template <typename T>
	T SSLL<T>::peek_front(){
		return head->data;
	}

	/*
	 * Returns whether the list is empty
	 * @return bool value of emptiness
	 * @param none
	 */
	template <typename T>
	bool SSLL<T>::is_empty(){
		if( head == 0 ){
			return true;
		}

		return false;
	}

	/*
	 * This particular kind of list can not be "full" unless max size is given
	 * @return false
	 * @param none
	 */
	template <typename T>
	bool SSLL<T>::is_full(){
		if( length() == maxSize ){
			return true;
		}

		return false;
	}

	/*
	 * Iterates over the linked list and returns the lenght of the list.
	 * @return size_t of the list
	 * @param none
	 */
	template <typename T>
	size_t SSLL<T>::length(){
		Node<T> * curr = head;
		size_t length = 0;
		while( curr != 0 ){
			++length;
			curr = curr->next;
		}

		return length;
	}

	/*
	 * Removes all elements from the list
	 * @return none
	 * @param none
	 */
	template <typename T>
	void SSLL<T>::clear(){
		Node<T> * curr = head;

		//Iterate over the list and delete nodes as we go
		while( curr != 0 ){
			Node<T> * temp = curr;
			curr = curr->next;
			delete temp;
		}
	}

	/*
	 * Iterates over the list and sees if an element exists in the list
	 * @return bool of whether the element exists in list
	 * @param T element
	 */
	template <typename T>
	bool SSLL<T>::contains( T element ){
		Node<T> * curr = head;
		//Iterate over list, return true if element exists in list
		while( curr != 0 ){
			if( curr-> data == element ){
				return true;
			}

			curr = curr->next;
		}

		return false;
	}

	/*
	 * Prints the list to the Ostream
	 * @return void
	 * @params std::ostream
	 */
	template <typename T>
	void SSLL<T>::print( std::ostream &out ){
		if( is_empty() ){
			throw std::domain_error( "The list is empty." );
		}

		Node<T> * curr = head;
		std::cout << "[";
		//Iterate over linked list.
		while( curr != 0 ){
			if( curr->next != 0 ){
				std::cout << curr->data;
				std::cout << ", ";
			} else {
				std::cout << curr->data;
			}

			curr = curr->next;
		}

		std::cout << "]";
	}

	template <typename T>
	void SSLL<T>::print(){
		Node<T> * curr =  head;

		while( curr != 0 ){
			std::cout << curr->data << "-> ";
			curr = curr->next;
		}
		std::cout << "\n";
	}

	/*
	 * Puts the list into an array
	 * @return *T array
	 * @param none
	 */
	template <typename T>
	T* SSLL<T>::contents() {
		if( is_empty() ){
			throw std::domain_error( "The list is empty." );
		}

		int size = length();
		Node<T> * curr = head;
		T * contents = new int[ size ];

		for( int i = 0; i < size; ++i ){
			contents[i] = curr->data;
			curr = curr->next;
		}

		return contents;
	}

	/*
	 * Descructor for list
	 */
	template <typename T>
	SSLL<T>::~SSLL() {
		clear();
		delete this;
	}

} /* namespace pa1 */

#endif /* ADTLIST_H_ */
