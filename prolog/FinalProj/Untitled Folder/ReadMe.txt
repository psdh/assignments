						ASSIGNMENT 2
					- Prabhjyot Singh Sodhi (2013A7PS151P)
					- Shivin Srivastava	(2013A7PS073P)
*********************************************************************************

PREDICATE : house(<name of house>)
FUNCTION  : It denotes the two houses present in the US assembly.

PREDICATE : compensation_for_services(<designation of member>)
FUNCTION  : It specifies the posts who are eligible for compensation.

PREDICATE : compensation_paid_out_of(<treasury>).
FUNCTION  : It specifies the source of income of senators.

Predicate : days_sanctioned_to_president.
FUNCTION  : Specifies the duration before which the president must return the bill back to the assembly.

Predicate : revenue_raising_bills(<name of house>)
FUNCTION  : Decides in which house the revenue raising bill originates

Predicate : duties_of_congress(<duty>)
FUNCTION  : Lists the duties of congress

Predicate : use_of_journal
FUNCTION  : It specifies functions of journal

Predicate : privledge_from_arrest(<crime>, <place where the person needs to be (session)>)
FUNCTION  : It decides wheather a senator has priviledge from arrest.

Predicate : can_be_questioned(<Action which the senator is performing>, <Current location of senator>)
FUNCTION  : It decides whether a senator can be questioned.

********** For functioning of the check_bill function, follow the below written instructions ***********

1. enter check_bill(<%Votes for the bill in Senate in 1st round>, <%Votes for the bill house of representatives in 1st round)
if answer is false, the bill doesn't become a law, else proceed as follows

2. enter check_bill(<%Votes for the bill in Senate>, <%Votes for the bill house of representatives>, <President's response ie. passed or not_passed>)
   if answer is true, the bill becomes a law, else proceed as follows

3. enter (<%Votes for the bill in Senate in 1st round>, <%Votes for the bill house of representatives in 1st round>, <%Votes for the bill in Senate in 2nd round>, <%Votes for the bill in Senate in 2nd round>)
   if the answer true, then it means that the bill has become a law.     

