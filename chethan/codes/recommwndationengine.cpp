#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Recommendation {
    string start_zone;
    string destination_shelter;
    string route;
    int time; // time in minutes
};

class SmartCityRecommendation {
private:
    vector<Recommendation> recommendations;

public:
    void addRecommendation(const string &start_zone, const string &destination_shelter, const string &route, int time) {
        Recommendation rec = {start_zone, destination_shelter, route, time};
        recommendations.push_back(rec);
    }

    void displayRecommendations() {
        cout << setw(20) << "Start Zone" << setw(30) << "Destination Shelter"
             << setw(30) << "Route" << setw(10) << "Time (mins)" << endl;
        cout << string(90, '-') << endl;

        for (const auto &rec : recommendations) {
            cout << setw(20) << rec.start_zone
                 << setw(30) << rec.destination_shelter
                 << setw(30) << rec.route
                 << setw(10) << rec.time << endl;
        }
    }

    void searchRecommendation(const string &start_zone) {
        bool found = false;
        cout << "\nRecommendations for Start Zone: " << start_zone << endl;

        for (const auto &rec : recommendations) {
            if (rec.start_zone == start_zone) {
                found = true;
                cout << "Start: " << rec.start_zone
                     << ", Destination: " << rec.destination_shelter
                     << ", Route: " << rec.route
                     << ", Time: " << rec.time << " mins" << endl;
            }
        }

        if (!found) {
            cout << "No recommendations found for the specified start zone." << endl;
        }
    }
};

int main() {
    SmartCityRecommendation engine;

   
    engine.addRecommendation("Zone 1", "Shelter A", "Zone 1 -> Shelter A", 22);
    engine.addRecommendation("Zone 2", "Shelter B", "Zone 2 -> Shelter B", 25);
    engine.addRecommendation("Zone 3", "Shelter C", "Zone 3 -> Shelter C", 11);
    engine.addRecommendation("Zone 4", "Shelter D", "Zone 4 -> Shelter D", 35);
    engine.addRecommendation("Zone 5", "Shelter E", "Zone 5 -> Shelter E", 40);
    engine.addRecommendation("Zone 6", "Shelter F", "Zone 6 -> Shelter F", 40);
    engine.addRecommendation("Zone 7", "Shelter G", "Zone 7 -> Shelter G", 11);
    engine.addRecommendation("Zone 8", "Shelter H", "Zone 8 -> Shelter H", 15);
    engine.addRecommendation("Zone 9", "Shelter I", "Zone 9 -> Shelter I", 15);
    engine.addRecommendation("Zone 10", "Shelter J", "Zone 10 -> Shelter J", 19);

    
    engine.displayRecommendations();

  
    string search_zone;
    cout << "Enter Start Zone to search for recommendations: ";
    cin >> search_zone;
    engine.searchRecommendation(search_zone);

    return 0;
}
