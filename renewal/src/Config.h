//
// Config.h for zia in /home/toumi_m/zia/renewal
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon Sep  8 13:45:46 2008 majdi toumi
// Last update Sun Sep 21 11:34:48 2008 caner candan
//

#ifndef __CONFIG_H__
# define __CONFIG_H__

# include <string>
# include <map>
# include "IConfig.hpp"
# include "XmlParser.h"
# include "Singleton.hpp"

# define CONFIG_FILE	"../server.xml"

class	Config : public ZenZiAPI::IConfig, public Singleton<Config>
{
  friend class	Singleton<Config>;
public:
  typedef std::map<std::string, std::string>	mapConfig;
public:
  std::string&	getParam(const std::string& param);
  int		getParamInt(const std::string& param);
  OS		getOS();

  XmlParser::listParam	getListParam(const std::string& param);

  void	setParam(const std::string& key,
		 const std::string& value);

  void	setLastParam(const std::string& key);

  void	setXmlParam(const std::string& key,
		    const std::string& path,
		    const std::string& attr);
private:
  Config();

  void	_loadConfig();
private:
  mapConfig	_mapConfig;
  mapConfig	_mapLastConfig;
  XmlParser	_xmlParser;
};

#endif /* !__CONFIG_H__ */
