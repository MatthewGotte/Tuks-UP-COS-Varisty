parent(bill, jake).
parent(jake, ted).

grandparent(X, Y) :- parent(X, P), parent(P, Y).
