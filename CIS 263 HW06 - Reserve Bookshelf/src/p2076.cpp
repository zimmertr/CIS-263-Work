
    #include <iostream>
    #include <iomanip>
    #include <fstream>
    #include <cstring>
    #include <stdio.h>
    #include <stdlib.h>
    #include <map>
    #include <list>
    using namespace std;

    int main(int argc, const char * argv[]) {
            ifstream input(argv[1]);
            int availableSpace, thickness;
            string command, title;
            map<string, pair<bool, int>> myMap;
            list<string> bookshelf;

            input >> availableSpace;
            while (input >> command) {
                    input >> std::ws;
                    if (command == "ADD") {

                            getline(input, title);
                            auto pos = title.find_last_of(' ');
                            thickness = atoi(title.substr(pos, title.size()).c_str());
                            title = title.substr(0, pos);
                            auto pos2 = title.find_last_not_of(' ') + 1;
                            title = title.substr(0, pos2);

                            // Begin work
                            bookshelf.push_front(title);
                            myMap[title].first = true;
                            myMap[title].second = thickness;
                            availableSpace -= thickness;
                            while (availableSpace < 0) {
                                    availableSpace += myMap[bookshelf.back()].second;
                                    myMap.erase(myMap.find(bookshelf.back()));
                                    bookshelf.pop_back();
                            }
                            //cerr << "Adding " << title << " with thickness " << thickness
                            //              << endl;
                    }
                    else if (command == "CHECKOUT") {
                            getline(input, title);

                            auto pos = title.find_last_not_of(' ') + 1;
                            title = title.substr(0, pos);
                            myMap[title].first = false;
                            bookshelf.remove(title);
                            availableSpace += myMap[title].second;

                            //cerr << "Checking out " << title << endl;
                    }
                    else if (command == "RETURN") {
                            getline(input, title);
                            myMap[title].first = true;
                            availableSpace -= myMap[title].second;
                            bookshelf.push_front(title);
                            while (availableSpace < 0) {
                                    availableSpace += myMap[bookshelf.back()].second;
                                    myMap.erase(myMap.find(bookshelf.back()));
                                    bookshelf.pop_back();
                            }
                    }
                    else
                	{
                            for (string x : bookshelf) {
                                    cout << x << "\t" << myMap[x].second << endl;
                            }
                            cout << "AVAILABLE SHELF SPACE:" << "\t" << "\t" << availableSpace
                                            << endl;
                            cout << "\n";
                    }
            }
            return 0;
    }

