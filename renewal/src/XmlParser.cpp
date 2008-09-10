//
// XmlParser.cpp for **zia** in /home/toumi_m/zia/renewal/api
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 13:09:45 2008 majdi toumi
// Last update Tue Sep  9 20:06:45 2008 majdi toumi
//

#include <string>
#include <iostream>
#include "XmlParser.h"

using namespace ZenZiAPI;

XmlParser::XmlParser(const std::string& filename)
  : _filename(filename)
{
  ::xmlInitParser();
  this->_doc = ::xmlParseFile(this->_filename.c_str());
  if (!this->_doc)
    {
      std::cerr << "errror - xml file configuration invalid" << std::endl;
      exit(-1);
    }
  this->_root = ::xmlDocGetRootElement(this->_doc);
  if (!this->_root)
    {
      ::xmlFreeDoc(this->_doc);
      std::cerr << "error - xml file configuration is empty" << std::endl;
      exit(-1);
    }
  ::xmlXPathInit();
  this->_ctxt = ::xmlXPathNewContext(_doc);
  if (!this->_ctxt)
    {
      ::xmlFreeDoc(this->_doc);
      std::cerr << "error - can't create xml path context" << std::endl;
      exit(-1);
    }
}

XmlParser::~XmlParser()
{
  ::xmlFreeDoc(this->_doc);
  ::xmlXPathFreeContext(this->_ctxt);
}

std::string	XmlParser::xmlGetParam(const std::string& path)
{
  xmlXPathObjectPtr	xpath;
  xmlNodePtr		node;
  int			i;

  if (!(xpath = ::xmlXPathEvalExpression((xmlChar*)path.c_str(),
					 this->_ctxt)))
    {
      std::cerr << "error - can't evaluate xpath expression"
		<< std::endl;
      exit(-1);
    }
  if (xpath->type != XPATH_NODESET)
    {
      std::cerr << "error: can't find [" << path
		<< "] content" << std::endl;
      exit(-1);
    }
  for (i = 0; i < xpath->nodesetval->nodeNr; i++)
    {
      node = xpath->nodesetval->nodeTab[i];
      return ((char*)node->properties->children->content);
    }
  return ("");
}
