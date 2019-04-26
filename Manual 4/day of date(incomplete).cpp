f = k + [(13*m-1)/5] + D + [D/4] + [C/4] - 2*C.

k is the day of the month. Let's use January 29, 2064 as an example. For this date, k = 29.
m is the month number. Months have to be counted specially for Zeller's Rule: March is 1, April is 2, and so on to February, which is 12. (This makes the formula simpler, because on leap years February 29 is counted as the last day of the year.) Because of this rule, January and February are always counted as the 11th and 12th months of the previous year. In our example, m = 11.
D is the last two digits of the year. Because in our example we are using January (see previous bullet) D = 63 even though we are using a date from 2064.
C stands for century: it's the first two digits of the year. In our case, C = 20.
Now let's substitute our example numbers into the formula.

f = k + [(13*m-1)/5] + D + [D/4] + [C/4] - 2*C
= 29 + [(13*11-1)/5] + 63 + [63/4] + [20/4] - 2*20
= 29 + [28.4] + 63 + [15.75] + [5] - 40
= 29 + 28 + 63 + 15 + 5 - 40
= 100.

Once we have found f, we divide it by 7 and take the remainder. Note that if the result for f is negative, care must be taken in calculating the proper remainder. Suppose f = -17. When we divide by 7, we have to follow the same rules as for the greatest integer function; namely we find the greatest multiple of 7 less than -17, so the remainder will be positive (or zero). -21 is the greatest multiple of 7 less than -17, so the remainder is 4 since -21 + 4 = -17. Alternatively, we can say that -7 goes into -17 twice, making -14 and leaving a remainder of -3, then add 7 since the remainder is negative, so -3 + 7 is again a remainder of 4.

A remainder of 0 corresponds to Sunday, 1 means Monday, etc. For our example, 100 / 7 = 14, remainder 2, so January 29, 2064 will be a Tuesday.
