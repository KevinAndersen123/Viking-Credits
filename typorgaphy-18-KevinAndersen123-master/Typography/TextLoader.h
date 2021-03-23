#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "yaml-cpp\yaml.h"

struct CreditData
{
	std::string groupName;
	std::vector<std::string> m_peopleNames;

};
/// <summary>
/// @brief A struct representing all the Level Data.
/// 
/// Obstacles may be repeated and are therefore stored in a container.
/// </summary>
struct LevelData
{
	std::vector<CreditData> groups;
};
static int s_currentGroup{ 0 };
/// <summary>
/// @brief A class to manage level loading.
/// 
/// This class will manage level loading using YAML.
/// </summary>
class TextLoader
{
public:

	/// <summary>
	/// @brief No-op default constructor.
	/// 
	/// </summary>
	TextLoader() = default;

	/// <summary>
	/// @brief Loads and parses the yaml level file.
	/// The level file is identified by a number and is assumed to have
	/// the following format: "level" followed by number followed by .yaml extension
	/// E.g. "level1.yaml"
	/// The level information is stored in the specified LevelData object.
	/// If the filename is not found or the file data is invalid, an exception
	/// is thrown.
	/// </summary>
	/// <param name="nr">The level number</param>
	/// <param name="level">A reference to the LevelData object</param>
	static void load(LevelData& level);
};