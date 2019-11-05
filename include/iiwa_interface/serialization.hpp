/*
 * serializer.hpp
 *
 *  Created on: Nov 5, 2019
 *      Author: rosdeveloper
 */

#ifndef INCLUDE_IIWA_INTERFACE_SERIALIZATION_HPP_
#define INCLUDE_IIWA_INTERFACE_SERIALIZATION_HPP_

#include <vector>

int serializeNext(int integer_in, std::vector<char>& serialized_out){
  char* bytes = reinterpret_cast<char*>(&integer_in);
  serialized_out.insert(serialized_out.end(), bytes, bytes + sizeof(int));
  //TODO: assert that int is 4 bytes long
  //TODO: check endiannes
  return sizeof(int);
}

int deserializeNext(const std::vector<char>& serialized_in, int& integer_out){
  if(serialized_in.size() < sizeof(int)){
    //TODO: error
  }
  integer_out = *(reinterpret_cast<int*>(serialized_in.data()));
  return sizeof(int);
}



#endif /* INCLUDE_IIWA_INTERFACE_SERIALIZATION_HPP_ */