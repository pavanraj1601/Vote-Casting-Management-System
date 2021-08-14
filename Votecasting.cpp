#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class RE{
	int age,bjp,jds,congress,prajakiya;
	char id[10],name[20],address[20];
	
	public:
	RE()
	{
		
		strcpy(id,"No ID");
		age=0;
		
	}
	void setdata();
	void showdata();
	int storedata();
	void viewalldata();
	void searchdata(char*);
	void deletedata(char*);
	void updatedata(char*);
	void cast_vote(char*);
	void display_result();
	void search();
	void delete1();
};

int menu3();
int menu2();
int menu();
void RE::setdata()
{
	cout<<"Enter the ID :"<<endl;
	cin>>id;
	
	cout<<"Enter the name :"<<endl;
	cin>>name;
	
	
	cout<<"Enter the age  :"<<endl;
	cin>>age;
	
	cout<<"Enter the address :"<<endl;
	cin>>address;
	
}
void RE::showdata() 
{
	cout<<"ID : "<<id<<endl<<"Name : "<<name<<endl<<"Age : "<<age<<endl<<"Address :"<<address;
	 
}
int RE::storedata()
{
	if(id==0&&age==0)
	{
		cout<<"\nData not initailized"<<endl;
		return 0;
		
	}
	else
	{
		ofstream fout;
		fout.open("voterid.txt",ios::app);
		fout.write((char*)this,sizeof(*this));
		fout.close();
	}
	
}
void RE::viewalldata()
{
	ifstream fin;
	fin.open("voterid.txt",ios::in);
	if(!fin)
	{
		cout<<"\nFile not found"<<endl;
		
	}
	else
	{
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			showdata();
			cout<<endl;
			fin.read((char*)this,sizeof(*this));
			
		}
		fin.close();
	}
}
void RE::searchdata(char* t)
{
	int count=0;
	ifstream fin;
	fin.open("voterid.txt",ios::in);
	if(!fin)
	{
		cout<<"\n File not found"<<endl;
		
	}
	else
	{
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(!strcmp(t,this->id))
			{
				showdata();
				count++;
				
			}
			fin.read((char*)this,sizeof(*this));
			
		}
		if(count==0)
		{
			cout<<"Data not found"<<endl;
			
		}
		fin.close();
	}
}
void RE::deletedata(char* t)
{
	ifstream fin;
	ofstream fout;
	fin.open("voterid.txt",ios::in);
	if(!fin)
	{
		cout<<"\nFile not exist"<<endl;
		
	}
	else
	{
		fout.open("Tempo.txt",ios::out);
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(strcmp(id,t))
			{
				fout.write((char*)this,sizeof(*this));
				
			}
			fin.read((char*)this,sizeof(*this));
		}
		fin.close();
		fout.close();
		remove("voterid.txt");
		rename("Tempo.txt","voterid.txt");
	}
	cout<<"delete successful"<<endl;
}
void RE::updatedata(char* t)
{
	fstream file;
	file.open("voterid.txt",ios::in|ios::out|ios::ate);
	file.seekg(0);
	file.read((char*)this,sizeof(*this));
	while(!file.eof())
	{
		if(!strcmp(t,id))
		{
			setdata();
			file.seekp(file.tellp()-sizeof(*this));
			file.write((char*)this,sizeof(*this));
			
		}
		file.read((char*)this,sizeof(*this));
		
	}
	file.close();
	
}
void RE::cast_vote(char*t)
{
	            
	            fstream file;
	   			
		int c=0,party;
		ifstream fin;
		fin.open("voterid.txt",ios::in);
		if(!fin)
		{
		cout<<"\n File not found"<<endl;
		
		}
		else
		{
			fin.read((char*)this,sizeof(*this));
			while(!fin.eof())
			{
				if(!strcmp(t,this->id))
				{
					showdata();
					cout<<"data found"<<endl;
					
				do
				{
				c++;
				cout<<"\n************************************";
				cout<<"\nChoose a Party to cast your Vote!!!";
				cout<<"\n************************************";
				cout<<"\n1-BJP"<<endl;
				cout<<"2-CONGRESS"<<endl;
				cout<<"3-PRAJAKIYA"<<endl;
				cout<<"4-JDS"<<endl;
				cout<<"************************************\n";
				cin>>party;
				}while((party<1 || party>4));
				int count;
				if(party==1)
				{
					file.open("BJP.txt",ios::in);
					file>>count;
					count++;
					file.close();
					file.open("BJP.txt",ios::out);
					file<<count;
					file.close();
				}
				else if(party==2)
				{
					file.open("CONGRESS.txt",ios::in);
					file>>count;
					count++;
					file.close();
					file.open("CONGRESS.txt",ios::out);
					file<<count;
					file.close();
				}
				else if(party==3)
				{
					file.open("PRAJAKIYA.txt",ios::in);
					file>>count;
					count++;
					file.close();
					file.open("PRAJAKIYA.txt",ios::out);
					file<<count;
					file.close();
				}
				else if(party==4)
				{
					file.open("JDS.txt",ios::in|ios::out);
					file>>count;
					count++;
					file.close();
					file.open("JDS.txt",ios::out);
					file<<count;
					file.close();
				}
				cout<<"\nYour vote has been casted successfully :) "<<endl;
				cout<<"\nThank You for casting Vote!!:) "<<endl;
				
				
				
				}
				fin.read((char*)this,sizeof(*this));
				
			
				
}


}

	
}


