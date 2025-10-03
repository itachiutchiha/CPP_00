# ifndef PHONEBOOK_CPP
# define PHONEBOOK_CPP

#include <iostream>
#include <string>
#include <cctype>



class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	secret;
	
	public:
		Contact();
		std::string	getFirstName();
		void		setFirstName(std::string newFirstName);
		std::string	getLastName();
		void		setLastName(std::string newLastName);
		std::string	getNickName();
		void		setNickName(std::string newNickName);
		std::string			getPhoneNumber();
		void		setPhoneNumber(std::string newPhoneNumber);
		std::string	getSecret();
		void		setSecret(std::string newSecret);


};

class PhoneBook {

	private:
    	int	isFull;
		int	index;
	public:
		PhoneBook();
		Contact	contacts[8];
		int		getFullVar();
		void	setFullVar(int newIsFull);
		int		getIndex();
		void	setIndex(int newIndex);
		void	incrementIndex();
		void	add();
		void	search();
		void	exit();
};

std::string	getUserInfo(std::string msg);
void		print_user_info(std::string str);

# endif
