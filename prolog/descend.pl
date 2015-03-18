descendent(X,Y) :- child(X,Y).
descendent(X,Y) :- child(X,Z), descendent(Z,Y).

child(anne,bridget). 
   child(bridget,caroline). 
   child(caroline,donna). 
   child(donna,emily). 
