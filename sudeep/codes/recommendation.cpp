#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
using namespace std;

struct tourist_spot {
    string recommendation_name;
    int visitors;
};

class recommendation_data
{
private:
    char spot_name[150][30];
    char recommendation_name[150][30];
    int visitors[150];
    int global_count;

public:
    recommendation_data();

    void welcome();
    void load_from_file();
    void display_data();
    void bfss(string name);
};

recommendation_data::recommendation_data()
{
    global_count = 0;
}

void recommendation_data::welcome()
{
    for (int i = 0; i < 80; i++)
        cout << "*";
    cout << "\n\n\t\t\t\ttourism spot reccomendation system\n\n\n";
    for (int i = 0; i < 80; i++)
        cout << "*";
    cout << "\n\n";
}

void recommendation_data::load_from_file()
{
    ifstream file("D:\\Github files\\tourist_data.txt.txt");
    //prajwal/files/tourist_data.txt.txt

    if (!file)
    {
        cout << "File Not Found\n";
        return;
    }

    while (file >> spot_name[global_count]
                >> recommendation_name[global_count]
                >> visitors[global_count])
    {
        if (global_count < 150)
            global_count++;
        else
        {
            cout << "Maximum data limit reached.\n";
            break;
        }
    }

    file.close();
}

void recommendation_data::display_data()
{
    for (int i = 0; i < global_count; i++)
    {
        cout << setw(30) << spot_name[i]
             << setw(30) << recommendation_name[i]
             << setw(10) << visitors[i] << endl;
    }
}

void insertion_sort(vector<tourist_spot> &recommendations) {
    int n = recommendations.size();
    for (int i = 1; i < n; i++) {
        tourist_spot key = recommendations[i];
        int j = i - 1;
        while (j >= 0 && recommendations[j].visitors < key.visitors) {
            recommendations[j + 1] = recommendations[j];
            j--;
        }
        recommendations[j + 1] = key;
    }
}

void recommendation_data::bfss(string name) {
    bool f = false;
    vector<tourist_spot> recommendations;

    for (int i = 0; i < global_count; i++) {
        int j = 0;

        while (name[j] != '\0' && spot_name[i][j] == name[j]) {
            j++;
        }

        if (name[j] == '\0') {
            f = true;
            tourist_spot rec;
            rec.recommendation_name = recommendation_name[i];
            rec.visitors = visitors[i];
            recommendations.push_back(rec);
        }
    }

    if (f) {
        cout << "Tourist spot found:\n";
        insertion_sort(recommendations);

        for (int i = 0; i < recommendations.size(); ++i) {
            cout << setw(30) << recommendations[i].recommendation_name
                 << setw(10) << recommendations[i].visitors << endl;
        }
    } else {
        cout << "Tourist spot not found.\n";
    }
}

int main()
{
    string name;
    recommendation_data engine;
    engine.welcome();

    engine.load_from_file();
    engine.display_data();
    cout<<endl;
    cout << "Enter the location you want to search : ";
    cin >> name;
    engine.bfss(name);

    return 0;
}
