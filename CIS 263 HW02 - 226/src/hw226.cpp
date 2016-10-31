/***********************************************************************
 * hw226.cpp
 *
 * Description: See page 75 for project description
 * A) How does the recursion terminate?
 * 	- Recursive functions terminate when the base case conditions are
 * 	  fulfilled. In this circumstance, it is when our recursively passed
 * 	  array is a size of two or less.
 *
 * B) How is the case where N is odd handled?
 *  - If n is even, then the majority will be contiguous at some point
 *    in the array. However, if n is odd, then there is a potential
 *    case where the majority number will alternate every other
 *    number leading to a non-contiguous majority. In this circumstance
 *    we force the last element into the majority check.
 *
 * C) What is the running time of the algorithm?
 *  - O(N)
 *
 * D) How can we avoid using an extra array, B?
 *  - We begin by iterating through the array. We establish a candidate
 *   with the first element of the array. Then we set the count equal
 *   to 1. We then check the next element and if it's contiguous we
 *   bump the count up by 1 and continue to check the rest of the
 *   values of the array. For every element that is not the potential
 *   candidate we decrease the count by one. When the count reaches
 *   zero we replace the candidate. In the end, the count has three
 *   potential states - Either zero, one, or some number greater than
 *   one. If the count is zero, that means the array is evenly spaced
 *   and there is no majority. If it is one, then it is an odd array and
 *   the final number is a potential majority. If it is greater than
 *   one, then we have found the majority number in the given array.
 *   From there we need to verify if this is the majority or not. This
 *   can be done by
 *
 * E) Write a program to compute the majority element.
 *  -
 *
 *
 *
 *  Created on: Sep 28, 2013
 *      Author: TJ
 **********************************************************************/
int Check_Candidate(int Candidate) {
	int i, Count = 0;
	for (i = 0; i < N; i++)
		if (A[i] == Candidate)
			Count++;
	if (Count > N / 2)
		return 1;
	else
		return 0;
}

int Majority(int A[], int N) {
int Candidate;
int i, Count = 0;
for (i = 0; i < N; i++)
	if (Count == 0) {
		Candidate = A[i];
		Count = 1;
	} else if (Candidate == A[i])
		Count++;
	else
		Count--;
if (Check_Candidate(Candidate, A, N) == 1)
	return Candidate;
else
	return 0;
}

