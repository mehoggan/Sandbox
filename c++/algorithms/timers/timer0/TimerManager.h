#ifndef TIMERMANAGER_H_
#define TIMERMANAGER_H_

#include <stdlib.h>
#include <iostream>
#include <pthread.h>
#include <list>

extern "C" {
  void *create_pthread(void *data);
}

class TimerManager {
public:
  TimerManager();
  ~TimerManager();
  void start();
  void stop();
  void addTimer(long usec, void (*callback)(int id));
  void removeTimer(long usec, void (*callback)(int id));
private:
  class Timer  
  {
  public:
    Timer(long usec, void (*callback)(int)) :
      duration(usec),
      callback(callback),
      start(0)
    {      
    }
    bool operator ==(Timer other)
    {
      if ((this->callback == other.callback) && (this->duration == other.duration)) {
        return true;
      }
      return false;
    }
    Timer &operator =(Timer other)
    {
      duration = other.duration;
      callback = other.callback;
      start = other.start;
      return (*this);
    }
    bool operator ()(const Timer &timer)
    {
      if((this->callback == timer.callback) && (this->duration == timer.duration)) {
        return true;
      }
      return false;
    }
    suseconds_t duration;
    void (*callback)(int);
    suseconds_t start;
  };
  class TimerError : public std::exception
  {
  public:
    TimerError(std::string error) :
      m_error(error)
    {
    }
    ~TimerError() throw() {}
  protected:
    const char *what() const throw()
    {
      return m_error.c_str();
    }
  private:
    std::string m_error;
  };
  Timer setUpTimer(long micro_duration, void (*callback)(int id));
  friend void *create_pthread(void *data);
  void run();
  bool m_bRunning;
  bool m_bGo;
  long m_lMinSleep;
  std::list<Timer> m_cTimers;
  pthread_t m_tTimerThread;
  pthread_cond_t m_tGoLockCondition;
  pthread_mutex_t m_tGoLock;
};

#endif
