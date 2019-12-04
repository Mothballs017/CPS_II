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

Pickup setPickup(Pickup P){
	P.front = 5;
	return P;
}
Compact setCompact(Compact C){
	C.front = 5;
	C.back1 = 3;
	C.back2 = 3;
	return C;
}
Sedan setSedan(Sedan S){
	S.front = 5;
	S.sideback1 = 2;
	S.sidemiddle = 1;
	S.sideback2 = 2;
	return S;
}

int getCount(passenger *head){
    if (head == NULL)
        return 0;
    return getCount(head->nextaddr)+1;
}

bool Select(passenger *current, Pickup pick[3], Compact comp[3], Sedan sed[3], int reserve){
	bool quit=false;
	int seat;
	char car_num;
	//	Print();
	cout << "Select vehicle type by number (1-3): ";
	cin >> car_num; cin.ignore();
//	cout << "car";
	string tmp,color;
	if(car_num=='1'){
		if(current->credit<5){
			cout<<"-INVALID CREDIT LIMIT-/Please reselect."<<endl;
		}else{
			cout << "Select pickup by color: ";
			cin>>tmp;
			for(char x: tmp)
				color+=toupper(x);
			if(color=="PURPLE"){
				if(pick[0].Front()!=0){
					current->credit-=5;
					pick[0].setPickup();
					pick[0].setPickupn(current->fname+" "+current->lname);
					cout << current->fname << " has been assigned to "<<pick[0].Color() <<" PICKUP's FRONT seat."<<endl;
					current->vehicle=pick[0].Type();
					current->color=pick[0].Color();
					current->location="FRONT";
					current->reserve=reserve;
					current->assigned=true;
					quit=!quit;
				}
				else cout<<"Front seat occupied. Please reselect." << endl;
			}else{
				if(color=="YELLOW"){
					if(pick[1].Front()!=0){
						current->credit-=5;
						pick[1].setPickup();
						pick[1].setPickupn(current->fname+" "+current->lname);
						cout << current->fname << " has been assigned to "<<pick[1].Color() <<" PICKUP's FRONT seat."<<endl;
						current->vehicle=pick[1].Type();
						current->color=pick[1].Color();
						current->location="FRONT";
						current->reserve=reserve;
						current->assigned=true;
						quit=!quit;
					}
					else cout<<"Front seat occupied. Please reselect." << endl;
				}else{
					if(color=="RED"){
						if(pick[2].Front()!=0){
							current->credit-=5;
							pick[2].setPickup();
							pick[2].setPickupn(current->fname+" "+current->lname);
							cout << current->fname << " has been assigned to "<<pick[2].Color() <<" PICKUP's FRONT seat."<<endl;
							current->vehicle=pick[2].Type();
							current->color=pick[2].Color();
							current->location="FRONT";
							current->reserve=reserve;
							current->assigned=true;
							quit=!quit;
						}
						else cout<<"Front seat occupied. Please reselect." << endl;
					}else cout << "-INVALID COLOR-\nPlease reselect." << endl;
				}
			}
		}
	}else{
		if(car_num=='2'){
			if(current->credit<3){
				cout<<"-INVALID CREDIT LIMIT-/Please reselect."<<endl;
			}else{
				cout << "Select compact car by color: ";
				cin>>tmp;
				for(char x: tmp)
					color+=toupper(x);
				if(color=="GREEN"){
					cout<<"Enter seat (1-3): ";
					cin>>seat;cin.ignore();
					switch(seat){
					case 1:
						if(comp[0].Front()!=0){
							current->credit-=5;
							comp[0].setCompactf();
							comp[0].setCompactfn(current->fname+" "+current->lname);
							cout << current->fname << " has been assigned to "<<comp[0].Color() <<" COMPACT's FRONT seat."<<endl;
							current->vehicle=comp[0].Type();
							current->color=comp[0].Color();
							current->location="FRONT";
							current->reserve=reserve;
							current->assigned=true;
							quit=!quit;
						}
						else cout<<"Front seat occupied. Please reselect." << endl;
						break;
					case 2:
						if(comp[0].Back1()!=0){
							current->credit-=3;
							comp[0].setCompactb1();
							comp[0].setCompactb1n(current->fname+" "+current->lname);
							cout << current->fname << " has been assigned to "<<comp[0].Color() <<" COMPACT's LEFT BACK seat."<<endl;
							current->vehicle=comp[0].Type();
							current->color=comp[0].Color();
							current->location="LEFT BACK";
							current->reserve=reserve;
							current->assigned=true;
							quit=!quit;
						}
						else cout<<"Left back seat occupied. Please reselect." << endl;
						break;
					case 3:
						if(comp[0].Back2()!=0){
							current->credit-=3;
							comp[0].setCompactb2();
							comp[0].setCompactb2n(current->fname+" "+current->lname);
							cout << current->fname << " has been assigned to "<<comp[0].Color() <<" COMPACT's RIGHT BACK seat."<<endl;
							current->vehicle=comp[0].Type();
							current->color=comp[0].Color();
							current->location="RIGHT BACK";
							current->reserve=reserve;
							current->assigned=true;
							quit=!quit;
						}
						else cout<<"Right back seat occupied. Please reselect." << endl;
						break;
					default:
						cout << "-INVALID SEAT-\nPlease reselect."<<endl;
						break;
					}
				}
				else{
					if(color=="BLUE"){
						cout<<"Enter seat (1-3): ";
						cin>>seat;cin.ignore();
						switch(seat){
						case 1:
							if(comp[1].Front()!=0){
								current->credit-=5;
								comp[1].setCompactf();
								comp[1].setCompactfn(current->fname+" "+current->lname);
								cout << current->fname << " has been assigned to "<<comp[1].Color() <<" COMPACT's FRONT seat."<<endl;
								current->vehicle=comp[1].Type();
								current->color=comp[1].Color();
								current->location="FRONT";
								current->reserve=reserve;
								current->assigned=true;
								quit=!quit;
							}
							else cout<<"Front seat occupied. Please reselect." << endl;
							break;
						case 2:
							if(comp[1].Back1()!=0){
								current->credit-=3;
								comp[1].setCompactb1();
								comp[1].setCompactb1n(current->fname+" "+current->lname);
								cout << current->fname << " has been assigned to "<<comp[1].Color() <<" COMPACT's LEFT BACK seat."<<endl;
								current->vehicle=comp[1].Type();
								current->color=comp[1].Color();
								current->location="LEFT BACK";
								current->reserve=reserve;
								current->assigned=true;
								quit=!quit;
							}
							else cout<<"Left back seat occupied. Please reselect." << endl;
							break;
						case 3:
							if(comp[1].Back2()!=0){
								current->credit-=3;
								comp[1].setCompactb2();
								comp[1].setCompactb2n(current->fname+" "+current->lname);
								cout << current->fname << " has been assigned to "<<comp[1].Color() <<" COMPACT's RIGHT BACK seat."<<endl;
								current->vehicle=comp[1].Type();
								current->color=comp[1].Color();
								current->location="RIGHT BACK";
								current->reserve=reserve;
								current->assigned=true;
								quit=!quit;
							}
							else cout<<"Right back seat occupied. Please reselect." << endl;
							break;
						default:
							cout <<"-INVALID SEAT-\nPlease reselect."<<endl;
							break;
						}
					}
					else{
						if(color=="YELLOW"){
							cout<<"Enter seat (1-3): ";
							cin>>seat;cin.ignore();
							switch(seat){
							case 1:
								if(comp[2].Front()!=0){
									current->credit-=5;
									comp[2].setCompactf();
									comp[2].setCompactfn(current->fname+" "+current->lname);
									cout << current->fname << " has been assigned to "<<comp[2].Color() <<" COMPACT's FRONT seat."<<endl;
									current->vehicle=comp[2].Type();
									current->color=comp[2].Color();
									current->location="FRONT";
									current->reserve=reserve;
									current->assigned=true;
									quit=!quit;
								}
								else cout<<"Front seat occupied. Please reselect." << endl;
								break;
							case 2:
								if(comp[2].Back1()!=0){
									current->credit-=3;
									comp[2].setCompactb1();
									comp[2].setCompactb1n(current->fname+" "+current->lname);
									cout << current->fname << " has been assigned to "<<comp[2].Color() <<" COMPACT's LEFT BACK seat."<<endl;
									current->vehicle=comp[2].Type();
									current->color=comp[2].Color();
									current->location="LEFT BACK";
									current->reserve=reserve;
									current->assigned=true;
									quit=!quit;
								}
								else cout<<"Left back seat occupied. Please reselect." << endl;
								break;
							case 3:
								if(comp[2].Back2()!=0){
									current->credit-=3;
									comp[2].setCompactb2();
									comp[2].setCompactb2n(current->fname+" "+current->lname);
									cout << current->fname << " has been assigned to "<<comp[2].Color() <<" COMPACT's RIGHT BACK seat."<<endl;
									current->vehicle=comp[2].Type();
									current->color=comp[2].Color();
									current->location="RIGHT BACK";
									current->reserve=reserve;
									current->assigned=true;
									quit=!quit;
								}
								else cout<<"Right back seat occupied. Please reselect." << endl;
								break;
							default:
								cout<<"-INVALID SEAT-\nPlease reselect."<<endl;
								break;
							}
						}else cout << "-INVALID COLOR-\nPlease reselect." << endl;
					}
				}
			}
		}else{
			if(car_num=='3'){
				if(current->credit<1){
					cout<<"-INVALID CREDIT LIMIT-/Please reselect."<<endl;
				}else{
					cout << "Select sedan by color: ";
					cin>>tmp;
					for(char x: tmp)
						color+=toupper(x);
					if(color=="RED"){
						cout<<"Enter seat (1-4): ";
						cin>>seat;cin.ignore();
						switch(seat){
						case 1:
							if(sed[0].Front()!=0){
								current->credit-=5;
								sed[0].setSedanf();
								sed[0].setSedanfn(current->fname+" "+current->lname);
								cout << current->fname << " has been assigned to "<<sed[0].Color() <<" COMPACT's FRONT seat."<<endl;
								current->vehicle=sed[0].Type();
								current->color=sed[0].Color();
								current->location="FRONT";
								current->reserve=reserve;
								current->assigned=true;
								quit=!quit;
							}
							else cout<<"Front seat occupied. Please reselect." << endl;
							break;
						case 2:
							if(sed[0].SideBack1()!=0){
								current->credit-=2;
								sed[0].setSedansb1();
								sed[0].setSedansb1n(current->fname+" "+current->lname);
								cout << current->fname << " has been assigned to "<<sed[0].Color() <<" COMPACT's LEFT SIDE BACK seat."<<endl;
								current->vehicle=sed[0].Type();
								current->color=sed[0].Color();
								current->location="LEFT SIDEBACK";
								current->reserve=reserve;
								current->assigned=true;
								quit=!quit;
							}
							else cout<<"Left back seat occupied. Please reselect." << endl;
							break;
						case 3:
							if(sed[0].SideMiddle()!=0){
								current->credit-=1;
								sed[0].setSedansm();
								sed[0].setSedansmn(current->fname+" "+current->lname);
								cout << current->fname << " has been assigned to "<<sed[0].Color() <<" COMPACT's MIDDLE BACK seat."<<endl;
								current->vehicle=sed[0].Type();
								current->color=sed[0].Color();
								current->location="MIDDLE BACK";
								current->reserve=reserve;
								current->assigned=true;
								quit=!quit;
							}
							else cout<<"Middle back seat occupied. Please reselect." << endl;
							break;
						case 4:
							if(sed[0].SideBack2()!=0){
								current->credit-=2;
								sed[0].setSedansb2();
								sed[0].setSedansb2n(current->fname+" "+current->lname);
								cout << current->fname << " has been assigned to "<<sed[0].Color() <<" COMPACT's RIGHT SIDE BACK seat."<<endl;
								current->vehicle=sed[0].Type();
								current->color=sed[0].Color();
								current->location="RIGHT SIDEBACK";
								current->reserve=reserve;
								current->assigned=true;
								quit=!quit;
							}
							else cout<<"Right back seat occupied. Please reselect." << endl;
							break;
						default:
							cout << "-INVALID SEAT-\nPlease reselect."<<endl;
							break;
						}
					}else{
						if(color=="GREEN"){
							cout<<"Enter seat (1-4): ";
							cin>>seat;cin.ignore();
							switch(seat){
							case 1:
								if(sed[1].Front()!=0){
									current->credit-=5;
									sed[1].setSedanf();
									sed[1].setSedanfn(current->fname+" "+current->lname);
									cout << current->fname << " has been assigned to "<<sed[1].Color() <<" COMPACT's FRONT seat."<<endl;
									current->vehicle=sed[1].Type();
									current->color=sed[1].Color();
									current->location="FRONT";
									current->reserve=reserve;
									current->assigned=true;
									quit=!quit;
								}
								else cout<<"Front seat occupied. Please reselect." << endl;
								break;
							case 2:
								if(sed[1].SideBack1()!=0){
									current->credit-=2;
									sed[1].setSedansb1();
									sed[1].setSedansb1n(current->fname+" "+current->lname);
									cout << current->fname << " has been assigned to "<<sed[1].Color() <<" COMPACT's LEFT SIDE BACK seat."<<endl;
									current->vehicle=sed[1].Type();
									current->color=sed[1].Color();
									current->location="LEFT SIDEBACK";
									current->reserve=reserve;
									current->assigned=true;
									quit=!quit;
								}
								else cout<<"Left back seat occupied. Please reselect." << endl;
								break;
							case 3:
								if(sed[1].SideMiddle()!=0){
									current->credit-=1;
									sed[1].setSedansm();
									sed[1].setSedansmn(current->fname+" "+current->lname);
									cout << current->fname << " has been assigned to "<<sed[1].Color() <<" COMPACT's MIDDLE BACK seat."<<endl;
									current->vehicle=sed[1].Type();
									current->color=sed[1].Color();
									current->location="MIDDLE BACK";
									current->reserve=reserve;
									current->assigned=true;
									quit=!quit;
								}
								else cout<<"Middle back seat occupied. Please reselect." << endl;
								break;
							case 4:
								if(sed[1].SideBack2()!=0){
									current->credit-=2;
									sed[1].setSedansb2();
									sed[1].setSedansb2n(current->fname+" "+current->lname);
									cout << current->fname << " has been assigned to "<<sed[1].Color() <<" COMPACT's RIGHT SIDE BACK seat."<<endl;
									current->vehicle=sed[1].Type();
									current->color=sed[1].Color();
									current->location="RIGHT SIDEBACK";
									current->reserve=reserve;
									current->assigned=true;
									quit=!quit;
								}
								else cout<<"Right back seat occupied. Please reselect." << endl;
								break;
							default:
								cout << "-INVALID SEAT-\nPlease reselect."<<endl;
								break;
							}
						}else{
							if(color=="BLUE"){
								cout<<"Enter seat (1-4): ";
								cin>>seat;cin.ignore();
								switch(seat){
								case 1:
									if(sed[2].Front()!=0){
										current->credit-=5;
										sed[2].setSedanf();
										sed[2].setSedanfn(current->fname+" "+current->lname);
										cout << current->fname << " has been assigned to "<<sed[2].Color() <<" COMPACT's FRONT seat."<<endl;
										current->vehicle=sed[2].Type();
										current->color=sed[2].Color();
										current->location="FRONT";
										current->reserve=reserve;
										current->assigned=true;
										quit=!quit;
									}
									else cout<<"Front seat occupied. Please reselect." << endl;
									break;
								case 2:
									if(sed[2].SideBack1()!=0){
										current->credit-=2;
										sed[2].setSedansb1();
										sed[2].setSedansb1n(current->fname+" "+current->lname);
										cout << current->fname << " has been assigned to "<<sed[2].Color() <<" COMPACT's LEFT SIDE BACK seat."<<endl;
										current->vehicle=sed[2].Type();
										current->color=sed[2].Color();
										current->location="LEFT SIDEBACK";
										current->reserve=reserve;
										current->assigned=true;
										quit=!quit;
									}
									else cout<<"Left back seat occupied. Please reselect." << endl;
									break;
								case 3:
									if(sed[2].SideMiddle()!=0){
										current->credit-=1;
										sed[2].setSedansm();
										sed[2].setSedansmn(current->fname+" "+current->lname);
										cout << current->fname << " has been assigned to "<<sed[2].Color() <<" COMPACT's MIDDLE BACK seat."<<endl;
										current->vehicle=sed[2].Type();
										current->color=sed[2].Color();
										current->location="MIDDLE BACK";
										current->reserve=reserve;
										current->assigned=true;
										quit=!quit;
									}
									else cout<<"Middle back seat occupied. Please reselect." << endl;
									break;
								case 4:
									if(sed[2].SideBack2()!=0){
										current->credit-=2;
										sed[2].setSedansb2();
										sed[2].setSedansb2n(current->fname+" "+current->lname);
										cout << current->fname << " has been assigned to "<<sed[2].Color() <<" COMPACT's RIGHT SIDE BACK seat."<<endl;
										current->vehicle=sed[2].Type();
										current->color=sed[2].Color();
										current->location="RIGHT SIDEBACK";
										current->reserve=reserve;
										current->assigned=true;
										quit=!quit;
									}
									else cout<<"Right back seat occupied. Please reselect." << endl;
									break;
								default:
									cout << "-INVALID SEAT-\nPlease reselect."<<endl;
									break;
								}
							}else cout << "-INVALID COLOR-\nPlease reselect." << endl;
						}
					}
				}
			}else cout<<"-INVALID VEHICLE-\nPlease reselect."<<endl;
		}
	}
	return quit;
}

