#include<iostream>
#include<vector>
#include<cstdlib>
#include <thread> 
#include <chrono>
using namespace std ;


struct booksDetels {
    string bookName ;
    string Auther ;
    int ManyPapers ;
    int QRCode ;
    float Price ;

};
void RunCode(int, vector<booksDetels>&);
void RunAllProgram(vector<booksDetels>&);

void waitFor(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void ShowBooks (vector <booksDetels> & BookDe )
{
    for(booksDetels &INFO :BookDe  )
    {
        cout<<"Name   : "<<INFO.bookName<<endl ;
        cout<<"Authle : "<<INFO.Auther<<endl ;
        cout<<"Pages  : "<<INFO.ManyPapers<<endl ;
        cout<<"QR Code: "<<INFO.QRCode<<endl ;
        cout<<"Price  : "<<INFO.Price<<" $ "<<endl ;

        cout<<"\n"<<endl ;
    }

}



int Random(int min,int max)

{
    int number = rand() % (max-min+1) +min  ;
    return number ;
}

void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

void RemoveLastElements(vector <booksDetels> & DELIB)
{
    char Answer = 'y' ;

    while((Answer =='y' || Answer =='Y')&&!DELIB.empty())
        
        {   
            DELIB.pop_back() ;
            
            ShowBooks(DELIB) ;
            
            cout<<endl; 
            
            cout<<"Do you want to Delete the Last Elements Agen : " ;
            cin>>Answer ;

        }
            cin.ignore() ;
            clearScreen() ;
            
}

void ShowSettings(vector <booksDetels> & DELIB)
{
   
    cout<<"\t Choese one option of this options : "<<endl;
    cout<<"1 : Add a Book "<<endl ;
    cout<<"2 : Remove last Book "<<endl ;
    cout<<"3 : Desplay all Books with Details "<<endl ;
    cout<<"4 : Remove all Books at Library "<<endl ;
    cout<<"5 : chick Library is Empty  "<<endl ;
    
    cout<<"\n6 : Exit "<<endl ;

       
}

void AddBook(vector <booksDetels> & BookDe )
{
   booksDetels SinglBook ;
    char countenuAnswer ='y';
    while(countenuAnswer =='Y'||countenuAnswer =='y')
    {
        cin.ignore() ;
        cout<<"Enter book Name :"<<endl ;
            getline(cin,SinglBook.bookName) ;

        cout<<"\nEnter Auther Name :"<<endl ;
            getline(cin,SinglBook.Auther) ;

        cout<<"How Many Pages at "<<SinglBook.bookName<<endl ;
            cin>>SinglBook.ManyPapers ;
        
        cout<<"How Much one copy of "<<SinglBook.bookName<<endl ;
            cin>>SinglBook.Price ;

        SinglBook.QRCode =Random(1000,1999) ;

    BookDe.push_back(SinglBook) ;

            cout<<"Do you want to countenue Y:N " ;
                cin>>countenuAnswer ;

    }
    
                
}

void isLibraryEmptey(vector <booksDetels> & BookDe)
{
   
   if(BookDe.empty())
   {
   char AddBooksAns ='n' ;
    cout<<"Yes its Empty"<<endl ;
    cout<<"Do you Want to Add Books Y:N"<<endl ;
    
    cin>>AddBooksAns ;
    cin.ignore() ;
        if(AddBooksAns == 'Y'||AddBooksAns == 'y')
            AddBook(BookDe) ;
   }

    else
    {
        cout<<"\n No its not Empty \n" ;
    }
}

void clearAllLibrary(vector <booksDetels> & BookDe)
{
    char Ans ='y' ;
    cout<<"are you sure ...  Y/N : ";
    cin>>Ans ;
    

    if(Ans =='y' || Ans == 'Y')
    {
        BookDe.clear() ;
    }
}

void RunCode(int UserCho,vector <booksDetels> & BookDe)
{
    switch (UserCho)
    {
    case 1:
        AddBook(BookDe) ;
        break;
    case 2:
        RemoveLastElements(BookDe) ;
        break;
    case 3 :
        ShowBooks(BookDe) ;
        waitFor(1500) ;
        break;
    case 4 :
        clearAllLibrary(BookDe) ;
        break;
    case 5 :
        isLibraryEmptey(BookDe) ;
    default:
        break;
    }
}

void RunAllProgram(vector <booksDetels> & BookDe)
{

  
     int UserChoese ;

    do
    {
         clearScreen() ;
        ShowSettings(BookDe) ;


     cout<<"\n\nEnter Your Choses " ;
            cin>>UserChoese;
                cout<<"\n" ;
            RunCode(UserChoese,BookDe) ;

        cin.ignore() ;
    } while(UserChoese<6&&UserChoese>0) ;
    
}


int main() {
    srand((unsigned)time(NULL)) ;
    vector <booksDetels> Library ;
  RunAllProgram(Library) ;
    }