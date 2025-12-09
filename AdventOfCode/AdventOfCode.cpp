// AdventOfCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>


using namespace std;


int dayOne();
long long dayTwo();
long long dayTwoP2();
int dayThree();
long long dayThreeP2();
int dayFour();
int dayFourP2();
int dayFive();
long long dayFiveP2();
long long daySix();
long long daySixP2();
int daySeven();
long long daySevenP2();
int dayEight();
int dayEightP2();
long long dayNine();
long long dayNineP2();

int main()
{


    cout << dayNineP2();

    return 0;
}



int dayOne() {



    // open file
    ifstream inFile;
    inFile.open("DayOneInput.txt", ifstream::in);

    // declare variables
    string line;
    int count = 0;
    int position = 50;

    // loop over file
    while (getline(inFile, line)) {
        // get amout to change by
        int change = stoi(line.substr(1,4));
        if (line[0] == 'L')
            change = -change;
        // apply change and loop
        position += change;


        // count over 100
        if (position >= 100) {
            count += position / 100;
        }
        // count < 0
        else if (position <= 0) {
            // check if we started at 0 or passed it
            if (position != change)
                count += 1;
            count += -position / 100;
            // loop back to positive
            position += (-position / 100) * 100 + 100;
        }

        // loop back to below 100
        position = position % 100;




        // remove part 1 counting
        // increment count
        //if (position == 0)
        //    count += 1;

    }

    cout << count;


    return 0;


}


long long dayTwo() {
    // open file
    ifstream inFile;
    inFile.open("DayTwoInput.txt", ifstream::in);

    // declare variables
    string line;
    getline(inFile, line);
    long long total = 0;

    // loop over file
    while (line.length() > 0) {
        
        
        // get range from line
        string range = line.substr(0, line.find(','));
        if (line.find(',') != -1)
            line = line.substr(line.find(',') + 1, line.length());
        else
            line = "";


        // get ids from range
        long long first = stoll(range.substr(0, range.find('-')));
        long long last = stoll(range.substr(range.find('-') + 1, range.length()));


        cout << "Checking values between " << first << " and " << last << "\n";

        // iterate over each id
        while (first <= last) {

            
            // if first half of number == second half, increase
            string number = to_string(first);


            if (number.length() % 2 == 0 and number.substr(0, number.length() / 2) == number.substr(number.length() / 2, number.length() / 2)) {
                total += first;
                cout << "Invalid id: " << number << " New total: " << total << endl;

            }

            first += 1;
        }




        

    }


    return total;
}


long long dayTwoP2() {
    // open file
    ifstream inFile;
    inFile.open("DayTwoInput.txt", ifstream::in);

    // declare variables
    string line;
    getline(inFile, line);
    long long total = 0;

    // loop over file
    while (line.length() > 0) {


        // get range from line
        string range = line.substr(0, line.find(','));
        if (line.find(',') != -1)
            line = line.substr(line.find(',') + 1, line.length());
        else
            line = "";


        // get ids from range
        long long first = stoll(range.substr(0, range.find('-')));
        long long last = stoll(range.substr(range.find('-') + 1, range.length()));


        cout << "Checking values between " << first << " and " << last << "\n";

        // iterate over each id
        while (first <= last) {


            string number = to_string(first);

            // Iterate over repeating char lengths
            for (int i = 1; i < 6; i++) {
                // If divisible by length
                if (number.length() % i == 0 and number.length() != i)
                {
                    string repeatingSequence = number.substr(0, i);
                    bool allRepeating = true;
                    // iterate over substrings
                    for (int j = 1; j < number.length() / i; j++) {
                        if (repeatingSequence != number.substr(j * i, i))
                        {
                            allRepeating = false;
                            break;
                        }

                    }
                    if (allRepeating == true)
                    {
                        cout << "Invalid id: " << number << endl;
                        total += first;
                        break;
                    }

                }
            }

            first += 1;
        }






    }


    return total;
}