passenger *Read(){
	ifstream inFile;

	inFile.open("seat_credits.txt");

	if (inFile.fail()){
		cout << "\nThe file did not successfully open... Program Terminated\n" << endl;
		exit (1);
	}

	passenger *current, *head;

	current = new passenger;
	head = current;

	do{
		inFile >> current->fname;
		inFile >> current->lname;
		inFile >> current->credit;inFile.ignore();
		current->reserve=0;
		current->vehicle="NONE";
		current->color="NONE";
		current->location="NONE";
		current->randomized=false;
		if (inFile.eof()){
			current->nextaddr = NULL;
			break;
		}
		else{
			current->nextaddr = new passenger;
			current = current->nextaddr;
		}
	}
	while(true);

	inFile.close();

	return head;
}

void Reservation(passenger *head) {
	string password="BATMAN";
	cout << "Are you the system administrator?\n--Please enter password--" << endl;
	string check,tmp;
	cin>>tmp;
	for(char x: tmp)
		check+=toupper(x);
	if(check!=password)
		cout << "Permission denied" << endl;
	else{
		passenger *current=head;
		ofstream outFile;
		outFile.open("all_reservations.txt");
		cout << "file out" << endl;
		if(current==NULL)
			outFile<<"NULL"<<endl;
		else{
			while (current->nextaddr != NULL)
			{
				outFile<< "Passenger (" << current->reserve << ")" << endl;
				outFile<< "Name: "<< current->lname << ", " << current->fname << endl;
				outFile<< "Vehicle: " << current->color << " " << current->vehicle << endl;
				outFile<< "Seat Location: " << current->location << endl;
				outFile<< "------------------------------------\n";
				current=current->nextaddr;
			}
		}
		outFile.close();
	}

}

