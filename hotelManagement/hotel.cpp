#include <iostream>
#include <vector>
#include <string>

class Room {
public:
    int room_number;
    std::string room_type;
    double price_per_day;
    int no_of_days;

    Room(int room_number, std::string room_type, double price_per_day, int no_of_days) :
        room_number(room_number), room_type(room_type), price_per_day(price_per_day), no_of_days(no_of_days) {}

    virtual double calculate_bill() {
        return price_per_day * no_of_days;
    }

    virtual void display_details() {
        std::cout << "Room Number: " << room_number << std::endl;
        std::cout << "Room Type: " << room_type << std::endl;
        std::cout << "Price per day: " << price_per_day << std::endl;
        std::cout << "Number of days: " << no_of_days << std::endl;
    }
};

class StandardRoom : public Room {
public:
    std::string amenities;

    StandardRoom(int room_number, double price_per_day, int no_of_days, std::string amenities) :
        Room(room_number, "Standard", price_per_day, no_of_days), amenities(amenities) {}

    void special_amenities() {
        std::cout << "Amenities: " << amenities << std::endl;
    }

    void display_details() override {
        Room::display_details();
        special_amenities();
        std::cout << "Total Bill: " << calculate_bill() << std::endl;
    }
};

class DeluxeRoom : public Room {
public:
    std::string special_service;

    DeluxeRoom(int room_number, double price_per_day, int no_of_days, std::string special_service) :
        Room(room_number, "Deluxe", price_per_day, no_of_days), special_service(special_service) {}

    void special_services() {
        std::cout << "Special Services: " << special_service << std::endl;
    }

    void display_details() override {
        Room::display_details();
        special_services();
        std::cout << "Total Bill: " << calculate_bill() << std::endl;
    }
};

int main() {
    std::vector<Room*> rooms;
    int choice;

    do {
        std::cout << "\nHotel Management System Menu:\n";
        std::cout << "1) Add Standard Room Details\n";
        std::cout << "2) Add Deluxe Room Details\n";
        std::cout << "3) Display details and Calculate bill\n";
        std::cout << "4) Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int room_number, no_of_days;
            double price_per_day;
            std::string amenities;

            std::cout << "Enter room number: ";
            std::cin >> room_number;
            std::cout << "Enter price per day: ";
            std::cin >> price_per_day;
            std::cout << "Enter number of days: ";
            std::cin >> no_of_days;
            std::cout << "Enter amenities: ";
            
            std::getline(std::cin, amenities);

            rooms.push_back(new StandardRoom(room_number, price_per_day, no_of_days, amenities));
            std::cout << "Standard Room added successfully!\n";
            break;
        }
        case 2: {
            int room_number, no_of_days;
            double price_per_day;
            std::string special_service;

            std::cout << "Enter room number: ";
            std::cin >> room_number;
            std::cout << "Enter price per day: ";
            std::cin >> price_per_day;
            std::cout << "Enter number of days: ";
            std::cin >> no_of_days;
            std::cout << "Enter special services: ";
            std::cin.ignore();
            std::getline(std::cin, special_service);

            rooms.push_back(new DeluxeRoom(room_number, price_per_day, no_of_days, special_service));
            std::cout << "Deluxe Room added successfully!\n";
            break;
        }
        case 3:
            if (rooms.empty()) {
                std::cout << "No rooms added yet.\n";
            }
            else {
                for (Room* room : rooms) {
                    room->display_details();
                    std::cout << std::endl;
                }
            }
            break;
        case 4:
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    for (Room* room : rooms) {
        delete room;
    }
    rooms.clear();

    return 0;
}