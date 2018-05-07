/*
 * Node.h
 *
 *  Created on: May 6, 2018
 *      Author: luke
 */

#ifndef NODE_H_
#define NODE_H_

namespace cop3530 {
	template <typename T>
	class Node {
		public:
			Node<T>();
			T data;
			Node<T> * next;
			virtual ~Node();
	};
	#include "Node.h"

	template <typename T>
	Node<T>::Node() {
		data = 0;
		next = 0;
	}

	template <typename T>
	Node<T>::~Node() {
		// TODO Auto-generated destructor stub
	}

} /* namespace cop3530 */

#endif /* NODE_H_ */