void Modify(passenger *head, Pickup pick[3], Compact comp[3], Sedan sed[3]){
	//check reservation #/print error, display vehicle+seat,reselect vehicle, reselect seat
	//CREATE VEHICLE+SEAT function and replace in Create()
	passenger *current=head;
	int res,credit=0;
	bool res_check=false,quit=false;
	while(quit==false){
		cout << "Please enter valid Reservation number: ";
		cin>>res;
		if(res<=9 && res>0)
			cin.ignore();
		if(res<=0 || res>getCount(head)){
			cout<<"-INVALID RESERVATION-\nPlease reselect."<<endl;
		}
		else{
			while(current != NULL){
				if(current->reserve==res){
					res_check=true;
					if(current->credit<=0){
						current->randomized=true;
						cout << current->fname << " " << current->lname << " will be assigned to remaining available seats." << endl;
						quit=!quit;
						break;
					}
					else{
						current->randomized=false;
						if(current->vehicle=="PICKUP"){
							for(int i=0;i<3;i++){
								if(current->color==pick[i].Color()){
									if(pick[i].front==0 && pick[i].name==(current->fname+" "+current->lname))
										credit=5;
									pick[i].setPickupn("");
									pick[i].setPickup(credit);
									current->location="";
									current->color="";
									current->vehicle="";
									current->credit+=credit;
									current->assigned=false;
								}
							}
						}
						if(current->vehicle=="COMPACT"){
							for(int i=0;i<3;i++){
								if(current->color==comp[i].Color()){
									if(comp[i].front==0 && comp[i].fname==(current->fname+" "+current->lname)){
										credit=5;
										comp[i].setCompactfn("");
										comp[i].setCompactf(credit);
									}
									if(comp[i].back1==0 && comp[i].b1name==(current->fname+" "+current->lname)){
										credit=3;
										comp[i].setCompactb1n("");
										comp[i].setCompactb1(credit);
									}
									if(comp[i].back2==0 && comp[i].b2name==(current->fname+" "+current->lname)){
										credit=3;
										comp[i].setCompactb2n("");
										comp[i].setCompactb2(credit);
									}
									current->credit+=credit;
									current->location="";
									current->color="";
									current->vehicle="";
									current->assigned=false;
								}
							}
						}
						if(current->vehicle=="SEDAN"){
							for(int i=0;i<3;i++){
								if(current->color==sed[i].Color()){
									if(sed[i].front==0 && sed[i].fname==(current->fname+" "+current->lname)){
										credit=5;
										sed[i].setSedanfn("");
										sed[i].setSedanf(credit);
									}
									if(sed[i].sideback1==0 && sed[i].sb1name==(current->fname+" "+current->lname)){
										credit=2;
										sed[i].setSedansb1n("");
										sed[i].setSedansb1(credit);
									}
									if(sed[i].sidemiddle==0 && sed[i].smname==(current->fname+" "+current->lname)){
										credit=1;
										sed[i].setSedansmn("");
										sed[i].setSedansm(credit);
									}
									if(sed[i].sideback2==0 && sed[i].sb2name==(current->fname+" "+current->lname)){
										credit=2;
										sed[i].setSedansb2n("");
										sed[i].setSedansb2(credit);
									}
									current->credit+=credit;
									current->location="";
									current->color="";
									current->vehicle="";
									current->assigned=false;
								}
							}
						}
						cout << current->fname <<" "<<current->lname << " has " << current->credit << " credits remaining." << endl;
						Display(pick,comp,sed);
						quit=Select(current, pick, comp, sed, res);
					}
				}
				current = current->nextaddr;
			}
			if(res_check==false){
				cout<<"-INVALID RESERVATION-\nPlease reselect from main menu."<<endl;
				quit=!quit;
			}
		}
	}
}

