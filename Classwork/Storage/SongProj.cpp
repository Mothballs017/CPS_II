#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>			// needed for file I/O
#include <cstdlib>			// needed for exit()

using namespace std;

struct song
{
	string name;
	string artist;
	int rank;
	int year;
	int decade;
	char performer;
	int genre;
	song *nextaddr;
};

struct playlist
{
	string name;
	song *item;
	playlist *nextaddr;
};


int list;
playlist list_name[5];

void Display(playlist *head, string plname);

song *Read();

int getCount(playlist *head){
    if (head == NULL)
        return 0;
    return getCount(head->nextaddr)+1;
}

playlist *Modify(string plname,int list, playlist *head[] );

playlist *Delete(string plname,int list, playlist *head[] );

void Create(song *songhead, int list, playlist *list_name[]){
	/*
	 * Inputs: list size, playlists array, songs *head
	 */
	char select;
	const int PLAYLIST_SIZE=200;
	if(list >= 5){
		cout << "Maximum number of playlists in library. Upgrade to premium for additional storage." << endl;
	}
	else{
		int position; char checker;
		playlist *current=new playlist,*head,*next=new playlist;
		song *tmpcurrent=songhead;
		cout << "New Playlist: \nEnter Playlist name: ";
		getline(cin,current->name);
		head=current;
		current->nextaddr=NULL;
		list_name[list]=head;
		do{
			bool first=true,valid_genre=false;
			cout << "Choose Playlist entry-maker: \n  (R)anking     (D)ecade     (P)erformer     (G)enre     (M)ulti-Entry\nEntry: ";
			cin >> select; cin.ignore();
			switch(select){
			case 'r':
			case 'R':cout << "Enter song ranking: ";
					cin >> position; cin.ignore();
					if(position>PLAYLIST_SIZE){
						cout << "Song ranking not valid. Reselect entry-maker" << endl;
						break;
					}
					while(true){
						if(tmpcurrent->rank == position){
							if(getCount(head)==1){
								current->item=tmpcurrent;
								current->nextaddr=NULL;
							}
							else{
								current->nextaddr=next;
								next->item=tmpcurrent;
								next->nextaddr=NULL;
							}
							break;
							select=' ';
						}
						tmpcurrent=tmpcurrent->nextaddr;
					}
					select=' ';
					break;
			case 'd':
			case 'D':cout << "Enter song decade: ";
					cin >> position; //cin.ignore();
					if(position == 50 || position == 60 || position == 70 || position == 80
							 || position == 90 || position == 00 || position == 10){
						tmpcurrent=songhead;
						for(int i=0; i<PLAYLIST_SIZE; i++){
							if(tmpcurrent->decade==position){
								if(current->nextaddr==NULL && first){
									current->item=tmpcurrent;
									current->nextaddr=NULL;
									first=!first;
								}
								else{
									current=head;
									playlist *next=new playlist;
									next->item=tmpcurrent;
									while(current->nextaddr != NULL)
										current=current->nextaddr;
									current->nextaddr=next;
									next->nextaddr=NULL;
								}
							}
							tmpcurrent=tmpcurrent->nextaddr;
						}
					}
					else{
						cout << "Decade not valid. Reselect entry-maker" << endl;
						break;
					}
					select=' ';
					cin.ignore();
					break;
			case 'p':
			case 'P':cout << "Enter performer type: ";
					cin >> checker; cin.ignore();
					if(checker == 'F' || checker =='M' || checker =='G'){
						tmpcurrent=songhead;
						for(int i=0; i<PLAYLIST_SIZE; i++){
							if(tmpcurrent->performer==checker){
								if(current->nextaddr==NULL && first){
									current->item=tmpcurrent;
									current->nextaddr=NULL;
									first=!first;
								}
								else{
									current=head;
									playlist *next=new playlist;
									next->item=tmpcurrent;
									while(current->nextaddr != NULL)
										current=current->nextaddr;
									current->nextaddr=next;
									next->nextaddr=NULL;
								}
							}
							tmpcurrent=tmpcurrent->nextaddr;
						}
					}
					else{
						cout << "Performer not valid. Reselect entry-maker" << endl;
						break;
					}
					select=' ';
				break;
			case 'g':
			case 'G':cout << "|1| Latin\n|2| Country\n|3| Hip-Hop/Rap\n|4| Jazz\n|5| Dance/Electronic\n|6| R&B\n|7| Pop\n|8| Rock\n";
					cout << "Select " << head->name << " genre : ";
					cin >> position; cin.ignore();
					for(int i=1;i<9;i++){
						if(i==position)
							valid_genre=true;
					}
					if(valid_genre != true){
						cout << "Genre not valid. Reselect entry-maker" << endl;
						break;
					}
					tmpcurrent=songhead;
					for(int i=0; i<PLAYLIST_SIZE; i++){
						if(tmpcurrent->genre==position){
							if(current->nextaddr==NULL && first){
								current->item=tmpcurrent;
								current->nextaddr=NULL;
								first=!first;
							}
							else{
								current=head;
								playlist *next=new playlist;
								next->item=tmpcurrent;
								while(current->nextaddr != NULL)
									current=current->nextaddr;
								current->nextaddr=next;
								next->nextaddr=NULL;
							}
						}
						tmpcurrent=tmpcurrent->nextaddr;
					}
					select=' ';
				break;
			case 'm':
			case 'M': int decade, genre; char performer;
					cout << "Enter Song Decade: ";
					cin >> decade;
					if(decade == 50 || decade == 60 || decade == 70 || decade == 80
							|| decade == 90 || decade == 00 || decade == 10){
						cout << "Enter Song Performer Type: ";
						cin >> performer; cin.ignore();
						if(performer == 'F' || performer =='M' || performer =='G'){
							cout << "|1| Latin\n|2| Country\n|3| Hip-Hop/Rap\n|4| Jazz\n"
									"|5| Dance/Electronic\n|6| R&B\n|7| Pop\n|8| Rock\n";
							cout << "Select " << head->name << " genre : ";
							cin >> genre; cin.ignore();
							for(int i=1;i<9;i++){
								if(i==genre)
									valid_genre=true;
							}
							if(valid_genre != true){
								cout << "Genre not valid. Reselect entry-maker" << endl;
								break;
							}
							tmpcurrent=songhead;
							for(int i=0; i<PLAYLIST_SIZE; i++){
								if(tmpcurrent->performer==performer &&
									tmpcurrent->decade==decade && tmpcurrent->genre==genre){
									if(current->nextaddr==NULL && first){
										current->item=tmpcurrent;
										current->nextaddr=NULL;
										first=!first;
									}
									else{
										current=head;
										playlist *next=new playlist;
										next->item=tmpcurrent;
										while(current->nextaddr != NULL)
											current=current->nextaddr;
										current->nextaddr=next;
										next->nextaddr=NULL;
									}
								}
								tmpcurrent=tmpcurrent->nextaddr;
							}
						}
						else{
							cout << "Performer not valid. Reselect entry-maker" << endl;
							break;
						}
					}
					else{
						cout << "Decade not valid. Reselect entry-maker" << endl;
						break;
					}
					select=' ';
				break;
			}
		}while(select == 'R' || select == 'r'
				|| select == 'D' || select == 'd'
				|| select == 'P' || select == 'p'
				|| select == 'G' || select == 'g');
	}
}

