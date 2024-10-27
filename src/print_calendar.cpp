/*

This program prompts the user to enter a year (examples 2015, 1992,...) and 
the first weekday of a year [1: Monday, ... 7:Sunday]. To be very clear,
the weekday may be 1 for Monday, 2 for Tuesday and so on. 

The program then prints the calendar for the specified year. Below is a simple run

PS E:\Sandbox\CppTemplateProject> .\rooster.exe
Enter a year  :  2020
Enter the first day of the year [1: Monday, ... 7:Sunday]: 3

Calendar for 2020
--January 2020 --
   Mon   Tue   Wed   Thu   Fri   Sat   Sun
                 1     2     3     4     5
     6     7     8     9    10    11    12
    13    14    15    16    17    18    19
    20    21    22    23    24    25    26
    27    28    29    30    31

--February 2020 --
   Mon   Tue   Wed   Thu   Fri   Sat   Sun
                                   1     2
     3     4     5     6     7     8     9
    10    11    12    13    14    15    16
    17    18    19    20    21    22    23
    24    25    26    27    28    29 

    ..... 

    This program is slightly challenging and may take you a while to get right.
    Don't worry if it takes you hours, even days! If you were stuck on it, just
    take a look at our reference solution and learn the little tricks we're using
    in here. This program will test your understanding of the many concepts learnt
    so far in the course. Things like 
      . data input
      . data output
      . output formatting
      . flow control
      . loops 
      . general problem solving skills

    Have fun!


*/


#include <iostream>
#include <iomanip>

int main()
{

    unsigned int year;
    unsigned int first_day;

    std::cout << "Which year do you want to print ?  ";

    std::cin >> year;

    std::cout << "Enter the first day of the year [1: Monday, ... 7:Sunday]: ";

    std::cin >> first_day;

    int days_in_the_month = 0;
    unsigned int days_count{0}; //After we print the day, we increment
    unsigned int print_width{6};
    unsigned int starting_column{first_day};

    std::cout << std::left << "   Calendar for " << year << std::endl;
    std::cout << std::left << "   =================" << std::endl;
    std::cout << std::endl;

    // Printing monthly calendar
    for (int month = 1; month <= 12; month++)
    {
        // Get the no of days in the month and also print the month
        switch (month)
        {
            case 1:
                days_in_the_month = 31;
                std::cout << "   January " << year <<  std::endl;
                std::cout << std::endl;
                break;
            case 2:
                // Take care of Leap years
                if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                    days_in_the_month = 29;
                else
                    days_in_the_month = 28;
                std::cout << "   February " << year << std::endl;
                std::cout << std::endl;

                break;
            case 3:
                days_in_the_month = 31;
                std::cout << "   March " << year << std::endl;
                std::cout << std::endl;

                break;
            case 4:
                days_in_the_month = 30;
                std::cout << "   April " << year <<  std::endl;
                std::cout << std::endl;
                break;
            case 5:
                days_in_the_month = 31;
                std::cout << "   May " << year <<  std::endl;
                std::cout << std::endl;
                break;
            case 6:
                days_in_the_month = 30;
                std::cout << "   June " <<year << std::endl;
                std::cout << std::endl;
                break;
            case 7:
                days_in_the_month = 31;
                std::cout << "   July " << year << std::endl;
                std::cout << std::endl;
                break;
            case 8:
                days_in_the_month = 31;
                std::cout << "   August " << year << std::endl;
                std::cout << std::endl;
                break;
            case 9:
                days_in_the_month = 30;
                std::cout << "   September " << year <<  std::endl;
                std::cout << std::endl;
                break;
            case 10:
                days_in_the_month = 31;
                std::cout << "   October " << year << std::endl;
                std::cout << std::endl;
                break;
            case 11:
                days_in_the_month = 30;
                std::cout << "   November " << year << std::endl;
                std::cout << std::endl;
                break;
            case 12:
                days_in_the_month = 31;
                std::cout << "   December " << year << std::endl;
                std::cout << std::endl;
                break;
        }

        //Print header

        std::cout   << std::right << std::setw(print_width) << "Mon"
                    << std::right << std::setw(print_width) << "Tue"
                    << std::right << std::setw(print_width) << "Wed"
                    << std::right << std::setw(print_width) << "Thu"
                    << std::right << std::setw(print_width) << "Fri"
                    << std::right << std::setw(print_width) << "Sat"
                    << std::right << std::setw(print_width) << "Sun"
                    << std::endl;

        // print the empty slot
        for(unsigned int j{1};j < starting_column; ++j){
            std::cout << std::setw(print_width) <<  "";
            ++ days_count;
            if(days_count == 7){
                std::cout << std::endl; // Reach end of the week
                days_count = 0;
            }
        
        }  

        // Print calendar
        for(unsigned int i{1} ; i <= days_in_the_month; ++i){ 
            std::cout << std::right << std::setw(print_width) << i;
            ++days_count;

            if(days_count == 7){
                std::cout << std::endl;
                days_count = 0;
            }
        }

        // Set the starting column for the following month
        starting_column = days_count + 1;
        days_count = 0;
        std::cout <<  std::endl;
        std::cout <<  std::endl;
    }

    return 0;
}