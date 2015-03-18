mployee('Pappu', '322003', 20, 30000, 6, 0).
employee('Bitoo', '922433', 21, 40000, 12, 0).
employee('Chinu', '121083', 19, 25000, 9, 0).
employee('Guddu', '432023', 18, 30000, 11, 0).
employee('Chotu', '182043', 23, 35000, 7, 0).
employee('Ghotu', '432023', 30, 50000, 11, 0).
employee('Pintu', '322653', 29, 40000, 24, 0).
employee('Monty', '543563', 27, 35000, 18, 0).
employee('Jonty', '135643', 29, 39000, 15, 0).
employee('Pinki', '973242', 28, 33000, 19, 0).
employee('Rinki', '783562', 25, 29000, 14, 0).

element_at(Q,[Q|_],1).
element_at(Q,[_,J],K) :- K >1, K1 is K-1 , element_at(Q,J,K1).

age_bracket(X,Y, employee(A,B,C)) :- employee(A,B,C,_,_), C >= X, Y>=C.

select(X,P,employee(A,B,_,_,_)) :- employee(A,B,_,D,E), E >= X, D =< P.
W is 2.
Project_list is ([[2, 6, 25000], [3, 8, 35000]]).

start(H) :- assert(project(H)).
start([H|T]) :- assert(project(H)), start(T).

select_n(1,Ex,Pa) :-

assign_project(project(X)) :-  element_at(No,X,1), element_at(Ex,X,2), element_at(Pa,X,3), select_n(No, Ex , Pa,employee(A,B,_,_,_,F),F = 0. 





%assign_project(project([_|T]),employee(A,B)) :- employee(A,B,_,D,E,F), project([[N,ME,MP]|_]),F = 1, N1 is N-1, N1>0, E>ME, MP>=D, F is 0, assign_project([N1,ME,MP]|_); N1 = 0,assign_project([T],employee(A,B)).

%assign_project(project([N,ME,MP]),employee(A,B)) :-employee(A,B,_,D,E,F), project([[N,ME,MP]|_]),F = 1, N1 is N-1, N1>0, E>ME, MP>=D, F is 0, assign_project([N,ME,MP]|_).


