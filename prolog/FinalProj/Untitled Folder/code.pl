% predicates specifying houses of the congress.
house(senate). 
house(house_of_representatives).

% predicate which specifies the posts who are eligible for compensation.
compensation_for_services(senators). 
compensation_for_services(representatives).


% predicate which specifies the source of income of senators.
compensation_paid_out_of(treasury).

days_sanctioned_to_president :- write('10 days excluding sundays \n').


revenues_raising_bills(house_of_representatives).

% duties of congress in predicate form
duties_of_congress('To borrow money on credit of the United States').

duties_of_congress('To regulate commerce with foreign nations, and amoung the several states, and with Indian tribes').

duties_of_congress('To establish an uniform Rule of Naturalization, and uniform Laws on the subject of Bankruptcies throughout the United States').

duties_of_congress('To coin Money, regulate the Value thereof, and of foreign Coin, and fix the Standard of Weights and Measures').

duties_of_congress('To provide for the Punishment of counterfeiting the Securities and current Coin of the United States').

duties_of_congress('To establish Post Offices and post Roads').

duties_of_congress('To borrow money on credit of the United States').

duties_of_congress('To promote the Progress of Science and useful Arts, by securing for limited Times to Authors and Inventors the exclusive Right to their respective Writings and Discoveries').

duties_of_congress('To constitute Tribunals inferior to the supreme Court').

duties_of_congress('To define and punish Piracies and Felonies committed on the high Seas, and Offences against the Law of Nations').

duties_of_congress('To declare War, grant Letters of Marque and Reprisal, and make Rules concerning Captures on Land and Water').

duties_of_congress('To raise and support Armies, but no Appropriation of Money to that Use shall be for a longer Term than two Years').

duties_of_congress('To provide and maintain a Navy').

duties_of_congress('To make Rules for the Government and Regulation of the land and naval Forces').

duties_of_congress('To provide for calling forth the Militia to execute the Laws of the Union, suppress Insurrections and repel Invasions').

duties_of_congress('To provide for organizing, arming, and disciplining, the Militia, and for governing such Part of them as may be employed in the Service of the United States, reserving to the States respectively, the Appointment of the Officers, and the Authority of training the Militia according to the discipline prescribed by Congress').

duties_of_congress('To exercise exclusive Legislation in all Cases whatsoever, over such District (not exceeding ten Miles square) as may, by Cession of particular States, and the Acceptance of Congress, become the Seat of the Government of the United States, and to exercise like Authority over all Places purchased by the Consent of the Legislature of the State in which the Same shall be, for the Erection of Forts, Magazines, Arsenals, dock-Yards, and other needful Buildings').

duties_of_congress('To make all Laws which shall be necessary and proper for carrying into Execution the foregoing Powers, and all other Powers vested by this Constitution in the Government of the United States, or in any Department or Officer thereof').


% function to specify functions of journal
use_of_journal :- write(' In each of the Houses :\n To Record the objections of President(if any) regarding a bill \n To Record the names of people participating in the poll along with their responses\n ').

% function to ascertain wheather a senator has priviledge from arrest.
privledge_from_arrest(Crime,Place) :- not(Crime = felony ; Crime = breach_of_peace; Crime = treason) , (Place = session ; Place = travelling_to_session).

% function to decide whether a senator can be questioned.
can_be_questioned(Action ,Y) :- house(Y) , (Action = debate ; Action = speech).

% function to decide whether a bill can become a law or not
check_bill(V1,V2) :- V1 > 50 , V2 > 50.
check_bill(V1,V2,ANS) :- V1 > 50, V2 > 50 ,ANS = 'passed'.
check_bill(_,_,H1,H2) :- H1 > 67, H2 > 67.
