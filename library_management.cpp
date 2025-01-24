#include<iostream>
#include<iomanip>
using namespace std;
const int MAX = 100;
const int MAX_Attempt = 3;
enum UserRole{
	LIBRARIAN = 1,
	CUSTOMER = 2
};
class book{
	private:
		string bookname;
		string author;
		int bookID;
		int copies;
		int price;
	public:
		book():bookname("null"),author("null"),bookID(0),copies(0),price(0){
		}
		
//	Setter Functions
		void setbookname(string a){
			bookname=a;
		}
		void setauthor(string b){
			author=b;
		}
		void setbookID(int c){
			bookID = c;
		}
		void setcopies(int d){
			copies=d;
		}
		void setprice(int e){
			price=e;
		}
		
//	Getter Functions
		string getbookname() const{
			return bookname;
			
		}
		string getauthor() const{
			return author;
		}
		int getbookID() const{
			return bookID;
		}
		int getcopies() const{
			return copies;
		}
		int getprice() const{
			return price;
		}
		
//	INPUT by USER

		void setdata(){
			string a;
			string b;
			int c;
			int d;
			int e;
			cout<<"Enter the book name : ";
			cin>>a;
			cout<<"Enter the author name :";
			cin>>b;
			cout<<"Enter the ID of book :";
			cin>>c;
			cout<<"Enter the Copies of Book : ";
			cin>>d;
			cout<<"Enter the price of the Book : ";
			cin>>e;
			
			setbookname(a);
			setauthor(b);
			setbookID(c);
			setcopies(d);
			setprice(e);
		}
		


