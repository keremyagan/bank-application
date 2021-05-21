#include <iostream>
#include "SignIn.h"
#include <fstream>
#include "FileRead.H">
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;
struct Info{
	string name,surname,password,id,account_balance,add_balance;	
};


bool SignIn::sign_in(string id,string password){
	string id_string;
	stringstream ss; 
	ss <<id;  
    ss >> id_string; //converting id no from int to string
	string file_extention=".txt";
	string file_name=id_string+file_extention; //file name is user's id no because it's unique
	FileRead file;
	typedef struct Info Struct;
	file.file_name=file_name;
	Struct info=file.file_read();
	string user_id=info.id;
	string user_password=info.password;
	if(id==user_id && password==user_password){
		return true;
	}
	else{
		return false;
	}
	
}


int SignIn::total_balance(){
	string id_string;
	stringstream ss; 
	ss <<id;  
    ss >> id_string; //converting id no from int to string
	string file_extention=".txt";
	string file_name=id_string+file_extention; 
	FileRead file;
	typedef struct Info Struct;
	file.file_name=file_name;
	Struct info=file.file_read();
	return atoi(info.add_balance.c_str())+atoi(info.account_balance.c_str());//return total balance(account balance+add balance)
}


int SignIn::balance(){
	string id_string;
	stringstream ss; 
	ss <<id;  
    ss >> id_string; //converting id no from int to string
	string file_extention=".txt";
	string file_name=id_string+file_extention; 
	FileRead file;
	typedef struct Info Struct;
	file.file_name=file_name;
	Struct info=file.file_read();
	return atoi(info.account_balance.c_str());
}


int SignIn::add_balance(){
	string id_string;
	stringstream ss; 
	ss <<id;  
    ss >> id_string; //converting id no from int to string
	string file_extention=".txt";
	string file_name=id_string+file_extention; //file name is user's id no because it's unique
	FileRead file;
	typedef struct Info Struct;
	file.file_name=file_name;
	Struct info=file.file_read();
	return atoi(info.add_balance.c_str());
}


string SignIn::name(){
	string id_string;
	stringstream ss; 
	ss <<id;  
    ss >> id_string; //converting id no from int to string
	string file_extention=".txt";
	string file_name=id_string+file_extention; //file name is user's id no because it's unique
	FileRead file;
	typedef struct Info Struct;
	file.file_name=file_name;
	Struct info=file.file_read();
	return info.name;
}


string SignIn::surname(){
	string id_string;
	stringstream ss; 
	ss <<id;  
    ss >> id_string; //converting id no from int to string
	string file_extention=".txt";
	string file_name=id_string+file_extention; //file name is user's id no because it's unique
	FileRead file;
	typedef struct Info Struct;
	file.file_name=file_name;
	Struct info=file.file_read();
	return info.surname;
}

void SignIn::deposit_money(string id,int amount){
	string id_string;
	stringstream ss; 
	ss <<id;  
    ss >> id_string; //converting id no from int to string
	string file_extention=".txt";
	string file_name=id_string+file_extention; 
	FileRead file;
	typedef struct Info Struct;
	file.file_name=file_name;
	Struct info=file.file_read();
	int last_money=atoi(info.account_balance.c_str())+amount;

	ofstream saveFile;
	saveFile.open(file_name.c_str());
	//saving new account info
	saveFile<<"Name:"<<info.name<<endl<<"Surname:"<<info.surname<<endl;
	saveFile<<"Id:"<<info.id<<endl<<"Account Balance:"<<last_money<<endl;
	saveFile<<"Account Additional Balance:"<<info.add_balance<<endl<<"Password:"<<info.password;
	saveFile.close();
	//Information is given to the user.
	cout<<endl<<"Depositing Successful."<<endl;	
	cout<<"Account Value Before Depositing"<<endl<<"Account Balance:"<<info.account_balance<<endl;
	cout<<"Account Add Balance:"<<info.add_balance<<endl<<"Account Value After Depositing"<<endl;
	cout<<"Account Balance:"<<last_money<<endl<<"Account Add Balance:"<<info.add_balance<<endl;
}

void SignIn::withdraw(string id,int amount){
	string id_string;
	stringstream ss; 
	ss <<id;  
    ss >> id_string; //converting id no from int to string
	string file_extention=".txt";
	string file_name=id_string+file_extention;
	FileRead file;
	typedef struct Info Struct;
	file.file_name=file_name;
	Struct info=file.file_read();
	int last_money;
	if (amount>atoi(info.account_balance.c_str())){
		last_money=atoi(info.add_balance.c_str())+atoi(info.account_balance.c_str())-amount;
		info.add_balance="0";
	}
	else{
		last_money=atoi(info.account_balance.c_str())-amount;
	}
	
	ofstream saveFile;
	saveFile.open(file_name.c_str());
	//saving new account info
	saveFile<<"Name:"<<info.name<<endl<<"Surname:"<<info.surname<<endl;
	saveFile<<"Id:"<<info.id<<endl<<"Account Balance:"<<last_money<<endl;
	saveFile<<"Account Additional Balance:"<<info.add_balance<<endl<<"Password:"<<info.password;
	saveFile.close();
	//Information is given to the user.
	cout<<endl<<"Withdrawal Successful."<<endl;		
	cout<<"Account Value Before Withdraw"<<endl<<"Account Balance:"<<info.account_balance<<endl;
	cout<<"Account Add Balance:"<<info.add_balance<<endl<<"Account Value After Withdraw"<<endl;
	cout<<"Account Balance:"<<last_money<<endl<<"Account Add Balance:"<<info.add_balance<<endl;	
}