int dayThree() {
    // open file
    ifstream inFile;
    inFile.open("DayThreeInput.txt", ifstream::in);

    // declare variables
    string line;

    int total = 0;

    while (getline(inFile, line)) {
        int maxValue = 0;
        int maxIndex = 0;
        for (int i = 0; i < line.length()-1; i++) {
            int currentNum = stoi(line.substr(i, 1));
            if (currentNum > maxValue)
            {
                maxValue = currentNum;
                maxIndex = i;
            }
        }
        line = line.substr(maxIndex + 1, line.length());
        int secondValue = 0;
        for (int i = 0; i < line.length(); i++) {
            int currentNum = stoi(line.substr(i, 1));
            if (currentNum > secondValue)
            {
                secondValue = currentNum;
            }
        }


        cout << "Values are: " << maxValue << secondValue << endl;
        total += maxValue * 10 + secondValue;
        
    }


    return total;

}

long long dayThreeP2() {
    // open file
    ifstream inFile;
    inFile.open("DayThreeInput.txt", ifstream::in);

    // declare variables
    string line;

    long long total = 0;

    

    while (getline(inFile, line)) {

        cout << "Line: " << line << endl << "Values are: ";

        for (int i = 11; i >= 0; i--) {
            int maxValue = 0;
            int maxIndex = 0;
            for (int j = 0; j < line.length() - i; j++) {
                int currentNum = stoi(line.substr(j, 1));
                if (currentNum > maxValue)
                {
                    maxValue = currentNum;
                    maxIndex = j;
                }
            }
            line = line.substr(maxIndex + 1, line.length());
            total += (maxValue * pow(10,i));
            cout << maxValue;
        }


        cout << endl;

    }


    return total;

}



const int DAY_FOUR_LINE_LENGTH = 136;
int dayFour() {

    // open file
    ifstream inFile;
    inFile.open("DayFourInput.txt", ifstream::in);

    // Populate map
    char map[DAY_FOUR_LINE_LENGTH+1][DAY_FOUR_LINE_LENGTH+1];
    for (int i = 0; i < DAY_FOUR_LINE_LENGTH; i++) {
        inFile.getline(map[i], DAY_FOUR_LINE_LENGTH+1);
    }
    
    int total = 0;

    for (int x = 0; x < DAY_FOUR_LINE_LENGTH; x++) {
        for (int y = 0; y < DAY_FOUR_LINE_LENGTH; y++) {
            if (map[x][y] == '.')
                continue;

            int occupied_count = 0;

            for (int x_offset = -1; x_offset < 2; x_offset++) {
                for (int y_offset = -1; y_offset < 2; y_offset++) {

                    int x_pos = x + x_offset;
                    int y_pos = y + y_offset;

                    if (x_pos < 0 or x_pos >= DAY_FOUR_LINE_LENGTH or y_pos < 0 or y_pos >= DAY_FOUR_LINE_LENGTH)
                        continue;
                    if (map[x_pos][y_pos] == '@')
                        occupied_count += 1;


                }
            }

            if (occupied_count <= 4)
                total += 1;






        }
    }

    return total;

}

int dayFourP2() {

    // open file
    ifstream inFile;
    inFile.open("DayFourInput.txt", ifstream::in);

    // Populate map
    char map[DAY_FOUR_LINE_LENGTH + 1][DAY_FOUR_LINE_LENGTH + 1];
    for (int i = 0; i < DAY_FOUR_LINE_LENGTH; i++) {
        inFile.getline(map[i], DAY_FOUR_LINE_LENGTH + 1);
    }

    int total = 0;
    bool papersRemoved = true;
    
    while (papersRemoved) {
        papersRemoved = false;
        // Find every paper to remove
        for (int x = 0; x < DAY_FOUR_LINE_LENGTH; x++) {
            for (int y = 0; y < DAY_FOUR_LINE_LENGTH; y++) {
                if (map[x][y] == '.')
                    continue;

                int occupied_count = 0;

                for (int x_offset = -1; x_offset < 2; x_offset++) {
                    for (int y_offset = -1; y_offset < 2; y_offset++) {

                        int x_pos = x + x_offset;
                        int y_pos = y + y_offset;

                        if (x_pos < 0 or x_pos >= DAY_FOUR_LINE_LENGTH or y_pos < 0 or y_pos >= DAY_FOUR_LINE_LENGTH)
                            continue;
                        if (map[x_pos][y_pos] == '@' or map[x_pos][y_pos] == 'x')
                            occupied_count += 1;


                    }
                }

                if (occupied_count <= 4) {
                    total += 1;
                    map[x][y] = 'x';
                    papersRemoved = true;
                }








            }
        }
        // Remove all marked papers
        for (int x = 0; x < DAY_FOUR_LINE_LENGTH; x++) {
            for (int y = 0; y < DAY_FOUR_LINE_LENGTH; y++) {
                if (map[x][y] == 'x')
                    map[x][y] = '.';
            }
        }
    }




    return total;

}

