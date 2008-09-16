//
// Thread.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 17:22:40 2008 caner candan
// Last update Mon Sep 15 20:50:23 2008 morgan armand
//

#include <iostream>
#include "Thread.h"

Thread::Thread(IRunnable* obj)
  : _obj(obj)
{}

void	Thread::start()
{
  std::cout << "debug: [" << "thread start" << ']' << std::endl;
#ifdef WIN32
  if (!(this->_thread = ::CreateThread(NULL, 0,
				       Thread::_threadProc,
				       this->_obj, 0, NULL)))
    std::cerr << "CreateThread() failed" << std::endl;
#else
  if (::pthread_create(&(this->_thread), NULL, Thread::_threadProc, this->_obj))
    {
      std::cerr << "pthread_create() failed" << std::endl;
    }
  //  if (::pthread_detach(this->_thread, NULL))
  //    std::cerr << "pthread_detach() failed" << std::endl;
#endif
  std::cout << "debug: [" << "thread start end" << ']' << std::endl;
}

void	Thread::join()
{
  if (::pthread_join(this->_thread, NULL))
    std::cerr << "pthread_join() failed" << std::endl;
}

#ifdef WIN32
DWORD WINAPI	Thread::_threadProc(LPVOID arg)
#else
  void*		Thread::_threadProc(void* arg)
#endif
{
  std::cout << "debug: [" << "thread proc" << ']' << std::endl;
  ((IRunnable *)arg)->run();
#ifdef WIN32
  return (0);
#else
  pthread_exit(0);
#endif
}
