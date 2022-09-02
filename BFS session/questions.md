# Question 0

Problem idea - https://codeforces.com/problemset/problem/1057/A

Utkarsh forms a new company "SigmaCorp" and starts hiring people in the company. At first, he was the only employee, so his employee ID is 1. Over time, he hired more and more people. Each time a new person was hired, he was assigned a single supervisor from the list of people already hired before. More formally, for each person i, there is one associated supervisor S(i) such that S(i) < i, that is, the ID of supervisor is lesser than the ID of the employee. (Of course, Utkarsh himself has no supervisor)

The latest employee hired was Manish (employee ID - N). However, due to his disobedience and arrogance, Utkarsh has decided to fire Manish. He will send a formal letter down the employee chain. Find the sequence of employees that the letter will go through until it reaches Manish.

Input Format: 
First line contains N (2 <= N <= 10^6), the number of employees in the company. 
The second line contains N - 1 integers S(2), S(3), .... S(N), where S(i) represents the supervisor of employee i.

Output:
On a single line, print the sequence of employees needed for the letter to reach from Utkarsh(1) to Manish(N).

Example:
8
1 1 2 2 3 2 5

Output : 1 2 5 8

4
1 2 3

Output : 1 2 3 4

# Submissions

Bhaskar - AC
Dev - ??
Harshith - MLE
Lakshit - AC
Saavi - AC
Saksham - TLE
Shardul - AC

# Question 1

Similar scenario as previous question. However, this time, assume that for each employee i and their supervisor S(i), it takes time T(i) for a letter to pass between them. Find the amount of time taken for the letter to reach from employee 1 to employee N.

Input Format:
First line contains N (2 <= N <= 10^6), the number of employees in the company.
Next N - 1 lines contain 2 integers each, representing S(i) and T(i) - the supervisor of employee i and the amount of time taken for a message to pass between i and S(i).

Output:
Print the total time taken. 

Example : 

7

1 3

1 2

2 6

2 7

3 5

4 6

Output : 15

# Question 2

Input: 

N M (Number of nodes, Number of edges)
Next M lines contain two integers each (X Y) meaning there is an edge between X and Y.
Final line contains S D --> Source and Destination

Output:
First line - Shortest distance.

Find the shortest path between Source and Destination
Also, PRINT the shortest path itself.

Example
4 4

1 2

2 3

1 3

3 4

1 4 [Source, destination]

Output:
2

1 3 4

# Question 3

Given a graph with N nodes and M edges, find the size of the largest component in the graph using BFS.

Input: 

N M (Nodes, edges)
Next M lines contain two integers each (X Y) meaning there is an edge between X and Y.

Output:
The size of the largest connected component in the graph.