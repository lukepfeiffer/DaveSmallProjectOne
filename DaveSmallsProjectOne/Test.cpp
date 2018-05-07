/*
 * Tests_test.cpp
 *
 *  Created on: May 6, 2018
 *      Author: luke
 */

#include "SSLL.h"
using namespace cop3530;
using namespace std;

void ssllPushFrontTest(){
	cout << "\t-------SSLL Push Front Tests-----" << endl;
	SSLL<int> * ssl_list = new SSLL<int>();
	ssl_list->push_front( 50 );
	cout <<  boolalpha << (ssl_list->peek_front() == 50) << " ";

	ssl_list->push_front( 40 );
	cout <<  boolalpha <<  (ssl_list->peek_front() == 40) << " ";

	ssl_list->push_front( 30 );
	cout <<  boolalpha <<  (ssl_list->peek_front() == 30) << " ";

	ssl_list->push_front( 20 );
	cout <<  boolalpha <<  (ssl_list->peek_front() == 20) << " ";

	ssl_list->push_front( 10 );
	cout <<  boolalpha <<  (ssl_list->peek_front() == 10) << "\n" << endl;

}

void ssllPushBackTest(){
	cout << "\t-------SSLL Push Back Tests-----" << endl;
	SSLL<int> * ssl_list = new SSLL<int>();
	ssl_list->push_back( 50 );
	cout <<  boolalpha << (ssl_list->peek_back() == 50) << " ";

	ssl_list->push_back( 40 );
	cout <<  boolalpha << (ssl_list->peek_back() == 40) << " ";

	ssl_list->push_back( 30 );
	cout <<  boolalpha <<  (ssl_list->peek_back() == 30) << " ";

	ssl_list->push_back( 20 );
	cout <<  boolalpha <<  (ssl_list->peek_back() == 20) << " ";

	ssl_list->push_back( 10 );
	cout <<  boolalpha <<  (ssl_list->peek_back() == 10) << "\n" << endl;

}


void ssllInsertTests(){
	cout << "\t-------SSLL Insert Tests-----" << endl;
	SSLL<int> * ssl_list = new SSLL<int>();
	//Head is null
	ssl_list->insert( 10, 2 );
	cout << ssl_list->peek_front();
	cout <<  boolalpha <<  (ssl_list->peek_front() == 10) << " ";
	//Insert at head

	ssl_list->insert( 5, 0 );
	cout << boolalpha << (ssl_list->peek_front() == 5) << endl;

	//Insert at tail
	ssl_list->insert( 3, 2 );
	//Insert in middle
	ssl_list->insert( 15, 1 );
}

void ssllPopBackTests(){
	cout << "\t-------SSLL PopBack Tests-----" << endl;
	SSLL<int> * ssl_list = new SSLL<int>();
	ssl_list->push_back( 5 );
	ssl_list->push_back( 10 );
	ssl_list->push_back( 15 );
	ssl_list->push_back( 20 );
	ssl_list->push_back( 25 );

	ssl_list->print();
	cout << boolalpha << ( ssl_list->pop_back() == 25 ) << " ";
	cout << boolalpha << ( ssl_list->pop_back() == 20 ) << " ";
	cout << boolalpha << ( ssl_list->pop_back() == 15 ) << " ";
	cout << boolalpha << ( ssl_list->pop_back() == 10 ) << " ";
	cout << boolalpha << ( ssl_list->pop_back() == 5 ) << "\n\n";
}

void ssllPopFrontTests(){
	cout << "\t-------SSLL PopFront Tests-----" << endl;
	SSLL<int> * ssl_list = new SSLL<int>();
	ssl_list->push_back( 5 );
	ssl_list->push_back( 10 );
	ssl_list->push_back( 15 );
	ssl_list->push_back( 20 );
	ssl_list->push_back( 25 );


	cout << boolalpha << ( ssl_list->pop_front() == 5 ) << " ";
	cout << boolalpha << ( ssl_list->pop_front() == 10 ) << " ";
	cout << boolalpha << ( ssl_list->pop_front() == 15 ) << " ";
	cout << boolalpha << ( ssl_list->pop_front() == 20 ) << " ";
	cout << boolalpha << ( ssl_list->pop_front() == 25 ) << "\n\n";

}

void ssllRemoveTests(){
	cout << "\t-------SSLL Remove Tests-----" << endl;
	SSLL<int> * ssl_list = new SSLL<int>();
	ssl_list->push_back( 5 );
	ssl_list->push_back( 10 );
	ssl_list->push_back( 15 );
	ssl_list->push_back( 20 );
	ssl_list->push_back( 25 );
	ssl_list->push_back( 30 );

	cout << boolalpha << ( ssl_list->remove(4) == 25 ) << " ";
	cout << boolalpha << ( ssl_list-> remove(3) == 20 ) << " ";
	cout << boolalpha << ( ssl_list-> remove(2) == 15 ) << " ";
	cout << boolalpha << ( ssl_list-> remove(1) == 10 ) <<  " ";
	cout << boolalpha << ( ssl_list-> remove(0) == 5 ) << "\n";

}

int main() {
	//SSLL TESTS
	cout.flush();
	ssllPushFrontTest();
	ssllPushBackTest();
	ssllPopBackTests();
	ssllPopFrontTests();
	ssllRemoveTests();
//	ssllInsertTests();
	return 0;
}
