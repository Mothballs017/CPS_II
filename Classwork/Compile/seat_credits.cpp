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
		string Type(){
			return type;
		}
		string Color(){
			return color;
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
	string name;
public:
	Pickup(){ front = 5; }
	void setPickupn(string p)
	{
		name = p;
	}
	void setPickup(int f=0)
	{
		front = f;
	}
	int Front(){
		return front;
	}
};

class Compact:public Car{
public:
	int front,back1,back2;
	string fname,b1name,b2name;
public:
	friend Compact setCompact(Compact C);

	void setCompactfn(string c){
		fname = c;
	}
	void setCompactb1n(string c){
		b1name = c;
	}
	void setCompactb2n(string c){
		b2name = c;
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
	int Front(){
		return front;
	}
	int Back1(){
		return back1;
	}
	int Back2(){
		return back2;
	}
};

class Sedan:public Car{
public:
	int front,sideback1,sideback2,sidemiddle;
	string fname,sb1name,sb2name,smname;
public:
	Sedan(){ front = 5; sideback1=2; sideback2=2; sidemiddle=1; }

	friend Sedan setSedan(Sedan S);

	void setSedanfn(string s){
		fname = s;
	}
	void setSedansb1n(string s){
		sb1name = s;
	}
	void setSedansb2n(string s){
		sb2name = s;
	}
	void setSedansmn(string s){
		smname = s;
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
	int Front(){
		return front;
	}
	int SideBack1(){
		return sideback1;
	}
	int SideMiddle(){
		return sidemiddle;
	}
	int SideBack2(){
		return sideback2;
	}
};

void setPickup(Pickup P){
	P.front = 5;
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

bool Select(passenger *current, Pickup pick[3], Compact comp[3], Sedan sed[3], int reserve){
	bool quit=false;
	int car_num,seat;
	//	Print();
	cout << "Select vehicle type by number (1-3): ";
	cin >> car_num; cin.ignore();
	string tmp,color;
	if(car_num==1){
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
					current->vehicle=pick[0].Type();
					current->color=pick[0].Color();
					current->location="FRONT";
					current->reserve=reserve;
					quit=!quit;
				}
				else cout<<"Front seat occupied. Please reselect." << endl;
			}
			if(color=="YELLOW"){
				if(pick[1].Front()!=0){
					current->credit-=5;
					pick[1].setPickup();
					pick[1].setPickupn(current->fname+" "+current->lname);
					current->vehicle=pick[1].Type();
					current->color=pick[1].Color();
					current->location="FRONT";
					current->reserve=reserve;
					quit=!quit;
				}
				else cout<<"Front seat occupied. Please reselect." << endl;
			}
			if(color=="RED"){
				if(pick[2].Front()!=0){
					current->credit-=5;
					pick[2].setPickup();
					pick[2].setPickupn(current->fname+" "+current->lname);
					current->vehicle=pick[2].Type();
					current->color=pick[2].Color();
					current->location="FRONT";
					current->reserve=reserve;
					quit=!quit;
				}
				else cout<<"Front seat occupied. Please reselect." << endl;
			}else cout << "-INVALID COLOR-\nPlease reselect." << endl;
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
				switch(seat){
				case 1:
					if(comp[0].Front()!=0){
						current->credit-=5;
						comp[0].setCompactf();
						comp[0].setCompactfn(current->fname+" "+current->lname);
						current->vehicle=comp[0].Type();
						current->color=comp[0].Color();
						current->location="FRONT";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Front seat occupied. Please reselect." << endl;
					break;
				case 2:
					if(comp[0].Back1()!=0){
						current->credit-=3;
						comp[0].setCompactb1();
						comp[0].setCompactb1n(current->fname+" "+current->lname);
						current->vehicle=comp[0].Type();
						current->color=comp[0].Color();
						current->location="LEFT BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Left back seat occupied. Please reselect." << endl;
					break;
				case 3:
					if(comp[0].Back2()!=0){
						current->credit-=3;
						comp[0].setCompactb2();
						comp[0].setCompactb2n(current->fname+" "+current->lname);
						current->vehicle=comp[0].Type();
						current->color=comp[0].Color();
						current->location="RIGHT BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Right back seat occupied. Please reselect." << endl;
					break;
				default:
					cout << "-INVALID SEAT-\nPlease reselect."<<endl;
					break;
				}
			}
			if(color=="BLUE"){
				cout<<"Enter seat (1-3): ";
				cin>>seat;cin.ignore();
				switch(seat){
				case 1:
					if(comp[1].Front()!=0){
						current->credit-=5;
						comp[1].setCompactf();
						comp[1].setCompactfn(current->fname+" "+current->lname);
						current->vehicle=comp[1].Type();
						current->color=comp[1].Color();
						current->location="FRONT";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Front seat occupied. Please reselect." << endl;
					break;
				case 2:
					if(comp[1].Back1()!=0){
						current->credit-=3;
						comp[1].setCompactb1();
						comp[1].setCompactb1n(current->fname+" "+current->lname);
						current->vehicle=comp[1].Type();
						current->color=comp[1].Color();
						current->location="LEFT BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Left back seat occupied. Please reselect." << endl;
					break;
				case 3:
					if(comp[1].Back2()!=0){
						current->credit-=3;
						comp[1].setCompactb2();
						comp[1].setCompactb2n(current->fname+" "+current->lname);
						current->vehicle=comp[1].Type();
						current->color=comp[1].Color();
						current->location="RIGHT BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Right back seat occupied. Please reselect." << endl;
					break;
				default:
					cout <<"-INVALID SEAT-\nPlease reselect."<<endl;
					break;
				}
			}
			if(color=="YELLOW"){
				cout<<"Enter seat (1-3): ";
				cin>>seat;cin.ignore();
				switch(seat){
				case 1:
					if(comp[2].Front()!=0){
						current->credit-=5;
						comp[2].setCompactf();
						comp[2].setCompactfn(current->fname+" "+current->lname);
						current->vehicle=comp[2].Type();
						current->color=comp[2].Color();
						current->location="FRONT";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Front seat occupied. Please reselect." << endl;
					break;
				case 2:
					if(comp[2].Back1()!=0){
						current->credit-=3;
						comp[2].setCompactb1();
						comp[2].setCompactb1n(current->fname+" "+current->lname);
						current->vehicle=comp[2].Type();
						current->color=comp[2].Color();
						current->location="LEFT BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Left back seat occupied. Please reselect." << endl;
					break;
				case 3:
					if(comp[2].Back2()!=0){
						current->credit-=3;
						comp[2].setCompactb2();
						comp[2].setCompactb2n(current->fname+" "+current->lname);
						current->vehicle=comp[2].Type();
						current->color=comp[2].Color();
						current->location="RIGHT BACK";
						current->reserve=reserve;
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
	if(car_num==3){
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
						current->vehicle=sed[0].Type();
						current->color=sed[0].Color();
						current->location="FRONT";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Front seat occupied. Please reselect." << endl;
					break;
				case 2:
					if(sed[0].SideBack1()!=0){
						current->credit-=2;
						sed[0].setSedansb1();
						sed[0].setSedansb1n(current->fname+" "+current->lname);
						current->vehicle=sed[0].Type();
						current->color=sed[0].Color();
						current->location="LEFT SIDEBACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Left back seat occupied. Please reselect." << endl;
					break;
				case 3:
					if(sed[0].SideMiddle()!=0){
						current->credit-=1;
						sed[0].setSedansm();
						sed[0].setSedansmn(current->fname+" "+current->lname);
						current->vehicle=sed[0].Type();
						current->color=sed[0].Color();
						current->location="MIDDLE BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Middle back seat occupied. Please reselect." << endl;
					break;
				case 4:
					if(sed[0].SideBack2()!=0){
						current->credit-=2;
						sed[0].setSedansb2();
						sed[0].setSedansb2n(current->fname+" "+current->lname);
						current->vehicle=sed[0].Type();
						current->color=sed[0].Color();
						current->location="RIGHT SIDEBACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Right back seat occupied. Please reselect." << endl;
					break;
				default:
					cout << "-INVALID SEAT-\nPlease reselect."<<endl;
					break;
				}
			}
			if(color=="GREEN"){
				cout<<"Enter seat (1-4): ";
				cin>>seat;cin.ignore();
				switch(seat){
				case 1:
					if(sed[1].Front()!=0){
						current->credit-=5;
						sed[1].setSedanf();
						sed[1].setSedanfn(current->fname+" "+current->lname);
						current->vehicle=sed[1].Type();
						current->color=sed[1].Color();
						current->location="FRONT";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Front seat occupied. Please reselect." << endl;
					break;
				case 2:
					if(sed[1].SideBack1()!=0){
						current->credit-=2;
						sed[1].setSedansb1();
						sed[1].setSedansb1n(current->fname+" "+current->lname);
						current->vehicle=sed[1].Type();
						current->color=sed[1].Color();
						current->location="LEFT SIDEBACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Left back seat occupied. Please reselect." << endl;
					break;
				case 3:
					if(sed[1].SideMiddle()!=0){
						current->credit-=1;
						sed[1].setSedansm();
						sed[1].setSedansmn(current->fname+" "+current->lname);
						current->vehicle=sed[1].Type();
						current->color=sed[1].Color();
						current->location="MIDDLE BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Middle back seat occupied. Please reselect." << endl;
					break;
				case 4:
					if(sed[1].SideBack2()!=0){
						current->credit-=2;
						sed[1].setSedansb2();
						sed[1].setSedansb2n(current->fname+" "+current->lname);
						current->vehicle=sed[1].Type();
						current->color=sed[1].Color();
						current->location="RIGHT SIDEBACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Right back seat occupied. Please reselect." << endl;
					break;
				default:
					cout << "-INVALID SEAT-\nPlease reselect."<<endl;
					break;
				}
			}
			if(color=="BLUE"){
				cout<<"Enter seat (1-4): ";
				cin>>seat;cin.ignore();
				switch(seat){
				case 1:
					if(sed[2].Front()!=0){
						current->credit-=5;
						sed[2].setSedanf();
						sed[2].setSedanfn(current->fname+" "+current->lname);
						current->vehicle=sed[2].Type();
						current->color=sed[2].Color();
						current->location="FRONT";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Front seat occupied. Please reselect." << endl;
					break;
				case 2:
					if(sed[2].SideBack1()!=0){
						current->credit-=2;
						sed[2].setSedansb1();
						sed[2].setSedansb1n(current->fname+" "+current->lname);
						current->vehicle=sed[2].Type();
						current->color=sed[2].Color();
						current->location="LEFT SIDEBACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Left back seat occupied. Please reselect." << endl;
					break;
				case 3:
					if(sed[2].SideMiddle()!=0){
						current->credit-=1;
						sed[2].setSedansm();
						sed[2].setSedansmn(current->fname+" "+current->lname);
						current->vehicle=sed[2].Type();
						current->color=sed[2].Color();
						current->location="MIDDLE BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Middle back seat occupied. Please reselect." << endl;
					break;
				case 4:
					if(sed[2].SideBack2()!=0){
						current->credit-=2;
						sed[2].setSedansb2();
						sed[2].setSedansb2n(current->fname+" "+current->lname);
						current->vehicle=sed[2].Type();
						current->color=sed[2].Color();
						current->location="RIGHT SIDEBACK";
						current->reserve=reserve;
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
	}else{
		cout<<"-INVALID VEHICLE-\nPlease reselect."<<endl;
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
	int res;
	bool res_check=false,quit=false;
	do{
		cout << "Please enter valid Reservation number: ";
		cin>>res;
		if(res<=9 && res>0)
			cin.ignore();
		else{
			while(current != NULL){
				if(current->reserve==res){
					res_check=true;
					cout << current->fname <<" "<<current->lname << " has " << current->credit << " credits remaining." << endl;
					if(current->credit<=0){
						current->randomized=true;
						cout << current->fname << " " << current->lname << "will be assigned to remaining available seats." << endl;
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
				quit=Select(current, pick, comp, sed, res);
			}
		}
	}while(!quit);
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
		char select=' ';
		while(current != NULL){
			if((first==current->fname && last==current->lname)||(first==current->lname && last==current->fname)){
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
		if(namecheck==false){
			cout<<"-INVALID NAME-\nPlease reselect from main menu."<<endl;
			quit=true;
		}
		else{
			Display(pick,comp,sed);
			cout << "Choose selection by category (Vehicle/Seat): ";
			cin >> select; cin.ignore();
			select=toupper(select);
			if(select=='V'){
				for(int i=0;i<3;i++){
					if(pick[i].Front()!=0){
						current->credit-=5;
						pick[i].setPickup();
						pick[i].setPickupn(current->fname+" "+current->lname);
						current->vehicle=pick[i].Front();
						current->color=pick[i].Color();
						current->location="FRONT";
						current->reserve=reserve;
						quit=!quit;
						break;
					}else{
						if(comp[i].Front()!=0){
							current->credit-=5;
							comp[i].setCompactf();
							comp[i].setCompactfn(current->fname+" "+current->lname);
							current->vehicle=comp[i].Type();
							current->color=comp[i].Color();
							current->location="FRONT";
							current->reserve=reserve;
							quit=!quit;
							break;
						}else
							if(sed[i].Front()!=0){
								current->credit-=5;
								sed[i].setSedanf();
								sed[i].setSedanfn(current->fname+" "+current->lname);
								current->vehicle=sed[i].Type();
								current->color=sed[i].Color();
								current->location="FRONT";
								current->reserve=reserve;
								quit=!quit;
								break;
							}
					}
				}
			}else{
				if(select=='S'){
					quit=Select(current,pick,comp,sed,reserve);
				}
//
				else{
					cout << "-INVALID SELECTION-\nPlease reselect." << endl;
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
		else{
			while(current != NULL){
				if(current->reserve==res){
					res_check=true;
					cout << current->fname <<" "<<current->lname << " has " << current->credit << " credits remaining." << endl;
					if(current->credit<=0){
						current->randomized=true;
						cout << current->fname << " " << current->lname << "will be assigned to remaining available seats." << endl;
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
							if(current->reserve==update)
								current->reserve--;
							current = current->nextaddr;
						}
						update++;
					}while(update<=reserve);
				}
			}
		}
	}while(!quit);
}

void Print(passenger *current, Pickup pick[3], Compact comp[3], Sedan sed[3], int reserve) {
	string vehicle,color,tmp,tmp2,seat;
	cout << "Which vehicle would you like to print?\n";
	cin>> tmp;
	cin>> tmp2;
	for(char x: tmp)
		color+=tolower(x);
	for(char x: tmp2)
		vehicle+=tolower(x);
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
	cout << sed[2].SideMiddle() << ")(" << sed[2].SideBack2() << ") "<<endl;
}

void Menu(){
	//Menu: Create(head,pick,comp,sed,reserve_num)
	//		Display()
	//		Modify(head,pick,comp,sed)
	//		Delete(head,pick,comp,sed,reserve_num)
	//		Print()
	//		Reservation(head)
	cout << "|1| Create Reservation"<<endl;
	cout << "|2| Display Vehicles"<<endl;
	
}

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
	//Display()		|
	//Modify()		| Completed (M)
	//Delete() 		| Completed (M)
	//Print()		| Completed (M)
	//Reservation()	| Completed (M)

	//Select()		| Completed (M)

	//header		|
	//body cpp		|
	//main loop		|

	//Xtra credit: 	auto-fill?
	//				randomize remaining?
	Pickup pick[3];
	pick[0].setCar("PURPLE","TRUCK");
	setPickup(pick[0]);
	pick[1].setCar("YELLOW","TRUCK");
	setPickup(pick[1]);
	pick[2].setCar("RED","TRUCK");
	setPickup(pick[2]);
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
	int reserve_num=1;
	bool running=true;
	Display(pick,comp,sed);

	//start loop
	while(running){
		Menu();
	}
	//Print menu
}
