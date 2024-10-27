#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<vector<int>> vect {{1, 0, 1}, {0, 1}, {1, 0, 1}}; 

    cout << "Using Indexing\n";

    int row_size = vect.size();    
    for (int i = 0; i < row_size; i++)
    {
        int col_size = vect[i].size();

        for (int j = 0; j < col_size; j++)
        {
            cout << vect[i][j] << " ";
        }

        cout << "\n";
    }


    cout << "Using Range-based for loops\n";

    for (auto &r: vect)
    {
        for (auto &c:r)
        {
            cout << c <<" ";
        }

        cout <<"\n";
    }

    cout << "Using std::for_each\n";

    for_each(vect.begin(), vect.end(), [](const auto & row){
        for_each(row.begin(), row.end(), [](const auto & col){
            cout << col << " ";
        });

        cout <<"\n";
    });


    cout << "Using Iterator 1\n";

	for(auto i = vect.begin() ; i < vect.end() ; i++)
    {
        for(auto j = i->begin() ; j < i->end() ; j++)
            cout << *j <<" ";
        cout <<"\n";  
    }
    
    cout << "Using Iterators 2\n";
    

    for(vector<vector<int>>::iterator row = vect.begin(); row != vect.end(); row++ )
    {
        for(vector<int>::iterator col = (*row).begin(); col != (*row).end(); col++ )
        {
            cout << (*col) << " ";
        }

        cout << "\n";
    }

}