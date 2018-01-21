/*
	Stable Marriage Problem :

	The Stable Marriage Problem states that given N men and N women, where each person
	has ranked all members of the opposite sex in order of preference, marry the men and 
	women together such that there are no two people of opposite sex who would both rather 
	have each other than their current partners. If there are no such people, all the 
	marriages are “stable” .

	Consider the following example.

	Let there be two men m1 and m2 and two women w1 and w2.

	Let m1‘s list of preferences be {w1, w2}
	Let m2‘s list of preferences be {w1, w2}
	Let w1‘s list of preferences be {m1, m2}
	Let w2‘s list of preferences be {m1, m2}

	The matching { {m1, w2}, {w1, m2} } is not stable because m1 and w1 would prefer each 
	other over their assigned partners. The matching {m1, w1} and {m2, w2} is stable because 
	there are no two people of opposite sex that would prefer each other over their 
	assigned partners.

