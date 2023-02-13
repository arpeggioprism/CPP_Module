#include "Serialization.hpp"
#include "Data.hpp"

int main()
{
	{
		Serialization s;
		Data data;

		data.setName("test");
		uintptr_t raw = s.serialize(&data);
		std::cout << "data's address: " << &data << std::endl;
		std::cout << "data's decimal address: " << raw << std::endl;

		std::cout << std::endl;
		Data *data2 = s.deserialize(raw);
		std::cout << "data2's address: " << &data << std::endl;
		std::cout << "data2's decimal address: " << raw << std::endl;
		std::cout << "_name: " << data2->getName() << std::endl;
		std::cout << ((data2 == &data) ? "true" : "false") << std::endl;
	}

	system("leaks a.out");

	return 0;
}