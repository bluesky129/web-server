//
// Client.cpp for zia in /home/hochwe_f/zia/prototype/src
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Wed Aug 27 16:43:05 2008 florent hochwelker
// Last update Fri Aug 29 14:15:27 2008 caner candan
//

#include "Client.h"
#include "Request.h"
#include "Response.h"
#include "FluxClient.h"

using namespace ziApi;

Client::Client(ISocket* sck)
  : _sck(sck), _module(0)
{}

void	Client::run()
{
  IRequest	*req;
  IResponse	*response;
  IFlux		*flux;
  Consumer	*consumer;
  HttpParser	parser(consumer, req);

  flux = new FluxClient(this->_sck);
  request = new Request;
  response = new Response(req);
  openModule("/tmp/test.so");
  if (this->_module != NULL)
    {
      req->accept(IModule::PRE, this->_module);
      req->accept(IModule::POST, this->module);
      response->accept(IModule::PRE, this->response);
    }
  response->sendResponse(this->_sck);
  if (this->_module != NULL)
    response->accept(IModule::POST, this->response);
}
  
bool	Client::openModule(const std::string& moduleName)
{
  if ((_handler = dlopen(moduleName.str_c(), RTLD_NOW)) == NULL)
    {
      _logger.error("Module Error: " + dlerror());
    }
  else if ((this->_call = dlsym(this->_handler, "call")) == NULL)
    {
      _logger.error("Module Error: " + dlerror());
    }
  else
    {
      this->_module = this->_call();
      return true;
    }
  return false;
}
