#include <iostream>
#include "Thread.h"

using namespace ziApi;

Thread::Thread(IRunnable* obj)
  : _obj(obj)
{}

void	Thread::start()
{
#ifdef WIN32
  if (!(this->_thread = ::CreateThread(NULL, 0,
				       Thread::_threadProc,
				       this->_obj, 0, NULL)))
    std::cerr << "CreateThread() failed" << std::endl;
#else
  if (::pthread_create(&(this->_thread), NULL,
		       Thread::_threadProc, this->_obj))
    std::cerr << "pthread_create() failed" << std::endl;
  if (::pthread_detach(this->_thread))
    std::cerr << "pthread_detach() failed" << std::endl;
#endif
}

#ifdef WIN32
DWORD WINAPI	Thread::_threadProc(LPVOID arg)
#else
  void*		Thread::_threadProc(void* arg)
#endif
{
  ((IRunnable *)arg)->run();
#ifdef WIN32
  return (0);
#else
  pthread_exit(0);
#endif
}
