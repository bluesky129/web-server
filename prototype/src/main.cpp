//
// main.cpp for Zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Jul 29 11:38:55 2008 morgan armand
// Last update Wed Aug 13 20:04:47 2008 caner candan
//

#include <iostream>
#include <sstream>
#include "Logger.h"
#include "Client.h"
#include "Thread.h"
#include "ServerSocket.h"
#include "ParserXml.h"
#include "ZiaConfiguration.h"

int			main(void)
{
  Logger		logger;
  ServerSocket		server;
  Socket*		socket;
  Client*		client;
  Thread*		thread;
  ZiaConfiguration*	conf;
  unsigned int		port;

  conf = ZiaConfiguration::getInstance();
  conf->setParserXml(new ParserXml(SERVER_XML));
  conf->loadConfig();

  std::istringstream	iss(conf->getValue("port"));
  iss >> port;
  logger.info("starting zia server");
  if (!server.create(port))
    {
      logger.error("an error occured while starting the server");
      return (1);
    }
  while (42)
    if (socket = server.accept())
      {
	logger.info("accept new connection from a client");
	client = new Client(socket);
	thread = new Thread(client);
	thread->start();
	delete thread;
      }
  server.close();
  conf->kill();
  logger.info("stopping zia server");
  return (0);
}
