//
// Server.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 17:25:17 2008 caner candan
// Last update Mon Sep 15 17:03:11 2008 caner candan
//

#ifndef __SERVER_H__
# define __SERVER_H__

# include <list>
# include <string>
# include "Logger.h"
# include "ServerSocket.h"
# include "IRunnable.h"
# include "ISignalManager.h"

class	Server : public IRunnable, public ISignalManager
{
public:
  Server();

  void	start(int port);
  void	loop();
  void	stop();

  void	signal();
private:
  Logger	_logger;
  ServerSocket	_server;
};

#endif //! __SERVER_H__
