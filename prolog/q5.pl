employee('Ramesh', '322003', 20, 30000, 10).
employee('Shyam', '922433', 21, 60000, 14).
employee('Ram', '121083', 19, 25000, 9).
employee('Sodhi', '432023', 18, 30000, 11).
employee('Shivin', '182043', 23, 35000, 7).
employee('Goku', '432023', 30, 50000, 11).
employee('Tyson', '322653', 29, 40000, 24).
employee('Ash', '543563', 27, 35000, 18).
employee('Nikhil', '135643', 29, 39000, 15).
employee('Abhishek', '973242', 28, 33000, 19).
employee('Reena', '783562', 25, 29000, 14).
employee('Ankush','123321',23,32000,16).
employee('Sherki', '172322', 48, 43000, 25).
employee('Kshitij', '323532', 19, 50000, 5).
employee('Rishabh','26341',33,22000,16).



list([['Ramesh', 322003, 20, 30000, 6],
      ['Shyam', 922433, 21, 40000, 12],
      ['Ram', 121083, 19, 25000, 9],
      ['Sodhi', 432023, 18, 30000, 11],
      ['Shivin', 182043, 23, 35000, 7],
      ['Goku', 432023, 30, 50000, 11],
      ['Tyson', 322653, 29, 40000, 24],
      ['Ash', 543563, 27, 35000, 18],
      ['Nikhil', 135643, 29, 39000, 15],  
      ['Abhishek',973242, 28, 45000, 19],
      ['Reena', 783562, 25, 29000, 14],
      ['Ankush',123321,23,32000,16],
      ['Sherki',172322, 48, 43000, 25],
      ['Kshitij',323532, 19, 50000, 5],
      ['Rishabh',26341,33,22000,16]]).


choose(X,E,employee(A,B,_,_,_)) :- employee(A,B,_,D,F) , D =< E, F>=X.

age_bracket(X,Y , employee(A,B,C,_,_)) :- employee(A,B,C,_,_) , C >= X , Y >=C.


append([],L,L).
append([H|T],L2,[H|L3])  :-  append(T,L2,L3). 

element_at(Q,[Q|_],1).
element_at(Q,[_|J],K) :- K >1, K1 is K - 1 , element_at(Q,J,K1).


notequals(V,B):- V \= B. 

isNotThere([],_).
isNotThere([K|T] ,H) :- notequals(K,H), isNotThere(T,H).


select(_,_,0,_).

select(X,P,No,Lis,L1) :- 
(
(No>0, [Head|Tail] = Lis, element_at(He, Head,2),isNotThere(L1,He),[A,B,_,D,E]=Head ,E>= X ,D=<P) -> (append(L1,[He],L2), No1 is No -1 ,write(A),write(': '),write(B),nl, select(X,P,No1,Tail,L2));

([Head|Tail] = Lis, select(X,P,No,Tail,L1))
).
assign(X,L1) :- element_at(No,X,1), element_at(E,X,2),element_at(Pa,X,3),list(Gh), select(E,Pa,No,Gh,L1).

assign_projects(_,0,_).

assign_projects(List1,Q) :- assign_projects(List1,Q,_).
assign_projects(List1,Q,L1) :-
(
    (Q>0, [X|_] = List1,write('Project :'),nl, assign(X,L1),Q1 is Q - 1) -> ( [X|L]=List1, Q1 is Q - 1,assign_projects(L,Q1,L1));
                               
        (  [X|L] = List1, Q1 is Q -1 , assign_projects(L,Q1,L1))
).



