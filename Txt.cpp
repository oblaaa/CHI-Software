#include "Txt.h"

namespace l1 
{
	Txt::Txt(const char* _str)
	{
		std::ifstream in;
		in.open(_str);
		if (!in.is_open())
		{
			this->strs = nullptr;
			this->sz = size_t();
		}
		else
		{
			int counter = 0;
			char tmp;
			while (in.get(tmp))
			{
				if (tmp == '\n')
					++counter;
			}
			sz = counter;
			this->strs = new std::string[counter];
			in.close();
			in.open(_str);
			counter = 0;
			while (!in.eof())
			{
				std::getline(in, strs[counter]);
				++counter;
			}
		}
	}

	size_t Txt::size()const
	{
		return this->sz;
	}

	Txt::Txt():strs(nullptr), sz(size_t())
	{ 
	}

	void Txt::swap(Txt& oth)
	{
		std::swap(sz, oth.sz);
		std::swap(strs, oth.strs);
	}

	Txt::Txt(Txt&& oth)noexcept :sz(oth.sz), strs(oth.strs)
	{
		oth.sz = 0;
		oth.strs = nullptr;
	}

	Txt& Txt::operator=(const Txt& oth)
	{
		Txt tmp = oth;
		swap(tmp);
		return *this;
	}

	Txt& Txt::operator=(Txt&& oth) noexcept
	{
		Txt tmp = std::move(oth);
		swap(tmp);
		return *this;
	}

	Txt::Txt(const Txt& oth):sz(oth.sz)
	{
		this->strs = new std::string[sz];
		for (int i = 0; i < oth.sz; i++)
		{
			this->strs[i] = oth.strs[i];
		}
	}

	Txt::~Txt()
	{
		if(this->strs != nullptr)
			delete[]strs;
	}
}