int dayFive() {

    // open file
    ifstream inFile;
    inFile.open("DayFiveInput.txt", ifstream::in);

    string line;
    getline(inFile, line);

    vector<pair<long long, long long>> ranges;

    while (line.length() > 0) {
        // get ids from range


        long long first = stoll(line.substr(0, line.find('-')));
        long long last = stoll(line.substr(line.find('-') + 1, line.length()));

        cout << "Adding ids of range " << line << "..." << endl;

        ranges.push_back(make_pair(first, last));

        getline(inFile, line);
    }

    int total = 0;

    while (getline(inFile, line)) {
        long long id = stoll(line);
        for (pair<long long, long long> current_range: ranges) {
            if (current_range.first <= id and current_range.second >= id) {
                total += 1;
                cout << "Set contains " << line << " between " << current_range.first << " and " << current_range.second << " so it is fresh" << endl;
                break;
            }
        }
    }

    return total;




}

long long dayFiveP2() {

    // open file
    ifstream inFile;
    inFile.open("DayFiveInput.txt", ifstream::in);

    string line;
    getline(inFile, line);

    vector<pair<long long, long long>> ranges;

    while (line.length() > 0) {
        // get ids from range


        long long first = stoll(line.substr(0, line.find('-')));
        long long second = stoll(line.substr(line.find('-') + 1, line.length()));

        

        

        vector<int> overlapped_indices;
        long long min_value = first;
        long long max_value = second;


        for (int i = 0; i < ranges.size(); i++) {
            

            pair<long long, long long> current_range = ranges[i];

            // any range endpoints overlap
            if ((current_range.first >= first and current_range.first <= second)
                or (current_range.second >= first and current_range.second <= second)
                or (first >= current_range.first and first <= current_range.second)
                or (second >= current_range.first and second <= current_range.second)) 
            {
                min_value = min(min_value, current_range.first);
                max_value = max(max_value, current_range.second);
                overlapped_indices.push_back(i);

            }
        }

        // erase is weird with the pairs of longs
        for (int index : overlapped_indices)
            ranges[index] = make_pair(-1,-1);
        
        
        ranges.push_back(make_pair(min_value, max_value));
        getline(inFile, line);

    }
    
    long long total = 0;
    for (pair<long long, long long> current_range : ranges) {
        if (current_range.first == -1)
            continue;
        cout << "Adding values between: " << current_range.first << " and " << current_range.second << endl;
        total += current_range.second - current_range.first + 1;

    }
    return total;
}

long long daySix() {

    // open file
    ifstream inFile;
    inFile.open("DaySixInput.txt", ifstream::in);
    string line;


    vector<vector<int>> values;


    while (getline(inFile, line)) {
        if (line[0] == '*')
            break;


        vector<int> row_values;
        while (line.size() > 0) {
            while (line[0] == ' ')
                line = line.substr(1, line.length());
            // put first num of line into vector
            if (line.find(' ') == -1) {
                row_values.push_back(stoi(line));
                line = "";
            }
            else {
                row_values.push_back(stoi(line.substr(0, line.find(' '))));
                line = line.substr(line.find(' ') + 1, line.length());
            }


        }
        values.push_back(row_values);

    }


    long long total = 0;
    for (int i = 0; i < values[0].size(); i++) {
        long long result = values[0][i];
        for (int j = 1; j < values.size(); j++) {
            if (line[0] == '*')
                result = result * values[j][i];
            else
                result += values[j][i];
        }
        total += result;
        do {
            line = line.substr(1, line.length());
        } while (line[0] == ' ' and line.length() > 0);
    }
    return total;

}