bool SignIn::remittance_eft(string id,int amount){
	string id_string;
	stringstream ss; 
	ss <<id;
    ss >> id_string; //converting id-no from int to string
	string file_extention=".txt";
	string file_name=id_string+file_extention; //file name is user's id no because it's unique
	FileRead file;
	typedef struct Info Struct;
	file.file_name=file_name;
	Struct info=file.file_read();
	int last_money=atoi(info.account_balance.c_str())+amount;
	ofstream saveFile;
	saveFile.open(file_name.c_str());
	//saving account info
	saveFile<<"Name:"<<info.name<<endl<<"Surname:"<<info.surname<<endl;
	saveFile<<"Id:"<<info.id<<endl<<"Account Balance:"<<last_money<<endl;
	saveFile<<"Account Additional Balance:"<<info.add_balance<<endl<<"Password:"<<info.password;
	saveFile.close();
	return true;
}

void SignIn::to_add(string id,int amount){
	string id_string;
	stringstream ss; 
	ss <<id;  
    ss >> id_string; //converting id no from int to string
	string file_extention=".txt";
	string file_name=id_string+file_extention; 
	FileRead file;
	typedef struct Info Struct;
	file.file_name=file_name;
	Struct info=file.file_read();
	int last_balance=atoi(info.account_balance.c_str())-amount;
	int last_add=atoi(info.add_balance.c_str())+amount;

	ofstream saveFile;
	saveFile.open(file_name.c_str());
	//saving account info
	saveFile<<"Name:"<<info.name<<endl<<"Surname:"<<info.surname<<endl;
	saveFile<<"Id:"<<info.id<<endl<<"Account Balance:"<<last_balance<<endl;
	saveFile<<"Account Additional Balance:"<<last_add<<endl<<"Password:"<<info.password;
	saveFile.close();
	//Information is given to the user.
	cout<<endl<<"Transfer Process Successful."<<endl;	
	cout<<"Account Value Before Transactions"<<endl<<"Account Balance:"<<info.account_balance<<endl;
	cout<<"Account Add Balance:"<<info.add_balance<<endl<<"Account Value After Transactions"<<endl;
	cout<<"Account Balance:"<<last_balance<<endl<<"Account Add Balance:"<<last_add<<endl;
}

void SignIn::to_balance(string id,int amount){
	string id_string;
	stringstream ss; 
	ss <<id;  
    ss >> id_string; //converting id no from int to string
	string file_extention=".txt";
	string file_name=id_string+file_extention; 
	FileRead file;
	typedef struct Info Struct;
	file.file_name=file_name;
	Struct info=file.file_read();
	int last_balance=atoi(info.account_balance.c_str())+amount;
	int last_add=atoi(info.add_balance.c_str())-amount;

	ofstream saveFile;
	saveFile.open(file_name.c_str());
	//saving account info
	saveFile<<"Name:"<<info.name<<endl<<"Surname:"<<info.surname<<endl;
	saveFile<<"Id:"<<info.id<<endl<<"Account Balance:"<<last_balance<<endl;
	saveFile<<"Account Additional Balance:"<<last_add<<endl<<"Password:"<<info.password;
	saveFile.close();
	//Information is given to the user.
	cout<<endl<<"Transfer Process Successful."<<endl;		
	cout<<"Account Value Before Transactions"<<endl<<"Account Balance:"<<info.account_balance<<endl;
	cout<<"Account Add Balance:"<<info.add_balance<<endl<<"Account Value After Transactions"<<endl;
	cout<<"Account Balance:"<<last_balance<<endl<<"Account Add Balance:"<<last_add<<endl;
}

void SignIn::change_password(string id,string new_password){
	string id_string;
	stringstream ss; 
	ss <<id;  
    ss >> id_string; //converting id no from int to string
	string file_extention=".txt";
	string file_name=id_string+file_extention; 
	FileRead file;
	typedef struct Info Struct;
	file.file_name=file_name;
	Struct info=file.file_read();

	ofstream saveFile;
	saveFile.open(file_name.c_str());
	//saving account info
	saveFile<<"Name:"<<info.name<<endl<<"Surname:"<<info.surname<<endl;
	saveFile<<"Id:"<<info.id<<endl<<"Account Balance:"<<info.account_balance<<endl;
	saveFile<<"Account Additional Balance:"<<info.add_balance<<endl<<"Password:"<<new_password;
	saveFile.close();
	//Information is given to the user.
	cout<<endl<<"Password Change Successful. Please Login Again."<<endl;	
}


