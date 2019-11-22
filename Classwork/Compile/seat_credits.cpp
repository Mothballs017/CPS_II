// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: seat_credits.cpp
// Course: Computational Problem Solving CPET-II
// Developer: MATTHEW CHU & John Alvarez
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
using namespace std;

struct passenger
{
	string fname;
	string lname;
	int credit;
	int reserve;
	string vehicle;
	string color;
	string location;
	bool randomized=false;
	passenger *nextaddr;
};

class Car
{
	protected:
		string color;
		string type;
	public:
	    Car()
	      { color = " "; type = " "; }

		void setCar(string c, string t)
		{
			color = c;
			type = t;
			return;
		}

//		void showCar()
//		{
//			cout << "Name : " << sName << endl;
//			switch (sColor)
//			{
//				case 'R' :
//				case 'r' : cout << "Color : Red" << endl;
//					       break;
//				case 'G' :
//				case 'g' : cout << "Color : Green" << endl;
//					       break;
//				case 'B' :
//				case 'b' : cout << "Color : Blue" << endl;
//					       break;
//				default  : cout << "Color : Unknown" << endl;
//					       break;
//			}
//			return;
//		}
};

class Pickup:public Car{
public:
	int front;
public:
	Pickup(){ front = 5; }

	void setPickup(int f=0)
	{
		front = f
	}
};

class Compact:public Car{
public:
	int front,back1,back2;
public:
	Compact(){ front = 5; back1 = 3; back2=3; }

	void setCompact(int f=0, int b1=0, int b2=0)
	{
		front = f;
		back1 = b1;
		back2 = b2;
		return;
	}
	void setCompactf(int f=0){
		front = f;
	}
	void setCompactb1(int b1=0){
		back1 = b1;
	}
	void setCompactb2(int b2=0){
		back2 = b2;
	}
};

class Sedan:public Car{
public:
	int front,sideback1,sideback2,sidemiddle;
public:
	Sedan(){ front = 5; sideback1=2; sideback2=2; sidemiddle=1; }

	void setSedan(int f=0, int sb1=0, int sb2=0, int sm=0)
	{
		front = f;
		sideback1 = sb1;
		sideback2 = sb2;
		sidemiddle = sm;
		return;
	}
	void setSedanf(int f=0){
		front = f;
	}
	void setSedansb1(int sb1=0){
		sideback1 = sb1;
	}
	void setSedansb2(int sb2=0){
		sideback2 = sb2;
	}
	void setSedansm(int sm=0){
		sidemiddle = sm;
	}
};

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

