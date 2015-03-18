employee('Pappu', '322003', 20, 30000, 6).
employee('Bitoo', '922433', 21, 40000, 12).
employee('Chinu', '121083', 19, 25000, 9).
employee('Guddu', '432023', 18, 30000, 11).
employee('Chotu', '182043', 23, 35000, 7).
employee('Ghotu', '432023', 30, 50000, 11).
employee('Pintu', '322653', 29, 40000, 24).
employee('Monty', '543563', 27, 35000, 18).
employee('Jonty', '135643', 29, 39000, 15).
employee('Pinki', '973242', 28, 33000, 19).
employee('Rinki', '783562', 25, 29000, 14).

age_bracket(X,Y, employee(A,B,C)) :- employee(A,B,C,_,_), C >= X, Y>=C.

select(X,P,employee(A,B,_,_,_)) :- employee(A,B,_,D,E), E >= X, D =< P.

project([[2, 6, 25000], [3, 8, 35000]]).

assign_project(project([_|T]),employee(A,B)) :- employee(A,B,_,D,E,F), project([[N,ME,MP]|_]),F = 1, N1 is N-1, N1>0, E>ME, MP>=D, F is 0, assign_project([N1,ME,MP]|_); N1 = 0,assign_project([T],employee(A,B)).

assign_project(project([N,ME,MP]),employee(A,B)) :-
employee(A,B,_,D,E,F), project([[N,ME,MP]|_]),F = 1, N1 is N-1, N1>0, E>ME, MP>=D, F is 0, assign_project([N,ME,MP]|_).


