   byCar(auckland,hamilton). 
   byCar(hamilton,raglan). 
   byCar(valmont,saarbruecken). 
   byCar(valmont,metz). 
    
   byTrain(metz,frankfurt). 
   byTrain(saarbruecken,frankfurt). 
   byTrain(metz,paris). 
   byTrain(saarbruecken,paris). 
    
   byPlane(frankfurt,bangkok). 
   byPlane(frankfurt,singapore). 
   byPlane(paris,losAngeles). 
   byPlane(bangkok,auckland). 
   byPlane(singapore,auckland). 
   byPlane(losAngeles,auckland).

travel(X,Y) :- byCar(X,Z), travel(Z,Y) ; byTrain(X,Z), travel(Z,Y); byPlane(X,Z), travel(Z,Y).

travel(X,Y) :- byCar(X,Y); byTrain(X,Y); byPlane(X,Y).

go(A,B,X) :- byCar(A,P), go(P,B,X), write(P),nl; byTrain(A,P), go(P,B,X), write(P),nl; byPlane(A,P), go(P,B,X), write(P),nl.

go(A,B,X) :- byCar(A,B), X = B; byTrain(A,B), X = B ; byPlane(A,B), X = B.

go(A,A,X).
