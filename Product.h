#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>

extern int FW;

namespace sict
{
	class Product
	{
	public:
		Product();
		Product(int product_no, double cost);
		virtual ~Product();
		virtual double price()const = 0;
		virtual void display(std::ostream& os) const = 0;
		virtual Product* readRecord(std::ifstream& file) = 0;
	protected:
		int product_no;
		double cost;
	};

	class iProduct : public Product
	{
	public:
		iProduct();
		iProduct(int pr_n, double cost);
		~iProduct() override;
		double price()const override;
		void display(std::ostream& os) const override;
		friend std::ostream& operator<< (std::ostream& os, const iProduct& p);
		Product* readRecord(std::ifstream& file) override;
	};


	class TaxableProduct : public Product
	{
	public:
		TaxableProduct();
		TaxableProduct(int pr_n, double cost, std::string& taxable);
		~TaxableProduct() override;
		double price()const override;
		void display(std::ostream& os) const override;
		friend std::ostream& operator<< (std::ostream& os, const TaxableProduct& p);
		Product* readRecord(std::ifstream& file) override;
	private:
		std::string taxable;
	};

}