#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>    // contains std::sort

typedef std::array<double, 2> point;        // um nicht den typen ausschreiben zu müssen, kann man ein alias definieren

std::vector<point> read_points_from_file(std::string filename) {
    double x;
    double y;
    std::vector<point> data;        // point ist alias von std::array<double, 2> wird nur als Beispiel verwendet, weiter unten nicht mehr
    std::ifstream inFile;
    inFile.open(filename);

    // abort if file is not open
    if(!inFile.is_open()) { 
        std::cout << "file has problems" << std::endl;
        return data; 
    }

    // read coordinates from file
    // the stream operator >> handles the spaces in the file
    while(inFile >> x >> y) {
        data.push_back(std::array<double, 2>{x, y});
    }

    return data;
}

void write_points_to_file(std::vector<std::array<double, 2>>& data, std::string filename) {
    std::ofstream outFile;
    outFile.open(filename);

    // abort if file is not open
    if(!outFile.is_open()) { 
        std::cout << "file has problems" << std::endl;
        return; 
    }

    // read coordinates from file
    // the stream operator >> handles the spaces in the file
    for (auto point : data) {
        outFile << point[0] << " " << point[1] << std::endl;
    }
    outFile.close();
}

bool sort_by_y(std::array<double, 2> a, std::array<double, 2> b) {
    if(a[1] < b[1]) return true;
    if(a[1] == b[1] and a[0] < b[0]) return true;

    return false;
}

bool sort_by_angle(std::array<double, 2> a, std::array<double, 2> b) {
    double temp = a[0] * b[1] - a[1] * b[0];

    if(temp > 0) return true;
    if(temp == 0 and std::abs(a[0])> std::abs(b[0])) return true;

    return false;
}

bool point_is_right(std::array<double, 2> a, std::array<double, 2> b, std::array<double, 2> c) {
    double value = (b[0]-a[0]) * (c[1]-a[1]) - (c[0]-a[0]) * (b[1]-a[1]);
    if(value < 0) return true;      // right of vector
    if(value == 0) return true;     // on the vector
    return false;
}

void convex_hull(std::vector<std::array<double, 2>>& points) {
    // sort by y
    std::sort(points.begin(), points.end(), sort_by_y);

    // substract p[0] from all entries
    for(int i = 1; i < points.size(); i++) {
        points[i][0] = points[i][0] - points[0][0];
        points[i][1] = points[i][1] - points[0][1];
    }
    // sort by angle
    std::sort(points.begin()+1, points.end(), sort_by_angle);

    // add p[0] to all entries
    for(int i = 1; i < points.size(); i++) {
        points[i][0] = points[i][0] + points[0][0];
        points[i][1] = points[i][1] + points[0][1];
    }


    // Graham scan
    std::vector<std::array<double, 2>>::iterator element = points.begin() + 1;
    while(element < points.end()) {
        if(point_is_right(*(element-1), *(element+1), *element)) {
            element++;
        }
        else {
            points.erase(element);
            element--;
        }
    }
}

int main() {
    std::vector<std::array<double, 2>> data = read_points_from_file("points.txt");
    
    convex_hull(data);

    write_points_to_file(data, "hull.txt");
}