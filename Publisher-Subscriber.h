#include <iostream>
#include <vector>

template<typename T>
class PublisherInterface;

template<typename T>
class SubscriberInterface
{
public:
	void setSubject(PublisherInterface<T>* su)
	{
		subject = su;
	}
	virtual void onNotified() = 0;
	virtual ~SubscriberInterface<T>() {}
protected:
	PublisherInterface<T>* subject;
};


template<typename T>
class PublisherInterface
{
public:
	void addObserver(SubscriberInterface<T>* obs) {
		observerlist.push_back(obs);
	}
	void notify() {
		for (auto &obs : observerlist) {
			obs->onNotified();
		}
	}
	void setMutableState(T* newstate) {
		_mutable_state = newstate;
	}
	T* getMutableState() {
		return _mutable_state;
	}
	virtual ~PublisherInterface<T>() {}
protected:
	std::vector<SubscriberInterface<T>*>observerlist;
	T* _mutable_state;
};
