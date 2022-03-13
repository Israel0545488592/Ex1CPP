/**
 * Demo program for mat exercise.
 *
 * Author: Tal Zichlinsky
 * Since : 2022-01
 */

#pragma once
#include "mat.h"

#include <iostream>
#include <stdexcept>

using namespace std;


//int main() {
//	cout << ariel::mat(9, 7, '@', '-') << endl;
	/* Should print:
	@@@@@@@@@
	@-------@
	@-@@@@@-@
	@-@---@-@
	@-@@@@@-@
	@-------@
	@@@@@@@@@
	*/
//	cout << ariel::mat(13, 5, '@', '-') << endl;
	/* Should print:
	@@@@@@@@@@@@@
	@-----------@
	@-@@@@@@@@@-@
	@-----------@
	@@@@@@@@@@@@@
	*/
//	try {
//		cout << ariel::mat(10, 5, '$', '%') << endl; // Exception - not a valid code
//	}
//	catch (exception& ex) {
//		cout << "   caught exception: " << ex.what() << endl;  // should print "Mat size is always odd"
//	}
//
//	return 0;
//}
