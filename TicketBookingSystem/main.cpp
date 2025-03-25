#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <map>

std::map<int, bool>seats;
std::mutex mtx;
std::mutex cout_mtx;

void displaySeats()
{
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> cout_lock(cout_mtx);
    std::cout << "Available Seats: ";
    for(const auto& seat: seats)
    {
        if(!seat.second)
        {
            std::cout << seat.first << " ";
        };
    };
    std::cout << std::endl;
};

void bookSeat(int seatNumber)
{
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> cout_lock(cout_mtx);
    if(seats.find(seatNumber) != seats.end() && !seats[seatNumber])
    {
        seats[seatNumber] = true;
        std::cout << "Seat " << seatNumber << " booked successfully!\n";
    } else
    {
        std::cout << "Seat " << seatNumber << " is already booked or invalid!\n";
    }
};

void userBooking(int userId, int seatNumber) {
    {
        std::lock_guard<std::mutex> cout_lock(cout_mtx);
        std::cout << "User " << userId << " trying to book seat " << seatNumber << "...\n";
    }
    bookSeat(seatNumber);
};

int main()
{
    for (int i = 1; i <= 10; ++i) {
        seats[i] = false;
    }

    std::vector<std::thread> users;
    
    displaySeats();

    users.emplace_back(userBooking, 1, 5);
    users.emplace_back(userBooking, 2, 5);
    users.emplace_back(userBooking, 3, 3);
    users.emplace_back(userBooking, 4, 7);
    users.emplace_back(userBooking, 5, 7);
    
    for (auto& user : users) {
        user.join();
    }

    displaySeats();
    
    return 0;
}