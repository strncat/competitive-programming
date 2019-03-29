2015 - B. Dreary Design  
  
Give [0,K] possible color values and V  
We have (r,g,b) where each color channel can have K possible values  
So the total possible colors possible is (K+1)^3  
How many of those triplets have the maximum difference between any two values <= V  

Example 1  
K = 1 and V = 0 
We have 2^3 possible triplets:   
  
(0,0,0), (0,0,1), (0,1,0), (1,0,0)  
(1,1,0), (1,0,1), (0,1,1), (1,1,1)  
  
Of those we want the triplets where the maximum difference between any two values is 0  
There are only possible triplets (0,0,0) and (1,1,1)  
  
  
Example 2  
K = 2 and V = 1  
We have 3^3 = 27 possible triplets:  
  
V = 0  
(0,0,0), (1,1,1), (2,2,2)  
  
V = 1  
(0,0,1), (0,1,0), (1,0,0)  
(1,1,0), (1,0,1), (0,1,1)  
  
(2,2,1), (2,1,2), (1,2,2)  
(1,1,2), (1,2,1), (2,1,1)  
  
V = 2  
(0,0,2), (0,2,0), (2,0,0)  
(2,2,0), (2,0,2), (0,2,2)  
  
(0,1,2), (2,1,0), (1,0,2)  
(0,2,1), (1,2,0), (2,0,1)  
  
How many of those have the maximum difference between any two values <= 1  
For V = 0:  
We have (K+1) possible triplets (0,0,0), (1,1,1), (2,2,2)  
For V = 1:  
We have K*6 = 2*6 = 12 possible triplets  
  
so 3 + 12 = 15 possible colors
  
  
Example 3  
K = 3 and V = 2  
We have 4^3 = 64 possible triplets:  
  
V = 0 (Total = (K + 1) = 4)  
(0,0,0), (1,1,1), (2,2,2), (3,3,3)  
  
V = 1 (Total = 6 * K = 18)  
(0,0,1), (0,1,0), (1,0,0)  
(1,1,0), (1,0,1), (0,1,1)  
  
(2,2,1), (2,1,2), (1,2,2)  
(1,1,2), (1,2,1), (2,1,1)  
  
(2,2,3), (2,3,2), (3,2,2)  
(3,3,2), (3,2,3), (2,3,3)  

V = 2 (Total = 24 = V * 6 + (K - V + 1))  
(0,0,2), (0,2,0), (2,0,0)  
(2,2,0), (2,0,2), (0,2,2)  
  
(1,1,3), (1,3,1), (3,1,1)  
(3,3,1), (3,1,3), (1,3,3)  
  
(0,1,2), (2,1,0), (1,0,2)  
(0,2,1), (1,2,0), (2,0,1)  
  
(3,1,2), (2,1,3), (1,3,2)  
(3,2,1), (1,2,3), (2,3,1)  
  
V = 3 (Total = (K - V + 1) * 6 * V = 18)  
(0,0,3), (0,3,0), (3,0,0)  
(3,3,0), (3,0,3), (0,3,3)  
  
(0,1,3), (1,0,3), (3,0,0)  
(0,3,1), (3,0,1), (0,3,3)  
  
(0,2,3), (2,0,3), (3,0,0)  
(0,3,2), (3,0,2), (0,2,2)  
  
