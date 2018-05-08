/*
 * SDAL.h
 *
 *  Created on: May 8, 2018
 *      Author: luke
 */
#include "ListInterface.h"
#include "Node.h"
#include <limits>
#include <iostream>

#ifndef SDAL_H_
#define SDAL_H_

namespace cop3530 {

	template <typename T>
	class SDAL : public ListInterface<T> {
		public:
			//Con/DeStructors
			SDAL<T>();
			SDAL<T>( T * startArray );
			SDAL<T>( int maxSize );
	        SDAL(const SDAL&); //copy contructor
	        SDAL& operator =(const SDAL&); //copy assignment operator
			virtual ~SDAL();

		    void insert( T element, int position ) override; //TODO check if it works
		    void push_back( T element ) override;
		    void push_front( T element ) override;
		    T replace( T element, int position ) override;
		    T remove( int position ) override;
		    T pop_back( void ) override;
		    T pop_front( void ) override;
		    T item_at( int position ) override;
		    T peek_back( void ) override;
		    T peek_front( void ) override;
		    bool is_empty( void ) override;
		    bool is_full() override;
		    size_t length( void ) override;
		    void clear( void ) override;
			bool contains( T element ) override;
			void print( std::ostream &out );
			void print();
		    T * contents() override;

		private:
		    T head;
		    T tail;
		    T * array;
		    int arrayLength;
	};

	template <typename T>
	SDAL<T>::SDAL(){
		head = 0;
		tail = 0;
		array = new T[50];
		arrayLength = 50;
	}

	template <typename T>
	SDAL<T>::SDAL( T * array ){
		head = 0;
		tail = 0;
		this->array = array;
		arrayLength = 50;
	}

} /* namespace cop3530 */

#endif /* SDAL_H_ */
