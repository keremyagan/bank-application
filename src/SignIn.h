#ifndef SignIn_H
#define SignIn_H
#include <iostream>
using namespace std;
class SignIn{
	public:
		string id;
		string password;
		int amount;
		int withdraw_amount;
		int total_balance();
		int balance();
		int add_balance();
		string name();
		string surname();
		string show_password();
		void deposit_money(string id,int amount);
		void withdraw(string id,int withraw_amount);
		bool is_file_exist(const char *fileName);
		bool sign_in(string id,string password);
		bool remittance_eft(string id,int amount);
		void to_add(string id,int amount);
		void to_balance(string id,int amount);
		void change_password(string id,string password);
};

#endif
