//
// HttpRequest.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Mon Aug 11 11:14:24 2008 morgan armand
// Last update Tue Aug 12 18:45:35 2008 caner candan
//

#include <sstream>
#include "HttpRequest.h"

HttpRequest::HttpRequest()
{
  _httpUrl.getHost().setPort(80);
}

const std::string&	HttpRequest::VersionProtocol::getName() const
{
  return (this->_name);
}

const int&	HttpRequest::VersionProtocol::getMajor() const
{
  return (this->_major);
}

const int&	HttpRequest::VersionProtocol::getMinor() const
{
  return (this->_minor);
}

const std::string&	HttpRequest::VersionProtocol::getOtherVersion() const
{
  return (this->_otherVersion);
}

void	HttpRequest::VersionProtocol::setName(const std::string& name)
{
  this->_name = name;
}

void	HttpRequest::VersionProtocol::setMajor(const int& major)
{
  this->_major = major;
}

void	HttpRequest::VersionProtocol::setMinor(const int& minor)
{
  this->_minor = minor;
}

void	HttpRequest::VersionProtocol::setOtherVersion(const std::string& otherVersion)
{
  this->_otherVersion = otherVersion;
}

const std::string&	HttpRequest::Host::getHostname() const
{
  return (this->_hostname);
}

const int&	HttpRequest::Host::getPort() const
{
  return (this->_port);
}

void	HttpRequest::Host::setHostname(const std::string& hostname)
{
  this->_hostname = hostname;
}

void	HttpRequest::Host::setPort(const int& port)
{
  this->_port = port;
}

HttpRequest::Host&	HttpRequest::HttpUrl::getHost()
{
  return (this->_host);
}

const std::string&	HttpRequest::HttpUrl::getAbsPath() const
{
  return (this->_absPath);
}

const std::string&	HttpRequest::HttpUrl::getQuery() const
{
  return (this->_query);
}

void	HttpRequest::HttpUrl::setAbsPath(const std::string& absPath)
{
  this->_absPath = absPath;
}

void	HttpRequest::HttpUrl::setQuery(const std::string& query)
{
  this->_query = query;
}

const std::string&	HttpRequest::Type::getMajor() const
{
  return (this->_major);
}

const std::string&	HttpRequest::Type::getMinor() const
{
  return (this->_minor);
}

const HttpRequest::mapKey&	HttpRequest::Type::getParam() const
{
  return (this->_param);
}

const HttpRequest::listString&	HttpRequest::Type::getParam(const std::string& key)
{
  return (this->_param[key]);
}

const std::string&	HttpRequest::Type::getParam(const std::string& key,
						    const int& pos)
{
  listString::const_iterator	it;
  listString::const_iterator	end = this->_param[key].end();
  int				i;

  i = 0;
  for (it = this->_param[key].begin(); it != end; ++it)
    if (i == pos)
      return (*it);
  return (*it);
}

void	HttpRequest::Type::setMajor(const std::string& major)
{
  this->_major = major;
}

void	HttpRequest::Type::setMinor(const std::string& minor)
{
  this->_minor = minor;
}

void	HttpRequest::Type::addParam(const std::string& key,
				    const std::string& value)
{
  this->_param[key].push_back(value);
}

const std::string&	HttpRequest::Warning::getCode() const
{
  return (this->_code);
}

const std::string&	HttpRequest::Warning::getAgent() const
{
  return (this->_agent);
}

const std::string&	HttpRequest::Warning::getText() const
{
  return (this->_text);
}

const std::string&	HttpRequest::Warning::getDate() const
{
  return (this->_date);
}

void	HttpRequest::Warning::setCode(const std::string& code)
{
  this->_code = code;
}

void	HttpRequest::Warning::setAgent(const std::string& agent)
{
  this->_agent = agent;
}

void	HttpRequest::Warning::setText(const std::string& text)
{
  this->_text = text;
}

void	HttpRequest::Warning::setDate(const std::string& date)
{
  this->_date = date;
}

const std::string&	HttpRequest::getMethod() const
{
  return (this->_method);
}

HttpRequest::HttpUrl&	HttpRequest::getHttpUrl()
{
  return (this->_httpUrl);
}

HttpRequest::VersionProtocol&	HttpRequest::getVersionProtocol()
{
  return (this->_versionProtocol);
}

const std::string&	HttpRequest::getPath() const
{
  return (this->_path);
}

void	HttpRequest::setMethod(const std::string& method)
{
  this->_method = method;
}

void	HttpRequest::setPath(const std::string& path)
{
  this->_path = path;
}
