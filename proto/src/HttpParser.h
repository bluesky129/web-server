//
// HttpParser.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 16:01:46 2008 morgan armand
// Last update Fri Aug  8 19:59:01 2008 morgan armand
//

#ifndef __HTTP_PARSER_H__
#define __HTTP_PARSER_H__

#include "URIParser.h"
#include "HttpRequest.h"

class	HttpParser : public URIParser
{
public:
  HttpParser(HttpProducer* prod, HttpRequest* request);
  ~HttpParser();

  bool	readRequest();
  bool	readRequestLine();

  bool	readMethod();
  bool	readExtensionMethod();

  bool	readRequestURI();
  bool	readHttpVersion();

private:
  HttpRequest*	_request;
};

#endif // !__HTTP_PARSER_H__