void RE::display_result()
{
	    fstream file;
	    file.open("BJP.txt",ios::in);
		file>>bjp;
		file.close();
		file.open("CONGRESS.txt",ios::in);
		file>>congress;
		file.close();
		file.open("PRAJAKIYA.txt",ios::in);
		file>>prajakiya;
		file.close();
		file.open("JDS.txt",ios::in);
		file>>jds;
		file.close();
		cout<<"\n=====================================";
		cout<<"\nNumber of votes casted to each party: "<<endl<<endl;
		cout<<"=====================================\n";
		cout<<":-BJP = "<<bjp<<endl;
		cout<<":-CONGRESS = "<<congress<<endl;
		cout<<":-PRAJAKIYA = "<<prajakiya<<endl;
		cout<<":-JDS = "<<jds<<endl;
		
		
	
}
void RE::search()
{
		int ch;
		fstream file;
	 	cout<<"\n\t\t>Select whose result you want to see:\n";
		cout<<"\t\t====================================";
		cout<<"\n\t\t1:BJP"<<endl;
		cout<<"\t\t2:CONGRESS"<<endl;
		cout<<"\t\t3:PRAJAKIYA"<<endl;
		cout<<"\t\t4:JDS"<<endl;
		cout<<"\t\t====================================\n";
		cin>>ch;
		switch(ch)
		{
		
			case 1:file.open("BJP.txt",ios::in);
					file>>bjp;
					file.close();
					cout<<"\n>Number of votes casted to BJP party "<<endl<<endl;
					cout<<":-BJP = "<<bjp<<endl;
		             break;
		       
		       
	    	case 2:file.open("CONGRESS.txt",ios::in);
					file>>congress;
					file.close();
						cout<<"\n>Number of votes casted to CONGRESS party "<<endl;
					cout<<":-CONGRESS = "<<congress<<endl;
		            break;
			   
		   case 3:	file.open("PRAJAKIYA.txt",ios::in);
					file>>prajakiya;
					file.close();
					cout<<"\n>Number of votes casted to PRAJAKIYA party "<<endl<<endl;
					cout<<":-PRAJAKIYA = "<<prajakiya<<endl;
		              break;
		   case 4:	file.open("JDS.txt",ios::in);
					file>>jds;
					file.close();
						cout<<"\n>Number of votes casted to JDS party "<<endl<<endl;
					cout<<":-JDS = "<<jds<<endl;
	         break;
	         
	         
	         default:cout<<"Invalid input"<<endl;
  
	     }
	
}

	
/*void RE:: delete1()
{
	fstream file;
	file.open("BJP.txt",ios::out|ios::trunc);
	file.close();
	file.open("CONGRESS.txt",ios::out|ios::trunc);
	file.close();
	file.open("PRAJAKIYA.txt",ios::out|ios::trunc);
	file.close();
	file.open("JDS.txt",ios::out|ios::trunc);
	file.close();
	cout<<"delete successfull!!"<<endl;
	
	
}	*/


