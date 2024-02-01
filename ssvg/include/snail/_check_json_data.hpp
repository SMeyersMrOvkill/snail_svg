#ifndef _CHECK_JSON_DATA_HPP
#define _CHECK_JSON_DATA_HPP 1

#include <boost/json.hpp>

namespace json = boost::json;

bool __snail_check_json_data(const json::value& data) {
  // Check if the data is an object.
  if (!data.is_object()) {
    std::cerr << "Error: Data is not an object." << std::endl;
    return false;
  }

  // Check if the object has three keys: "vertices", "colors", and "objects".
  if (!data.has_key("vertices") || !data.has_key("colors") || !data.has_key("objects")) {
    std::cerr << "Error: Object does not have keys \"vertices\", \"colors\", and \"objects\"." << std::endl;
    return false;
  }

  // Check the "vertices" key.
  const json::value& vertices_value = data["vertices"];
  if (!vertices_value.is_array()) {
    std::cerr << "Error: Value of \"vertices\" key is not an array." << std::endl;
    return false;
  }

  // Check each element of the vertices array.
  for (const json::value& vertex_value : vertices_value) {
    if (!vertex_value.is_array()) {
      std::cerr << "Error: Element of vertices array is not an array." << std::endl;
      return false;
    }

    if (vertex_value.size() != 3) {
      std::cerr << "Error: Element of vertices array does not have three elements." << std::endl;
      return false;
    }

    for (const json::value& vertex_component_value : vertex_value) {
      if (!vertex_component_value.is_number()) {
        std::cerr << "Error: Element of vertices array is not a number." << std::endl;
        return false;
      }
    }
  }

  // Check the "colors" key.
  const json::value& colors_value = data["colors"];
  if (!colors_value.is_array()) {
    std::cerr << "Error: Value of \"colors\" key is not an array." << std::endl;
    return false;
  }

  // Check each element of the colors array.
  for (const json::value& color_value : colors_value) {
    if (!color_value.is_array()) {
      std::cerr << "Error: Element of colors array is not an array." << std::endl;
      return false;
    }

    if (color_value.size() != 3) {
      std::cerr << "Error: Element of colors array does not have three elements." << std::endl;
      return false;
    }

    for (const json::value& color_component_value : color_value) {
      if (!color_component_value.is_number()) {
        std::cerr << "Error: Element of colors array is not a number." << std::endl;
        return false;
      }
    }
  }

  // Check the "objects" key.
  const json::value& objects_value = data["objects"];
  if (!objects_value.is_array()) {
    std::cerr << "Error: Value of \"objects\" key is not an array." << std::endl;
    return false;
  }

  // Check each element of the objects array.
  for (const json::value& object_value : objects_value) {
    if (!object_value.is_object()) {
      std::cerr << "Error: Element of objects array is not an object." << std::endl;
      return false;
    }

    // Check for the "name" key.
    if (!object_value.has_key("name")) {
      std::cerr << "Error: Object in objects array does not have a \"name\" key." << std::endl;
      return false;
    }

    // Check the value of the "name" key.
    const json::value& name_value = object_value["name"];
    if (!name_value.is_string()) {
      std::cerr << "Error: Value of \"name\" key is not a string." << std::endl;
      return false;
    }

    // Check for the "indices" key.
    if (!object_value.has_key("indices")) {
      std::cerr << "Error: Object in objects array does not have an \"indices\" key." << std::endl;
      return false;
    }

    // Check the value of the "indices" key.
    const json::value& indices_value = object_value["indices"];
    if (!indices_value.is_array()) {
      std::cerr << "Error: Value of \"indices\" key is not an array." << std::endl;
      return false;
    }

    // Check each element of the indices array.
    for (const json::value& index_value : indices_value) {
      if (!index_value.is_array()) {
        std::cerr << "Error: Element of indices array is not an array." << std::endl;
        return false;
      }

      if (index_value.size() != 3) {
        std::cerr << "Error: Element of indices array does not have three elements." << std::endl;
        return false;
      }

      for (const json::value& index_component_value : index_value) {
        if (!index_component_value.is_number()) {
          std::cerr << "Error: Element of indices array is not a number." << std::endl;
          return false;
        }
      }
    }
  }

  return true;
}

#endif