void Modify(passenger *head){
	//check reservation #/print error, display vehicle+seat,reselect vehicle, reselect seat
	//CREATE VEHICLE+SEAT function and replace in Create()
	passenger *current=head;
	int res;
	cout << "Please enter valid Reservation number: ";
	cin>>res;
	if(res<=9 && res>0)
		cin.ignore();
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
		int car_num,seat;
		char select=' ';
		while(current != NULL){
			if(first==current->fname && last==current->lname){
				namecheck=true;
				cout << current->fname <<" "<<current->lname << " has " << current->credit << " credits remaining." << endl;
				if(current->credit<=0){
					current->randomized=true;
					cout << current->fname << " " << current->lname << "will be assigned to remaining available seats." << endl;
				}
				else current->randomized=false;
			}
			current = current->nextaddr;
		}
		if(namecheck==false)
			quit=true;
		else{
//			Print();
			cout << "Choose selection by category (Vehicle/Seat): ";
			cin >> select; cin.ignore();
			select=toupper(select);
			if(select=='V'){
				for(int i=0;i<3;i++){
					if(pick[i].front!=0){
						current->credit-=5;
						pick[i].setPickup();
						current->vehicle=pick[i].type;
						current->color=pick[i].color;
						current->location="FRONT";
						current->reserve=reserve;
						quit=!quit;
						break;
					}else{
						if(comp[i].front!=0){
							current->credit-=5;
							comp[i].setCompactf();
							current->vehicle=comp[i].type;
							current->color=comp[i].color;
							current->location="FRONT";
							current->reserve=reserve;
							quit=!quit;
							break;
						}else
							if(sed[i].front!=0){
								current->credit-=5;
								sed[i].setSedanf();
								current->vehicle=sed[i].type;
								current->color=sed[i].color;
								current->location="FRONT";
								current->reserve=reserve;
								quit=!quit;
								break;
							}
					}
				}
			}else{
				if(select=='S'){
//					Print();
					cout << "Select vehicle type by number (1-3): ";
					cin >> car_num; cin.ignore();
					string tmp;
					if(car_num==1){
						if(current->credit<5){
							cout<<"-INVALID CREDIT LIMIT-/Please reselect."<<endl;
						}else
						{
							cout << "Select pickup by color: ";
							cin>>tmp;
							for(char x: tmp)
								color+=toupper(x);
							if(color=="PURPLE"){
								if(pick[0].front!=0){
									current->credit-=5;
									pick[0].setPickup();
									current->vehicle=pick[0].type;
									current->color=pick[0].color;
									current->location="FRONT";
									current->reserve=reserve;
									quit=!quit;
									break;
								}
								else cout<<"Front seat occupied. Please reselect." << endl;
							}
							if(color=="YELLOW"){
								if(pick[1].front!=0){
									current->credit-=5;
									pick[1].setPickup();
									current->vehicle=pick[1].type;
									current->color=pick[1].color;
									current->location="FRONT";
									current->reserve=reserve;
									quit=!quit;
									break;
								}
								else cout<<"Front seat occupied. Please reselect." << endl;
							}
							if(color=="RED"){
								if(pick[2].front!=0){
									current->credit-=5;
									pick[2].setPickup();
									current->vehicle=pick[2].type;
									current->color=pick[2].color;
									current->location="FRONT";
									current->reserve=reserve;
									quit=!quit;
									break;
								}
								else cout<<"Front seat occupied. Please reselect." << endl;
							}else{
								cout << "-INVALID COLOR-\nPlease reselect." << endl;
							}
						}
					}
					if(car_num==2){
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
								if(seat==1){
									if(comp[0].front!=0){
										current->credit-=5;
										comp[0].setCompactf();
										current->vehicle=comp[0].type;
										current->color=comp[0].color;
										current->location="FRONT";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Front seat occupied. Please reselect." << endl;
								}
								if(seat==2){
									if(comp[0].back1!=0){
										current->credit-=3;
										comp[0].setCompactb1();
										current->vehicle=comp[0].type;
										current->color=comp[0].color;
										current->location="LEFT BACK";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Left back seat occupied. Please reselect." << endl;
								}
								if(seat==3){
									if(comp[0].back2!=0){
										current->credit-=3;
										comp[0].setCompactb2;
										current->vehicle=comp[0].type;
										current->color=comp[0].color;
										current->location="RIGHT BACK";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Right back seat occupied. Please reselect." << endl;
								}else cout << "-INVALID SEAT-\nPlease reselect."<<endl;
							}
							if(color=="BLUE"){
								cout<<"Enter seat (1-3): ";
								cin>>seat;cin.ignore();
								if(seat==1){
									if(comp[1].front!=0){
										current->credit-=5;
										comp[1].setCompactf();
										current->vehicle=comp[1].type;
										current->color=comp[1].color;
										current->location="FRONT";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Front seat occupied. Please reselect." << endl;
								}
								if(seat==2){
									if(comp[1].back1!=0){
										current->credit-=3;
										comp[1].setCompactb1();
										current->vehicle=comp[1].type;
										current->color=comp[1].color;
										current->location="LEFT BACK";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Left back seat occupied. Please reselect." << endl;
								}
								if(seat==3){
									if(comp[1].back2!=0){
										current->credit-=3;
										comp[1].setCompactb2();
										current->vehicle=comp[1].type;
										current->color=comp[1].color;
										current->location="RIGHT BACK";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Right back seat occupied. Please reselect." << endl;
								}else cout <<"-INVALID SEAT-\nPlease reselect."<<endl;
							}
							if(color=="YELLOW"){
								cout<<"Enter seat (1-3): ";
								cin>>seat;cin.ignore();
								if(seat==1){
									if(comp[2].front!=0){
										current->credit-=5;
										comp[2].setCompactf();
										current->vehicle=comp[2].type;
										current->color=comp[2].color;
										current->location="FRONT";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Front seat occupied. Please reselect." << endl;
								}
								if(seat==2){
									if(comp[2].back1!=0){
										current->credit-=3;
										comp[2].setCompactb1();
										current->vehicle=comp[2].type;
										current->color=comp[2].color;
										current->location="LEFT BACK";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Left back seat occupied. Please reselect." << endl;
								}
								if(seat==3){
									if(comp[2].back2!=0){
										current->credit-=3;
										comp[2].setCompactb2();
										current->vehicle=comp[2].type;
										current->color=comp[2].color;
										current->location="RIGHT BACK";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Right back seat occupied. Please reselect." << endl;
								}else cout<<"-INVALID SEAT-\nPlease reselect."<<endl;
							}else{
								cout << "-INVALID COLOR-\nPlease reselect." << endl;
							}
						}
					}
					if(car_num==3){
						if(current->credit<5){
							cout<<"-INVALID CREDIT LIMIT-/Please reselect."<<endl;
						}else{
							cout << "Select sedan by color: ";
							cin>>tmp;
							for(char x: tmp)
								color+=toupper(x);
							if(color=="RED"){
								cout<<"Enter seat (1-4): ";
								cin>>seat;cin.ignore();
								if(seat==1){
									if(sed[0].front!=0){
										current->credit-=5;
										sed[0].setSedanf();
										current->vehicle=sed[0].type;
										current->color=sed[0].color;
										current->location="FRONT";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Front seat occupied. Please reselect." << endl;
								}
								if(seat==2){
									if(sed[0].sideback1!=0){
										current->credit-=2;
										sed[0].setSedansb1();
										current->vehicle=sed[0].type;
										current->color=sed[0].color;
										current->location="LEFT SIDEBACK";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Left back seat occupied. Please reselect." << endl;
								}
								if(seat==3){
									if(sed[0].sidemiddle!=0){
										current->credit-=1;
										sed[0].setSedansm();
										current->vehicle=sed[0].type;
										current->color=sed[0].color;
										current->location="MIDDLE BACK";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Middle back seat occupied. Please reselect." << endl;
								}
								if(seat==4){
									if(sed[0].sideback2!=0){
										current->credit-=2;
										sed[0].setSedansb2();
										current->vehicle=sed[0].type;
										current->color=sed[0].color;
										current->location="RIGHT SIDEBACK";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Right back seat occupied. Please reselect." << endl;
								}else cout << "-INVALID SEAT-\nPlease reselect."<<endl;
							}
							if(color=="GREEN"){
								cout<<"Enter seat (1-4): ";
								cin>>seat;cin.ignore();
								if(seat==1){
									if(sed[1].front!=0){
										current->credit-=5;
										sed[1].setSedanf();
										current->vehicle=sed[1].type;
										current->color=sed[1].color;
										current->location="FRONT";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Front seat occupied. Please reselect." << endl;
								}
								if(seat==2){
									if(sed[1].sideback1!=0){
										current->credit-=2;
										sed[1].setSedansb1();
										current->vehicle=sed[1].type;
										current->color=sed[1].color;
										current->location="LEFT SIDEBACK";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Left back seat occupied. Please reselect." << endl;
								}
								if(seat==3){
									if(sed[1].sidemiddle!=0){
										current->credit-=1;
										sed[1].setSedansm();
										current->vehicle=sed[1].type;
										current->color=sed[1].color;
										current->location="MIDDLE BACK";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Middle back seat occupied. Please reselect." << endl;
								}
								if(seat==4){
									if(sed[1].sideback2!=0){
										current->credit-=2;
										sed[1].setSedansb2();
										current->vehicle=sed[1].type;
										current->color=sed[1].color;
										current->location="RIGHT SIDEBACK";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Right back seat occupied. Please reselect." << endl;
								}else cout << "-INVALID SEAT-\nPlease reselect."<<endl;
							}
							if(color=="BLUE"){
								cout<<"Enter seat (1-4): ";
								cin>>seat;cin.ignore();
								if(seat==1){
									if(sed[2].front!=0){
										current->credit-=5;
										sed[2].setSedanf();
										current->vehicle=sed[2].type;
										current->color=sed[2].color;
										current->location="FRONT";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Front seat occupied. Please reselect." << endl;
								}
								if(seat==2){
									if(sed[2].sideback1!=0){
										current->credit-=2;
										sed[2].setSedansb1();
										current->vehicle=sed[2].type;
										current->color=sed[2].color;
										current->location="LEFT SIDEBACK";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Left back seat occupied. Please reselect." << endl;
								}
								if(seat==3){
									if(sed[2].sidemiddle!=0){
										current->credit-=1;
										sed[2].setSedansm();
										current->vehicle=sed[2].type;
										current->color=sed[2].color;
										current->location="MIDDLE BACK";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Middle back seat occupied. Please reselect." << endl;
								}
								if(seat==4){
									if(sed[2].sideback2!=0){
										current->credit-=2;
										sed[2].setSedansb2();
										current->vehicle=sed[2].type;
										current->color=sed[2].color;
										current->location="RIGHT SIDEBACK";
										current->reserve=reserve;
										quit=!quit;
										break;
									}
									else cout<<"Right back seat occupied. Please reselect." << endl;
								}else cout << "-INVALID SEAT-\nPlease reselect."<<endl;
							}else{
								cout << "-INVALID COLOR-\nPlease reselect." << endl;
							}
						}
					}else{
						cout<<"-INVALID VEHICLE-\nPlease reselect."<<endl;
					}
				}else{
					cout << "-INVALID SELECTION-\nPlease reselect." << endl;
				}
			}
		}
	}while(!quit);
}

int main()
{
	//Create(head)
	//Display()
	//Modify()
	//Delete()
	//Print()
	//Reservation()

	Pickup pick[3];
	pick[0].setCar("PURPLE","TRUCK");
	pick[1].setCar("YELLOW","TRUCK");
	pick[2].setCar("RED","TRUCK");
	Compact comp[3];
	comp[0].setCar("GREEN","COMPACT");
	comp[1].setCar("BLUE","COMPACT");
	comp[2].setCar("YELLOW","COMPACT");
	Sedan sed[3];
	sed[0].setCar("RED","SEDAN");
	sed[1].setCar("GREEN","SEDAN");
	sed[2].setCar("BLUE","SEDAN");

	passenger *head = Read();
	int reserve_num=0;
	reserve_num++;
//	Create(head,pick,comp,sed,reserve_num);
//	string tmp="Can you Re@d this?";
//	string tmp2;
//	cout<<tmp << endl;
//	for (char x : tmp)
//		tmp+=toupper(x);
//	cout << tmp;
	cout << head->fname << endl;
	cout << head->lname << endl;
	cout << "credit" << head->credit << endl;
	cout << "location" << head->location<<endl;
	cout << "bool" << head->randomized<<endl;
	cout << "vehicle" << head->vehicle << endl;
	cout << "color" << head->color << endl;
}
