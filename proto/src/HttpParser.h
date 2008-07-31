//
// HttpParser.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:27:44 2008 morgan armand
// Last update Wed Jul 30 19:57:46 2008 morgan armand
//

#ifndef __HTTP_PARSER_H__
#define __HTTP_PARSER_H__

#include "IRunnable.h"
#include "HttpConsumer.h"

class	HttpParser : public HttpConsumer, public IRunnable
{
public:
  HttpParser(HttpProducer& prod);

  // Thread entry point.
  void	run();

  // Read a HTTP request, and fill a HttpRequest object
  bool	readHttpRequest(/*HttpRequest& req*/);
};

#endif // __HTTP_PARSER_H__
