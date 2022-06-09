#pragma once

template<typename A, typename B>
class Pair
{
public:
	Pair();
	Pair(const A& a, const B& b);
	const A& getKey() const;
	const B& getValue() const;
	~Pair();
private:
	A key;
	B value;
};

template<typename A, typename B>
Pair<A, B>::Pair()
{
	this->key = A();
	this->value = B();
}

template<typename A, typename B>
Pair<A, B>::Pair(const A& a, const B& b)
{
	this->key = a;
	this->value = b;
}

template<typename A, typename B>
const B& Pair<A, B>::getValue() const
{
	return this->value;
}

template<typename A, typename B>
const A& Pair<A, B>::getKey() const
{
	return this->key;
}

template<typename A, typename B>
Pair<A, B>::~Pair()
{

}