playlist *Modify(string plname, int list, playlist *head[]){
	bool check = false;

	playlist *current,*previous,*tmphead;
	char userchoice;
	int n, m;

	for(int i=0;i<list;i++)
		if(head[i]->name==plname){
			current=head[i];
			tmphead=current;
			check=true;
		}

	if(check){
		while(check)
			{
				cout << "Insert (I) or Delete (D): "; cin >> userchoice;

				switch(userchoice)
				{
				case 'I':
					cout << "Enter the Rank of the song you would like added to the playlist: "; cin >>n;
					cout << "Enter the position you would like the song placed: "; cin >> m;

					for (int i=1; i<m; i++)
					{
						previous = current;
						current = current->nextaddr;
					}
					current->item->rank = m;
					break;
				case 'D':
					cout << "Enter the position of the song you would like deleted: "; cin >>n;

					if (n==1)
					{
						tmphead = current->nextaddr;
					}
					else
					{
						for (int i=1; i<n; i++)
						{
							previous = current;
							current = current->nextaddr;
						}
						previous->nextaddr = current->nextaddr;
					}
					delete(current);
					break;
				}
			}
		return(tmphead);
	}
	else{
		cout << "Name does not match available playlists"<<endl;
		return(NULL);
	}
}

playlist *Delete(string plname, int list, playlist *head[]){

	playlist *current, *previous,*tmphead;
	bool check = false;
	for(int i=0;i<list;i++)
		if(head[i]->name==plname){
			current=head[i];
			tmphead=current;
			check=true;
		}
	if(check){
		while(check){
			previous = current->nextaddr;
			delete(current);
			current = previous;
		}
		return(tmphead);
	}
	else{
		cout << "Name does not match available playlists"<<endl;
		return(NULL);
	}
}

