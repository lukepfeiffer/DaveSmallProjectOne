/*
 * Tests_test.cpp
 *
 *  Created on: May 6, 2018
 *      Author: luke
 */

#include "SSLL.h"
#include "PSLL.h"
using namespace cop3530;
using namespace std;

void pushFrontTests( int type ){

	SSLL<int> * list = new SSLL<int>();
	if( type == 0 ){
		cout << "\t-------SSLL Replace Tests-----" << endl;
		SSLL<int> * list = new SSLL<int>();
	} else if( type == 1 ){
		cout << "\t-------PSLL Replace Tests-----" << endl;
		PSLL<int> * list = new PSLL<int>();
	} else if( type == 2 ){
	} else if( type == 3 ){
	} else {
		cout << "\t-------SSLL Replace Tests-----" << endl;
		SSLL<int> * list = new SSLL<int>();
	}

	list->push_front( 50 );
	cout <<  boolalpha << (list->peek_front() == 50) << " ";

	list->push_front( 40 );
	cout <<  boolalpha <<  (list->peek_front() == 40) << " ";

	list->push_front( 30 );
	cout <<  boolalpha <<  (list->peek_front() == 30) << " ";

	list->push_front( 20 );
	cout <<  boolalpha <<  (list->peek_front() == 20) << " ";

	list->push_front( 10 );
	cout <<  boolalpha <<  (list->peek_front() == 10) << "\n" << endl;

}

void pushBackTests( int type ){

	SSLL<int> * list = new SSLL<int>();
	if( type == 0 ){
		cout << "\t-------SSLL Replace Tests-----" << endl;
		SSLL<int> * list = new SSLL<int>();
	} else if( type == 1 ){
		cout << "\t-------PSLL Replace Tests-----" << endl;
		PSLL<int> * list = new PSLL<int>();
	} else if( type == 2 ){
	} else if( type == 3 ){
	} else {
		cout << "\t-------SSLL Replace Tests-----" << endl;
		SSLL<int> * list = new SSLL<int>();
	}
	list->push_back( 50 );
	cout <<  boolalpha << (list->peek_back() == 50) << " ";

	list->push_back( 40 );
	cout <<  boolalpha << (list->peek_back() == 40) << " ";

	list->push_back( 30 );
	cout <<  boolalpha <<  (list->peek_back() == 30) << " ";

	list->push_back( 20 );
	cout <<  boolalpha <<  (list->peek_back() == 20) << " ";

	list->push_back( 10 );
	cout <<  boolalpha <<  (list->peek_back() == 10) << "\n" << endl;

}


void insertTests(){
	cout << "\t-------SSLL Insert Tests-----" << endl;
	SSLL<int> * list = new SSLL<int>();
	//Head is null
	list->insert( 10, 2 );
	cout << list->peek_front();
	cout <<  boolalpha <<  (list->peek_front() == 10) << " ";
	//Insert at head

	list->insert( 5, 0 );
	cout << boolalpha << (list->peek_front() == 5) << endl;

	//Insert at tail
	list->insert( 3, 2 );
	//Insert in middle
	list->insert( 15, 1 );
}

void popBackTests( int type ){
	SSLL<int> * list = new SSLL<int>();
	if( type == 0 ){
		cout << "\t-------SSLL PopBack Tests-----" << endl;
		SSLL<int> * list = new SSLL<int>();
	} else if( type == 1 ){
		cout << "\t-------PSLL PopBack Tests-----" << endl;
		PSLL<int> * list = new PSLL<int>();
	} else if( type == 2 ){
	} else if( type == 3 ){
	} else {
		cout << "\t-------SSLL Replace Tests-----" << endl;
		SSLL<int> * list = new SSLL<int>();
	}

	list->push_back( 5 );
	list->push_back( 10 );
	list->push_back( 15 );
	list->push_back( 20 );
	list->push_back( 25 );

	list->print();
	cout << boolalpha << ( list->pop_back() == 25 ) << " ";
	cout << boolalpha << ( list->pop_back() == 20 ) << " ";
	cout << boolalpha << ( list->pop_back() == 15 ) << " ";
	cout << boolalpha << ( list->pop_back() == 10 ) << " ";
	cout << boolalpha << ( list->pop_back() == 5 ) << "\n\n";
}

void popFrontTests( int type ){
	SSLL<int> * list = new SSLL<int>();
	if( type == 0 ){
		cout << "\t-------SSLL PopFront Tests-----" << endl;
		SSLL<int> * list = new SSLL<int>();
	} else if( type == 1 ){
		cout << "\t-------PSLL PopFront Tests-----" << endl;
		PSLL<int> * list = new PSLL<int>();
	} else if( type == 2 ){
	} else if( type == 3 ){
	} else {
		cout << "\t-------SSLL Replace Tests-----" << endl;
		SSLL<int> * list = new SSLL<int>();
	}

	list->push_back( 5 );
	list->push_back( 10 );
	list->push_back( 15 );
	list->push_back( 20 );
	list->push_back( 25 );


	cout << boolalpha << ( list->pop_front() == 5 ) << " ";
	cout << boolalpha << ( list->pop_front() == 10 ) << " ";
	cout << boolalpha << ( list->pop_front() == 15 ) << " ";
	cout << boolalpha << ( list->pop_front() == 20 ) << " ";
	cout << boolalpha << ( list->pop_front() == 25 ) << "\n\n";

}

