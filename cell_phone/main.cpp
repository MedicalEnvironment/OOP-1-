#include <iostream>
#include <string>
#include <vector>

class PhoneNumber {
private:
    std::string number;

public:
    PhoneNumber(const std::string& phoneNumber) : number(phoneNumber) {}

    std::string getNumber() const {
        return number;
    }
};

class Contact {
private:
    std::string name;
    PhoneNumber phoneNumber;

public:
    Contact(const std::string& contactName, const std::string& contactNumber)
            : name(contactName), phoneNumber(contactNumber) {}

    std::string getName() const {
        return name;
    }

    PhoneNumber getPhoneNumber() const {
        return phoneNumber;
    }
};

class MobilePhone {
private:
    std::vector<Contact> addressBook;

public:
    void addContact(const std::string& contactName, const std::string& contactNumber) {
        Contact newContact(contactName, contactNumber);
        addressBook.push_back(newContact);
        std::cout << "Contact added: " << contactName << " - " << contactNumber << std::endl;
    }

    void makeCall(const std::string& contactNameOrNumber) {
        for (const auto& contact : addressBook) {
            if (contact.getName() == contactNameOrNumber || contact.getPhoneNumber().getNumber() == contactNameOrNumber) {
                std::cout << "CALL: Calling " << contact.getPhoneNumber().getNumber() << std::endl;
                return;
            }
        }
        std::cout << "Contact not found." << std::endl;
    }

    void sendSMS(const std::string& contactNameOrNumber) {
        std::string message;
        std::cout << "Enter the message: ";
        std::cin.ignore();
        std::getline(std::cin, message);

        for (const auto& contact : addressBook) {
            if (contact.getName() == contactNameOrNumber || contact.getPhoneNumber().getNumber() == contactNameOrNumber) {
                std::cout << "SMS: Sending message to " << contact.getPhoneNumber().getNumber() << " - " << message << std::endl;
                return;
            }
        }
        std::cout << "Contact not found." << std::endl;
    }
};

int main() {
    MobilePhone phone;
    std::string command;
    std::string name;
    std::string number;

    while (true) {
        std::cout << "Enter a command ('add', 'call', 'sms', 'exit'): ";
        std::cin >> command;

        if (command == "add") {
            std::cout << "Enter contact name: ";
            std::cin >> name;
            std::cout << "Enter contact number: ";
            std::cin >> number;
            phone.addContact(name, number);
        } else if (command == "call") {
            std::cout << "Enter contact name or number: ";
            std::cin >> name;
            phone.makeCall(name);
        } else if (command == "sms") {
            std::cout << "Enter contact name or number: ";
            std::cin >> name;
            phone.sendSMS(name);
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}
