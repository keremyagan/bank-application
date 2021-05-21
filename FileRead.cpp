#include <iostream>
#include "FileRead.h"
#include <fstream>
using namespace std;

struct Info{
	string name,surname,password,id,account_balance,add_balance;
};

string reverse(const string &str)//reverses the word
{
    return  { str.rbegin(), str.rend() };
}

string split_word(string word){//if word=Name:John, new_word=nhoJ,reverse(new_word)=John
	string reverse_word=reverse(word);
	string delimiter = ":";
	string token = reverse_word.substr(0, reverse_word.find(delimiter));
	string check_character="";
	string new_word="";
	int counter=0;
	while(reverse_word[counter]!=':'){
		new_word=new_word+reverse_word[counter];
		counter++;
	}
	return reverse(new_word);
	
}

typedef struct Info Struct;
Struct FileRead::file_read(){
	ifstream ClientFile;
	string line;
	string name,surname,id,password,account_balance,add_balance;
	ClientFile.open(FileRead::file_name.c_str());
	
	getline(ClientFile,line);
	name=split_word(line);//getting name from file
	
	getline(ClientFile,line);
	surname=split_word(line);//getting surname from file
	
	getline(ClientFile,line);
	id=split_word(line);//getting id from file
	
	getline(ClientFile,line);
	account_balance=split_word(line);//getting account balance from file
		
	getline(ClientFile,line);
	add_balance=split_word(line);//getting add balance from file
		
	getline(ClientFile,line);
	password=split_word(line);//getting password from file
	
	ClientFile.close();
	Info info;
	//Data are saved to struct.
	info.name=name;
	info.surname=surname;
	info.password=password;
	info.id=id;
	info.account_balance=account_balance;
	info.add_balance=add_balance;	
	return info;//return struct

	
}
