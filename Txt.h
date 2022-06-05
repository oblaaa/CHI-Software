#include <iostream>
#include <fstream>
#include <string>



namespace l1
{


	class Txt
	{
	public:
		Txt(const char* _str);
		Txt();
		~Txt();
		size_t size() const;
		Txt(const Txt& oth);
		Txt(Txt&& oth)noexcept;
		Txt& operator=(Txt&& oth)noexcept;
		Txt& operator=(const Txt& oth);
		void swap(Txt& oth);
	private:
		std::string* strs;
		size_t sz;
	};
}
