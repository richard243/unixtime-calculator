#include <iostream>
#include <string>
#include <vector>

int main()
{
  std::vector<int> daysinmonth{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    std::string time {};
    std::cout << "Enter a timestamp in the format of dd/MM/yyyy HH:mm:ss below\n";
    getline(std::cin, time);
	int day{ std::stoi(time.substr(0, 2)) };
	int month{ std::stoi(time.substr(3, 2)) };

	int year{ std::stoi(time.substr(6, 4)) };
	int unixclock{ (std::stoi(time.substr(11, 2)) * 3600) + (std::stoi(time.substr(14, 2)) * 60) + std::stoi(time.substr(17, 2)) };


	int num1{-2};

	int i{};
	
	
	
	while (i < month - 1) {
		num1 += daysinmonth[i];
		i++;
	}

	num1 += day;
	// num1 = daysinmonth[0];
	std::cout << num1 << std::endl;


	int yearssinceunix{};

	yearssinceunix = year - 1970;
	int lyears = yearssinceunix / 4;
	yearssinceunix -= lyears;
	int yearseconds = ((yearssinceunix * 365) + (lyears * 366)) * 86400;
	
	num1 *= 86400;
	std::cout << (yearseconds + num1 + 86400 + unixclock) << std::endl;
    
    
    return 0;

}
