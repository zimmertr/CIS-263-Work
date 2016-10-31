/***********************************************************************
 * hw217.cpp
 *
 * Description: Give efficient algorithms (Along with running time
 * analysis) to
 * A) Don't do
 * B) Find the minimum positive subsequence sum.
 * C) Find the maimum subsequence product.
 *
 *  Created on: Sep 28, 2013
 *      Author: TJ
 ***********************************************************************/
#include <vector>
#include <iostream>

using namespace std;

int minSubSum(const vector<int> & a) {

	int minSum = a[0], thisSum = 0;

	for (int j = 0; j < a.size(); ++j) {

		if (a[j] <= thisSum && (a[j] >= 0))
			thisSum = a[j];
		if (a[j] <= 0 && thisSum > 0) {
			thisSum = a[j];
		} else
			thisSum += a[j];
		if (thisSum < minSum)
			minSum = thisSum;
	}

	return minSum;
}

int minPSum(const vector<int> & a) {

	int minSum = a[0], thisSum = 0;

	for (int j = 0; j < a.size(); ++j) {

		if (a[j] <= thisSum && (a[j] >= 0))
			thisSum = a[j];
		if (a[j] <= 0 && thisSum > 0) {
			thisSum = a[j];
		} else
			thisSum += a[j];

		if(thisSum < 0 ){
			if(a[j] > 0){
				thisSum = minSum = a[j];
			}
			else
				thisSum -= a[j];
		}

		if (thisSum < minSum)
			minSum = thisSum;
	}

	return minSum;
}

int main() {

	vector<int> a = { 2, -2, 3, -7, -2, 1, 7, 8, 9 };
	vector<int> b = { 1, 2, 2, 2, 2, 2, 2 };

	cout << minSubSum(a) << endl;
	cout << minSubSum(b) << endl;
	cout << minPSum(a) << endl;
	cout << minPSum(b) << endl;

	return 0;
}
