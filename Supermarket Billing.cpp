#include<iostream>
#include<fstream>
#include<string>
using namespace std;
 
class shopping
{
    private:
    int productcode;
    float price;
    float discount;
    string productname;

    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void del();
    void list();
    void receipt();
    void usignup();
    void ulogin();
    void feedback();
    void reviews();
};

void shopping::menu()
{
    m:
    int choice;
    string email;
    string password;
    string s;
    int mLength;

    cout<<"\t\t\t________________________________________________________________________"<<endl;
    cout<<"\t\t\t                                                                        "<<endl;
    cout<<"\t\t\t                          Supermarket Main Menu                         "<<endl;
    cout<<"\t\t\t________________________________________________________________________"<<endl;
    cout<<"\t\t\t                                                                        "<<endl;
    cout<<"\t\t  |      1) ADMINISTRATOR       |"<<endl;
    cout<<"\t\t                                 "<<endl;
    cout<<"\t\t  |      2) BUYER               |"<<endl;
    cout<<"\t\t                                 "<<endl;
    cout<<"\t\t  |      3) EXIT                |"<<endl;
    cout<<"\t\t                                 "<<endl;
    cout<<"\t\t\tPlease select: ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<"\t\t\tPlease login!"<<endl;
        cout<<"\t\t\tEnter Email: ";
        cin>>email;
        cout<<"\t\t\tPassword: ";
        cin>>password;
        mLength = email.length();
        s = email.substr(mLength-7, mLength-1);
        if (s == "@bb.com" && (password == "sourav"||password=="utkarsh"))
        {
            administrator();
        }
        else
        {
            cout<<"Invalid Email/Password."<<endl;
        }
        break;

    case 2:
        {
            //buyer();
        }
        break;

    case 3:
        {
            exit(0);
        }
        break;
    
    default:
        {
            cout<<"Please select from the given options!"<<endl;
        }
        break;
    }
    goto m;
}