int menu()
{
	mid:
	int choice;
	 cout<<"\n\t=====================================";
	cout<<"\n\t!!!VOTE CASTING MANAGEMENT SYSTEM!!!";
	cout<<"\n\t=====================================";
	cout<<"\n\n\t 1. Add voter-id";
	cout<<"\n\n\t 2. View all voter-id";
	cout<<"\n\n\t 3. Search voter-id";
	cout<<"\n\n\t 4. Delete voter-id";
	cout<<"\n\n\t 5. Update voter-id";
	cout<<"\n\n\t 6. Exit ";
	cout<<"\n\n\t Enter your choice : ";
	cout<<"\n\n=========================================\n";
	cin>>choice;
	RE r1;
	char id1[20];
	while(1)
	{
		system("cls");
		switch(choice)
		{
			case 1:
				r1.setdata();
				r1.storedata();
				cout<<"Stored voter-id..."<<endl;
				goto mid;
				break;
			case 2:
				r1.viewalldata();
				goto mid;
				break;
			case 3:
				cout<<"Enter the voter-id  to search"<<endl;
				cin.ignore();
				cin.getline(id1,19);
				r1.searchdata(id1);
				goto mid;
				break;
			case 4:
				cout<<"Enter the voter-id to delete"<<endl;
				cin.ignore();
				cin.getline(id1,19);
				r1.deletedata(id1);
				goto mid;
				break;
			case 5:
				cout<<"Enter the voter-id for update"<<endl;
				cin.ignore();
				cin.getline(id1,19);
				r1.updatedata(id1);
				goto mid;
				break;
			
			case 6:system("cls");
					menu3();
					break;		 		
				
				default:cout<<"Invalid input"<<endl;
		}			    	
	}
	
}

int menu2()
{
	pack:
	int cat;
	cout<<"\n\t=====================================";
	cout<<"\n\t!!!VOTE CASTING MANAGEMENT SYSTEM!!!";
	cout<<"\n\t=====================================";
	cout<<"\n\n\t 1. Cast your vote";
	cout<<"\n\n\t 2. Display the voting result";
	cout<<"\n\n\t 3. Search Voting result  ";
//	cout<<"\n\n\t 4. Delete Voting result  ";
	cout<<"\n\n\t 4. Exit  ";
	cout<<"\n\n\t Enter your choice : \n";
	cin>>cat;

	RE r1;
	char id1[20];
	while(1)
	{
		system("cls");
		switch(cat)
		{
	        case 1:	cout<<"Enter the voter-id to vote"<<endl;
					cin.ignore();
					cin.getline(id1,19);
					r1.cast_vote(id1);
					goto pack;
					break;
			case 2: r1.display_result();
					goto pack;
			     	break;
			     	
			     	
			case 3: r1.search();
					goto pack;
					break; 
					
					
		/*	case 4: r1.delete1();
					goto pack;
					break; 	*/	    		
					 
			case 4:system("cls");
					menu3();
					break;		 		
				
				default:cout<<"Invalid input"<<endl;
	}	}			    
}
 
 
 int menu3()
 {
 	int item;
	 
	 cout<<"\n\t=====================================";
	cout<<"\n\t!!!VOTE CASTING MANAGEMENT SYSTEM!!!";
	cout<<"\n\t=====================================";
	cout<<"\n\t==============main menu==============";
	cout<<"\n\n\t 1. Admin";
	cout<<"\n\n\t 2. User";
	cout<<"\n\n\t 3. Exit";
	cout<<"\n\n\t Enter your choice : ";
	cin>>item;
	return item;
 }
 main(){

	string username,pass;
	while(1)
	{
		system("cls");
		switch(menu3())
		{
			case 1: {
					    cout<<"\n\t=====================================";
						cout<<"\n\t!!!VOTE CASTING MANAGEMENT SYSTEM!!!";
						cout<<"\n\t=====================================";
						cout<<"\n\tEnter username:"<<endl;
						cin>>username;
						cout<<"\n\t Enter Password:"<<endl;
						cin>>pass;
						if( (username=="admin")&&(pass=="admin")){
						
							 menu();
						}
						else{
							cout<<"invalid password"<<endl;
						}
							
						
						break;
					}
					
					
			case 2:{
						system("cls");
						 menu2();
						break;
					}	
					
			case 3:cout<<"\n Thank You :)"<<endl;
					system("cls");
					exit(0);
					break;		 		
				
				default:cout<<"Invalid input"<<endl;			
		}
	}
}


