#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool isDone = true;
int input;
char cont;
string name;
int conti;

vector <string> user;
vector <string> admin;


void _controlPanel();
void _returnH();
void _home();
void _if();


int main()
{
  _controlPanel();
}


void _controlPanel()
{
  _home();
  _if();
}


void _home()
{
  system("clear");
  cout << setw(45) << "PROGRAMMERS CAMP" << endl;
  cout << "\n1. Add Users \n"
       << "2. View Users \n"
       << "3. Add Admins \n"
       << "4. view Admins \n"
       << "5. Exit " << endl;

  cout << "\n\n";
  cout << "Enter a corresponding input: ";
  cin >> input;
}


void _returnH()
{
  cout << "Enter '0' to return Home: ";
  cin >> conti;

  if(conti != 0)
  {
    cout << "invalid input..."<< endl;
    cout << "Enter '0' to return Home: ";
    cin >> conti;
  }
  
  else
  {
    _controlPanel();
  }
}



void _if()
{
  while(isDone)
  {//whileLoop
    if (input == 1)
    {//input 1 if
      system("clear");
      cout << setw(40) << "ADD USER" << endl;
      cout << setw(46) << "Enter 'quit' to Exit\n" << endl;
      cout << "Enter User name: ";
      cin.ignore();
      getline(cin, name);
      
      if (name == "quit" || name == "Quit")
      {
	_controlPanel();
      }

      else 
      {
	for(int i=0; i < user.size(); i++)
	{
	  if (name == user[i])
          {
            cout << "User already exit" << endl;
	    _returnH();
	  }
	}
	system("clear");
	user.push_back(name);
	cout << "User successfully added" << endl;
	_returnH();
      }
    }//input 1 if



    else if (input == 2)
    {//input 2 if
      int userT = 0;
      system("clear");
      cout << setw(46) << "Programmers Camp Users are :" << endl;

      for(int i = 0; i < user.size(); i++)
      {
        cout << user[i] << endl;
	userT++;
      }
      cout<< "\n\n" << setw(40)<<"Current users are "<< userT << "\n\n";
      _returnH();
    }//input 2 if


    else if(input == 3)
    {//input 3 if
      system("clear");
      cout << setw(40) << "ADD ADMINS" << endl;
      cout << setw(46) << "Enter 'quit' to Exit\n" << endl;;
      cout << "Enter User name: ";
      cin.ignore();
      getline(cin, name);
      
      if (name == "quit" || name == "Quit")
      {
        _controlPanel();
      }

      else
      {
        for (int i =0; i <user.size(); i++)
        {
	  if (name == user[i])
	  {
	  //to remove an element from vector --->
	  user.erase(remove(user.begin(), user.end(), name),user.end());
	    admin.push_back(name);
	    cout << "Admin added successfully\n" << endl;

	    _returnH();
	  }

	  else
	  {
	    for (int j = 0; j < admin.size(); i++)
	    {
	      if (name == admin[i])
	      {
	        cout << "\aCannot process.... User is an admin" << endl;
		cout << "\n\n" << endl; _returnH();
	      }
	    }
	  }
        }
      }
    }//input 3 if


    else if (input == 4)
    {//input 4 if
      system("clear");
      int adminT = 0;
      cout << setw(46) << "Programmers Camp Admins are : \n" <<endl;

      for (int i = 0; i < admin.size(); i++)
      {
	cout << admin[i] << endl;
	adminT++;
      }

      cout <<"\n\n"<<setw(40)<<"Current Admins are : " << adminT <<endl;
      cout << "\n\n" << endl;
      _returnH();
    }//input 4 if


    else 
    {
     system("clear");
     isDone = false;
     system("exit");
    }
  }//whileLoop
}
