#include <iostream>
#include <list>

using namespace std;

list<int> removeCommonints(list<int>);
void print_list(list<int>);
bool compareint(int line1, int line2);
std::list<int> removeint(std::list<int> lines, int val);

int main()
{
    list<int> lines     = {45, 453, 46, 47, 46, 4, 1, 2, 45};
    list<int> new_lines = removeCommonints(lines);
    print_list(lines);
    print_list(new_lines);
    return 0;
}

std::list<int> removeCommonints(std::list<int> lines)
{
    /**
     * This method is used remove duplicate lines from the given line
     * list, this will only for the specific case I have. If a duplicate
     * is found both the original and the duplicate are removed from the
     * list. This is done to eliminate inner line-segments of the
     * translated structure.
     */
    std::list<int> new_lines = lines;

    while (!lines.empty()) {
        int line1 = lines.front();  // Get the 1st line from the list
        lines.pop_front();          // Remove the same line from the list
        for (list<int>::iterator it = lines.begin(); it != lines.end(); ++it)
            if (compareint(line1, *it))                   // Compare to see if same lines exists
                new_lines = removeint(new_lines, line1);  // new_lines.remove(line1);
    }

    return new_lines;
}

void print_list(list<int> print_me)
{
    cout << "(";
    for (list<int>::iterator it = print_me.begin(); it != print_me.end();) {
        cout << *it;
        it++;
        if (it != print_me.end()) cout << ", ";
    }
    cout << ")\n";
}

bool compareint(int line1, int line2)
{
    /**
     * Just to clarify we obviously don't need this in real life. This
     * actually compares lines strcuts, this is just a test repo.
     */
    if (line1 == line2)
        return true;
    else
        return false;
}

std::list<int> removeint(std::list<int> lines, int val)
{
    /**
     * Override function for list::remove rewritten for list<Line>
     */
    for (list<int>::iterator it = lines.begin(); it != lines.end();) {
        if (compareint(val, *it))  // If same lines exists
            it = lines.erase(it);
        else
            ++it;
    }
    return lines;
}