void Create(passenger *head, Pickup pick[3], Compact comp[3], Sedan sed[3], int reserve){
	string first, last;
	bool quit=false;
	passenger *current;
	do{
		cout << "Enter name (first, last): ";
		cin >> first; cin >> last;
		bool namecheck=false;
		string type, color;
		current=head;
		char select;
		while(current != NULL){
			if((first==current->fname && last==current->lname)||(first==current->lname && last==current->fname)){
				namecheck=true;
				cout << current->fname <<" "<<current->lname << " has " << current->credit << " credits remaining." << endl;
				if(current->credit<=0){
					current->randomized=true;
					cout << current->fname << " " << current->lname << " will be assigned to remaining available seats." << endl;

				}
				else current->randomized=false;
				break;
			}
			current = current->nextaddr;
		}
		if(namecheck==false){
			cout<<"-INVALID NAME-\nPlease reselect from main menu."<<endl;
			quit=true;
		}
		else{
			if(current->assigned){
				cout << "-INVALID SELECTION-\nPassenger already assigned."<<endl;
			}
			else{
				Display(pick,comp,sed);
				cin.ignore();
				cout << "Choose selection by category (Vehicle/Seat): ";
				cin >> select; cin.ignore();
				select=toupper(select);
				if(select=='V'){
					if(current->credit<5){
						cout << "-INVALID SELECTION-\nNot enough credits. Please reselect."<<endl;
					}
					else{
						for(int i=0;i<3;i++){
							if(pick[i].Front()!=0){
								namecheck=false;
								current->credit-=5;
								pick[i].setPickup();
								pick[i].setPickupn(current->fname+" "+current->lname);
								cout << current->fname << " has been assigned to "<<pick[i].Color() <<" PICKUP's FRONT seat."<<endl;
								current->vehicle=pick[i].Front();
								current->color=pick[i].Color();
								current->location="FRONT";
								current->reserve=reserve;
								current->assigned=true;
								quit=!quit;
								break;
							}else{
								if(comp[i].Front()!=0){
									namecheck=false;
									current->credit-=5;
									comp[i].setCompactf();
									comp[i].setCompactfn(current->fname+" "+current->lname);
									cout << current->fname << " has been assigned to "<<comp[i].Color() <<" COMPACT's FRONT seat."<<endl;
									current->vehicle=comp[i].Type();
									current->color=comp[i].Color();
									current->location="FRONT";
									current->reserve=reserve;
									current->assigned=true;
									quit=!quit;
									break;
								}else{
									if(sed[i].Front()!=0){
										namecheck=false;
										current->credit-=5;
										sed[i].setSedanf();
										sed[i].setSedanfn(current->fname+" "+current->lname);
										cout << current->fname << " has been assigned to "<<sed[i].Color() <<" SEDAN's FRONT seat."<<endl;
										current->vehicle=sed[i].Type();
										current->color=sed[i].Color();
										current->location="FRONT";
										current->reserve=reserve;
										current->assigned=true;
										quit=!quit;
										break;
									}
								}
							}
						}
						if(namecheck)
							cout<<"-INVALID SELECTION-\nPlease reselect from main menu."<<endl;
					}
				}else{
					if(select=='S'){
						quit=Select(current,pick,comp,sed,reserve);
					}else{
						cout << "-INVALID SELECTION-\nPlease reselect." << endl;
					}
				}
			}
		}
	}while(!quit);
}