long long daySixP2() {


    // open file
    ifstream inFile;
    inFile.open("DaySixInput.txt", ifstream::in);
    string line;

    vector<string> lines;
    vector<vector<string>> values;


    // put all lines into vector
    while (getline(inFile, line)) {
        lines.push_back(line);
    }
    // find column breaks, put each column into vector
    int i = 0;
    while (lines[0].size() > 0) {
        
        
        bool is_column = true;
        
        if (i < lines[0].length()) {
            for (int j = 0; j < lines.size(); j++) {
                if (lines[j][i] != ' ')
                    is_column = false;
            }
        }




        if (is_column) {
            vector<string> column;
            for (int j = 0; j < lines.size(); j++) {
                column.push_back(lines[j].substr(0, i));
                if (i < lines.back().size())
                    lines[j] = lines[j].substr(i + 1, lines[0].length());
                else
                    lines[j] = "";
            }
            i = -1;
            values.push_back(column);
        }
        i++;
    }

    long long total = 0;
    // for each column
    for (vector<string> column : values) {
        long long result = 0;
        // for each character
        for (int i = 0; i < column[0].size(); i++) {
            string number;
            
            // for each row excluding sign
            for (int j = 0; j < column.size() - 1; j++) {
                if (column[j][i] != ' ') {
                    number += column[j][i];
                }
            }
            // add number to result
            if (number.size() > 0) {
                int value = stoi(number);
                if (result == 0)
                    result = value;
                else {
                    if (column.back()[0] == '*')
                        result = result * value;
                    else
                        result += value;
                }
            }
        }
        total += result;
    }




    return total;
}

int daySeven() {
    // open file
    ifstream inFile;
    inFile.open("DaySevenInput.txt", ifstream::in);
    string line;

    set<int> beam_indices;
    getline(inFile, line);
    beam_indices.insert(line.find('S'));


    int total = 0;
    while (getline(inFile, line)) {
        set<int> new_indices;
        for (int index : beam_indices) {
            if (line[index] == '^') {
                new_indices.insert(index - 1);
                new_indices.insert(index + 1);
                total++;
            }
            else
                new_indices.insert(index);
        }
        beam_indices = new_indices;


    }
    return total;
}

long long daySevenP2() {
    // open file
    ifstream inFile;
    inFile.open("DaySevenInput.txt", ifstream::in);
    string line;

    map<int,long long> beam_indices;
    getline(inFile, line);
    beam_indices.insert({ int(line.find('S')),1 });

    while (getline(inFile, line)) {
        map<int,long long> new_indices;
        for (auto const& [key, val] : beam_indices) {
            if (line[key] == '^') {
                if (new_indices.contains(key - 1))
                    new_indices[key - 1] += val;
                else
                    new_indices.insert({ key - 1, val });
                if (new_indices.contains(key + 1))
                    new_indices[key + 1] += val;
                else
                    new_indices.insert({key + 1, val});
            }
            else
                if (new_indices.contains(key))
                    new_indices[key] += val;
                else
                    new_indices.insert({ key, val });
        }
        beam_indices = new_indices;
    }
    long long prev_total = 0;
    long long total = 0;
    for (auto const& [key, val] : beam_indices) {
        prev_total = total;
        total += val;
        if (prev_total > total)
            cout << "uh oh";
    }


    //return total;
    return total;

}



struct Vector3 {
    long long x;
    long long y;
    long long z;

    Vector3(long long x, long long y, long long z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double distance_to(Vector3 other) {
        long long d_x = x - other.x;
        long long d_y = y - other.y;
        long long d_z = z - other.z;


        return sqrt((d_x * d_x) + (d_y * d_y) + (d_z * d_z));
    }

};
struct Connection {
    int first_index;
    int second_index;
    double distance;