		void displaybook(){
        cout << " " << setw(11) << left << getbookID()
             << setw(22) << left << getbookname()
             << setw(22) << left << getauthor()
             << setw(18) << left << getcopies()
             << setw(14) << left << getprice() << "\n";
		}
};
class customer{
	private:
		string name;
		int age;
		string number;
	public:
		customer():name("null"),age(0),number("null"){
		}
		void setName(string a){
			name = a;
		}
		void setAge(int b){
			age = b;
		}
		void setNumber(string c){
			number = c;
		}
		void setdataCustomer(){
			string nam;
			int ag;
			string num;
			cout<<"Enter the name of the customer :";
			
			cin.ignore();
			getline(cin,nam);
			cout<<"Enter the age of the customer : ";
			cin>>ag;
			cout<<"Enter the number of the customer :";
			cin>>num;
			setName(nam);
			setAge(ag);
			setNumber(num);
		}
		string getname(){
			return name;
		}
		int getage(){
			return age;
		}
		string getnumber(){
			return number;
		}
		void customerdetails(){
			 cout<<" " << setw(22) << left << getname()
             << setw(15) << left << getage()
             << setw(22) << left << getnumber()
             << "\n";
		}
};
class bookInventory{
	protected:
		book books[MAX];
		int numbook;
	public:
		bookInventory():numbook(0){}
		// add book function
		void addbook(){
			if(numbook<MAX){
				book* b = new book;			
				b->setdata();
				bool isid = false;
				for(int i=0; i<numbook; i++){
					if(b->getbookID()==books[i].getbookID()){
						isid = true;
					}
				}
				if(isid){
					cout<<"\n\tCannot add the book by the same id"<<endl;
				}
				if(!isid){
				books[numbook++]=*b;
				cout<<"\n\tbook are added successfully"<<endl;
				delete b;
			}
	 	}
			else{
				cout<<"\n\tBook Inventory is Full"<<endl;
			}
			
			}
		// remove book function
			void removebook(){
			if(numbook>0){
				int id;
				bool found = false;
				int index;
				cout<<"Enter the Book Id to be removed :";
				cin>>id;
				for(int i=0; i<numbook; i++){
					if(books[i].getbookID()==id){
						found = true;
						index = i;
					}
				}
				if(!found){
					cout<<"NO! BOOK FOUND"<<endl;
				}else{
					for(int i = index; i<numbook-1; i++){
					books[index]=books[index+1];
				}
					numbook--;
					cout<<"\n\tBook Removed Successfully"<<endl;
				}
			}
			else{
				cout<<"\n\tNO RECORD FOUND!"<<endl;
			}
		}
		//update book function
		void updatebook(){
				if(numbook>0){
				int id;
				bool found=false;
				int index;
				cout<<"Enter the book id to be updated :";
				cin>>id;
				for(int i=0; i<numbook; i++){
					if(books[i].getbookID()==id){
						found = true;
						index = i;
					}
				}
				if(!found){
					cout<<"no book found"<<endl;
				}
				else{
					int choice;
					cout<<"\n Book found. choose what to update"<<endl;
					cout<<"\n1. Update All Information"<<endl;
					cout<<"\n2. Update Price only"<<endl;
					cin>>choice;
					switch(choice){
						case 1:
							system("cls");
							cout<<"\nEnter the new detail of the book"<<endl;
							books[index].setdata();
							cout<<"\t\n Book Data is Updated"<<endl;
							system("pause");
							break;
						case 2:
							int newprice;
							cout<<"\nEnter the new price : ";
							cin>>newprice;
							books[index].setprice(newprice);
							cout<<"\t\n Price is Updated"<<endl;
							break;
						default:
							cout<<"\t\nInvalid choice"<<endl;
					}
			}
		}
			else{
				cout<<"NO! RECORD FOUND"<<endl;
			}
		}
		// show all book function
		void showall(){
			if(numbook>0){
			cout << "==========================================================================================\n";
    		cout << "BOOK ID     BOOK NAME             AUTHOR NAME           NO. OF COPIES     PRICE " << endl;
    		cout << "==========================================================================================\n";
				for(int i=0; i<numbook; i++){
					books[i].displaybook();
				}
			}else{
				cout<<"NO! RECORD FOUND"<<endl;
			}
		}
		int getTotalboook(){
			return numbook;
		}
};
class customerInventory : public bookInventory{
	private:
		customer customers[MAX];
		int numborrow;
		int totalcustomer;
		book borrows[MAX];
	public:
		customerInventory():numborrow(0),totalcustomer(0){
		}
		// borrow book function
		void bookborrow(){
			if(numbook>0){
			int id;
			int index;
			cout<<"Enter the ID of the book to be borrow :";
			cin>>id;
			bool found = false;
			for(int i=0; i<numbook; i++){
			if(id==books[i].getbookID()){
				found = true;
				index = i;
				cout<<"\t\nHere is the detail of the Book"<<endl;
				cout<<"Book ID : "<<books[i].getbookID()<<endl;
				cout<<"Book Name : "<<books[i].getbookname()<<endl;
				cout<<"\t\n\nEnter Your Detail "<<endl;
				break;
			}
		}
				if(found){
					if(numborrow<MAX){
						customer* c = new customer;
						c->setdataCustomer();
						customers[totalcustomer++] = *c;
				}else{
					cout<<"\t\nborrow List is full"<<endl;
				}	
			}	
			if(found){
					if(id==books[index].getbookID() && books[index].getcopies()>1){
						borrows[numborrow++] = books[index];
						books[index].setcopies(books[index].getcopies()-1);
						cout<<"\t\nOne of the copy of book borrow successfully "<<endl;
					}else{
						borrows[numborrow++] = books[index];
						books[index] = books[index+1];
						numbook--;
						cout<<"\t\nbook borrow successfully"<<endl;
					}
				}
			if(!found){
				cout<<"\nThis ID Book is not in the inventory, Enter the valid ID"<<endl;
			}
	   	}else{
	   		cout<<"\t\nInventory is empty"<<endl;
		   }
	}
	
		// buy book function
	  	void buybook(){
	  		if(numbook>0){
	  		int id;
	  		int index;
	  		cout<<"Enter the id of the book to be buy :";
	  		cin>>id;
	  		bool found = false;
	  		for(int i=0; i<numbook; i++){
	  			if(id==books[i].getbookID()){
	  				found = true ;
	  				index = i;
	  				cout<<"\t\nHere is the detail of the Book"<<endl;
	  				cout<<"\n";
					cout<<"Book ID : "<<books[i].getbookID()<<endl;
					cout<<"Book Name : "<<books[i].getbookname()<<endl;
					cout<<"Author :"<<books[i].getauthor()<<endl;
					cout<<"Price :"<<books[i].getprice()<<endl;
					cout<<"\n";
					break;
				}
			}
					if(found){
						if(books[index].getcopies() > 1){
							books[index].setcopies(books[index].getcopies()-1);
							cout<<"\t\nOne of the Copy is bought Successfully"<<endl;
						}else{
	  						books[index] = books[index+1];
	  						numbook--;
	  						cout<<"\t\nbook buy successfully"<<endl;
	  					}
	  				}
			if(!found){
				cout<<"No book found by this ID"<<endl;
		}
	}else{
		cout<<"Inventory is empty"<<endl;
	}
}

		int getnumborrow(){
			return numborrow;
		}
		
		// return function
		
