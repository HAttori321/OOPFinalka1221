#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

struct Athlete
{
    string name;
    string coach;
    string country;
};
struct Event
{
    string name;
};
struct Result
{
    string athleteName;
    string eventName;
    float time;
};

vector<Athlete> athletes;
vector<Event> events;
vector<Result> results;

void addAthlete()
{
    Athlete athlete;
    cout << "Enter athlete's name: ";
    getline(cin, athlete.name);
    cout << "Enter athlete's coach: ";
    getline(cin, athlete.coach);
    cout << "Enter athlete's country: ";
    getline(cin, athlete.country);
    athletes.push_back(athlete);
}
void addEvent()
{
    Event event;
    cout << "Enter event's name: ";
    getline(cin, event.name);
    events.push_back(event);
}
void addResult()
{
    Result result;
    cout << "Enter athlete's name: ";
    getline(cin, result.athleteName);
    cout << "Enter event's name: ";
    getline(cin, result.eventName);
    cout << "Enter result time: ";
    cin >> result.time;
    cin.ignore();
    results.push_back(result);
}
void saveAthletesToFile() 
{
    ofstream outFile("athletes.txt");
    for (const auto& athlete : athletes)
    {
        outFile << athlete.name << "," << athlete.coach << "," << athlete.country << endl;
    }
    outFile.close();
    cout << "Athletes saved to file.\n";
}
void loadAthletesFromFile()
{
    ifstream inFile("athletes.txt");
    if (inFile.is_open()) {
        athletes.clear();
        string line;
        while (getline(inFile, line)) {
            string name, coach, country;
            size_t pos1 = line.find(',');
            size_t pos2 = line.rfind(',');
            if (pos1 != string::npos && pos2 != string::npos && pos1 != pos2) {
                name = line.substr(0, pos1);
                coach = line.substr(pos1 + 1, pos2 - pos1 - 1);
                country = line.substr(pos2 + 1);
                Athlete athlete = { name, coach, country };
                athletes.push_back(athlete);
            }
        }
        inFile.close();
        cout << "Athletes loaded from file.\n";
    }
    else 
    {
        cout << "Unable to open athletes file.\n";
    }
}
void saveEventsToFile() 
{
    ofstream outFile("events.txt");
    for (const auto& event : events) 
    {
        outFile << event.name << endl;
    }
    outFile.close();
    cout << "Events saved to file.\n";
}
void loadEventsFromFile()
{
    ifstream inFile("events.txt");
    if (inFile.is_open()) {
        events.clear();
        string eventName;
        while (getline(inFile, eventName)) 
        {
            Event event = { eventName };
            events.push_back(event);
        }
        inFile.close();
        cout << "Events loaded from file.\n";
    }
    else
    {
        cout << "Unable to open events file.\n";
    }
}
void saveResultsToFile() 
{
    ofstream outFile("results.txt");
    for (const auto& result : results) 
    {
        outFile << result.athleteName << "," << result.eventName << "," << result.time << endl;
    }
    outFile.close();
    cout << "Results saved to file.\n";
}
void loadResultsFromFile()
{
    ifstream inFile("results.txt");
    if (inFile.is_open()) {
        results.clear();
        string line;
        while (getline(inFile, line)) {
            string athleteName, eventName;
            float time;
            size_t pos1 = line.find(',');
            size_t pos2 = line.rfind(',');
            if (pos1 != string::npos && pos2 != string::npos && pos1 != pos2) {
                athleteName = line.substr(0, pos1);
                eventName = line.substr(pos1 + 1, pos2 - pos1 - 1);
                time = stof(line.substr(pos2 + 1));
                Result result = { athleteName, eventName, time };
                results.push_back(result);
            }
        }
        inFile.close();
        cout << "Results loaded from file.\n";
    }
    else 
    {
        cout << "Unable to open results file.\n";
    }
}
void displayAthletes() 
{
    cout << "Athletes:\n";
    for (const auto& athlete : athletes)
    {
        cout << "Name: " << athlete.name << ", Coach: " << athlete.coach << ", Country: " << athlete.country << endl;
    }
}
void displayEvents() 
{
    cout << "Events:\n";
    for (const auto& event : events)
    {
        cout << "Name: " << event.name << endl;
    }
}
void displayResults() 
{
    cout << "Results:\n";
    for (const auto& result : results)
    {
        cout << "Athlete: " << result.athleteName << ", Event: " << result.eventName << ", Time: " << result.time << endl;
    }
}
void determineWinners() 
{
    if (events.empty())
    {
        cout << "No events available.\n";
        return;
    }

    cout << "Enter the event name to determine the winner: ";
    string eventName;
    getline(cin, eventName);

    float bestTime = -1;
    string winner;

    for (const auto& result : results) 
    {
        if (result.eventName == eventName) 
        {
            if (bestTime == -1 || result.time < bestTime) 
            {

                bestTime = result.time;
                winner = result.athleteName;
            }
        }
    }
    if (!winner.empty()) 
    {
        cout << "The winner of the event " << eventName << " is " << winner << " with a time of " << bestTime << " seconds.\n";
    }
    else 
    {
        cout << "No results found for the event " << eventName << ".\n";
    }
}
int main()
{
    int choice;
    do
    {
        cout << "1. Add athlete\n2. Add event\n3. Add result\n4. Save athletes to file\n5. Load athletes from file\n6. Save events to file\n7. Load events from file\n8. Save results to file\n9. Load results from file\n10. Display athletes\n11. Display events\n12. Display results\n13. Determine winners\n14. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            addAthlete();
            break;
        case 2:
            addEvent();
            break;
        case 3:
            addResult();
            break;
        case 4:
            saveAthletesToFile();
            break;
        case 5:
            loadAthletesFromFile();
            break;
        case 6:
            saveEventsToFile();
            break;
        case 7:
            loadEventsFromFile();
            break;
        case 8:
            saveResultsToFile();
            break;
        case 9:
            loadResultsFromFile();
            break;
        case 10:
            displayAthletes();
            break;
        case 11:
            displayEvents();
            break;
        case 12:
            displayResults();
            break;
        case 13:
            determineWinners();
            break;
        case 14:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 14);
}
