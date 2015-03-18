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
project(1,2,12,30000).
project(2,3,15,50000).
project(3,2,8, 35000).

list([['Pappu', '322003', 20, 30000, 6],['Bitoo', '922433', 21, 40000, 12],['Chinu', '121083', 19, 25000, 9],['Guddu', '432023', 18, 30000, 11], ['Chotu', '182043', 23, 35000, 7], ['Ghotu', '432023', 30, 50000, 11], ['Pintu', '322653', 29, 40000, 24],['Monty', '543563', 27, 35000, 18]]).

element_at(Q,[Q|_],1).
element_at(Q,[_|J],K) :- K >1, K1 is K - 1 , element_at(Q,J,K1).

age_bracket(X,Y , employee(A,B,C,_,_)) :- employee(A,B,C,_,_) , C >= X , Y >=C.

select(_,_,0,_).

%%select(X,P,0, [Cur|[]]) :- [A,B,_,D,E]= Cur, E >= X , D =< P, select(_,_,0,_).

select(X,P,No,Lis) :-No>0, [Head|Tail] = Lis, [A,B,_,D,E]=Head ,E>= X ,D=<P, No1 is No -1 ,write(A),nl, select(X,P,No1,Tail).

select(X,P,No,Lis) :-No>0, [Head|Tail] = Lis, [A,B,_,D,E]=Head , select(X,P,No,Tail).

assign(X) :- element_at(No,X,1), element_at(Ex,X,2),element_at(Pa,X,3),list(Gh), select(Ex,Pa,No,Gh).

assign_projects(List1,0).

assign_projects(List1,Q) :- [X|L] = List1,write('Project :'),nl, assign(X) ,Q1 is Q - 1 , assign_projects(L,Q1),nl.


