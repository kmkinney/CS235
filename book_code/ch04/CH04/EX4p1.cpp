/** Functions for exercises in section 4.1 */
#include <string>
#include "vector.h"
using KW::vector;
using std::string;

/** Finds the first occurrence of target in a_vector.
    @return The index of the first occurrence of the target
            or size if the target is not found
*/
int find(const vector<string>& a_vector, 
         const string& target)
{
}

/** Replaces each occurrence of old_item in a_vector 
    with new_item.
*/
void replace(vector<string>& a_vector,
             const string& old_item,
             const string& new_item)
{
}

/** Removes the first occurrence of target in a_vector. */
template<typename Item_Type>
  void remove(vector<Item_Type>& a_vector, 
              const Item_Type& target)
{
}

#include <iostream>
using std::cout;
using std::endl;

/** Function to test the above functions */
int main()
{
  vector<string> the_vector;
  the_vector.push_back("Tom");
  the_vector.push_back("Dick");
  the_vector.push_back("Harry");
  the_vector.push_back("Sam");
  the_vector.push_back("Dick");

  size_t pos_dick = find(the_vector, "Dick");
  cout << "Found \"Dick\" at postion " << pos_dick;
  if (pos_dick == 1)
    cout << " PASS\n";
  else
    cout << " ****FAIL\n";

  size_t pos_jack = find(the_vector, "Jack");
  if (pos_jack == the_vector.size())
    cout << "Did not find \"Jack\" PASS\n";
  else
    cout << "Found \"Jack\" at position " << pos_jack << " ****FAIL\n";

  replace(the_vector, "Dick", "Richard");
  pos_dick = find(the_vector, "Dick");
  if (pos_jack == the_vector.size())
    cout << "Did not find \"Dick\" PASS\n";
  else
    cout << "Found \"Dick\" at position " << pos_jack << " ****FAIL\n";

  size_t pos_richard = find(the_vector, "Richard");
  cout << "Found \"Richard\" at postion " << pos_richard;
  if (pos_richard == 1)
    cout << " PASS\n";
  else
    cout << " ****FAIL\n";

  remove(the_vector, string("Richard"));
  pos_richard = find(the_vector, "Richard");
  cout << "Found \"Richard\" at postion " << pos_richard;
  if (pos_richard == 3)
    cout << " PASS\n";
  else
    cout << " ****FAIL\n";

  remove(the_vector, string("Richard"));
  pos_richard = find(the_vector, "Richard");
  if (pos_richard == the_vector.size())
    cout << "Did not find \"Richard\" PASS\n";
  else
    cout << "Found \"Richard\" at position " << pos_richard << " ****FAIL\n";

  vector<string> another_vector; // empty vector
  pos_jack = find(another_vector, "Jack");
  if (pos_jack == another_vector.size())
    cout << "Did not find \"Jack\" PASS\n";
  else
    cout << "Found \"Jack\" at position " << pos_jack << " ****FAIL\n";

  replace(another_vector, "Dick", "Jack");
  pos_jack = find(another_vector, "Jack");
  if (pos_jack == another_vector.size())
    cout << "Did not find \"Jack\" PASS\n";
  else
    cout << "Found \"Jack\" at position " << pos_jack << " ****FAIL\n";

  remove(another_vector, string("Jack"));
  pos_jack = find(another_vector, "Jack");
  if (pos_jack == another_vector.size())
    cout << "Did not find \"Jack\" PASS\n";
  else
    cout << "Found \"Jack\" at position " << pos_jack << " ****FAIL\n";
}
