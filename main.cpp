#include <iostream>
#include "SignUp.H">
#include "SignIn.H">
#include "FileRead.H">
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
struct Info{
	string name,surname,password,id,account_balance,add_balance;
};




int main() {
	int option;
	
	cout<<"Welcome To Kerem Bank"<<endl<<endl;
	for(int i=0;i<1;i++){
		cout<<"1-Sign Up"<<endl<<"2-Sign In"<<endl<<"3-Exit"<<endl<<"Please Enter Transaction Number:";
		cin>>option;
		if (option==1){
			SignUp client;
			client.sign_up();
			i=i-1;
		}
		if(option==2){
			string id;
			string password;
			SignIn user;
			cout<<"Please Enter Your Id:";
			cin>>id;
			user.id=id;
			cout<<"Please Enter Your Password:";
			cin>>password;
			string id_string;
			stringstream ss; 
			ss <<id;  
		    ss >> id_string; 
			bool is_true=user.sign_in(id_string.c_str(),password);
			if(is_true==true){
				cout<<"Login Successful"<<endl;
				for(int k=0;k<1;k++){
					SignIn user;
					user.id=id;
					cout<<"Welcome "<<user.name()<<" "<<user.surname()<<endl;
					cout<<"1-Deposit Money"<<endl<<"2-Withdraw Money"<<endl<<"3-Remittance/Eft"<<endl<<"4-Money, Additional Money Transactions"<<endl;
					cout<<"5-Account Details"<<endl<<"6-Change Password"<<endl<<"7-Delete Account"<<endl<<"8-Exit"<<endl<<"Please Enter Transaction Number:";
					int option_1;
					cin>>option_1;
					if(option_1==1){//deposit money
						int amount;
						cout<<"Please Enter Amount of Money:";
						cin>>amount;
						user.amount=amount;
						user.deposit_money(id_string.c_str(),amount);
						k=k-1;
					}
					if(option_1==2){//withdraw money
						k=k-1;
						int withdraw_amount;
						cout<<"Please Enter Amount of Money You Want to Withdraw"<<"Max("<<user.total_balance()<<"):";
						cin>>withdraw_amount;
						if(withdraw_amount>user.balance()){
							string y_n;
							cout<<"Do You Want to Use Add Balance(Y/N):";
							cin>>y_n;
							if(y_n=="Y" || y_n=="y"){
								if(user.total_balance()>withdraw_amount){
									user.withdraw_amount=withdraw_amount;
									user.withdraw(id_string.c_str(),withdraw_amount);
								}
								else{
									cout<<"You Do Not Have Enough Money."<<endl;
								}

							}
							else{
								cout<<"Operation Failed"<<endl;
								k=k-1;
							}
						}
						else{
								user.withdraw_amount=withdraw_amount;
								user.withdraw(id_string.c_str(),withdraw_amount);
								k=k-1;
						}
					}
					if(option_1==3){//remittance eft
						k=k-1;
						cout<<"Please Enter Id which You Want to Send Money:";
						int to;
						cin>>to;
						stringstream ss; 
						string to_string;
						ss << to;  
						ss >> to_string; //converting id no from int to string
						string file_extention=".txt";
						string file_name=to_string+file_extention; 
						SignUp user2;
						bool check_file=user2.is_file_exist(file_name.c_str());
						if(check_file==1){
							SignIn user2;
							user2.id=to_string;
							cout<<"Receiver Name:"<<user2.name()<<endl<<"Receiver Surname:"<<user2.surname()<<endl;
							cout<<"Do You Want To Continue(Y/N):";
							string yes_no;
							cin>>yes_no;
							if(yes_no=="Y" || yes_no=="y"){
								int withdraw_amount;
								cout<<"Please Enter Amount of Money You Want to Withdraw "<<"Max("<<user.total_balance()<<"):";
								cin>>withdraw_amount;
								if(withdraw_amount>user.balance()){
									string y_n;
									cout<<"Do You Want to Use Add Balance(Y/N):";
									cin>>y_n;
									if(y_n=="Y" || y_n=="y"){
										if(user.total_balance()>withdraw_amount){
											user.withdraw_amount=withdraw_amount;
											user.withdraw(id_string.c_str(),withdraw_amount);
											user2.id=to_string;
											user2.amount=withdraw_amount;
											bool result=user2.remittance_eft(to_string.c_str(),withdraw_amount);
											if(result==true){
												cout<<"Transaction Successful"<<endl;
											}
											else{
												cout<<"Something Went Wrong";
											}
											
										}
										else{
											cout<<"You Do Not Have Enough Money."<<endl;
										}
	
									}
									else{
										cout<<"Operation Failed"<<endl;
									}
								}
								else{
									user.withdraw_amount=withdraw_amount;
									user.withdraw(id_string.c_str(),withdraw_amount);
									user2.amount=withdraw_amount;
									bool result =user2.remittance_eft(to_string.c_str(),withdraw_amount);
									if(result==true){
										cout<<"Transaction Successful";
										k=k-1;
									}
									else{
										cout<<"Something Went Wrong";
										k=k-1;
										}				
								}
							}
							
							else{
								cout<<"Exit Successful."<<endl;
							}
						}else{
							cout<<"Contact Information Not Found"<<endl;
							k=k-1;
							}
						}
					if(option_1==4){//money additional money transactions
						k=k-1;
						cout<<"Account Balance:"<<user.balance()<<endl<<"Add Balance:"<<user.add_balance()<<endl;
						cout<<"1-From Account Balance To Add Balance"<<endl<<"2-From Add Balance To Account Balance"<<endl;
						cout<<"Please Enter Transaction Number:";
						int change_balance;
						cin>>change_balance;
						if(change_balance==1){//to add balance
							cout<<"Please Enter Amaount of Money:";
							int to_add;
							cin>>to_add;
							if(to_add<user.balance()){
								user.to_add(id_string.c_str(),to_add);
								
							}
							else{
								cout<<"You Dont Have Enough Money\n";
							}
						}
						if(change_balance==2){
							cout<<"Please Enter Amaount of Money:";
							int to_balance;
							cin>>to_balance;
							if(to_balance<user.add_balance()){
								user.to_balance(id_string.c_str(),to_balance);
								
							}
							else{
								cout<<"You Dont Have Enough Money\n";
							}
						}
						
					}
					if(option_1==5){//account details
						cout<<"Name: "<<user.name()<<endl;
						cout<<"Surname: "<<user.surname()<<endl;
						cout<<"Id: "<<id_string<<endl;
						cout<<"Account Balance: "<<user.balance()<<endl;
						cout<<"Account Add Balance: "<<user.add_balance()<<endl;
						cout<<"Password: "<<password<<endl;
						k=k-1;}
					if(option_1==6){//change password
						cout<<"Please Enter New Password:";
						string new_password;
						cin>>new_password;
						if(new_password==user.password){
							cout<<"Your New Password Cannot Be The Same As Older";
							k=k-1;
						}
						else{
							user.change_password(id_string.c_str(),new_password);
							i=i-1;
						}
					}					
					if(option_1==7){//delete account
						cout<<"Your Account Will Be Deleted And This Transaction Cannot Be Undone. Do You Want To Continue?(Y/N)";
						string confirm_delete;
						cin>>confirm_delete;
						if(confirm_delete=="Y" || confirm_delete=="y"){//delete account
							cout<<"Please enter your password to confirm the transaction:";
							string confirm_password;
							cin>>confirm_password;
							if(confirm_password==user.show_password()){
								stringstream ss; 
								string file_extention=".txt";
								string file_name=id_string+file_extention;
								remove(file_name.c_str());
								cout<<"We are sorry that you left us. See you .."<<endl;
								i=i-1;
							}
							else{
								cout<<"Incorrect password.Please try again later."<<endl;
								k=k-1;
							}
						}
						else{
							cout<<"We are happy to see you among us."<<endl;
							cout<<"If you have an account problem, contact our support team instead of deleting your account"<<endl;
							cout<<"kerembank@info.com"<<endl;
							k=k-1;
						}
					}
					if(option_1==8){
						cout<<"Exit Successful."<<endl;
					}
					}
				
			}
			else{
				cout<<"Id or Password is Incorrect"<<endl;
				i=i-1;
			}
		}
		else{
			cout<<"Exit Successful."<<endl;
		}
	}


	return 0;
}