		// return book function
		void returnbook(){
			if(numborrow>0){
				int id;
				cout<<"Enter the id of the book to be returned "<<endl;
				cin>>id;
//				int index;
				bool found = false;
				for(int i =0; i<numborrow; i++){
					if(id==borrows[i].getbookID()){
						found = true;
//						index = i;
						cout<<"\t\nID found"<<endl;
					}
				}
					if(found){
						for(int i=0; i<numborrow; i++){
							for(int j =0; j<numbook; j++){
								if(borrows[i].getcopies()>1){
									if(books[j].getbookID()==borrows[i].getbookID()){
										books[j].setcopies(books[j].getcopies()+1);
										borrows[i] = borrows[i+1];
										numborrow--;
										cout<<"One copy of book Return successfully"<<endl;
										break;
							}
						}
						else{
							books[numbook++] = borrows[i];
							borrows[i] = borrows[i+1];
							numborrow--;
							cout<<"book return successfully"<<endl;
					}
				}
			}
		}
						
//						cout<<"Book Return Successfully"<<endl;
				if(!found){
						cout<<"No book borrow by this ID"<<endl;
					}
			}else{
				cout<<"No borrow book"<<endl;
			}
		}
		
		// all customer detial function
		void ShowAllCustomer(){
			if(numborrow>0){
		    cout << "==========================================================================================\n";
    		cout << "NO.     NAME           AGE                NUMBER                " << endl;
    		cout << "==========================================================================================\n";
					for(int j=0; j<numborrow; j++){
						cout<<j+1<<".";
						customers[j].customerdetails();
						cout<<"\n\tBook Borrow by this Customer "<<endl;
						cout<<"BOOK NAME :"<<borrows[j].getbookname()<<endl;
						cout<<"AUHTOR :"<<borrows[j].getauthor()<<endl;
						cout<<"PRICE :"<<borrows[j].getprice()<<endl;
						cout<<"------------------------------------------------------------------------"<<endl;
				}	
			}
			else{
				cout<<"NO! RECORD FOUND	"<<endl;
			}
		}
		
		
};
class library : public customerInventory{
	public:
		//librarian function
		void librarian(){
			system("cls");
			int choice2;
			do{
				system("cls");
			cout<<"============================================================="<<endl;
			cout<<"\t\t WELCOME LIBRARIAN"<<endl;
			cout<<"============================================================="<<endl;

			cout<<"Enter the choices \n"<<endl;
			cout<<"1. ADD BOOK \n"<<endl;
			cout<<"2. REMOVE BOOK \n"<<endl;
			cout<<"3. UPDATE BOOK \n"<<endl;
			cout<<"4. SHOW ALL BOOKS \n"<<endl;
			cout<<"5. SHOW CUSTOMER DETAILS \n"<<endl;
			cout<<"6. BACK TO MAIN\n"<<endl;
			cout<<"7. EXIT"<<endl;
			cin>>choice2;
			char ch;
			switch(choice2){
				case 1:
					ch = 'y';
    				while (ch == 'y' || ch == 'Y') {
        				system("cls");
     				    cout << "\t\t --------ADD BOOK--------\n" << endl;
        				cout << "\t ENTER THE BOOK DETAILS" << endl;
        				bookInventory::addbook();
        				cout << "Do you want to add another book? (y/n): ";
        				cin >> ch;
						if (ch != 'y' && ch != 'Y') {
            			cout << "\tNO MORE BOOKS WANTED TO ADD. BACKING......\n";
        				}
    				}
					cout << "Exiting...\n";
					system("pause");
					break;
				case 2:
					ch = 'y';
					
					while(ch=='y'||ch=='Y'){
					system("cls");
					cout<<"\t\t ---------REMOVE BOOK---------\n"<<endl;
					bookInventory::removebook();
					cout<<" Do you want to remove more book? (y/n): ";
					cin>>ch;
					if(ch != 'y'&& ch != 'Y'){
						cout<<"No more book wanted to removed \n ";
					}
				}
					cout<<"Exiting.....\n";
					system("pause");
					break;
				case 3:
					system("cls");
					cout<<"\t\t ---------UPDATE BOOK----------\n"<<endl;
					bookInventory::updatebook();
					system("pause");
					break;
				case 4:
					system("cls");
					cout<<"\t\t -------ALL BOOKS------\n"<<endl;
					bookInventory::showall();
					cout<<"\nTotal number of books in the inventory is : ";
					cout<<bookInventory::getTotalboook();
					cout<<"\n";
					cout<<"\nTotal numbers of books borrowed :";
					cout<<customerInventory::getnumborrow();
					cout<<"\n";
					system("pause");
					break;
				case 5:
					system("cls");
					cout<<"\t\t -------CUSTOMER DETAILS--------"<<endl;
					customerInventory::ShowAllCustomer();
					
					system("pause");
					break;
				case 6:
					system("cls");
					mainpanel();
					break;
				case 7:
					system("cls");
					cout<<"\n\n\n"<<endl;
					cout<<"\t\t THANKS FOR USING OUR SYSTEM"<<endl;
					cout<<"\t\t HAVE A NICE DAY \3 \n\n";
					exit(0);
					break;
				default:
					cout<<"Enter the valid choice"<<endl;
			}
		}while(choice2!=7);
	}
	
