###All Your Base###

Given a string "cats"

How can we represent this number in any base we want such that it gives us
the minimum number possible?

The minimum possible number will definitely come from using a greedy approach. Simply give the most significant digit 0 and then give the next digit 1 and so on.

So "cats" will be represented by "0123"

But the problem says that a number can't start with 0 so we flip 0 and 1 in the number and we get the representation 1023 in base 4.

Now we just convert from base 4 to base 10 to know value of the number. In this case 1023 = 1*4^3 + 0*4^2 + 2*4^1 + 3*4^0 = 75
