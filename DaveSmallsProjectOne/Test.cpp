/*
 * Tests_test.cpp
 *
 *  Created on: May 6, 2018
 *      Author: luke
 */

#include "SSLL.h"
using namespace cop3530;

void ssllContentsTests(){
	SSLL<int> ssl_list;
	ssl_list.push_front( 50 );
	//Couple tests
}

void ssllInsertTests(){
	SSLL<int> ssl_list;
	//Head is null
	ssl_list.insert( 10, 2 );
	//Insert at head
	ssl_list.insert( 5, 0 );
	//Insert at tail
	ssl_list.insert( 3, 2 );
	//Insert in middle
	ssl_list.insert( 15, 1 );

}

int main() {
	//SSLL TESTS
	ssllInsertTests();
	ssllContentsTests();
	return 0;
}
