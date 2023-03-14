#include "common.hpp"

namespace enc {
	__forceinline void encrypt(std::string& str) {
		std::random_device r;
		std::default_random_engine e1(r());
		std::uniform_int_distribution<int> gen(0, 255);

		char k1 = static_cast<char>(gen(e1));
		char k2 = static_cast<char>(gen(e1));
		for (int i = 0; i < str.size(); i++) {
			char k = (i % 2) ? k1 : k2;
			str[i] ^= k;
		}
		str.insert(str.begin(), k1);
		str.insert(str.end(), k2);
	}

	__forceinline void decrypt(std::string& str) {
		char k1 = str[0];
		char k2 = str[str.size() - 1];

		str.erase(str.begin());
		str.erase(str.end() - 1);

		for (int i = 0; i < str.size(); i++) {
			char k = (i % 2) ? k1 : k2;
			str[i] ^= k;
		}
	}

};