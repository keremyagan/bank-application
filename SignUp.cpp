#include <iostream>
#include "SignUp.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

bool is_file_exist(const char *fileName)//File presence is checked
{
    std::ifstream infile(fileName);
    return infile.good();
}

bool SignUp::is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

void SignUp::sign_up(){
	//getting info from user
	cout<<"Please Enter Your Identification Number:";
	cin>>SignUp::id;
	stringstream ss; 
	string id_string;
	ss << SignUp::id;  
  	ss >> id_string; //converting id no from int to string
	string file_extention=".txt";
	string file_name=id_string+file_extention; //file name is user's id no because it's unique
	bool check_file=is_file_exist(file_name.c_str());
	if (check_file==0){
		cout<<"Please Enter Your Name:";
		cin>>SignUp::name;
		cout<<"Please Enter Your Surame:";
		cin>>SignUp::surname;
		cout<<"Please Enter Your Account Balance:";
		cin>>SignUp::balance;
		cout<<"Please Enter Your Account Additional Balance:";
		cin>>SignUp::add_balance;
		cout<<"Please Enter Your Password:";
		cin>>SignUp::password;	
		ofstream saveFile;
		saveFile.open(file_name.c_str());
		//saving account info
		saveFile<<"Name:"<<SignUp::name<<endl<<"Surname:"<<SignUp::surname<<endl;
		saveFile<<"Id:"<<SignUp::id<<endl<<"Account Balance:"<<SignUp::balance<<endl;
		saveFile<<"Account Additional Balance:"<<SignUp::add_balance<<endl<<"Password:"<<SignUp::password;
		saveFile.close();
		cout<<endl<<"Member Registration Successful"<<endl;	
		
	}
	else{
		cout<<"You are already a member. Please login."<<endl;
	}

}
