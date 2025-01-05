
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class recommendation_data {
private:
    char housing_name[150][50];
    char applicant_name[150][50];
    int location_score[150];
    int price_score[150];
    int amenities_score[150];
    int global_count;

public:
    recommendation_data();
    void welcome();
    void load_from_file();
    void display_data();
    void search_recommendation(const char* user);
};

recommendation_data::recommendation_data() {
    global_count = 0;
}

void recommendation_data::welcome() {
    for (int i = 0; i < 80; i++)
        cout << "*";
    cout << "\n\n\t\t\t\tHOUSING RECOMMENDATION ENGINE\n\n\n";
    for (int i = 0; i < 80; i++)
        cout << "*";
    cout << "\n\n";
}

void recommendation_data::load_from_file() {
    ifstream file("housing_data.txt");

    if (!file) {
        cout << "File Not Found\n";
        return;
    }

    while (file >> housing_name[global_count]
                >> applicant_name[global_count]
                >> location_score[global_count]
                >> price_score[global_count]
                >> amenities_score[global_count]) {
        if (global_count < 150)
            global_count++;
        else {
            cout << "Maximum data limit reached.\n";
            break;
        }
    }

    file.close();
}

void recommendation_data::display_data() {
    for (int i = 0; i < global_count; i++) {
        cout << setw(30) << housing_name[i]
             << setw(30) << applicant_name[i]
             << setw(10) << location_score[i]
             << setw(10) << price_score[i]
             << setw(10) << amenities_score[i] << endl;
    }
}

void recommendation_data::search_recommendation(const char* user) {
    bool found = false;
    int user_length = strlen(user);

    for (int i = 0; i < global_count; i++) {
        bool match = true;

        for (int j = 0; j < user_length; j++) {
            if (applicant_name[i][j] != user[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            found = true;
            cout << setw(30) << housing_name[i]
                 << setw(30) << applicant_name[i]
                 << setw(10) << location_score[i]
                 << setw(10) << price_score[i]
                 << setw(10) << amenities_score[i] << endl;
        }
    }

    if (!found) {
        cout << "No recommendations found for applicant: '" << user << "'.\n";
    }
}

int main() {
    recommendation_data engine;
    engine.welcome();

    engine.load_from_file();
    engine.display_data();

    char user[50];
    cout << "Enter the applicant's name to get recommendations:\n";
    cin >> user;
    engine.search_recommendation(user);

    return 0;
}
