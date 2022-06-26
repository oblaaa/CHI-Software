#include "Sale.h"

//#define DEBUG

extern int FW;

namespace sict
{
	Sale::Sale()
	{
	}

	Sale::Sale(const char* str)
	{
		std::ifstream i;
		i.open(str);
		if (!i.is_open())
		{
			std::cout << "File is not open!" << std::endl;
			throw 3;
		}
		else
		{
			this->products.reserve(10);
			std::vector<std::string> info;
			std::string tmp;
			while (!i.eof())
			{
				i >> tmp;
				info.push_back(tmp);
			}
#ifdef DEBUG
			std::cout << "info after reading file" << std::endl;
			std::cout << "it		it.size()" << std::endl;
			for (const auto& it : info)
			{
				std::cout << it <<"\t" <<it.size() << std::endl;
			}
			std::cout << std::endl << std::endl << std::endl;
#endif // DEBUG
			TaxableProduct* tp;
			iProduct* ip;
			int count = 0;
			for (int i = 0; i < info.size()-1; i++)
			{
				if (count == 1 && info[i + 1].size() != 1)
				{
					count = 0;
					ip = new iProduct(std::stoi(info[i - 1]), std::stod(info[i]));
					this->products.push_back(ip);
#ifdef DEBUG
					std::cout << i << " ----ip----" << *ip << "\n";
#endif // DEBUG
				}
				else if (count == 2 /*&& (info[i+1].size()) == 1*/)
				{
					count = 0;
					info[i] += "ST";
					tp = new TaxableProduct(std::stoi(info[i - 2]), std::stod(info[i - 1]), info[i]);
					this->products.push_back(tp);
#ifdef DEBUG
					std::cout << i<<" ----tp----" << *tp << "\n";
#endif // DEBUG
				}
				else if (count == 0 && (i + 1) == info.size() - 1)
				{
					count = 0;
					ip = new iProduct(std::stoi(info[i]), std::stod(info[i+1]));
					this->products.push_back(ip);
#ifdef DEBUG
					std::cout << i << " ----ip----" << *ip << "\n";
#endif // DEBUG
				}
				else if (count == 1 && (i + 1) == info.size() - 1)
				{
					count = 0;
					info[i + 1] += "ST";
					tp = new TaxableProduct(std::stoi(info[i - 1]), std::stod(info[i]), info[i+1]);
					this->products.push_back(tp);
#ifdef DEBUG
					std::cout << i << " ----tp----" << *tp << "\n";
#endif// DEBUG
				}
				else
				{
#ifdef DEBUG
					std::cout << i << " ----info[i]----" << info[i] << "\n";
#endif // DEBUG
					count++;
				}
			}
#ifdef DEBUG

#endif // DEBUG

		}
	}

	void Sale::display(std::ostream& os) const
	{
#ifdef DEBUG
		std::cout << std::endl;
		for (auto& it : this->products)
		{
			os << typeid(it).name() << "\n";
		}
		std::cout << std::endl;
#endif // DEBUG
		os << std::setw(FW) << "Product No" << std::setw(FW) << std::right  << "Cost" << std::setw(FW) << std::left << " Taxable"<<std::endl;
		os << std::right;
		for (auto& it:this->products)
		{
			it->display(os);
		}
	}

	Sale::~Sale()
	{
	}

}






/*
		for (auto& it : this->products)
		{
			if (typeid(it) == typeid(iProduct))
				std::cout << *((iProduct*)it) << std::endl;
			else if (typeid(it) == typeid(TaxableProduct))
				std::cout << *((TaxableProduct*)it) << std::endl;
		}
*/