    Connection(int first, int second, double distance) {
        first_index = first;
        second_index = second;
        this->distance = distance;
    }

    bool operator == (const Connection& other) { return distance == other.distance; }
    bool operator > (const Connection& other) { return distance > other.distance; }
    bool operator < (const Connection& other) { return distance < other.distance; }
};
struct Circuit {
    set<int> values;

    Circuit() {}

    bool operator == (const Circuit& other) { return values.size() == other.values.size(); }
    bool operator > (const Circuit& other) { return values.size() < other.values.size(); }
    bool operator < (const Circuit& other) { return values.size() > other.values.size(); }

};



const int CONNECTION_COUNT = 1000;
int dayEight() {
    // open file
    ifstream inFile;
    inFile.open("DayEightInput.txt", ifstream::in);
    string line;
    
    // Get all positions
    vector<Vector3> points;
    while (getline(inFile, line)) {
        long long x = stoi(line.substr(0, line.find(',')));
        long long y = stoi(line.substr(line.find(',') + 1, line.find_last_of(',')));
        long long z = stoi(line.substr(line.find_last_of(',')+1, line.length()));
        points.push_back(Vector3(x, y, z));
    }
    
    // Find every connection distance
    vector<Connection> connections;
    // for each point

    int real_count = 0;
    for (int i = 0; i < points.size(); i++) {
        // for each proceeding point
        for (int j = i + 1; j < points.size(); j++) {
            
            double distance = points[i].distance_to(points[j]);
            if (distance != distance) {
                cout << "Not a number!!!";
            }

            connections.push_back(Connection(i, j, distance));

        }

    }
    // Sort the distances
    sort(connections.begin(), connections.end());


    for (Connection c : connections) {
        //cout << c.distance << endl;
    }


    vector<Circuit> circuits;

    for (int i = 0; i < CONNECTION_COUNT; i++) {
        int first = connections[i].first_index;
        int second = connections[i].second_index;
        cout << "Adding the values: " << first << " " << second << "... ";
        bool inserted = false;
        int inserted_index = 0;
        bool double_inserted = false;
        int double_index = 0;

        // For each circuit
        for (int j = 0; j < circuits.size(); j++) {
            
            // If an index is in circuit, add both to circut
            if (circuits[j].values.contains(first) or circuits[j].values.contains(second)) {
                circuits[j].values.insert(first);
                circuits[j].values.insert(second);

                // If we already inserted, its a double insert and we need to merge
                if (inserted) {
                    double_inserted = true;
                    double_index = j;
                }
                else
                    inserted_index = j;


                inserted = true;
                cout << "Inserted into existing set." << endl;
            }
        }
        if (not inserted) {
            Circuit new_circuit = Circuit();
            new_circuit.values.insert(first);
            new_circuit.values.insert(second);
            circuits.push_back(new_circuit);
            cout << "Inserted into new set." << endl;
        }
        // Combine sets
        if (double_inserted) {
            set<int> double_values = circuits[double_index].values;
            circuits[inserted_index].values.insert(double_values.begin(), double_values.end());
            circuits[double_index].values.clear();
        }
    }

    sort(circuits.begin(), circuits.end());





    return circuits[0].values.size() * circuits[1].values.size() * circuits[2].values.size();
}

int dayEightP2() {
    // open file
    ifstream inFile;
    inFile.open("DayEightInput.txt", ifstream::in);
    string line;

    // Get all positions
    vector<Vector3> points;
    while (getline(inFile, line)) {
        long long x = stoi(line.substr(0, line.find(',')));
        long long y = stoi(line.substr(line.find(',') + 1, line.find_last_of(',')));
        long long z = stoi(line.substr(line.find_last_of(',') + 1, line.length()));
        points.push_back(Vector3(x, y, z));
    }

    // Find every connection distance
    vector<Connection> connections;
    // for each point

    int real_count = 0;
    for (int i = 0; i < points.size(); i++) {
        // for each proceeding point
        for (int j = i + 1; j < points.size(); j++) {

            double distance = points[i].distance_to(points[j]);
            if (distance != distance) {
                cout << "Not a number!!!";
            }

            connections.push_back(Connection(i, j, distance));

        }

    }
    // Sort the distances
    sort(connections.begin(), connections.end());


    for (Connection c : connections) {
        //cout << c.distance << endl;
    }


    vector<Circuit> circuits;

    int i = 0;
    // Iterate until all connected

    int first = 0;
    int second = 0;

    while (circuits.size() == 0 or circuits[0].values.size() < points.size()) {
        first = connections[i].first_index;
        second = connections[i].second_index;
        cout << "Adding the values: " << first << " " << second << "... ";
        bool inserted = false;
        int inserted_index = 0;
        bool double_inserted = false;
        int double_index = 0;

        // For each circuit
        for (int j = 0; j < circuits.size(); j++) {

            // If an index is in circuit, add both to circut
            if (circuits[j].values.contains(first) or circuits[j].values.contains(second)) {
                circuits[j].values.insert(first);
                circuits[j].values.insert(second);

                // If we already inserted, its a double insert and we need to merge
                if (inserted) {
                    double_inserted = true;
                    double_index = j;
                }
                else
                    inserted_index = j;


                inserted = true;
                cout << "Inserted into existing set." << endl;
            }
        }
        if (not inserted) {
            Circuit new_circuit = Circuit();
            new_circuit.values.insert(first);
            new_circuit.values.insert(second);
            circuits.push_back(new_circuit);
            cout << "Inserted into new set." << endl;
        }
        // Combine sets
        if (double_inserted) {
            set<int> double_values = circuits[double_index].values;
            circuits[inserted_index].values.insert(double_values.begin(), double_values.end());
            circuits[double_index].values.clear();
        }
        i++;
    }

    //sort(circuits.begin(), circuits.end());





    return points[first].x * points[second].x;
}



long long dayNine() {
    // open file
    ifstream inFile;
    inFile.open("DayNineInput.txt", ifstream::in);
    string line;


    long long largest = 0;
    vector<pair<int, int>> points;

    while (getline(inFile, line)) {
        int first = stoi(line.substr(0, line.find(',')));
        int second = stoi(line.substr(line.find(',') + 1, line.length()));

        //cout << "Comparing point " << first << "," << second << endl;

        for (int i = 0; i < points.size(); i++) {
            long long width = abs(first - points[i].first)+1;
            long long height = abs(second - points[i].second)+1;
            long long size = width * height;

            //cout << "With point " << points[i].first << "," << points[i].second << " makes size " << size << endl;

            if (size > largest)
                largest = size;

        }
        points.push_back(make_pair(first, second));
    }

    return largest;
}

long long dayNineP2() {
    // open file
    ifstream inFile;
    inFile.open("exampleInput.txt", ifstream::in);
    string line;


    long long largest = 0;
    vector<pair<int, int>> points;
    set<pair<int, int>> allowed_tiles;

    while (getline(inFile, line)) {
        int first = stoi(line.substr(0, line.find(',')));
        int second = stoi(line.substr(line.find(',') + 1, line.length()));
        
        pair<int, int> current_point = make_pair(first, second);

        // Add green tiles going to point
        if (points.size() > 0) {
            pair<int, int> previous_point = points.back();

            // Get distance and direction of current_point
            int x_distance = current_point.first - previous_point.first;
            int y_distance = current_point.second - previous_point.second;



            for (int i = 0; i < max(abs(x_distance),abs(y_distance)); i++) {
                allowed_tiles.insert(make_pair(previous_point.first + .first * distance, previous_point.second + direction.second * distance));
            }
        }

        
        points.push_back(current_point);



    }

    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            long long width = abs(points[j].first - points[i].first) + 1;
            long long height = abs(points[j].second - points[i].second) + 1;
            long long size = width * height;

            if (size > largest)
                largest = size;
        }
    }


    return largest;
}