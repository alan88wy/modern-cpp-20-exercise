#include <iostream>

int main() {

    const char* encryption_key = std::getenv("ENCKEY");
    char password[50];
    char encrypted_password[64];

    std::cout << "Encryption Key is : " << encryption_key << "\n";   

    fgets(password, sizeof(password), stdin);

    

    return 0;
}
