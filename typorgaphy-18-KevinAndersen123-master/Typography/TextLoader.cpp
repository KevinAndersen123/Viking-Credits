#include "TextLoader.h"

////////////////////////////////////////////////////////////
void operator >> (const YAML::Node& creditsNode, CreditData& credits)
{
	s_currentGroup++;
	std::stringstream ss;
	ss << "group_name";
	ss << s_currentGroup;

	credits.groupName = creditsNode[ss.str()].as<std::string>();

	int index = 1;
	for (const auto&p : creditsNode["group_list"])
	{
		std::stringstream sr;
		sr << "person_name";
		sr << index;
		credits.m_peopleNames.push_back(p[sr.str()].as<std::string>());
		index++;
	}
}

////////////////////////////////////////////////////////////
void operator >> (const YAML::Node& levelNode, LevelData& creditFile )
{
	const YAML::Node& creditNode = levelNode["Credits"].as<YAML::Node>();
	for (unsigned i = 0; i < creditNode.size(); ++i)
	{
		CreditData group;
		creditNode[i] >> group;
		creditFile.groups.push_back(group);
	}
}

////////////////////////////////////////////////////////////
void TextLoader::load(LevelData& level)
{
	std::stringstream ss;
	ss << "./ASSETS/credits.yaml";
	
	try
	{
		YAML::Node baseNode = YAML::LoadFile(ss.str());
		if (baseNode.IsNull())
		{
			std::string message("File: " + ss.str() + " not found");
			throw std::exception(message.c_str());
		}
		baseNode >> level;
	}
	catch (YAML::ParserException& e)
	{
		std::string message(e.what());
		message = "YAML Parser Error: " + message;
		throw std::exception(message.c_str());
	}
	catch (std::exception& e)
	{
		std::string message(e.what());
		message = "Unexpected Error: " + message;
		throw std::exception(message.c_str());
	}
}