void removeTests( int type ){
	SSLL<int> * list = new SSLL<int>();
	if( type == 0 ){
		cout << "\t-------SSLL Remove Tests-----" << endl;
		SSLL<int> * list = new SSLL<int>();
	} else if( type == 1 ){
		cout << "\t-------PSLL Remove Tests-----" << endl;
		PSLL<int> * list = new PSLL<int>();
	} else if( type == 2 ){
	} else if( type == 3 ){
	} else {
		cout << "\t-------SSLL Replace Tests-----" << endl;
		SSLL<int> * list = new SSLL<int>();
	}

	list->push_back( 5 );
	list->push_back( 10 );
	list->push_back( 15 );
	list->push_back( 20 );
	list->push_back( 25 );
	list->push_back( 30 );

	cout << boolalpha << ( list->remove(4) == 25 ) << " ";
	cout << boolalpha << ( list->remove(3) == 20 ) << " ";
	cout << boolalpha << ( list->remove(2) == 15 ) << " ";
	cout << boolalpha << ( list->remove(1) == 10 ) <<  " ";
	cout << boolalpha << ( list->remove(0) == 5 ) << "\n\n";

}

void itemAtTests( int type ){
	SSLL<int> * list = new SSLL<int>();
	if( type == 0 ){
		cout << "\t-------SSLL ItemAt Tests-----" << endl;
		SSLL<int> * list = new SSLL<int>();
	} else if( type == 1 ){
		cout << "\t-------PSLL ItemAt Tests-----" << endl;
		PSLL<int> * list = new PSLL<int>();
	} else if( type == 2 ){
	} else if( type == 3 ){
	} else {
		cout << "\t-------SSLL Replace Tests-----" << endl;
		SSLL<int> * list = new SSLL<int>();
	}

	list->push_back( 5 );
	list->push_back( 10 );
	list->push_back( 15 );
	list->push_back( 20 );
	list->push_back( 25 );
	list->push_back( 30 );


	cout << boolalpha << ( list->item_at(4) == 25 ) << " ";
	cout << boolalpha << ( list->item_at(3) == 20 ) << " ";
	cout << boolalpha << ( list->item_at(2) == 15 ) << " ";
	cout << boolalpha << ( list->item_at(1) == 10 ) <<  " ";
	cout << boolalpha << ( list->item_at(0) == 5 ) << "\n\n";
}

void replaceTests( int type ){
	SSLL<int> * list = new SSLL<int>();
	if( type == 0 ){
		cout << "\t-------SSLL Replace Tests-----" << endl;
		SSLL<int> * list = new SSLL<int>();
	} else if( type == 1 ){
		cout << "\t-------PSLL Replace Tests-----" << endl;
		PSLL<int> * list = new PSLL<int>();
	} else if( type == 2 ){
	} else if( type == 3 ){
	} else {
		cout << "\t-------SSLL Replace Tests-----" << endl;
		SSLL<int> * list = new SSLL<int>();
	}

	list->push_back( 5 );
	list->push_back( 10 );
	list->push_back( 15 );
	list->push_back( 20 );
	list->push_back( 25 );
	list->push_back( 30 );

	cout << boolalpha << ( list->replace(100, 4) == 25 ) << " ";
	cout << boolalpha << ( list->replace(200, 3) == 20 ) << " ";
	cout << boolalpha << ( list->replace(300, 2) == 15 ) << " ";
	cout << boolalpha << ( list->replace(400, 1) == 10 ) <<  " ";
	cout << boolalpha << ( list->replace(500, 0) == 5 ) << "\n";

	cout << boolalpha << ( list->item_at(5) == 30 ) << " ";
	cout << boolalpha << ( list->item_at(4) == 100 ) << " ";
	cout << boolalpha << ( list->item_at(3) == 200 ) << " ";
	cout << boolalpha << ( list->item_at(2) == 300 ) << " ";
	cout << boolalpha << ( list->item_at(1) == 400 ) <<  " ";
	cout << boolalpha << ( list->item_at(0) == 500 ) << "\n\n";
}

int main() {
	//SSLL TESTS
	cout.flush();
	pushFrontTests( 0 );
	pushFrontTests( 1 );

	pushBackTests( 0 );
	pushBackTests( 1 );

	popBackTests( 0 );
	popBackTests( 1 );

	popFrontTests( 0 );
	popFrontTests( 1 );


	removeTests( 0 );
	removeTests( 1 );

	itemAtTests( 0 );
	itemAtTests( 1 );

	replaceTests( 0 );
	replaceTests( 1 );
//	ssllInsertTests();
	return 0;
}
