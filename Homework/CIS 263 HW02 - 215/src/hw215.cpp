/***********************************************************************
 * hw215.cpp
 *
 * Description: Give an efficient algorithm to determine if there exists
 * an integer i such that Ai = i in an array of integers
 * Ai < A2 < A3 ... < An. What is the running time of your algorithm?
 *
 *  Created on: Sep 28, 2013
 *      Author: TJ
 **********************************************************************/
#include <vector>
#include <iostream>

using namespace std;

int main() {

	vector<int>arr = {-1, 0, 1, 2, 3, 4, 6, 8, 9, 10};

	int k = arr.size() / 2;
	int mid = k/2;

	while (k > 1 && k < arr.size()) {
		if(arr[k]==k){
			cout << k;
			return k;
		}

		if(arr[k]<k)
			k = k+mid;
		else
			k = k - mid;

		mid--;
	}

	cout  << "not found";

	return 0;
}
