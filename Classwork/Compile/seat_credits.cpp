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
private:
	int front;
public:
	Pickup(){ front = 5; }

	void setPickup(int f=0)
	{
		front = f;
	}
	int Front(){
		return front;
	}
};

class Compact:public Car{
private:
	int front,back1,back2;
public:
	friend setCompact(Compact);

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
private:
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
void setCompact(Compact C){
	C.front = 5;
	C.back1 = 3;
	C.back2 = 3;
}
void setSedan(Sedan S){
	S.front = 5;
	S.sideback1 = 2;
	S.sidemiddle = 1;
	S.sideback2 = 2;
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
					current->vehicle=pick[2].Type();
					current->color=pick[2].Color();
					current->location="FRONT";
					current->reserve=reserve;
					quit=!quit;
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
					if(comp[0].Front()!=0){
						current->credit-=5;
						comp[0].setCompactf();
						current->vehicle=comp[0].Type();
						current->color=comp[0].Color();
						current->location="FRONT";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Front seat occupied. Please reselect." << endl;
				}
				if(seat==2){
					if(comp[0].Back1()!=0){
						current->credit-=3;
						comp[0].setCompactb1();
						current->vehicle=comp[0].Type();
						current->color=comp[0].Color();
						current->location="LEFT BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Left back seat occupied. Please reselect." << endl;
				}
				if(seat==3){
					if(comp[0].Back2()!=0){
						current->credit-=3;
						comp[0].setCompactb2();
						current->vehicle=comp[0].Type();
						current->color=comp[0].Color();
						current->location="RIGHT BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Right back seat occupied. Please reselect." << endl;
				}else cout << "-INVALID SEAT-\nPlease reselect."<<endl;
			}
			if(color=="BLUE"){
				cout<<"Enter seat (1-3): ";
				cin>>seat;cin.ignore();
				if(seat==1){
					if(comp[1].Front()!=0){
						current->credit-=5;
						comp[1].setCompactf();
						current->vehicle=comp[1].Type();
						current->color=comp[1].Color();
						current->location="FRONT";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Front seat occupied. Please reselect." << endl;
				}
				if(seat==2){
					if(comp[1].Back1()!=0){
						current->credit-=3;
						comp[1].setCompactb1();
						current->vehicle=comp[1].Type();
						current->color=comp[1].Color();
						current->location="LEFT BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Left back seat occupied. Please reselect." << endl;
				}
				if(seat==3){
					if(comp[1].Back2()!=0){
						current->credit-=3;
						comp[1].setCompactb2();
						current->vehicle=comp[1].Type();
						current->color=comp[1].Color();
						current->location="RIGHT BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Right back seat occupied. Please reselect." << endl;
				}else cout <<"-INVALID SEAT-\nPlease reselect."<<endl;
			}
			if(color=="YELLOW"){
				cout<<"Enter seat (1-3): ";
				cin>>seat;cin.ignore();
				if(seat==1){
					if(comp[2].Front()!=0){
						current->credit-=5;
						comp[2].setCompactf();
						current->vehicle=comp[2].Type();
						current->color=comp[2].Color();
						current->location="FRONT";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Front seat occupied. Please reselect." << endl;
				}
				if(seat==2){
					if(comp[2].Back1()!=0){
						current->credit-=3;
						comp[2].setCompactb1();
						current->vehicle=comp[2].Type();
						current->color=comp[2].Color();
						current->location="LEFT BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Left back seat occupied. Please reselect." << endl;
				}
				if(seat==3){
					if(comp[2].Back2()!=0){
						current->credit-=3;
						comp[2].setCompactb2();
						current->vehicle=comp[2].Type();
						current->color=comp[2].Color();
						current->location="RIGHT BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Right back seat occupied. Please reselect." << endl;
				}else cout<<"-INVALID SEAT-\nPlease reselect."<<endl;
			}else{
				cout << "-INVALID COLOR-\nPlease reselect." << endl;
			}
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
				if(seat==1){
					if(sed[0].Front()!=0){
						current->credit-=5;
						sed[0].setSedanf();
						current->vehicle=sed[0].Type();
						current->color=sed[0].Color();
						current->location="FRONT";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Front seat occupied. Please reselect." << endl;
				}
				if(seat==2){
					if(sed[0].SideBack1()!=0){
						current->credit-=2;
						sed[0].setSedansb1();
						current->vehicle=sed[0].Type();
						current->color=sed[0].Color();
						current->location="LEFT SIDEBACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Left back seat occupied. Please reselect." << endl;
				}
				if(seat==3){
					if(sed[0].SideMiddle()!=0){
						current->credit-=1;
						sed[0].setSedansm();
						current->vehicle=sed[0].Type();
						current->color=sed[0].Color();
						current->location="MIDDLE BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Middle back seat occupied. Please reselect." << endl;
				}
				if(seat==4){
					if(sed[0].SideBack2()!=0){
						current->credit-=2;
						sed[0].setSedansb2();
						current->vehicle=sed[0].Type();
						current->color=sed[0].Color();
						current->location="RIGHT SIDEBACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Right back seat occupied. Please reselect." << endl;
				}else cout << "-INVALID SEAT-\nPlease reselect."<<endl;
			}
			if(color=="GREEN"){
				cout<<"Enter seat (1-4): ";
				cin>>seat;cin.ignore();
				if(seat==1){
					if(sed[1].Front()!=0){
						current->credit-=5;
						sed[1].setSedanf();
						current->vehicle=sed[1].Type();
						current->color=sed[1].Color();
						current->location="FRONT";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Front seat occupied. Please reselect." << endl;
				}
				if(seat==2){
					if(sed[1].SideBack1()!=0){
						current->credit-=2;
						sed[1].setSedansb1();
						current->vehicle=sed[1].Type();
						current->color=sed[1].Color();
						current->location="LEFT SIDEBACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Left back seat occupied. Please reselect." << endl;
				}
				if(seat==3){
					if(sed[1].SideMiddle()!=0){
						current->credit-=1;
						sed[1].setSedansm();
						current->vehicle=sed[1].Type();
						current->color=sed[1].Color();
						current->location="MIDDLE BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Middle back seat occupied. Please reselect." << endl;
				}
				if(seat==4){
					if(sed[1].SideBack2()!=0){
						current->credit-=2;
						sed[1].setSedansb2();
						current->vehicle=sed[1].Type();
						current->color=sed[1].Color();
						current->location="RIGHT SIDEBACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Right back seat occupied. Please reselect." << endl;
				}else cout << "-INVALID SEAT-\nPlease reselect."<<endl;
			}
			if(color=="BLUE"){
				cout<<"Enter seat (1-4): ";
				cin>>seat;cin.ignore();
				if(seat==1){
					if(sed[2].Front()!=0){
						current->credit-=5;
						sed[2].setSedanf();
						current->vehicle=sed[2].Type();
						current->color=sed[2].Color();
						current->location="FRONT";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Front seat occupied. Please reselect." << endl;
				}
				if(seat==2){
					if(sed[2].SideBack1()!=0){
						current->credit-=2;
						sed[2].setSedansb1();
						current->vehicle=sed[2].Type();
						current->color=sed[2].Color();
						current->location="LEFT SIDEBACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Left back seat occupied. Please reselect." << endl;
				}
				if(seat==3){
					if(sed[2].SideMiddle()!=0){
						current->credit-=1;
						sed[2].setSedansm();
						current->vehicle=sed[2].Type();
						current->color=sed[2].Color();
						current->location="MIDDLE BACK";
						current->reserve=reserve;
						quit=!quit;
					}
					else cout<<"Middle back seat occupied. Please reselect." << endl;
				}
				if(seat==4){
					if(sed[2].SideBack2()!=0){
						current->credit-=2;
						sed[2].setSedansb2();
						current->vehicle=sed[2].Type();
						current->color=sed[2].Color();
						current->location="RIGHT SIDEBACK";
						current->reserve=reserve;
						quit=!quit;
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
//			Print();
			cout << "Choose selection by category (Vehicle/Seat): ";
			cin >> select; cin.ignore();
			select=toupper(select);
			if(select=='V'){
				for(int i=0;i<3;i++){
					if(pick[i].Front()!=0){
						current->credit-=5;
						pick[i].setPickup();
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
	//Modify()		| Completed
	//Delete() 		| Completed (M)
	//Print()		|
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
	setCompact(comp[0]);
	comp[1].setCar("BLUE","COMPACT");
	setCompact(comp[1]);
	comp[2].setCar("YELLOW","COMPACT");
	setCompact(comp[2]);
	Sedan sed[3];
	sed[0].setCar("RED","SEDAN");
	setSedan(sed[0]);
	sed[1].setCar("GREEN","SEDAN");
	setSedan(sed[1]);
	sed[2].setCar("BLUE","SEDAN");
	setSedan(sed[2]);
	passenger *head = Read();
	int reserve_num=1;

	//start loop
	//Print menu
	//Menu: Create(head,pick,comp,sed,reserve_num)
	//		Display()
	//		Modify(head,pick,comp,sed)
	//		Delete(head,pick,comp,sed,reserve_num)
	//		Print()
	//		Reservation(head)
}
