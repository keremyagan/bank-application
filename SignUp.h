#ifndef SignUp_H
#define SignUp_H
#include <iostream>
using namespace std;
class SignUp{
	public:
		string name,surname,password;
		int id,balance,add_balance;
		void sign_up();
		bool is_file_exist(const char *fileName);

};

#endif