			// customer function
			void customer(){
				system("cls");
				int choice3;
				do{
					system("cls");
				cout<<"----------------------------------------------------------"<<endl;
				cout<<"\t\t WELCOME "<<endl;
				cout<<"----------------------------------------------------------"<<endl;
				cout<<"1. show all books \n"<<endl;
				cout<<"2. BUY BOOK \n"<<endl;
				cout<<"3. BORROW BOOK \n"<<endl;
				cout<<"4. RETURN BOOK \n"<<endl;
				cout<<"5. BACK TO MAIN\n"<<endl;
				cout<<"6. EXIT \n"<<endl;
				cout<<"ENTER THE CHOICE : "<<endl;
				cin>>choice3;
				switch(choice3){
					case 1:
						system("cls");
						cout<<"\t\t -------ALL BOOKS--------\n"<<endl;
						bookInventory::showall();
						cout<<"\nTotal number of books in the inventory is : ";
						cout<<bookInventory::getTotalboook();
						cout<<"\n";
						cout<<"\nTotal numbers of books borrowed :";
						cout<<customerInventory::getnumborrow();
						cout<<"\n";
						system("pause");
						break;
					case 2:
						system("cls");
						cout<<"\t\t -------BUY BOOK--------\n"<<endl;
						customerInventory::buybook();
						
						system("pause");
						break;
					case 3:
						system("cls");
						cout<<"\t\t -------BORROW BOOK--------\n "<<endl;
						customerInventory::bookborrow();
						system("pause");
						break;
					case 4:
						system("cls");
						cout<<"\t\t-----RETURN BOOK---------\n"<<endl;
						customerInventory::returnbook();
						
						system("pause");
						break;
					case 5:
						system("cls");
						mainpanel();
						break;
					case 6:
						system("cls");
						cout<<"\n\n\n"<<endl;
						cout<<"\t\t THANKS FOR USING OUR SYSTEM"<<endl;
						cout<<"\t\t HAVE A NICE DAY \3 \n\n";
						exit(0);
						break;
					default:
						cout<<"ENTER THE VALID CHOICE"<<endl;
				}
			}while(choice3!=5);
		}
		
			//main panel funciton
			void mainpanel(){
			system("cls");
			cout<<"\t\t-------------------------------------------------------------------------"<<endl;
			cout<<"\t\t|";
			cout<<"\t\t\t\tBOOK HUB";
			cout<<"\t\t\t\t|"<<endl;
			cout<<"\t\t-------------------------------------------------------------------------"<<endl;
			int loginAttempt = 0;
			string username, password;
			int choice1;
			cout<<"\n\t\tEnter your choice between "<<LIBRARIAN<<" or "<<CUSTOMER<<".\n"<<endl;
			cout<<"\t\t1. LIBRARIAN \n"<<endl;
			cout<<"\t\t2. CUSTOMER \n"<<endl;
			cout<<"\tINPUT :"<<" ";
			cin>>choice1;
			switch(choice1){
				
			case LIBRARIAN:
				
				system("cls");
				cout<<"\t\t ENTER YOUR LOGIN \n"<<endl;
				while(loginAttempt<MAX_Attempt){
				cout<<"Enter your username : ";
				cin>>username;
				cout<<"Enter password : ";
				cin>>password;
					if(username=="admin"&&password=="1234"){
						cout<<"Login Successfull.....";
						librarian();
		    		}
	    			else{
	    				loginAttempt++;
						cout<<"\n invalid username and password. Attempts left "<<MAX_Attempt-loginAttempt<<endl;
	    			}
	    		}
				if(loginAttempt==MAX_Attempt){
					cout<<"Max login attempt reached "<<endl;
					cout<<"Exiting the program.......";
				}
				break;
				
			case CUSTOMER:
				customer();
				break;
			default:
				cout<<"Enter the valid choice"<<endl;
		}
			}
};

int main(){
	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t WELCOME TO"<<endl;
	cout<<"\t\t\t\t\t  BOOK HUB"<<endl;
	cout<<"\t\t\t\t\t LIBRARY"<<endl;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	library l;
	l.mainpanel();
	return 0;
}