void Delete(passenger *head, Pickup pick[3], Compact comp[3], Sedan sed[3], int reserve){
	//add passenger credit
	//remove and hold reserve number
	//clear passenger vehicle,color,location
	//add car seat value
	passenger *current=head;
	int res,update=-1,credit;
	bool res_check=false,quit=false,color_check=false;
	do{
		cout << "Please enter valid Reservation number: ";
		cin>>res;
		if(res<=9 && res>0)
			cin.ignore();
		if(res<=0 || res>getCount(head)){
			cout<<"-INVALID RESERVATION-\nPlease reselect."<<endl;
		}
		else{


//			if(res<=0 || res>getCount(head)){
//						cout<<"-INVALID RESERVATION-\nPlease reselect."<<endl;
//					}
//					else{
//						while(current != NULL){
//							if(current->reserve==res){
//								res_check=true;
//								if(current->credit<=0){
//									current->randomized=true;
//									cout << current->fname << " " << current->lname << " will be assigned to remaining available seats." << endl;
//									quit=!quit;
//									break;
//								}
//								else{
//									current->randomized=false;
//									if(current->vehicle=="PICKUP"){
//										for(int i=0;i<3;i++){
//											if(current->color==pick[i].Color()){
//												if(pick[i].front==0 && pick[i].name==(current->fname+" "+current->lname))
//													credit=5;
//												pick[i].setPickupn("");
//												pick[i].setPickup(credit);
//												current->location="";
//												current->color="";
//												current->vehicle="";
//												current->credit+=credit;
//												current->assigned=false;
//											}
//										}
//									}
//									if(current->vehicle=="COMPACT"){
//										for(int i=0;i<3;i++){
//											if(current->color==comp[i].Color()){
//												if(comp[i].front==0 && comp[i].fname==(current->fname+" "+current->lname)){
//													credit=5;
//													comp[i].setCompactfn("");
//													comp[i].setCompactf(credit);
//												}
//												if(comp[i].back1==0 && comp[i].b1name==(current->fname+" "+current->lname)){
//													credit=3;
//													comp[i].setCompactb1n("");
//													comp[i].setCompactb1(credit);
//												}
//												if(comp[i].back2==0 && comp[i].b2name==(current->fname+" "+current->lname)){
//													credit=3;
//													comp[i].setCompactb2n("");
//													comp[i].setCompactb2(credit);
//												}
//												current->credit+=credit;
//												current->location="";
//												current->color="";
//												current->vehicle="";
//												current->assigned=false;
//											}
//										}
//									}
//									if(current->vehicle=="SEDAN"){
//										for(int i=0;i<3;i++){
//											if(current->color==sed[i].Color()){
//												if(sed[i].front==0 && sed[i].fname==(current->fname+" "+current->lname)){
//													credit=5;
//													sed[i].setSedanfn("");
//													sed[i].setSedanf(credit);
//												}
//												if(sed[i].sideback1==0 && sed[i].sb1name==(current->fname+" "+current->lname)){
//													credit=2;
//													sed[i].setSedansb1n("");
//													sed[i].setSedansb1(credit);
//												}
//												if(sed[i].sidemiddle==0 && sed[i].smname==(current->fname+" "+current->lname)){
//													credit=1;
//													sed[i].setSedansmn("");
//													sed[i].setSedansm(credit);
//												}
//												if(sed[i].sideback2==0 && sed[i].sb2name==(current->fname+" "+current->lname)){
//													credit=2;
//													sed[i].setSedansb2n("");
//													sed[i].setSedansb2(credit);
//												}
//												current->credit+=credit;
//												current->location="";
//												current->color="";
//												current->vehicle="";
//												current->assigned=false;
//											}
//										}
//									}
//									cout << current->fname <<" "<<current->lname << " has " << current->credit << " credits remaining." << endl;
//									Display(pick,comp,sed);
//									quit=Select(current, pick, comp, sed, res);
//								}
//							}
//							current = current->nextaddr;
//						}
//						if(res_check==false){
//							cout<<"-INVALID RESERVATION-\nPlease reselect from main menu."<<endl;
//							quit=!quit;
//						}
//					}



			while(current != NULL){
				if(current->reserve==res){
					res_check=true;
					cout << current->fname <<" "<<current->lname << " has " << current->credit << " credits remaining." << endl;
					if(current->credit<=0){
						current->randomized=true;
						cout << current->fname << " " << current->lname << " will be assigned to remaining available seats." << endl;
						break;
					}
					else current->randomized=false;
				}
				current = current->nextaddr;
			}
			if(res_check==false){
				cout<<"-INVALID RESERVATION-\nPlease reselect from main menu."<<endl;
				quit=true;
			}
			else{
				if(current->vehicle=="PICKUP"){
					if(current->color=="PURPLE" || current->color=="YELLOW" || current->color=="RED"){
						for(int i=0;i<3;i++){
							if(pick[i].Color()==current->color){
								color_check=true;
								pick[i].setPickup(5);
								pick[i].setPickupn(" ");
							}
						}
						if(color_check==true){
							if(current->location=="FRONT"){
								credit=5;
								update=current->reserve;
								current->location="NONE";
								current->color="NONE";
								current->credit+=credit;
								current->vehicle="NONE";
								current->reserve=0;
							}else{
								cout<<"-INVALID LOCATION-\nUser has not yet been assigned."<<endl;
							}
						}
					}else{
						cout<<"-INVALID COLOR-\nUser has not yet been assigned." << endl;
					}
				}
				if(current->vehicle=="COMPACT"){
					if(current->color=="GREEN" || current->color=="BLUE" || current->color=="YELLOW"){
						int i;
						for(i=0;i<3;i++)
							if(comp[i].Color()==current->color)
								color_check=true;
						if(color_check==true){
							if(current->location=="FRONT"){
								credit=5;
								comp[i].setCompactf(credit);
								comp[i].setCompactfn(" ");
								update=current->reserve;
								current->location="NONE";
								current->color="NONE";
								current->credit+=credit;
								current->vehicle="NONE";
								current->reserve=0;
							}
							if(current->location=="LEFT BACK"){
								credit=3;
								comp[i].setCompactb1(credit);
								comp[i].setCompactb1n(" ");
								update=current->reserve;
								current->location="NONE";
								current->color="NONE";
								current->credit+=credit;
								current->vehicle="NONE";
								current->reserve=0;
							}
							if(current->location=="RIGHT BACK"){
								credit=3;
								comp[i].setCompactb2(credit);
								comp[i].setCompactb2n(" ");
								update=current->reserve;
								current->location="NONE";
								current->color="NONE";
								current->credit+=credit;
								current->vehicle="NONE";
								current->reserve=0;
							}else{
								cout<<"-INVALID LOCATION-\nUser has not yet been assigned."<<endl;
							}
						}
					}
					else{
						cout<<"-INVALID COLOR-\nUser has not yet been assigned." << endl;
					}
				}
				if(current->vehicle=="SEDAN"){
					if(current->color=="RED" || current->color=="GREEN" || current->color=="BLUE"){
						int i;
						for(i=0;i<3;i++)
							if(sed[i].Color()==current->color)
								color_check=true;
						if(color_check==true){
							if(current->location=="FRONT"){
								credit=5;
								sed[i].setSedanf(credit);
								sed[i].setSedanfn(" ");
								update=current->reserve;
								current->location="NONE";
								current->color="NONE";
								current->credit+=credit;
								current->vehicle="NONE";
								current->reserve=0;
							}
							if(current->location=="LEFT SIDEBACK"){
								credit=2;
								sed[i].setSedansb1(credit);
								sed[i].setSedansb1n(" ");
								update=current->reserve;
								current->location="NONE";
								current->color="NONE";
								current->credit+=credit;
								current->vehicle="NONE";
								current->reserve=0;
							}
							if(current->location=="MIDDLE BACK"){
								credit=1;
								sed[i].setSedansm(credit);
								sed[i].setSedansmn(" ");
								update=current->reserve;
								current->location="NONE";
								current->color="NONE";
								current->credit+=credit;
								current->vehicle="NONE";
								current->reserve=0;
							}
							if(current->location=="RIGHT SIDEBACK"){
								credit=2;
								sed[i].setSedansb2(credit);
								sed[i].setSedansb2n(" ");
								update=current->reserve;
								current->location="NONE";
								current->color="NONE";
								current->credit+=credit;
								current->vehicle="NONE";
								current->reserve=0;
							}else{
								cout<<"-INVALID LOCATION-\nUser has not yet been assigned."<<endl;
							}
						}
					}
					else{
						cout<<"-INVALID COLOR-\nUser has not yet been assigned." << endl;
					}
				}else{
					cout<<"-INVALID VEHICLE-\nUser has not yet been assigned."<<endl;
				}
				if(update>0){
					do{
						current=head;
						while(current != NULL){
							if(current->reserve==update){
								current->reserve--;
								break;
							}
							current = current->nextaddr;
						}
						update++;
					}while(update<=reserve);
				}
			}
		}
	}while(!quit);
}

