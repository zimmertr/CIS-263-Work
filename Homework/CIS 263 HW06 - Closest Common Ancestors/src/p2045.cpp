//
//  2045 Closest Common Ancestor
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[])
{
    ifstream input (argv[1]);
    int N;
    while (input >> N) {
        std::cerr << "New data set" << std::endl;

        for (int k = 0; k < N; k++) /* read the tree structure */
        {
            char ignore_me;
            int parent, child, num_children;
            input >> parent >> std::ws >> ignore_me >> std::ws >> ignore_me;
            input >> num_children >> std::ws >> ignore_me;
            for (int n = 0; n < num_children; n++)
            {
                input >> child;
            }
        }

        int Npairs;
        input >> Npairs;

        /* read the pair inquiries */
        for (int k = 0; k < Npairs; k++)
        {
            char ignore_me;
            int n1, n2;
            input >> ws >> ignore_me >> n1 >> n2 >> ws >> ignore_me;
            cerr << "Who is the common ancestor of " << n2 <<
                " and " << n2 << "?" << endl;
        }
    }
    return 0;
}