void Save(playlist *head, string plname, string fname);

int main(){

	int list;
	playlist *list_name[5];
//	song TestSongA = {"THE TWIST", "Chubby Checker", 1, 1960, 60, 'M', 6, NULL};
//	playlist testplaylistA = {"Test Playlist #1",{"THE TWIST", "Chubby Checker", 1, 1960, 60, 'M', 6, NULL},NULL};

	//playlist testplaylistB = {"Test Playlist #2", "SMOOTH", "Santana Featuring Rob Thomas", 2, 1999, 'G', 8 };


	song *main_head;
//	playlist *playlistmain_head;

	main_head = Read();
	list=0;
	Create(main_head, list,list_name);
	list=1;
	Create(main_head, list,list_name);
	string playlistname, filename;

//cout << list_name[0]->item->name << endl;
//cout << list_name[0]->nextaddr->item->name << endl;
	cout << "enter playlist name: \n";
	getline(cin,playlistname);
//
//	cout << "enter file name: "; cin >> filename;
//
//
//
//	//Save(main_head, filename);
//
	Display(list_name[0], playlistname);

}

song *Read(){
	ifstream inFile;

	inFile.open("billboard.txt");

	if (inFile.fail())
	{
		cout << "\nThe file did not successfully open... Program Terminated\n" << endl;
		exit (1);
	}

	song *current, *head;

	current = new song;
	head = current;

	do
	{
		getline(inFile, current->name);
		getline(inFile, current->artist);
		inFile >> current->rank; inFile.ignore();
		inFile >> current->year; inFile.ignore();
		inFile >> current->decade;inFile.ignore();
		inFile >> current->performer; inFile.ignore();
		inFile >> current->genre; inFile.ignore();

		if (inFile.eof())
		{
			current->nextaddr = NULL;
			break;
		}
		else
		{
			current->nextaddr = new song;
			current = current->nextaddr;
		}

	}
	while(true);

	inFile.close();

	return(head);
}

void Display(playlist *head, string plname){
	playlist *current = head;
	if (plname==current->name){
		cout << plname<< ":\n____________________________________\n";
		if(current==NULL)
			cout<<"Playlist empty"<<endl;
		else
			while(current != NULL){
				cout << "Song: "<< current->item->name << endl;
				cout << "Artist: " << current->item->artist<< endl;
				cout << "Billboard Ranking (#): " << current->item->rank<< endl;
				cout << "Year of Release: " << current->item->year << endl;
				cout << "Song Decade: " << current->item->decade<< endl;
				cout << "Song Performer: " << current->item->performer<< endl;
				cout << "Song Genre (#): " << current->item->genre << endl;
				cout << "------------------------------------\n";

				current = current->nextaddr;
			}
	}
	else{
		cout << "Playlist name not found" << endl;
	}
}

void Save(playlist *head[], string name, int list) {

	playlist *current;
	name += ".txt";
	bool valid_name=false;
	for(int i=0;i<list;i++){
		if(head[i]->name==name){
			current=head[i];
			valid_name=true;
		}
	}
	if(valid_name){
		ofstream outFile;
		outFile.open(name);
		if(current==NULL)
			outFile<<"Playlist empty"<<endl;
		else{
			outFile << current->name << ":\n____________________________________\n";
			while (current->nextaddr != NULL)
			{
				outFile<< "Song: "<< current->item->name << endl;
				outFile<< "Artist: " << current->item->artist << endl;
				outFile<< "Billboard Ranking (#): " << current->item->rank << endl;
				outFile<< "Year of Release: " << current->item->year << endl;
				outFile<< "Song Decade: " << current->item->decade << endl;
				outFile<< "Song Performer: " << current->item->performer << endl;
				outFile<< "Song Genre (#): " << current->item->genre << endl;
				outFile<< "------------------------------------\n";

				current=current->nextaddr;
			}
		}
		outFile.close();
	}
	else cout << "Name does not match available playlists" << endl;
}
