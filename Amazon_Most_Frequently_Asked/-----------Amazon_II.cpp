Round-1 [Technical + Behavioural]  ( Both are medium level )

Question -1 

You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.
  

Question-2 

There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true



Question 3- 

  Tell Me About a Time You Went Above and Beyond

Question 4- 

  What do you do if you disagree with someone at work?



====================================================================================================================================================



Round -2   [Technical ]  ( Both are Hard  level Question )

 Question -1 

Q2: You are given a n×m size grid. Some of the cells of the grid are blocked. There are two robots one standing 
    at (1, 1) and other at (n, m). In a single move, a robot can move from a cell (i, j) to cell (x, y) 
    such that |x - i| + |y - j| ≤ S Both the robots make moves simultaneously, find out minimum number of moves 
    required so that both the robots meet at some common cell. If it is not possible for them to meet, print -1 

Sample Case: n=4, m=5
X 1 0 1 0
0 0 1 0 1
1 0 0 1 0
0 1 0 0 Y
Answer = 4




Question -2 
 
  You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


