/*
Here you will provide the definiton of each member function. Remeber include your class.
*/

#include "Client.h"
#include <fstream>
#include <iostream>
using namespace std;



void Client::set_client_info(string name, string ssn2, double BankAccount, double B)
{
  client_name = name;
  ssn = ssn2;
  bank_account = BankAccount;
  balance = B;
}



void saving_info(string file_name)
{
    
}
 
void Client::find_client(double account_number)
{

  for(int i = 0; i < num_client; i++)
  {
    if(client_info[i].account_number == account_number)
    {
      cout << "Client is: " client_info[i].name << " " << client_info[i].account_number << endl;
      return client_info[i];
    }
    else
    {
      cout << "Client is not in the list. " << endl;
    }
  }
}

Client::Client(string file_name, num_clt )
{
  ifstream InputFile;

  Inputfile.open(file_name)

  if(!InputFile)
  {
    cout << "Error: The path or file does not exist";
    exit(1);
  }

  num_client = num_clt;
  
  client_info = new
    
}

/*
Client::~Client()
{
  for(int i=0; i<num_students; i++)
  {
    delete[] student_inf[i];
    delete[] test_grade[i];
  }

  delete[] student_inf;
  delete[] test_grade;

  student_inf = nullptr; //AVOIDING DANGLING POINTERS
  test_grade = nullptr; //AVOIDING DANGLING POINTERS
}
*/