void Print(passenger *head, Pickup pick[3], Compact comp[3], Sedan sed[3]) {
	string vehicle,color,tmp,tmp2,seat;
	passenger *current=head;
	cout << "Which vehicle would you like to print?\n";
	cin>> tmp;
	cin>> tmp2;
	for(char x: tmp)
		color+=tolower(x);
	for(char x: tmp2)
		vehicle+=tolower(x);
	if((vehicle=="pickup"||vehicle=="compact"||vehicle=="sedan")&&
		(color=="purple" || color=="yellow" || color=="red" || color=="green" || color=="blue" || color=="yellow")){
		while(current != NULL){
			if(current->vehicle==vehicle && current->color==color){
				cout << current->fname <<" "<<current->lname << " has " << current->credit << " credits remaining." << endl;
				if(current->credit<=0){
					current->randomized=true;
					cout << current->fname << " " << current->lname << " will be assigned to remaining available seats." << endl;
					break;
				}
				else current->randomized=false;
			}
			current = current->nextaddr;
		}
	}
	ofstream outFile;
	outFile.open(color+"_"+vehicle+".txt");
	outFile<< "Vehicle: "+color+" "+vehicle << endl;
	if(vehicle=="pickup"){
		if(color=="purple"){
			cout << color+" "+vehicle+"\n" << "Front: " << pick[0].name << endl;
			outFile<< "Front: " << pick[0].name << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
		}
		if(color=="yellow"){
			cout << color+" "+vehicle+"\n" << "Front: " << pick[1].name << endl;
			outFile<< "Front: " << pick[1].name << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
		}
		if(color=="red"){
			cout << color+" "+vehicle+"\n" << "Front: " << pick[2].name << endl;
			outFile<< "Front: " << pick[2].name << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
		}else cout << "-INVALID COLOR-\nIncorrect color entered. Please try again." << endl;
	}
	if(vehicle=="compact"){
		if(color=="green"){
			cout << color+" "+vehicle+"\n" << "Front: " << comp[0].fname << "\nLeft Back: ";
			cout << comp[0].b1name << "\nRight Back: " << comp[0].b2name << endl;
			outFile<< "Front: " << comp[0].fname << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
			outFile<< "Left Back: " << comp[0].b1name << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
			outFile<< "Right Back: " << comp[0].b2name << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
		}
		if(color=="blue"){
			cout << color+" "+vehicle+"\n" << "Front: " << comp[1].fname << "\nLeft Back: ";
			cout << comp[1].b1name << "\nRight Back: " << comp[1].b2name << endl;
			outFile<< "Front: " << comp[1].fname << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
			outFile<< "Left Back: " << comp[1].b1name << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
			outFile<< "Right Back: " << comp[1].b2name << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
		}
		if(color=="yellow"){
			cout << color+" "+vehicle+"\n" << "Front: " << comp[2].fname << "\nLeft Back: ";
			cout << comp[2].b1name << "\nRight Back: " << comp[2].b2name << endl;
			outFile<< "Front: " << comp[2].fname << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
			outFile<< "Left Back: " << comp[2].b1name << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
			outFile<< "Right Back: " << comp[2].b2name << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
		}else cout << "-INVALID COLOR-\nIncorrect color entered. Please try again." << endl;
	}
	if(vehicle=="sedan"){
		if(color=="red"){
			cout << color+" "+vehicle+"\n" << "Front: " << sed[0].fname << "\nLeft Back: ";
			cout << sed[0].sb1name << "\nMiddle Back: " << sed[0].smname << "\nRight Back: " << sed[0].sb2name << endl;
			outFile<< "Front: " << sed[0].fname << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
			outFile<< "Left Back: " << sed[0].sb1name << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
			outFile<< "Middle Back: " << sed[0].smname << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
			outFile<< "Right Back: " << sed[0].sb2name << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
		}
		if(color=="green"){
			cout << color+" "+vehicle+"\n" << "Front: " << sed[0].fname << "\nLeft Back: ";
			cout << sed[0].sb1name << "\nMiddle Back: " << sed[0].smname << "\nRight Back: " << sed[0].sb2name << endl;
			outFile<< "Front: " << sed[0].fname << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
			outFile<< "Left Back: " << sed[0].sb1name << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
			outFile<< "Middle Back: " << sed[0].smname << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
			outFile<< "Right Back: " << sed[0].sb2name << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
		}
		if(color=="blue"){
			cout << color+" "+vehicle+"\n" << "Front: " << sed[0].fname << "\nLeft Back: ";
			cout << sed[0].sb1name << "\nMiddle Back: " << sed[0].smname << "\nRight Back: " << sed[0].sb2name << endl;
			outFile<< "Front: " << sed[0].fname << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
			outFile<< "Left Back: " << sed[0].sb1name << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
			outFile<< "Middle Back: " << sed[0].smname << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
			outFile<< "Right Back: " << sed[0].sb2name << endl;
			outFile<< "Reserve #: "<< current->reserve << endl;
			outFile<< "------------------------------------\n";
		}else cout << "-INVALID COLOR-\nIncorrect color entered. Please try again." << endl;
	}else cout << "-INVALID VEHICLE-\nIncorrect vehicle entered. Please try again." << endl;
	outFile.close();
}

