#pragma once
#include <iostream>




namespace PNet 
{
	class Validator
	{
	public:
		static bool isValidPart(const std::string& ptr);
		static int isValidIp(const std::string& ip_str);
	};
};

/*
bool ValidatorIP::isValidPart(const std::string& address) const 
{
	size_t countdigit = address.size();
	if (countdigit > 3) { return false;}
	for(int i = 0 ; i < countdigit;i++)
	{
		if((address[i] >= '0' && address[i] <= '9') == false ){return false;}
	}
	if (address.find('0') == 0 && countdigit > 1) { std::cerr << "index out of range!" << std::endl; }
	std::stringstream strStream{ address };
	int number = 0;
	strStream >> number;	
	return (number >= 0 && number <= 255);
}

int ValidatorIP::isValidIp(const std::string& address) const 
{
	int dots = 0;
	size_t lenghIPaddr = address.length();
	try
	{
		if (lenghIPaddr == 0 || typeid(address).name() != typeid(std::string).name())
			throw 0;
	}
	catch(int exe)
	{
		std::cerr << "Lenght of Ipaddress is wrong || ipaddress != std::string: "<<exe<< std::endl;
	}
	int counter = 0;
	for (int i = 0; i < lenghIPaddr; i++)
		if (address[i] == '.') { counter++; }
	if (counter != 3) { std::cerr << "counter !=3 " << std::endl; }
	char* token;
	const char* convertedIp = address.c_str();
	char* ptrIp = strtok_s(const_cast<char*>(convertedIp), ".",&token);
	while(ptrIp)
	{
		if(ValidatorIP::isValidPart(ptrIp))
		{
			ptrIp = strtok_s(nullptr, ".", &token);
			if (ptrIp != nullptr)
			{
				++dots;
			}
		}
		else
		{
			break;
		}
	}
	if (dots != 3) { return false; }
	return 1;
}

*/