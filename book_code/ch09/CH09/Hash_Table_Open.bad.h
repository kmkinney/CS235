#ifndef HASH_TABLE_OPEN_H_
#define HASH_TABLE_OPEN_H_

/** Implementaion of the hash_map class using open hashing */

#include <stdexcept>
#include <cstddef>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <ostream>
#include "hash.h"

namespace KW
{
/** Definition of the hash_map class. This definition is similar
    to the unordered_map that has been proposed for the next
    version of the C++ standard.
    @param Key_Type The type of the keys
    @param Value_Type The type of the values
*/
template<typename Key_Type, typename Value_Type>
  class hash_map {
    
    public:
    
    // Typedefs
    typedef std::pair<const Key_Type, Value_Type> Entry_Type;

    // Forward declaration of iterator
    class iterator;
    class const_iterator;
    
    /** Construct an empty hash_map. */
    hash_map() :
      hash_fcn(hash<Key_Type>()), num_keys(0), 
      the_table(INITIAL_CAPACITY, NULL),
      LOAD_THRESHOLD(0.75), 
      num_deletes(0) 
      {}
    /** Copy Constructor.
	@param other The other map to be copied
    */
    hash_map(const hash_map<Key_Type, Value_Type>& other) :
      hash_fcn(hash<Key_Type>()), num_keys(0), 
      the_table(other.the_table.size(), NULL),
      LOAD_THRESHOLD(0.75), 
      num_deletes(0) 
      {
	for (size_t i = 0; i < other.the_table.size(); i++) {
	  if (other.the_table[i] != NULL && other.the_table[i] != DELETED)
	    insert(Entry_Type(other.the_table[i]->first, 
			      other.the_table[i]->second));
	}
      }
    /** Assignment operator 
	@param other The other map to be assigned
	@return This map after assignment
    */
    hash_map<Key_Type, Value_Type>& 
      operator=(const hash_map<Key_Type, Value_Type>& other) {
      return *this;
    }
    /** Destructor */
    ~hash_map() {
    }
    /** Swap this hash_map with another */
    void swap(hash_map<Key_Type, Value_Type>& other) {
    }
    /** Inserts an item into the map.
	post: The key is associated with the value in the map.
	@param entry The key, value pair to be inserted
	@return An iterator to the inserted item and true
	if the entry was inserted; an iterator to the existing
	item and false if the item is already present
    */
    std::pair<iterator, bool> insert(const Entry_Type& entry) {
      double load_factor = double(num_keys + num_deletes) / the_table.size();
      if (load_factor > LOAD_THRESHOLD) {
	rehash(); // Double the size of the table.
      }
      // Find the position in the table.
      size_t index = locate(entry.first);
      // See whether it is empty.
      if (the_table[index] == NULL) {
	// Create a new entry.
	the_table[index] = new Entry_Type(entry);
	num_keys++;
	return std::make_pair(iterator(this, index), true);
      } else {
	// Item is already in the table.
	return std::make_pair(iterator(this, index), false);
      }
    }
    
    /** Lookup an item in the map
	@param key The key of the item being sought
	@return An iterator that references a 
	pair<const Key_Type, Value_Type> that
	contains the key and the associated value sought,
	or end() if the key is not in the map.
    */
    iterator find(const Key_Type& key) {
      size_t index = locate(key);
      if (the_table[index] == NULL) {
	return iterator(this, the_table.size());
      } else {
	return iterator(this, index);
      }
    }
    
    const_iterator find(const Key_Type& key) const {
      size_t index = locate(key);
      if (the_table[index] == NULL) {
	return const_iterator(this, the_table.size());
      } else {
	return const_iterator(this, index);
      }
    }
    
    /** Accesses a value in the map, using the key as an index.
	@param key The key of the item being sought
	@return A reference to the associated value. If the
	key was not in the map, a default value is inserted and
	a reference to this value is returned.
    */
    Value_Type& operator[](const Key_Type& key) {
      // Try to insert a dummy item.
      std::pair<iterator, bool> ret = insert(Entry_Type(key, Value_Type()));
      // Return a reference to the value found or inserted.
      return ret.first->second;
    }
    
    /** Remove an item from the map based on a key
	@param key The key of the item to be removed
	@return true if the item removed, false if the item
	was not already in the map
    */
    void erase(const Key_Type& key) {
    }
    
    /** Return an iterator to the beginning of the map */
    iterator begin() {
      iterator return_value(this, 0);
      return_value.advance();
      return return_value;
    }
    
    /** Return a const_iterator to the beginning of the map */
    const_iterator begin() const {
      const_iterator return_value(this, 0);
      return_value.advance();
      return return_value;
    }
    
    /** Return an iterator to the end of the map */
    iterator end() {
      return iterator(this, the_table.size());
    }
    
    /** Return an iterator to the end of the map */
    const_iterator end() const {
      return const_iterator(this, the_table.size());
    }
    
    
    /** Determine if the map is empty */
    bool empty() const {return num_keys == 0;}
    
    /*</exercise chapter="9" section="4" type="programming" number="4">*/
    /** Return a string representation of the hash map 
	@return A string that contains each pair enclosed in "[" and "]"
	with the key and value separated by a comma. The whole string
	is enclosed in "{" and "}" 
    */
    std::string to_string() const {
      std::ostringstream result;
      result << "{";
      const_iterator itr = begin();
      if (itr != end()) {
	result << "[" << itr->first << ", " << itr->second << "]";
	while (++itr != end()) {
	  result << ", [" << itr->first << ", " << itr->second << "]";
	}
      }
      result << "}";
      return result.str();
    }
    /*</exercise>*/