void shopping::administrator()
{
    m:
    int choice;
    cout<<"\t\t\t\tAdministrator Menu     "<<endl;
    cout<<"\t\t  |      1) ADD THE PRODUCT             |"<<endl;
    cout<<"\t\t                                         "<<endl;
    cout<<"\t\t  |      2) MODIFY THE PRODUCT          |"<<endl;
    cout<<"\t\t                                         "<<endl;
    cout<<"\t\t  |      3) DELETE THE PRODUCT          |"<<endl;
    cout<<"\t\t                                         "<<endl;
    cout<<"\t\t  |      4) BACK TO MAIN MENU           |"<<endl;
    cout<<"\t\t\tPlease select: ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        {
            add();
        }
        break;

    case 2:
        {
            edit();
        }
        break;

    case 3:
        {
            del();
        }
        break;
    
    case 4:
        {
            menu();
        }
        break;
    
    default:
        cout<<"Invalid choice!"<<endl;
        break;
    }
    goto m;
}
/*
void shopping::buyer()
{
    m:
    int choice;
    cout<<"\t\t\t BUYER                         "<<endl;
    cout<<"\t\t  |      1) BUY PRODUCT         |"<<endl;
    cout<<"\t\t                                 "<<endl;
    cout<<"\t\t  |      2) GO BACK             |"<<endl;
    cout<<"\t\t                                 "<<endl;
    cout<<"\t\t\tPlease select: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;
    
    case 2:
        menu();
        break;
    default:
        cout<<"Invalid choice!"<<endl;
        break;
    }
    goto m;
}
*/
void shopping::usignup()
{
  
  fstream data;
  string mn;//mail or no.
  string password;
  string name;
  data.open("user.txt",ios::app);
  cout<<"/t/t Enter Your Name"<<endl;
  getline(cin,name);
  data<<name<<"  ";
  m:
  cout<<"/t/t Enter Email ID/Phone No."<<endl;
  cin>>mn;
  if((mn.length()==10)|| mn.substr(mn.length()-10, mn.length()-1)=="@gmail.com")
  {
    data<<mn<<"  ";
  }
  else{
    cout<<"Wrong Email ID/Phone No."<<endl;
    goto m;
  }
  n:
  cout<<"/t/tEnter Password"<<endl;
  cin>>password;
  if(password.length()>7)
  {
    data<<password<<endl;
  }
  else{
    cout<<"Password length must be greater than 8"<<endl;
    goto n;
  }
  data.close();
  
}
void shopping::ulogin()
{
  m:
  fstream data;
  string mn;//mail or no.
  string mno;
  string p;
  string password;
  string name;
  int token=0;
  data.open("user.txt",ios::out);
  cout<<"/t/t Enter Email ID/Phone No."<<endl;
  cin>>mno;
  cout<<"/t/tEnter Password"<<endl;
  cin>>p;
  data>>name>>mn>>password;
  while(!data.eof())
  {
    if((mn==mno)&& password==p)
    {
      token++;
    }
    data>>name>>mn>>password;
  }
  if(token==0)
  {
    cout<<"/t/tWrong Email ID/Password!!"<<endl;
    int choice;
    cout<<"/t/t 1) Try Again!"<<endl;
    cout<<"/t/t 2) Buy as Normal User"<<endl;
    cin>>choice;
    switch(choice)
    {
      case 1:
        {
          goto m;
        }
        case 2:
          {
           // buyer();
          }
    }
  }
  data.close();
}
void shopping:: feedback()
{
  fstream data;
  int rating;
  string feedback;
  data.open("feedback.txt",ios::app|ios::in);
  data<<5;
  data<<""<<endl;
  data<<5;
  data<<""<<endl;
  data<<3;
  data<<""<<endl;
  data<<4;
  data<<""<<endl;
  data<<2;
  data<<""<<endl;
  
  cout<<"\t\t Rate Us(1-5):        "<<endl;
  cin>>rating;
  data<<rating;
  cout<<"\t\t Please Give your Valuable feedback"<<endl;
  getline(cin, feedback);
  data<<feedback<<endl;
  data.close();
}
void shopping:: reviews()
{
  fstream data;
  int rating;
  string feedback;
  data.open("feedback.txt",ios::out);
  data>>rating>>feedback;
  while(!data.eof())
  {
    if(rating==5)
    {
      cout<<"/t/t "<<rating<<"    "<<feedback<<endl;
    }
    data>>rating>>feedback;
  }
  cout<<endl<<endl;
  while(!data.eof())
  {
    if(rating==4)
    {
      cout<<"/t/t "<<rating<<"    "<<feedback<<endl;
    }
    data>>rating>>feedback;
  }
  while(!data.eof())
  {
    if(rating==3)
    {
      cout<<"/t/t "<<rating<<"    "<<feedback<<endl;
    }
    data>>rating>>feedback;
  }
  while(!data.eof())
  {
    if(rating==2)
    {
      cout<<"/t/t "<<rating<<"    "<<feedback<<endl;
    }
    data>>rating>>feedback;
  }
  while(!data.eof())
  {
    if(rating==1)
    {
      cout<<"/t/t "<<rating<<"    "<<feedback<<endl;
    }
    data>>rating>>feedback;
  }
  data.close();
}
void shopping::add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\t\tAdd New Product        "<<endl;
    cout<<"\t\tProduct Code Of The Product"<<endl;
    cin>>productcode;
    cout<<"\t\tName Of The Product     "<<endl;
    cin>>productname;
    cout<<"\t\tPrice Of The Product     "<<endl;
    cin>>price;
    cout<<"\t\tDiscount On Product      "<<endl;
    cin>>discount;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << productcode <<" "<< productname <<" "<< price <<" "<< discount<<"\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == productcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
        if (token == 1)
        {
            cout<<"\t\t\t========Product Already Exist=============="<<endl;
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << productcode <<" "<< productname <<" "<< price <<" "<< discount<<"\n";
            data.close();
        }
    }
    
    cout<<"\t\t\t===============Record Inserted=================="<<endl;
}

void shopping::edit()
{
    fstream data, data1;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    int pcode;
    cout<<"\t\t\t==============Product Code========================"<<endl;
    cin>>pcode;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout<<"\t\t\t------------File Doesn't Exist------------------"<<endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                cout<<"\t\t\t Enter New Product Code:-";
                cin>>c;
                cout<<"\t\t\t Enter Name Of The Product:-";
                cin>>n;
                cout<<"\t\t\t Enter Price Of The Product:-";
                cin>>p;
                cout<<"\t\t\t Enter Discount Of The Product:-";
                cin>>d;
                data1<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
                cout<<"\t\t\t=============Records Edited!================"<<endl;
                token++;
            }
            else
            {
                data1<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        data1.close();
        if (token == 0)
        {
            cout<<"\t\t\t=========== Record Not Found! ======================"<<endl;
        }
        remove("database.txt");
        rename("database1.txt", "database.txt");
    }
}

void shopping::del()
{
    fstream data, data1;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    int pcode;
    cout<<"\t\t\t==============Product Code========================"<<endl;
    cin>>pcode;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout<<"\t\t\t------------File Doesn't Exist------------------"<<endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                cout<<"\t\t\t=============Records Deleted!================"<<endl;
                token++;
            }
            else
            {
                data1<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        data1.close();
        if (token == 0)
        {
            cout<<"\t\t\t=========== Record Not Found! ======================"<<endl;
        }
        remove("database.txt");
        rename("database1.txt", "database.txt");
    }
}

int main()
{
    shopping s;
    s.menu();
    return 0;
}
