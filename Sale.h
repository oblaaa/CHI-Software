#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Product.h"
#include <vector>
#include <string>


namespace sict
{
	class Sale
	{
	public:
		Sale();
		Sale(const char* str);
		void display(std::ostream& os) const;
		~Sale();
	private:
		std::vector<Product*> products;
	};





}