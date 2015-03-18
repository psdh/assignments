employee('Pappu', '322003', 20, 30000, 6, 0).
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
project1(2,12,30000).
project2(3,15,50000).
project3(2,8, 35000).

element_at(Q,[Q|],1).
element_at(Q,[_|J,K) :- K >1, K1 is K - 1 , element_at(Q,J,K1).

age_bracket(X,Y , employee(A,B,C,_,_)) :- employee(A,B,C,_,_) , C >= X , Y >=C.

select(X,P,employee(A,B,_,_,)) :- employee(A,B,_,D,E) , E >= X , D =< P.

select(X,P,No,employee(A,B,_,_,_)) :- employee(A,B,_,D,E) , E>= X ,D=<P, ,No1 is No -1 , select(X,P,No1,employee(V,Z,_,_,_)).



assign(X) :- 



assign_projects(List,1) :- [X|_] = List, assign(X).




assign_projects(List,Q) :- [X|L] = List, assign(X), Q1 is Q-1, assign_projects(L,Q1).



%assign_projects(List,Q) :- [X|L] = List, assign(X) ,Q1 is Q - 1; assign_projects(L,Q1).


