 ///
 /// @file    observer.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <memory>
using std::cout;
using std::endl;
using std::list;
using std::string;

class Observer;

typedef bool State;

class Subject
{
public:
	virtual void attach(Observer *) = 0;
	virtual void detach(Observer *) = 0;
	virtual void notify() = 0;
	virtual void setState() = 0;
	virtual State getState() = 0;

	virtual ~Subject() {}
};

class Observer
{
public:
	virtual void update() = 0;

	virtual ~Observer() {}
};

class Ring
	: public Subject
{
public:
	Ring()
		: _isAlarm(false)
	{
		cout << "Ring()" << endl;
	}

	~Ring() { cout << "~Ring()" << endl; }

	void attach(Observer *obj)
	{
		size_t cnt = std::count(_obserList.begin(), _obserList.end(), obj);
		if (cnt == 0)
			_obserList.push_back(obj);
	}
	virtual void detach(Observer *obj)
	{
		auto iter = std::find(_obserList.begin(), _obserList.end(), obj);
		if (iter != _obserList.end())
			_obserList.erase(iter);
	}
	virtual void notify()
	{
		cout << ">> notify all observers" << endl;
		for (auto &ob : _obserList)
		{
			ob->update();
		}
	}

	void press()
	{
		_isAlarm = true;
		cout << ">> Ring is alarming...." << endl;
	}

	virtual void setState()
	{
		press();
		notify();
	}
	virtual State getState()
	{
		return _isAlarm;
	}

private:
	list<Observer *> _obserList;
	State _isAlarm;
};

class Nurse
	: public Observer
{
public:
	Nurse(const string &name)
		: _random(0), _name(name)
	{
		cout << "Nurse(const string&)" << endl;
	}

	void update()
	{
		action();
	}

	void action()
	{
		::srand(::clock());
		_random = ::rand() % 100;

		if (_random < 70)
		{
			cout << _name << " wake up and open the door..." << endl;
		}
		else
		{
			cout << _name << " is sleeping." << endl;
		}
	}

	~Nurse()
	{
		cout << "~Nurse()" << endl;
	}

private:
	int _random;
	string _name;
};

class Baby
	: public Observer
{
public:
	Baby(const string &name)
		: _random(0), _name(name)
	{
		cout << "Baby()" << endl;
	}

	void update()
	{
		action();
	}

	void action()
	{
		::srand(::clock());
		_random = ::rand() % 100;

		if (_random < 30)
		{
			cout << _name << " wake up, begin cring loudly..." << endl;
		}
		else
		{
			cout << _name << " is sleeping sweetly." << endl;
		}
	}

	~Baby() { cout << "~Baby()" << endl; }

private:
	int _random;
	string _name;
};

class Guest
{
public:
	void knock(Ring &ring)
	{
		cout << "Guest knocked..." << endl;
		ring.setState();
	}
};

int main(void)
{
	std::unique_ptr<Ring> ring(new Ring());
	std::unique_ptr<Observer> nurse1(new Nurse("Xiao Fang"));
	std::unique_ptr<Observer> nurse2(new Nurse("Xiao Hong"));
	std::unique_ptr<Observer> baby1(new Baby("Da bao"));
	std::unique_ptr<Observer> baby2(new Baby("er bao"));

	ring->attach(nurse1.get());
	ring->attach(nurse2.get());
	ring->attach(baby1.get());
	ring->attach(baby2.get());

	Guest guest;
	guest.knock(*ring);

	cout << endl;
	ring->detach(nurse2.get());
	guest.knock(*ring);
	cout << endl;

	return 0;
}

