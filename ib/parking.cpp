//
// Created by Vinay Saini on 05/03/19.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <list>
#include <cstdlib>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

class Car {
public:
    string registration_num;
    string color;
};

class Parking {

private:
    int entry_points;
    int slots;
    queue<int> available_slots;
    int cur_slot = 1;
    map<string, set<string> > colors;
    map<string, pair<int, Car> > inParking;
    map<int, string> parked;
public:

    int findAvailableSlot() {
        int alloted_slot;
        if(!available_slots.empty()) {
            alloted_slot = available_slots.front();
            available_slots.pop();
        } else if(cur_slot <= slots) {
            alloted_slot = cur_slot;
            cur_slot++;
        } else {
            return -1;
        }
        return alloted_slot;
    }

    int park(Car car, int entrypoint_id) {
        if(entrypoint_id < 1 || entrypoint_id > entry_points) {
            return -1;
        }
        int slot = findAvailableSlot();
        if(slot != -1) {
            parked[slot] = car.registration_num;
            inParking[car.registration_num] = {slot, car};
           if(colors.find(car.color) == colors.end()) {
               set<string> car_by_colors;
               car_by_colors.insert(car.registration_num);
               colors[car.color] = car_by_colors;
           } else {
               colors[car.color].insert(car.registration_num);
           }
        }
        return -2;
    }

    bool leave(int parking_slot) {
        if(parked.find(parking_slot) != parked.end()) {
            Car car = inParking[parked[parking_slot]].second;
            colors[car.color].erase(car.registration_num);
            parked.erase(parking_slot);
            available_slots.push(parking_slot);
            inParking.erase(car.registration_num);
            return true;
        } else {
            return false;
        }
    }

    set<string> findCarsByColor(string color) {
        return colors[color];
    }

    vector<int> findSlotsByColor(string color) {
        vector<int> ret;
        set<string> reg_nums = colors[color];
        for(set<string>::iterator it; it!= reg_nums.end(); it++) {
            ret.push_back(inParking[*it].first);
        }
        return ret;
    }
    int finSlotByRegistrationNumber(string registration_num) {
        if(inParking.find(registration_num) == inParking.end()) {
            return -1;
        }
        return inParking[registration_num].first;
    }
};

int main(){
    string input;
    cin >> input;
    Parking parking;
    if(input == "create_parking_lot") {
        int lot, entry_point;
        cin >> lot >> entry_point;
        parking.entry_points = entry_point;
        parking.slots = lot;
    } else if(input == "park") {
        string reg_num;
        string color;
        int entry_point;
        cin >> reg_num >> color >> entry_point;
        Car car(reg_num, color);
        parking.park(car, entry_point);
    }
    else {
        cout << "wrong input";
    }

    return 0;
}