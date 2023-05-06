#include <iostream>
#include <ctime>

int main(){
    //srand() has to run once per program run
    std::srand(std::time(0)); // Seed

    bool done { false };

    std::cout << "Welcome to the greatest calculator on Earth! " << std::endl;

    unsigned int MAX_NUMBER {200};

    while (!done) {

        int num1 = static_cast<size_t>((std::rand() % MAX_NUMBER));
        int num2 = static_cast<size_t>((std::rand() % MAX_NUMBER)) + 1;

        int ops = static_cast<size_t>((std::rand() % 4));

        switch (ops){

            case 0 :
                std::cout << "What's the result of " << num1 << " + " << num2 << " : ";
                break;
            case 1 :
                std::cout << "What's the result of " << num1 << " - " << num2 << " : ";
                break;
            case 2 :
                std::cout << "What's the result of " << num1 << " / " << num2 << " : ";
                break;
            default :
                std::cout << "What's the result of " << num1 << " * " << num2 << " : ";
                break;
        }

        int user_input;

        std::cin >> user_input;

        switch (ops) {
            case 0 :
                if((num1 + num2) == user_input ){
                    std::cout << "Congratulations! You got the result "
                        << user_input << " right!" << std::endl;
                }else{
                    std::cout << "Naah! the correct result is : "
                        << num1 + num2 << std::endl;
                }
                break;
            case 1 :
                if((num1 - num2) == user_input ){
                    std::cout << "Congratulations! You got the result "
                        << user_input << " right!" << std::endl;
                }else{
                    std::cout << "Naah! the correct result is : "
                        << num1 - num2 << std::endl;
                }
                break;
            case 2 :
                if((num1 / num2) == user_input ){
                    std::cout << "Congratulations! You got the result "
                        << user_input << " right!" << std::endl;
                }else{
                    std::cout << "Naah! the correct result is : "
                        << num1 - num2 << std::endl;
                }
                break;
            default :
                if((num1 * num2) == user_input ){
                    std::cout << "Congratulations! You got the result "
                        << user_input << " right!" << std::endl;
                }else{
                    std::cout << "Naah! the correct result is : "
                        << num1 * num2 << std::endl;
                }
                break;
        }

        std::cout << std::endl;
        std::cout << "Do you want me to try again ? (Y | N) : ";

        char user_action;
        std::cin >> user_action;

        done = ((user_action == 'Y') || (user_action == 'y')) ? false : true;

    }

    std::cout << "See you later!" << std::endl;

    return 0;
}