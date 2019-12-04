/*
 * seat_credits.h
 *
 *  Created on: Dec 3, 2019
 *      Author: mxc6641
 */

#ifndef SEAT_CREDITS_H_
#define SEAT_CREDITS_H_

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
	bool assigned=false;
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
};

class Pickup:public Car{
public:
	int front;
	string name;
public:
	Pickup(){ front = 5; }
	friend Pickup setPickup(Pickup P);
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

Pickup setPickup(Pickup P);
Compact setCompact(Compact C);
Sedan setSedan(Sedan S);
bool Select(passenger *current, Pickup pick[3], Compact comp[3], Sedan sed[3], int reserve);
passenger *Read();
void Reservation(passenger *head);
void Modify(passenger *head, Pickup pick[3], Compact comp[3], Sedan sed[3]);
void Create(passenger *head, Pickup pick[3], Compact comp[3], Sedan sed[3], int reserve);
void Delete(passenger *head, Pickup pick[3], Compact comp[3], Sedan sed[3], int reserve);
void Print(passenger *head, Pickup pick[3], Compact comp[3], Sedan sed[3]);
void Display(Pickup pick[3],Compact comp[3],Sedan sed[3]);

#endif /* SEAT_CREDITS_H_ */
