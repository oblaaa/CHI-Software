#include "Product.h"

namespace sict
{
	//////////////////////////     Product        ////////////////////////////////

	Product::Product():product_no(NULL), cost(NULL)
	{
	}

	Product::Product(int pr_n, double cost) :product_no(pr_n), cost(cost)
	{
	}
	
	Product::~Product()
	{
	}



	//////////////////////////     iProduct        ////////////////////////////////

	iProduct::iProduct():Product()
	{

	}

	iProduct::iProduct(int pr_n, double cost) :Product(pr_n, cost)
	{
		
	}

	Product* iProduct::readRecord(std::ifstream& file)
	{
		if (!file.is_open())
			return nullptr;
		iProduct* ip = new iProduct();
		file >> this->product_no >> this->cost;
		return this;
	}

	double iProduct::price() const
	{
		return cost;
	}

	void iProduct::display(std::ostream& os) const
	{
		os << std::setw(FW) << this->product_no <<std::right<< std::setw(FW) << this->cost << std::endl;
	}

	std::ostream& sict::operator<<(std::ostream& os, const iProduct& p)
	{
		os << std::setw(FW) << p.product_no << std::right << std::setw(FW) << p.cost << std::right << '\n';
		return os;
	}

	iProduct::~iProduct()
	{
	}



	//////////////////////////     TaxableProduct        ////////////////////////////////

	TaxableProduct::TaxableProduct():Product(), taxable("")
	{
	}

	TaxableProduct::TaxableProduct(int pr_n, double cost, std::string& taxable):Product(pr_n, cost), taxable(taxable)
	{
	}

	TaxableProduct::~TaxableProduct()
	{
	}

	double TaxableProduct::price() const
	{
		return this->cost;
	}

	void TaxableProduct::display(std::ostream& os) const
	{
		os << std::setw(FW) << this->product_no << std::right << std::setw(FW) << this->cost  << " " << this->taxable << std::right << std::endl;
	}

	std::ostream& sict::operator<<(std::ostream& os, const TaxableProduct& p)
	{
		os << std::setw(FW) << p.product_no << std::right << std::setw(FW) << p.cost <<" " << p.taxable << std::right << '\n';
		return os;
	}

	Product* sict::TaxableProduct::readRecord(std::ifstream& file)
	{
		if (!file.is_open())
			return nullptr;
		iProduct* ip = new iProduct();
		file >> this->product_no >> this->cost>>this->taxable;
		return this;
	}

}