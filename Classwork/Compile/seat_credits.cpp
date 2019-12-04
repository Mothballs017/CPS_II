// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: seat_credits.cpp
// Course: Computational Problem Solving CPET-II
// Developer: MATTHEW CHU
// Date : Fall 2019 (2191)
// Description: Problem #2
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()
#include <cctype>
#include <cstring>
#include <cstdio>
#include "seat_credits.h"
using namespace std;

int main()
{
	//passenger		| Completed (M)
	//Car			| Completed (M)
	//Pickup		| Completed (M)
	//Compact		| Completed (M)
	//Sedan			| Completed (M)
	//setPickup()	| Completed (M)
	//setCompact()	| Completed (M)
	//setSedan()	| Completed (M)
	//Create()		| Completed (M)
	//Display()		| Completed (M)
	//Modify()		| Completed (M)
	//Delete() 		| Completed (M)
	//Print()		| Completed (M)
	//Reservation()	| Completed (M)

	//Select()		| Completed (M)

	//header		| Completed (M)
	//body cpp		| Completed (M)
	//main loop		| Completed (M)

	Pickup pick[3];
	pick[0].setCar("PURPLE","PICKUP");
	pick[0]=setPickup(pick[0]);
	pick[1].setCar("YELLOW","PICKUP");
	pick[1]=setPickup(pick[1]);
	pick[2].setCar("RED","PICKUP");
	pick[2]=setPickup(pick[2]);
	Compact comp[3];
	comp[0].setCar("GREEN","COMPACT");
	comp[0]=setCompact(comp[0]);
	comp[1].setCar("BLUE","COMPACT");
	comp[1]=setCompact(comp[1]);
	comp[2].setCar("YELLOW","COMPACT");
	comp[2]=setCompact(comp[2]);
	Sedan sed[3];
	sed[0].setCar("RED","SEDAN");
	sed[0]=setSedan(sed[0]);
	sed[1].setCar("GREEN","SEDAN");
	sed[1]=setSedan(sed[1]);
	sed[2].setCar("BLUE","SEDAN");
	sed[2]=setSedan(sed[2]);
	passenger *head = Read();
	int reserve_num=1,menu_select;
	bool running=true;
	//start loop
	while(running){
		cout << "|1| Create Reservation"<<endl;
		cout << "|2| Display Vehicles"<<endl;
		cout << "|3| Modify Reservation"<<endl;
		cout << "|4| Delete Reservation"<<endl;
		cout << "|5| Print Vehicle"<<endl;
		cout << "|6| Print Reservation -ADMIN-"<<endl;
		cout << "|7| Exit Menu"<<endl;
		cout << "Select from menu: \n";
		cin >> menu_select; cin.ignore();
		switch(menu_select){
		case 1:
			Create(head,pick,comp,sed,reserve_num);
			break;
		case 2:
			Display(pick,comp,sed);
			break;
		case 3:
			Modify(head,pick,comp,sed);
			break;
		case 4:
			Delete(head,pick,comp,sed,reserve_num);
			break;
		case 5:
			Print(head,pick,comp,sed);
			break;
		case 6:
			Reservation(head);
			break;
		case 7:
			running=!running;
			break;
		default:
			cout<<"-INVALID SELECTION-\nPlease reselect from menu."<<endl;
			break;
		}
	}
}