void Display(Pickup pick[3],Compact comp[3],Sedan sed[3]){
	cout << "\n";
	cout << "   Truck   Compact     Sedan" << endl;
	cout << "   -----   -------     -----" << endl;
	cout << "  " << pick[0].Color() << "    " << comp[0].Color() << "       " << sed[0].Color() << endl;
	cout << "  (-)(" << pick[0].Front() << ")   (-) (" << comp[0].Front() << ")   (-)   (" << sed[0].Front() << ") "<<endl;
	cout << "           (" << comp[0].Back1() << ") (" << comp[0].Back2() << ")   (" << sed[0].SideBack1() << ")(";
	cout << sed[0].SideMiddle() << ")(" << sed[0].SideBack2() << ") "<<endl;
	cout << "  " << pick[1].Color() << "     " << comp[1].Color() << "      " << sed[1].Color() << endl;
	cout << "  (-)(" << pick[1].Front() << ")   (-) (" << comp[1].Front() << ")   (-)   (" << sed[1].Front() << ") "<<endl;
	cout << "           (" << comp[1].Back1() << ") (" << comp[1].Back2() << ")   (" << sed[1].SideBack1() << ")(";
	cout << sed[1].SideMiddle() << ")(" << sed[1].SideBack2() << ") "<<endl;
	cout << "   " << pick[2].Color() << "      " << comp[2].Color() << "     " << sed[2].Color() << endl;
	cout << "  (-)(" << pick[2].Front() << ")   (-) (" << comp[2].Front() << ")   (-)   (" << sed[2].Front() << ") "<<endl;
	cout << "           (" << comp[2].Back1() << ") (" << comp[2].Back2() << ")   (" << sed[2].SideBack1() << ")(";
	cout << sed[2].SideMiddle() << ")(" << sed[2].SideBack2() << ") \n"<<endl;
}
